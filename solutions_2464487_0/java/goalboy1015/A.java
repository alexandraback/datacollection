import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "A";
	static final String INPUT = "small";
	static final String ID = "0";
	static final String PATH = "C:\\software installation\\codejam-commandline-1.2-beta1\\source\\";

	public static void main(String args[]) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int radius = in.nextInt();
			int paint = in.nextInt();
			boolean black = true;
			int circle = 0;
			while (true) {
				if (black) {
					int needed = 2 * radius + 1;
					if (needed > paint) {
						break;
					}
					paint -= needed;
					circle++;
				}
				radius++;
				black = !black;
			}
			out.println(circle);
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}
}
