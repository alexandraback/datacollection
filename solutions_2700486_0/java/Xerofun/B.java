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


public class B 
{
    private BufferedReader reader;
    private BufferedWriter writer;
    
    private static List<Long> geoList = new ArrayList<>(300);
    private static Map<Long, Long> geoMap = new HashMap<>();
    
    /**
     * @param args
     */
    public static void main(String[] args)
    {
    	long sum = 0;
    	
    	for (long i = 0; sum < 100000; i++)
    	{
    		sum += i;
    		
    		if (i % 2 == 1)
    		{
    			geoMap.put(sum, i);
    			geoList.add(sum);
    		}
    	}
    	
    	
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
            int x;
            int y;
            long n;
            
            try
            {
                input = reader.readLine().split("\\s");
                n = Long.parseLong(input[0]);
                x = Integer.parseInt(input[1]);
                y = Integer.parseInt(input[2]);
                
                double answer = getProbability(n, x, y);
                
                
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
    
    
    private static double getProbability(long n, int x, int y)
    {
    	if (x == 0 && y == 0)
    	{
    		return 1;
    	}
    	
    	if (x % 2 != y % 2)
    	{
    		return 0;
    	}
    	
    	long baseSize = getBaseSize(n);
    	long baseCount = geoSum(baseSize);
    	
    	if (x == 0 && y == baseSize + 1)
    	{
    		return 0;
    	}
    	
    	
    	if (isInBase(x, y, baseSize))
    	{
    		return 1.0;
    	}
    	
    	if (!isOnBase(x, y, baseSize))
    	{
    		return 0.0;
    	}
    	
    	// we care about the y height and n at this point
    	
    	double p = 0;
    	
    	long remaining = n - baseCount;
    	
    	
    	
    	int i = y;
    	
    	for (;i < n - baseCount; i++)
    	{
    		System.out.println(i - (remaining - y + baseSize - 2));
    		
    		if (i > remaining - y + baseSize - 2 && remaining > baseSize + 1)
    		{
    			p += Math.pow(0.5, i + 1 + (i - (remaining - y + baseSize - 2)));	
    		}
    		
    		p += Math.pow(0.5, i + 1);
    	}
    	
    	if (remaining + y > baseSize + 2)
    	{
    		p += Math.pow(0.5, i + 1);
    	}
    	
    	return p;
    }
    
    
    private static long getBaseSize(long n)
    {
    	long lastValue = 1;
    	
    	for (Long geo : geoList)
    	{
    		if (n >= geo)
    		{
    			lastValue = geo;
    		}
    		else
    		{
    			return geoMap.get(lastValue);
    		}
    	}
    	
    	return geoMap.get(lastValue);
    }
   
    
    private static long geoSum(long n)
    {
    	return n * (n + 1) / 2;
    }
    
    
    private static boolean isInBase(long x, long y, long b)
    {
    	return Math.abs(x) + y <= b - 1;
    }
    
    private static boolean isOnBase(long x, long y, long b)
    {
    	return Math.abs(x) + y == b + 1;
    }
}

