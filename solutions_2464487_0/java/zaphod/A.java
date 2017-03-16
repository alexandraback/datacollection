import java.io.*;
import java.util.Scanner;

public class A
{
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "A-small1";
        Scanner in = new Scanner(new File (fileName +".in"));
		PrintWriter out = new PrintWriter(new FileWriter(
				fileName +".out"));
		
		int noOfCases = in.nextInt();
		for (int caseNo =1 ; caseNo <=noOfCases; caseNo++)
		{
			long r = in.nextLong();
			long t = in.nextLong();
			long noOfRings = 0;
			
			while(t > 0)
			{
			    long paintNeeded = 2*r+1;
			    if(t >= paintNeeded)
			    	noOfRings++;
			    t -= paintNeeded;
			    r+=2;	
			}
			
			System.out.println("Case #" + caseNo + ": " + noOfRings);
			out.println("Case #" + caseNo + ": " + noOfRings);
			
			}
		in.close();
		out.close();

	}

}
