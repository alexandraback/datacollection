import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;


public class NewLotteryGame {

	/**
	 * @param args input arguments.  First and only expected parameter is the input filename
	 * 
	 * for the output, everything is printed to screen, and piped to a file.
	 * Input is expected to be correct and don't foresee any error handling for wrong input.
	 * 
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// open file and create a buffered reader
		FileReader input = new FileReader(args[0]);
		BufferedReader buffer = new BufferedReader(input);
		
		//read the number of testcases
		int max = Integer.parseInt(buffer.readLine().trim());
		
		// read a line and call the solving procedure for a single test case.  We expect back the result as a string
		for (int i = 1; i <= max; i++) {
			System.out.println("Case #"+i+": " + solve(buffer.readLine()));
		}

	}

	private static String solve(String input) {
		String[] split = input.split("\\s+");
		int A = Integer.parseInt(split[0]);
		int B = Integer.parseInt(split[1]);
		int K = Integer.parseInt(split[2]);
		
		// brute force for small input
		
		int count = 0;
		
		for(int a = 0; a < A; a++)
		{
			for(int b = 0; b < B; b++)
			{
				if((a&b) < K)
				{
					count++;
				}
			}
		}
		
		return String.valueOf(count);
	}

}
