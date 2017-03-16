import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class B 
{
    private BufferedReader reader;
    private BufferedWriter writer;
    
    /**
     * @param args
     */
    public static void main(String[] args)
    {
        B b = new B(args[0]);
        b.executeTests();
    }
    

    public B(String filename)
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
            int e;
            int r;
            int n;
            List<Integer> values;
            
            try
            {
                input = reader.readLine().split("\\s");
                e = Integer.parseInt(input[0]);
                r = Integer.parseInt(input[1]);
                n = Integer.parseInt(input[2]);
                input = reader.readLine().split("\\s");
                values = new ArrayList<Integer>(n);
                
                for (int i = 0; i < n; i++)
                {
                	values.add(Integer.parseInt(input[i]));
                }
                
                long answer = maximizeValue(e, r, values, e, 0);
                
                
                writer.write("Case #" + testCase + ": " + answer + '\n');
            }
            catch (IOException ioe)
            {
                ioe.printStackTrace();
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
    
    
    
    private static long maximizeValue(int maxEnergy, int recovery, List<Integer> values, int currentEnergy, int currentPosition)
    {
    	List<Long> results = new ArrayList<Long>();
    	
    	if (currentPosition + 1 == values.size())
    	{
    		return values.get(currentPosition) * currentEnergy;
    	}
    	
    	for (int energySpent = 0; energySpent <= currentEnergy; energySpent++)
    	{
    		results.add(energySpent * values.get(currentPosition) + maximizeValue(maxEnergy, recovery, values, Math.min(maxEnergy, currentEnergy - energySpent + recovery), currentPosition + 1));
    	}
    	
    	
    	return Collections.max(results);
    }
}

