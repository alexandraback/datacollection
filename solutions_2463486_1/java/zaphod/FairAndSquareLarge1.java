import java.io.*;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class FairAndSquareLarge1
{

	public static boolean isPalindrome(long n)
	{
		if (n % 10 == 0)
			return false;
		long front = 0;
		while (n > front)
		{
			front = 10 * front + n % 10;
			if (n == front)
				return true;
			n /= 10;
		}
		return n == front;
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "C-large1";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		// Pre-calculate all of the fair and square numbers between 1 and 10^14
		TreeSet<Long> fairAndSquare = new TreeSet<Long>();

		for (long sqrt = 1; sqrt <= 10000000; sqrt++)
		{
			if (isPalindrome(sqrt))
			{
				long number = sqrt * sqrt;
				if (isPalindrome(number))
				{
					fairAndSquare.add(number);
				}
			}
		}
		
		//System.out.println(fairAndSquare.size());

		int noOfCases = in.nextInt();
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			long A = in.nextLong();
			long B = in.nextLong();
			
			int count = fairAndSquare.subSet(A, B+1).size();

			System.out.println("Case #" + caseNo + ": " + count);
			out.println("Case #" + caseNo + ": " + count);
		}
		in.close();
		out.close();

	}

}
