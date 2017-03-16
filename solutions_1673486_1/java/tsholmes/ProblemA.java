import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemA {
	private enum RunType {
		DEBUG, TEST, SMALL, LARGE
	}

	private static RunType runType = RunType.LARGE;

	private static int caseCount;

	public static void main(String[] args) throws Throwable {
		switch (runType) {
		case TEST:
			System.setIn(new FileInputStream("a-test.in"));
			break;
		case SMALL:
			System.setIn(new FileInputStream("a-small.in"));
			System.setOut(new PrintStream(new FileOutputStream("a-small.out")));
			break;
		case LARGE:
			System.setIn(new FileInputStream("a-large.in"));
			System.setOut(new PrintStream(new FileOutputStream("a-large.out")));
			break;
		}

		Scanner in = new Scanner(System.in);

		caseCount = in.nextInt();
		in.nextLine();

		for (int n = 1; n <= caseCount; n++) {
			int A = in.nextInt();
			int B = in.nextInt();
			double[] ps = new double[A];
			for (int i = 0; i < A; i++)
				ps[i] = in.nextDouble();
			String output = "" + solve(A, B, ps);
			System.out.println("Case #" + n + ": " + output);
		}

		System.in.close();
		System.out.close();
	}

	private static double solve(int A, int B, double[] ps) {
		double min = Double.MAX_VALUE;
		min = Math.min(min, retype(A,B,ps));
		min = Math.min(min, attempt(A,B,ps));
		for (int i = 0; i <= A; i++) {
			min = Math.min(min, backspace(A, B, ps, i));
		}
		return min;
	}
	
	private static double retype(int A, int B, double[] ps) {
		return 2 + B; // enter to restart, all character, enter to submit
	}
	
	private static double attempt(int A, int B, double[] ps) {
		double finish = B - A + 1; // enter plus remaining characters
		double correctchance = 1.0;
		for (int i = 0; i < A; i++) {
			correctchance *= ps[i];
		}
		return (finish * correctchance) + (finish + B + 1) * (1 - correctchance);
	}
	
	private static double backspace(int A, int B, double[] ps, int num) {
		double finish = B - A + 1 + 2 * num;
		double correctchance = 1.0;
		for (int i = 0; i < A - num; i++) {
			correctchance *= ps[i];
		}
		return (finish * correctchance) + (finish + B + 1) * (1 - correctchance);
	}

}
