import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.LinkedList;


public class D 
{
    private BufferedReader reader;
    private BufferedWriter writer;
    
    /**
     * @param args
     */
    public static void main(String[] args)
    {
        D d = new D(args[0]);
        d.executeTests();
    }
    

    public D(String filename)
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
            try
            {
            	reader.readLine();
            	
            	LinkedList<Double> naomi = new LinkedList<>();
            	LinkedList<Double> ken = new LinkedList<>();
            	
            	String[] input = reader.readLine().split("\\s");
            	
            	for (String entry : input)
            	{
            		naomi.add(Double.valueOf(entry));
            	}

            	input = reader.readLine().split("\\s");
            	
            	for (String entry : input)
            	{
            		ken.add(Double.valueOf(entry));
            	}
            	
            	int deceitfulWins = deceitfulWins(new LinkedList<Double>(naomi), new LinkedList<Double>(ken));
            	int honestWins = honestWins(naomi, ken);
            	
            	
                writer.write("Case #" + testCase + ": " + deceitfulWins + " " + honestWins + '\n');
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
    

    private int deceitfulWins(LinkedList<Double> naomi, LinkedList<Double> ken)
    {
    	Collections.sort(naomi);
    	Collections.sort(ken);
    	
    	int wins = 0;
    	
    	while (!naomi.isEmpty())
    	{
    		if (naomi.getFirst() < ken.getFirst())
    		{
    			naomi.removeFirst();
    			ken.removeLast();
    		}
    		else
    		{
    			wins++;
    			naomi.removeFirst();
    			ken.removeFirst();
    		}
    	}
    	
    	return wins;
    }
    
    private int honestWins(LinkedList<Double> naomi, LinkedList<Double> ken)
    {
    	Collections.sort(naomi);
    	Collections.sort(ken);
    	
    	int wins = 0;
    	
    	while (!naomi.isEmpty())
    	{    		
    		if (naomi.getLast() > ken.getLast())
    		{
    			wins++;
    			naomi.removeLast();
    			ken.removeFirst();
    		}
    		else
    		{
    			naomi.removeLast();
    			ken.removeLast();
    		}
    	}
    	
    	return wins;
    }
    
 }

