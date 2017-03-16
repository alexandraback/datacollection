import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class D_Small {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "D";
	static final String INPUT = "small";
	static final String ID = "1";
	static final String PATH = "/Users/wangkai/Documents/codejam-commandline-1.2-beta1/source/";

	public static void main(String[] args) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int omino = in.nextInt();
			int row = in.nextInt();
			int col = in.nextInt();

			boolean firstPlayerWin;
			if (omino == 1) {
				firstPlayerWin = false;
			} else if (omino == 2) {
				if (row * col % 2 == 0) {
					firstPlayerWin = false;
				} else {
					firstPlayerWin = true;
				}
			} else if (omino == 3) {
				if (row * col % 3 != 0) {
					firstPlayerWin = true;
				} else if (row == 1 || col == 1) {
					firstPlayerWin = true;
				} else {
					firstPlayerWin = false;
				}
			} else { // omino == 4
				if (row * col % 4 != 0) {
					firstPlayerWin = true;
				} else if (row <= 2 || col <= 2) {
					firstPlayerWin = true;
				} else {
					firstPlayerWin = false;
				}
			}
			out.println(firstPlayerWin ? "RICHARD" : "GABRIEL");
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}
}
