import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemA {

	private static final String PROBLEM_PREFIX = "A";
	
	//private static final String PROBLEM_NAME = PROBLEM_PREFIX + "-test";

	private static final String PROBLEM_NAME = PROBLEM_PREFIX + "-small-attempt0";
	//private static final String PROBLEM_NAME = PROBLEM_PREFIX + "-small-attempt1";
	//private static final String PROBLEM_NAME = PROBLEM_PREFIX + "-small-attempt2";
	//private static final String PROBLEM_NAME = PROBLEM_PREFIX + "-small-attempt3";
	//private static final String PROBLEM_NAME = PROBLEM_PREFIX + "-large";

	public static String solve(String s) {
		String result = "";
		for (char c : s.toCharArray()) {
			if (result.length() == 0 || c >= result.charAt(0)) {
				result = c + result;
			} else {
				result += c;
			}
		}
		return result;
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File(PROBLEM_NAME + ".in"));
		PrintStream out = new PrintStream(new File(PROBLEM_NAME + ".out"));
		try {
			int t = in.nextInt();
			int caseNumber = 1;
			while (caseNumber <= t) {
				String s = in.next();
				out.println("Case #" + caseNumber++ + ": " + solve(s));
			}
		} finally {
			in.close();
			out.close();
		}
	}

}
