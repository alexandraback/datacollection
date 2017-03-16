import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


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
        	double farmCost;
        	double farmCPS;
        	double targetBank;
        	
            try
            {
            	String[] input = reader.readLine().split(" ");
            	
            	farmCost = Double.valueOf(input[0]);
            	farmCPS = Double.valueOf(input[1]);
            	targetBank = Double.valueOf(input[2]);
            	
                double response = optimalTime(farmCost, farmCPS, targetBank);
                               
                writer.write("Case #" + testCase + ": " + response + '\n');
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
    
    
    
    public double optimalTime(double farmCost, double farmCPS, double targetBank)
    {
    	double bank = 0;
    	double currentCPS = 2.0;
    	double elapsedTime = 0;
    	
    	for (;;)
    	{   		
    		// If we can't earn enough cookies for a new farm before we win
    		if (farmCost >= targetBank - bank)
    		{
    			return elapsedTime + ((targetBank - bank) / currentCPS);
    		}
    		
    		elapsedTime += (farmCost / currentCPS);
    		bank += farmCost;
    		
    		// We now have enough for a farm
    		double noFarmTime = (targetBank - bank) / currentCPS;
    		double newFarmTime = (targetBank) / (currentCPS + farmCPS);
    		
    		if (noFarmTime <= newFarmTime)
    		{	// No sense buying a farm
    			return elapsedTime + noFarmTime;
    		}
    		else
    		{	// Buy the farm
    			currentCPS += farmCPS;
    			bank = 0;
    		}
    	}
    }
}

