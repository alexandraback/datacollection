import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;


public class A 
{
    private BufferedReader reader;
    private BufferedWriter writer;

    
    private static Set<Character> vowels = new HashSet<Character>(); 
    
    /**
     * @param args
     */
    public static void main(String[] args)
    {
    	vowels.add('a');
    	vowels.add('e');
    	vowels.add('i');
    	vowels.add('o');
    	vowels.add('u');
    	
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
            String name;
            int n;
            
            try
            {
                input = reader.readLine().split("\\s");
                
                name = input[0];
                n = Integer.parseInt(input[1]);

                long answer = nValue(name, n);
                
                writer.write("Case #" + testCase + ": " + answer + '\n');
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
    
    
//    private static long nValue(String name, int n)
//    {
//    	System.out.println("Start");
//    	
//    	int startOfLastRun = 0;
//    	long count = 0;
//    	int subsBefore = 0;
//    	
//    	for (int i = 0; i < name.length(); i++)
//    	{
//    		if (vowels.contains(name.charAt(i)))
//    		{
//    			startOfLastRun = i + 1;
//    			continue;
//    		}
//    		
//    		if (i - startOfLastRun + 1 >= n)
//    		{
//    			System.out.println(i + ": " + startOfLastRun + " - " + (startOfLastRun + (name.length() - i)));
//    			count += startOfLastRun + (name.length() - i);
//    			subsBefore++;
//    		}
//    	}
//    	
//    	return count;
//    }
    
    
    private static long nValue(String name, int n)
    {
    	System.out.println("Begin");
    	String newName = name;
    	
    	Set<String> subs = new HashSet<String>();
    	
    	long count = 0;
    	int startOfRun = 0;
    	
    	for (int i = 0; i < name.length(); i++)
    	{
    		if (vowels.contains(name.charAt(i)))
    		{
    			startOfRun = i + 1;
    			continue;
    		}
    		
    		if (i - startOfRun + 1 >= n)
    		{
    			int left = startOfRun - (name.length() - newName.length());
    			int right = name.length() - i - 1;
    			int split = left * right;
    			count += left + right + split + 1;
    			
    			newName = name.substring(i - n + 2);
    			
    			startOfRun++;
    			
    			System.out.println(newName + "left: " + left + "  right: " + right + "split: " + split + " i: " + i + "startOfRun: " + startOfRun);
    		}
    	}
    	
    	return count;
    }
    
}

