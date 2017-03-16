import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;

public class Technobabble
{
    public static void main(String[] args)
    {
        try
        {
            File file = new File("input.txt");
            FileReader fileReader = new FileReader(file);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            StringBuffer output = new StringBuffer();
            
            int lines = Integer.parseInt(bufferedReader.readLine());
            for(int i = 1; i <= lines; i++)
            {
                int topics = Integer.parseInt(bufferedReader.readLine());
                ArrayList<String> firstList = new ArrayList<String>();
                ArrayList<String> secondList = new ArrayList<String>();
                HashMap<String, Integer> firstMap = new HashMap<String, Integer>();
                HashMap<String, Integer> secondMap = new HashMap<String, Integer>();
                for(int j = 0; j < topics; j++)
                {
            		String[] topic = bufferedReader.readLine().split(" ");
            		firstList.add(topic[0]);
            		secondList.add(topic[1]);
            		firstMap.put(topic[0], firstMap.get(topic[0]) == null ? 1 : firstMap.get(topic[0]) + 1);
            		secondMap.put(topic[1], secondMap.get(topic[1]) == null ? 1 : secondMap.get(topic[1]) + 1);
                }
                
                // Sets of relevant real topics
                HashSet<String> firstSet = new HashSet<String>();
                HashSet<String> secondSet = new HashSet<String>();
                
                int fakes = 0;
                boolean finished = false;
                while(!finished)
                {
                	finished = true;
                    for(int j = 0; j < firstList.size(); j++)
                    {
                    	if(firstSet.contains(firstList.get(j)) && secondSet.contains(secondList.get(j)) 
                    			|| firstSet.contains(firstList.get(j)) && secondMap.get(secondList.get(j)) > 1 
                    			|| secondSet.contains(secondList.get(j)) && firstMap.get(firstList.get(j)) > 1)
                    	{
                    		// It's fake
                    		firstMap.put(firstList.get(j), firstMap.get(firstList.get(j)) - 1);
                    		secondMap.put(secondList.get(j), secondMap.get(secondList.get(j)) - 1);
                    		firstList.remove(j);
                    		secondList.remove(j);
                    		fakes++;
                    		j--;
                    		finished = false;
                    	}
                    	else if(firstMap.get(firstList.get(j)) == 1 || secondMap.get(secondList.get(j)) == 1)
                    	{
                    		// It's real
                    		if(firstMap.get(firstList.get(j)) != 1 || secondMap.get(secondList.get(j)) != 1)
                    		{
                    			// Add to relevant real set
                    			firstSet.add(firstList.get(j));
                    			secondSet.add(secondList.get(j));
                    		}
                    		firstMap.put(firstList.get(j), firstMap.get(firstList.get(j)) - 1);
                    		secondMap.put(secondList.get(j), secondMap.get(secondList.get(j)) - 1);
                    		firstList.remove(j);
                    		secondList.remove(j);
                    		j--;
                    		finished = false;
                    	}
                    }
                    
                    // Guessing
                    if(finished && firstList.size() != 0)
                    {
                    	firstSet.add(firstList.get(0));
            			secondSet.add(secondList.get(0));
                		firstList.remove(0);
                		secondList.remove(0);
                		firstMap.put(firstList.get(0), firstMap.get(firstList.get(0)) - 1);
                		secondMap.put(secondList.get(0), secondMap.get(secondList.get(0)) - 1);
                		finished = false;
                    }
                }
                
                output.append("Case #" + i + ": " + fakes + "\r\n");
            }
            fileReader.close();
            
            file = new File("output.txt");
            FileWriter fileWriter = new FileWriter(file);
            fileWriter.write(output.toString());
            fileWriter.flush();
            fileWriter.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}