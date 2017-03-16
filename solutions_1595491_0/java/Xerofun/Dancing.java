import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Dancing {
	private static Map<String, String> knowledgeBase = new HashMap<String, String>();
	
	static
	{
		knowledgeBase.put("our language is impossible to understand", "ejp mysljylc kd kxveddknmc re jsicpdrysi");
		knowledgeBase.put("there are twenty six factorial possibilities", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
		knowledgeBase.put("so it is okay if you want to just give up", "de kr kd eoya kw aej tysr re ujdr lkgc jv");
		knowledgeBase.put("aozq", "yeqz");
	}


    private BufferedReader reader;
    private BufferedWriter writer;
    
    /**
     * @param args
     */
    public static void main(String[] args)
    {
        Dancing dancing = new Dancing(args[0]);
        dancing.executeTests();
    }
    

    public Dancing(String filename)
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
                
                int contestants = Integer.parseInt(input[0]);
                int surprises = Integer.parseInt(input[1]);
                int threshhold = Integer.parseInt(input[2]);
                
                List<Integer> scores = new ArrayList<Integer>();
                
                for (int i = 3; i < 3 + contestants; i++)
                {
                	scores.add(Integer.parseInt(input[i]));
                }
                
                int answer = findWinners(surprises, threshhold, scores);
                
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


	private static int findWinners(int surprises, int threshhold, List<Integer> scores)
	{
		int totalPossible = 0;
		int surprisesRemaining = surprises;
		
		for (Integer score : scores)
		{
			Map<String, Integer> maxScores = getMaxScores(score);
			
			if (maxScores.get("normal") >= threshhold)
			{
				totalPossible++;
			}
			else if (maxScores.get("surprise") >= threshhold && surprisesRemaining > 0)
			{
				totalPossible++;
				surprisesRemaining--;
			}
		}
	
		return totalPossible;
	}
	
	private static Map<String, Integer> getMaxScores(int totalScore)
	{
		int maxNormalScore = ((totalScore - 1) / 3) + 1;
		int maxSurpriseScore = maxNormalScore;
		
		if (totalScore % 3 != 1)
		{
			maxSurpriseScore++;
		}
		
		Map<String, Integer> maxScores = new HashMap<String, Integer>();
		maxScores.put("normal", maxNormalScore);
		maxScores.put("surprise", maxSurpriseScore);
		
		// Special case to continue using integer division
		if (totalScore == 0)
		{
			maxScores.put("normal", 0);
			maxScores.put("surprise", 0);
		}
		
		return maxScores;
	}
}
