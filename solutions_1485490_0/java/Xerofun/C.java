import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;


public class C 
{
    private BufferedReader reader;
    private BufferedWriter writer;
    
    /**
     * @param args
     */
    public static void main(String[] args)
    {
        C c = new C(args[0]);
        c.executeTests();
    }
    

    public C(String filename)
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
                
                long toys = Long.parseLong(input[0]);
                long boxes = Long.parseLong(input[1]);
                
                LinkedList<Long> toyType = new LinkedList<Long>();
                LinkedList<Long> toyAmt = new LinkedList<Long>();
                LinkedList<Long> boxType = new LinkedList<Long>();
                LinkedList<Long> boxAmt = new LinkedList<Long>();
                
                String[] toyLine = reader.readLine().split("\\s");
                String[] boxLine = reader.readLine().split("\\s");
                
                for (int i = 0; i < toys; i++)
                {
                	toyType.add(Long.parseLong(toyLine[i*2 + 1]));
                	toyAmt.add(Long.parseLong(toyLine[i*2]));
                }

                for (int i = 0; i < boxes; i++)
                {
                	boxType.add(Long.parseLong(boxLine[i*2 + 1]));
                	boxAmt.add(Long.parseLong(boxLine[i*2]));
                }
                
                // Calculate answer
                long maxDeliveries = getMaxDeliveries(toyType, toyAmt, boxType, boxAmt);
                
                writer.write("Case #" + testCase + ": " + maxDeliveries + '\n');
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


	private long getMaxDeliveries(LinkedList<Long> toyType,
			LinkedList<Long> toyAmt, LinkedList<Long> boxType,
			LinkedList<Long> boxAmt)
	{
		if (toyType.size() == 0 || boxType.size() == 0)
		{	// Base Case
			return 0;
		}
		else
		{	// Recursive Case
			long toyCnt = toyAmt.get(0);
			long boxCnt = boxAmt.get(0);
			
			if (toyType.get(0) == boxType.get(0))
			{	// find min of counts
				long boxable = Math.min(toyCnt, boxCnt);
				// remove that many from both
				toyCnt += -boxable;
				boxCnt += -boxable;
				
				// check for 0's
				if (toyCnt == 0)
				{
					toyType.remove(0);
					toyAmt.remove(0);
				}
				else
				{
					toyAmt.set(0, toyCnt);
				}
				
				if (boxCnt == 0)
				{
					boxType.remove(0);
					boxAmt.remove(0);
				}
				else
				{
					boxAmt.set(0, boxCnt);
				}
				
				// Recurse
				return boxable + getMaxDeliveries(new LinkedList<Long>(toyType), new LinkedList<Long>(toyAmt), new LinkedList<Long>(boxType), new LinkedList<Long>(boxAmt));
			}
			else
			{	// Return max of removeToy, removeBox
				LinkedList<Long> removeToyType = new LinkedList<Long>(toyType);
				LinkedList<Long> removeToyAmt = new LinkedList<Long>(toyAmt);
				LinkedList<Long> removeBoxType = new LinkedList<Long>(boxType);
				LinkedList<Long> removeBoxAmt = new LinkedList<Long>(boxAmt);
				
				removeToyType.remove(0);
				removeToyAmt.remove(0);
				removeBoxType.remove(0);
				removeBoxAmt.remove(0);
				
				return Math.max(
						getMaxDeliveries(removeToyType, removeToyAmt, new LinkedList<Long>(boxType), new LinkedList<Long>(boxAmt)),
						getMaxDeliveries(new LinkedList<Long>(toyType), new LinkedList<Long>(toyAmt), removeBoxType, removeBoxAmt)
						);
			}
		}
	}
}
