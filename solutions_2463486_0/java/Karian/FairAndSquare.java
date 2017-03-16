import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


public class FairAndSquare {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// open file and create a buffered reader
		FileReader input = new FileReader(args[0]);
		BufferedReader buffer = new BufferedReader(input);
		
		//read the number of testcases
		int max = Integer.parseInt(buffer.readLine().trim());
		
		generateValidSquares();
		// read a line and call the solving procedure for a single test case.  We expect back the result as a string
		for (int i = 1; i <= max; i++) {
			System.out.println("Case #"+i+": " + solve(buffer.readLine()));
		}
	}

	private static long solve(String input) {
		String[] split = input.split(" ");
		long A = Long.parseLong(split[0]);
		long B = Long.parseLong(split[1]);
		long count = 0;
		int index = 0;
		while (index < list.size() && list.get(index) < A)
		{
			index++;
		}
		while (index < list.size() && list.get(index) <= B)
		{
			count++;
			index++;
		}
		return count;
	}
	
	private static long max = 100000000000000L;
	private static long sqrtMax = 10000000L;
	private static ArrayList<Long> list;
	
	private static void generateValidSquares()
	{
		list = new ArrayList<Long>();
		for(long i = 1; i < sqrtMax; i++)
		{
			long square = i*i;
			if(isPalindrome(String.valueOf(i)) && isPalindrome(String.valueOf(square)))
			{
				list.add(square);
			}
		}
	}

	private static boolean isPalindrome(String str)
	{
		for (int i = 0, j = str.length() - 1; i < j; i++, j--)
		{
			if(str.charAt(i) != str.charAt(j))
			{
				return false;
			}
		}
		return true;
	}
}
