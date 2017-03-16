import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class StandingOvation
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
			String[] lineParts = reader.readLine().split(" ");
			int smax = Integer.parseInt(lineParts[0]);
			int[] audienceArray = new int[smax+1];
			for (int j = 0; j < lineParts[1].length(); ++j)
			{
				audienceArray[j] = ((int) lineParts[1].charAt(j)) - ((int) '0');
			}
			
			int friendCount = doTestCase(smax, audienceArray);
			
			System.out.println("Case #" + (i+1) + ": " + friendCount);
		}
	}
	
	private static int doTestCase(int smax, int[] audienceArray)
	{
		int standing = audienceArray[0];
		int friendCount = 0;
		
		for (int i = 1; i < audienceArray.length; ++i)
		{
			if (standing < i)
			{
				friendCount += (i - standing);
				standing += (i - standing);
			}
			
			standing += audienceArray[i];
		}
		
		return friendCount;
	}
}