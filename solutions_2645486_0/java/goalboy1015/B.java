import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class B {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "B";
	static final String INPUT = "small";
	static final String ID = "0";
	static final String PATH = "C:\\software installation\\codejam-commandline-1.2-beta1\\source\\";

	static int E;
	static int R;
	static int values[];
	static int maxGain;

	public static void main(String args[]) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			E = in.nextInt();
			R = in.nextInt();
			int N = in.nextInt();
			values = new int[N];
			for (int i = 0; i < values.length; i++) {
				values[i] = in.nextInt();
			}

			maxGain = 0;
			search(0, E, 0);

			out.println(maxGain);
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static void search(int index, int energy, int totalGain) {
		if (index == values.length) {
			maxGain = Math.max(maxGain, totalGain);
			return;
		}
		for (int i = 0; i <= energy; i++) {
			search(index + 1, Math.min(E, energy - i + R), totalGain + i
					* values[index]);
		}
	}
}
