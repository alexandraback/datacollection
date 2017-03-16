import java.util.*;
import java.io.*;

public class ProblemB {

	private static final String IN_DIR = "inputs";
	private static final String OUT_DIR = "outputs";

	private static final String IN_FILE = "B-small-attempt0.in";
	private static final String OUT_FILE = "output_b.txt";
	
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
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		String xDir = x > 0 ? "WE" : "EW";
		String yDir = y > 0 ? "SN" : "NS";
		
		x = Math.abs(x);
		y = Math.abs(y);
		
		String result = "";
		for (int i = 0; i < x; i++) {
			result += xDir;
		}		
		for (int i = 0; i < y; i++) {
			result += yDir;
		}
		
		out.write("Case #" + caseNum + ": " + result + '\n');
	}
	
}
