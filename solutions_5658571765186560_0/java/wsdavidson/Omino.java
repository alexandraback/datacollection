import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;


public class Omino
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
			String[] unparsed = reader.readLine().split(" ");
			int x = Integer.parseInt(unparsed[0]);
			int r = Integer.parseInt(unparsed[1]);
			int c = Integer.parseInt(unparsed[2]);
			
			String winner = doTestCase(x, r, c);
			
			//System.out.println("Case #" + (i+1) + ": " + x + ", " + r + ", " + c + " -- " + winner);
			System.out.println("Case #" + (i+1) + ": " + winner);
		}
	}
	
	private static String doTestCase(final int x, final int r, final int c)
	{
		String RICHARD = "RICHARD";
		String GABRIEL = "GABRIEL";
		
		if ((r*c) % x != 0) return RICHARD; // Guaranteed to have extra squares left over
		
		int maxScalar = x;
		int minScalar = (int) Math.floor(Math.sqrt(x));
		if (maxScalar > r && maxScalar > c) return RICHARD; // Can pick a omino that is 1xX and spills over
		if (minScalar > r || minScalar > c) return RICHARD; // Can pick a boxy omino that spills over
		if ((r == 1 || c == 1) && x > 2) return RICHARD; // Can put a L-shape omino that spills over
		if (x >= 7) return RICHARD; // Can pick a omino with a hole in middle
		
		if (r > 3 && c > 3) return GABRIEL; // if under 7-omino and this size, we can always find a way
		if (r == 2 || c == 2)
		{
			if (x == 4 || x == 6) return RICHARD;
			if (x == 5 && r*c <= 20) return RICHARD;
			return GABRIEL;
		}
		
		// we know it to be 3xX now
		
		if (x == 6) return RICHARD;
		return GABRIEL;  // only 6 ominos will stick in 3xX
	}
}