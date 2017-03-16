import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class D {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner console = new Scanner(new File("D-small-attempt0.in"));
		PrintStream output = new PrintStream(new File("D1.txt"));
		int caseNum = console.nextInt();
		for (long i = 1; i <= caseNum; i++) {
			int X = console.nextInt();
			int R = console.nextInt();
			int C = console.nextInt();
			output.println("Case #" + i + ": " + result(X, R, C));

		}
	}

	public static String result(int x, int r, int c) {
		if (x <= 6) {
			if (x == 1) {
				return "GABRIEL";
			} else {
				if ((r % x != 0) && (c % x != 0)) {
					return "RICHARD";
				} else {
					if (r % x != 0) {
						int temp = c;
						c = r;
						r = temp;
					}
					if (x == 6) {
						if (c >= 4) {
							return "GABRIEL";
						}
					} else {
						if (c >= x - 1) {
							return "GABRIEL";
						}
					}
				}
			}
		}
		return "RICHARD";
	}
}