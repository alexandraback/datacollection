import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;


public class Pancakes
{
	public static void main(String[] args)
	{
		try
		{
			start();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	
	private static void start() throws NumberFormatException, IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int testCases = Integer.parseInt(reader.readLine());
		
		for (int i = 0; i < testCases; ++i)
		{
			int count = Integer.parseInt(reader.readLine());
			String[] unparsedDiners = reader.readLine().split(" ");
			int[] diners = new int[count];
			for (int j = 0; j < count; ++j)
			{
				diners[j] = Integer.parseInt(unparsedDiners[j]);
			}
			
			int minutes = doTestCase(diners);
			
			System.out.println("Case #" + (i+1) + ": " + minutes);
		}
	}
	
	private static int doTestCase(int[] diners)
	{
		Arrays.sort(diners);
		
		int max = diners[diners.length-1];
		int minutes = max;
		
		for (int i = max-1; i >= 2; --i)
		{
			// count number of splits required to get under the number
			int count = 0;
			
			for (int j = diners.length-1; j >= 0; --j)
			{
				if (diners[j] <= i) break;
				
				count += (int) Math.ceil((double) diners[j] / (double) i) - 1;
			}
			
			//System.out.println("   minutes if trying to get all to " + i + ": " + (count+i));
			
			if (count + i < minutes)
			{
				minutes = count+i;
			}
		}
		
		return minutes;
	}
}