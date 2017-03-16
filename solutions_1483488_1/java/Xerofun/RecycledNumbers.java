import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;


public class RecycledNumbers 
{
    private BufferedReader reader;
    private BufferedWriter writer;
    
    /**
     * @param args
     */
    public static void main(String[] args)
    {
        RecycledNumbers rn = new RecycledNumbers(args[0]);
        rn.executeTests();
    }
    

    public RecycledNumbers(String filename)
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
                input = reader.readLine().split("\\s");
                
                int min = Integer.parseInt(input[0]);
                int max = Integer.parseInt(input[1]);
                
                List<Integer> scores = new ArrayList<Integer>();
                
                int answer = totalRecycledPairs(min, max);
                
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


	private static int totalRecycledPairs(int min, int max)
	{
		// Number -> Unique Pair Count
		Map<Integer, Integer> uniquePairCount = new HashMap<Integer, Integer>();
		
		int total = 0;
		
		for (int number = min; number <= max; number++)
		{
			int count = 0;
			
			for (Integer recycled : getRecycledPairs(number))
			{
				if (!uniquePairCount.containsKey(recycled) &&
						recycled <= max && recycled >= min)
				{
					count++;
				}
			}
			
			uniquePairCount.put(number, count);
			total += count;
		}
		
		return total;
	}
	
	
	private static Set<Integer> getRecycledPairs(int number)
	{
		Set<Integer> pairs = new HashSet<Integer>();
		
		String numberString = String.valueOf(number);
		
		for (int i = 1; i < numberString.length(); i++)
		{
			String rcirc = numberString.substring(numberString.length() - i) +
					numberString.substring(0, numberString.length() - i);
			
			int pair = Integer.parseInt(rcirc);  
			if (numberString.length() == String.valueOf(pair).length() &&
					pair != number)
			{
				pairs.add(Integer.parseInt(rcirc));
			}
		}
		
		return pairs;
	}

}

