import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	static boolean canWin(int x, int r, int c) {
		if (1 == x) {
			return true;
		} else if (2 == x) {
			return 0 == (r * c) % 2;
		} else if (3 == x) {
			return r >= 2 && c >= 2 && 0 == (r * c) % 3;
		} else if (4 == x) {
			return r > 2 && c > 2 && 0 == (r * c) % 4;
		} else {
			throw new RuntimeException("Unexpected value of X -- " + x);
		}
	}

	public static void main(String args[]) {
		Scanner s = null;
		PrintWriter out = null;

		try {
			String inputFilename;
			if (args.length > 0) {
				inputFilename = args[0];
			} else {
				System.out.print("Input file name: ");
				BufferedReader in = new BufferedReader(new InputStreamReader(
						System.in));
				inputFilename = in.readLine();
			}

			File f = new File("data/" + inputFilename);
			String outputFilename = inputFilename.replaceFirst("(\\.in)?$",
					".out");

			s = new Scanner(new FileReader(f));
			out = new PrintWriter(new FileWriter("data/" + outputFilename));
			int testCases = s.nextInt();
			for (int t = 1; t <= testCases; ++t) {
				int x = s.nextInt();
				int r = s.nextInt();
				int c = s.nextInt();

				boolean result = canWin(x, r, c);

				out.println("Case #" + t + ": "
						+ (result ? "GABRIEL" : "RICHARD"));
			}

			out.close();
			s.close();
		} catch (Exception e) {
			System.err.println(e);
		} finally {
			if (null != out)
				out.close();
			if (null != s)
				s.close();
		}
	}
}
