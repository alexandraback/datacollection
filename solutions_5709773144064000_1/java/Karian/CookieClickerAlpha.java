import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;


public class CookieClickerAlpha {

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
		double C = Double.parseDouble(split[0]);
		double F = Double.parseDouble(split[1]);
		double X = Double.parseDouble(split[2]);
		
		double speed = 2.0;
		double buildphase = 0.0;

		double best = X/speed;
		
		while (buildphase < best)
		{
			buildphase += C/speed;
			speed += F;
			double time = buildphase + X/speed;
			best = Math.min(best, time);
		}
		
		DecimalFormat df = new DecimalFormat("0.0000000");
		return new String("" + df.format(best));
	}

}
