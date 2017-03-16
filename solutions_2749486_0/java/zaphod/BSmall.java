import java.io.*;
import java.util.Scanner;

public class BSmall
{
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "B-small0";
        Scanner in = new Scanner(new File (fileName +".in"));
		PrintWriter out = new PrintWriter(new FileWriter(
				fileName +".out"));
		
		int noOfCases = in.nextInt();
		for (int caseNo =1 ; caseNo <=noOfCases; caseNo++)
		{
			int X = in.nextInt();
			int Y = in.nextInt();
			//int distance = Math.abs(X)+Math.abs(Y);
			//int n = (int)Math.sqrt(2*distance);
			//System.out.println(distance + " "+ n);
			
			String directions = "";
			String XString = "WE";
			if (X < 0)
				XString = "EW";
			String YString = "SN";
			if (Y < 0)
				YString = "NS";
			for (int x = 0; x < Math.abs(X); x++)
				directions += XString;
			for (int y = 0; y < Math.abs(Y); y++)
				directions += YString;
			
			System.out.printf("Case #%d: %s%n", caseNo, directions);
			out.printf("Case #%d: %s%n", caseNo, directions);
		}
		in.close();
		out.close();

	}

}
