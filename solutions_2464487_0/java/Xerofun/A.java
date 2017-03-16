import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;


public class A 
{
	private static final BigInteger ONE = BigInteger.ONE;
	private static final BigInteger TWO = new BigInteger("2");
	private static final BigInteger THREE = new BigInteger("3");
	private static final BigInteger FOUR = new BigInteger("4");
	
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
            BigInteger r;
            BigInteger t;
            
            try
            {
                input = reader.readLine().split("\\s");
                
                r = new BigInteger(input[0]);
                t = new BigInteger(input[1]);

                BigInteger answer = maxRings(r, t);
                
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
    
    
    private static BigInteger maxRings(BigInteger r, BigInteger t)
    {
    	final BigInteger BASE = r.multiply(TWO); 
    	
    	BigInteger remaining = t;
    	BigInteger nextRingCost = BASE.add(ONE);
    	BigInteger ringCount = BigInteger.ZERO;
    	
    	while (remaining.compareTo(nextRingCost) >= 0)
    	{
    		remaining = remaining.subtract(nextRingCost);
    		ringCount = ringCount.add(ONE);
    		nextRingCost = BASE.add(FOUR.multiply(ringCount.add(ONE))).subtract(THREE); 
    	}
    	
    	return ringCount;
    }
}

