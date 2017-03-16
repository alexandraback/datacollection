import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;




public class FairAndSquare {

	public static boolean isPalindrome(long number)
	{
		char[] numberString = Long.toString(number).toCharArray();
		int lengthNumberString = numberString.length;
		
		for (int i = 0; i < lengthNumberString/2; i++)
		{
			if (numberString[i] != numberString[lengthNumberString - (i + 1)])
			{
				return false;
			}
		}
		return true;
	}
	
	public static ArrayList<Long> fairAndSquare(long maximum)
	{
		ArrayList <Long> fairAndSquares = new ArrayList<Long>();
		for (long i = 1; i < maximum; i++)
		{
			if (isPalindrome(i))
			{
				long product = i * i;
				if (isPalindrome(product))
				{
					fairAndSquares.add(product);
				}
			}
		}
		return fairAndSquares;
	}
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader in
		   = new BufferedReader(new FileReader("/Users/aniket/Desktop/C-large-1.in.txt"));
		PrintWriter out
		   = new PrintWriter(new BufferedWriter(new FileWriter("/Users/aniket/Desktop/C-large-1-answers.in.txt")));
		ArrayList<Long> results = fairAndSquare(10000000); // Will give me products upto 10^14
		int caseCounter = 1;
		String line = null;
		boolean ignoreFirstLine = true;
		while( (line = in.readLine()) != null)
		{
			if(ignoreFirstLine)
			{
				ignoreFirstLine = false;
				continue;
			}
			line = line.trim();
			long startPoint = Long.parseLong(line.split(" ")[0]);
			long finishPoint = Long.parseLong(line.split(" ")[1]);
			long totalCount = 0;
			for(int i = 0; i < results.size(); i++)
			{
				if (results.get(i) >= startPoint && results.get(i) <= finishPoint)
				{
					totalCount ++;
				}
			}
			out.write("Case #" + Integer.toString(caseCounter) + ": " + Long.toString(totalCount) + "\n");
			caseCounter ++;
		}
		in.close();
		out.flush();
		out.close();
		System.out.println("Program completed successfully!");
	}
}
