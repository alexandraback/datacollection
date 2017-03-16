import java.io.*;
import java.util.*;

public class CodeJamA
{

	public static String translate(String line)
	{
		String alpha = "abcdefghijklmnopqrstuvwxyz";
		String code  = "ynficwlbkuomxsevzpdrjgthaq";
		
		StringBuffer translate = new StringBuffer(line.length());
		
		for (int i = 0; i < line.length(); i++)
		{
			char next = line.charAt(i);
			if (next == ' ')
				translate.append(' ');
			else
				translate.append(alpha.charAt(code.indexOf(next)));
		}
		return translate.toString();
	}
	
	public static void main(String[] args) throws IOException
	{
		String fileName = "A-small0";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				fileName + ".out")));

		// Keep track of time for efficiency
		long startTime = System.currentTimeMillis();

		// Process each of the test cases
		int noOfCases = in.nextInt();
		in.nextLine();

		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			String line = in.nextLine();
			
			String output = translate(line);
			
			System.out.println("Case #" + caseNo + ": " + output);
			out.println("Case #" + caseNo + ": " + output);

		}

		System.out.println("Done");
		long stopTime = System.currentTimeMillis();
		System.out.println("Time: " + (stopTime - startTime) / 1000.0);

		// Close the files
		in.close();
		out.close();
	}

}
