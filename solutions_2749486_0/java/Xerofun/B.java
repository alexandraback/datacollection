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
            String[] input;
            int x;
            int y;
            
            try
            {
                input = reader.readLine().split("\\s");
                x = Integer.parseInt(input[0]);
                y = Integer.parseInt(input[1]);
                
                String answer = findRoute(x, y);
                
                
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
    
    private static String findRoute(int x, int y)
    {
    	char filler = 'N';
    	
    	int deltaX;
    	int deltaY;
    	int xTarget;
    	int yTarget;
    	
    	StringBuilder route = new StringBuilder();
    	    	
    	if (Math.abs(x) != Math.abs(y))
    	{
    		deltaX = 0;
    		deltaY = 0;
    		xTarget = Math.abs(x);
    		yTarget = Math.abs(y);
    	}
    	else
    	{
    		xTarget = Math.abs(x);
    		yTarget = xTarget + 1;
    		deltaX = 0;
    		deltaY = 1 * (int)Math.signum(y);
    	}
    		
    	int max = Math.max(xTarget, yTarget);

		for (int i = 1; i <= max; i++)
		{
			if (i == xTarget)
			{
				if (x < 0)
				{
    				route.append("W");
				}
				else
				{
					route.append("E");
				}
				
				continue;
			}
			
			if (i == yTarget)
			{
				if (y < 0)
				{
					route.append("S");
				}
				else
				{
					route.append("N");
				}
				
				continue;
			}
			
			route.append(filler);
			
			if (filler == 'N')
			{
				filler = 'S';
				deltaY += i;
			}
			else
			{
				filler = 'N';
				deltaY -= i;
			}
    	}
		
		String recovery;
		
		if (deltaY != 0)
		{
			if (deltaY < 0)
			{
				recovery = "SN";
			}
			else
			{
				recovery = "NS";
			}
			
			for (int i = 0 ; i < Math.abs(deltaY); i++)
			{
				route.append(recovery);
			}
		}
    	
    	return route.toString();
    }
}

