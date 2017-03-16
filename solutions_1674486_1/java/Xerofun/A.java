import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Stack;


public class A 
{
    private BufferedReader reader;
    private BufferedWriter writer;
    
    /**
     * @param args
     */
    public static void main(String[] args)
    {
        A a = new A(args[0]);
        a.executeTests();
    }
    

    public A(String filename)
    {
        // Open file
        File file = new File(filename);
        try
        {
            reader = new BufferedReader(new FileReader(file));
            writer = new BufferedWriter(new FileWriter(file+".out"));
        }
        catch (IOException e)
        {
            // Failed to open new buffered reader
            System.err.println("Failed to open FileReader");
            e.printStackTrace();
            System.exit(-1);
        }
    }
    
    private void executeTests()
    {
        // Read number of test cases
        int numberOfTests = 0; 
        
        try
        {
            // Read number of tests (first line)
            numberOfTests = Integer.parseInt(reader.readLine());
        }
        catch (NumberFormatException | IOException e)
        {
            // Failed to read a line
            System.err.println("Failed to read a line");
            e.printStackTrace();
            System.exit(-1);
        }

        for (int testCase = 1; testCase <= numberOfTests; testCase++)
        {
            String[] input;
            
            try
            {
            	// Grab and parse next test case
                input = reader.readLine().split("\\s");
                
                int classes = Integer.parseInt(input[0]);
                
                Map<Integer, List<Integer>> diagram = new HashMap<Integer, List<Integer>>();
                
                for (int i = 1; i < classes + 1; i++)
                {
                	List<Integer> parents = new ArrayList<Integer>();
                	String[] line = reader.readLine().split("\\s");
                	int parentCount = Integer.parseInt(line[0]);
                	
                	for (int j = 1; j < parentCount + 1; j++)
                	{
                		parents.add(Integer.parseInt(line[j]));
                	}
                	
                	diagram.put(i, parents);
                }
                
                // Calculate answer
                boolean hasDiamond = hasDeathDiamond(diagram);
                
                String output = "";
                
                if (hasDiamond)
                {
                	output = "Yes";
                }
                else
                {
                	output = "No";
                }
                
                writer.write("Case #" + testCase + ": " + output + '\n');
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
        }
        
        try
        {
            reader.close();
            writer.flush();
            writer.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }


	private static boolean hasDeathDiamond(Map<Integer, List<Integer>> diagram)
	{
		// To have diamond, must have a class with multiple inheritance
		List<Integer> multiInheritance = new ArrayList<Integer>();
		
        for (Map.Entry<Integer, List<Integer>> entry : diagram.entrySet())
        {
        	if (entry.getValue().size() > 1)
        	{
        		multiInheritance.add(entry.getKey());
        	}
        }
		
        if (multiInheritance.size() == 0)
        {
        	return false;
        }
        
        // Build inheritance chains for the multi inheritance nodes
        for (int multiClass : multiInheritance)
        {
        	if (hasDupe(diagram, multiClass))
        	{
        		return true;
        	}
        }
        
		
		return false;
	}


	private static boolean hasDupe(Map<Integer, List<Integer>> diagram,
			int multiClass) 
	{
		LinkedList<Integer> frontier = new LinkedList<Integer>(diagram.get(multiClass));
		Map<Integer, Integer> visited = new HashMap<Integer, Integer>();
		
		while (frontier.size() > 0)
		{
			int current = frontier.pop();
			
			if (visited.containsKey(current))
			{
				return true;
			}
			else
			{
				visited.put(current, 0);
			}
			
			// add all elements of first one to frontier
			for (int i : diagram.get(current))
			{
				frontier.push(i);
			}
		}
		
		return false;
	}
}
