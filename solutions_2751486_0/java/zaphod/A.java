import java.io.*;
import java.util.Scanner;

public class A
{
	public static boolean isValid(String str, int n)
	{
		int noOfCon = 0;
		for (int i = 0; i < str.length(); i++)
		{
			char next = str.charAt(i);
			if ("aeiou".indexOf(next) == -1)
				noOfCon++;
			else
				noOfCon = 0;
			if (noOfCon >= n)
				return true;
		}
		return false;
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "A-small0";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		int noOfCases = in.nextInt();
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			String name = in.next();
			int n = in.nextInt();
			int L = name.length();
			int nValue = 0;
			
			for (int begin = 0; begin <= L - n; begin++)
			{
				for (int end = begin + n; end <= L; end++)
				{
					//System.out.println(name.substring(begin, end));
					if (isValid(name.substring(begin, end),n))
						nValue++;
				}
			}
			
			System.out.printf("Case #%d: %d%n", caseNo, nValue);
			out.printf("Case #%d: %d%n", caseNo, nValue);

		}
		in.close();
		out.close();
	}
}
