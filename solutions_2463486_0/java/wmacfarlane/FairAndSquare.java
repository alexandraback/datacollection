import java.math.*;
import java.io.*;

class FairAndSquare
{
	public static void main ( String [] args ) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("FairAndSquare.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("FairAndSquare.out")));
		int numTests = Integer.parseInt(br.readLine());
		String[] throwAway;
		long lowBound, highBound, sqrtOfLowBound, sqrtOfHighBound;
		for(int test = 1; test <= numTests; test++)
		{
			throwAway = br.readLine().split(" ");
			lowBound = Long.parseLong(throwAway[0]);
			highBound = Long.parseLong(throwAway[1]);
			
			sqrtOfLowBound = (long) Math.ceil(Math.sqrt(lowBound));
			sqrtOfHighBound = (long) Math.floor(Math.sqrt(highBound));
			
			/* begin algorithm */
			
			int numFAS = 0;
			for(long i = sqrtOfLowBound; i <= sqrtOfHighBound; i++)
			{
				if( isPal(i + "") && isPal( ((long) Math.pow(i, 2)) + "") )
					numFAS++;
			}
			
			/* end algorithm */
		
			out.println("Case #" + test + ": " + numFAS);
		}
		
		
		
		br.close();
		out.close();
	}
	static boolean isPal(String val)
	{
		for(int i = 0; i < val.length() / 2; i++)
		{
			if( val.charAt(i) != val.charAt(val.length() - 1 - i) )
				return false;
		}
		return true;
	}
}