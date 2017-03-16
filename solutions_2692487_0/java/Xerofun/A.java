import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.PriorityQueue;


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
            long initSize;
            
            PriorityQueue<Long> motes = new PriorityQueue<>();
            
            try
            {
                input = reader.readLine().split("\\s");
                
                initSize = Long.parseLong(input[0]);

                input = reader.readLine().split("\\s");
                
                for (String s : input)
                {
                	motes.add(Long.parseLong(s));
                }
                
                long answer = minAdds(initSize, motes);
                
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
    
    
    public static long minAdds(long initSize, PriorityQueue<Long> motes)
    {
    	long currentSize = initSize;
    	long count = 0;
    	long minCount = motes.size();
    	
    	if (initSize == 1)
    	{
    		return motes.size();
    	}
    	
    	while (!motes.isEmpty()) 
    	{
    		if (currentSize > motes.peek())
    		{
    			currentSize += motes.poll();
    		}
    		else
    		{
//    			long addsUntil = addsUntil(currentSize, motes.peek());
//    			
//    			if (addsUntil > motes.size())
    			
				minCount = Math.min(minCount, count + motes.size());
				currentSize += currentSize - 1;
    			
    			count++;
    		}
    	}
    	
    	return Math.min(minCount, count);
    }
}

