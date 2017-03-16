import java.util.*;
import java.io.*;

public class ProblemA {

	private static final String IN_DIR = "inputs";
	private static final String OUT_DIR = "outputs";

	private static final String IN_FILE = "A-small-attempt0.in";
	private static final String OUT_FILE = "output_a.txt";
	
	public static void main(String[] args) {
		Scanner sc = null;
		BufferedWriter out = null;

		try {
			sc = new Scanner(new File(IN_DIR + "/" + IN_FILE));
			out = new BufferedWriter(new FileWriter(OUT_DIR + "/" + OUT_FILE));
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		int numTests = sc.nextInt();
		sc.nextLine();
		try {
			for (int i = 0; i < numTests; i++) {
				handleTest(sc, out, i+1);
			}

			// clean up
			sc.close();
			out.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static void handleTest(Scanner sc, BufferedWriter out, int caseNum) throws IOException {
		int r = sc.nextInt();
		int t = sc.nextInt();
		double disc = (2*r-1) * (2*r-1) + 8*t;
		double soln = ((1 - 2*r) + Math.sqrt(disc)) / 4;
		double dfloor = Math.floor(soln);
		
		int floor = (int) dfloor - 1;
		int result = floor;
		for (int i = 1; i <= 2; i++) {
			if (numCircles(floor + i, r) <= t) {
				result = floor + i;
			}
		}		
		out.write("Case #" + caseNum + ": " + result + '\n');
	}

	private static int numCircles(int k, int r) {
		return 2 * k * k + 2 * r * k - k;
	}
	
}
