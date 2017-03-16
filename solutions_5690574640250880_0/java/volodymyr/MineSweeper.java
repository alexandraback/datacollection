import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class MineSweeper {
	private static InputStream in;
	private static PrintStream out;
	private static Scanner sc;
	static {
		try {
			in =
			 new FileInputStream("C-small-attempt3.in");
//			System.in;
			out =
			 new PrintStream(new FileOutputStream("out.txt"));
//			System.out;
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		sc = new Scanner(in);
		int numCases = sc.nextInt();
		for (int i = 0; i < numCases; i++) {
			out.println("Case #" + (i + 1) + ": ");
			solve();
		}
	}

	private static void solve() {
		int r = sc.nextInt();
		int c = sc.nextInt();

		int m = sc.nextInt();

		boolean possible;
		int numBlanks;
		if (r == 1) {
			possible = true;
			numBlanks = c - m;
		} else if (c == 1) {
			possible = true;
			numBlanks = r - m;
		} else {
			possible = m == 0 || ((r * c - m) >= 4) || ((r * c - m) == 1);
			numBlanks = r * c - m;
		}

		if (!possible) {
			out.println("Impossible");
			return;
		}

		int numCorners = 0;
		int coveredByCorners = 0;
		int nextCorner = 1;
		while (coveredByCorners < numBlanks) {
			coveredByCorners += nextCorner;
			numCorners++;
			if (numCorners > r || numCorners > c
					|| coveredByCorners > numBlanks) {
				coveredByCorners -= nextCorner;
				numCorners--;
				break;
			}

			nextCorner += 2;
		}

		int right = 0;
		int down = 0;
		int blanksLeft = numBlanks - coveredByCorners;

		int lastLeft = 0;

		if (numCorners == r) {
			right = blanksLeft / r;
			lastLeft = blanksLeft % r;

		} else if (numCorners == c) {
			down = blanksLeft / c;
			lastLeft = blanksLeft % c;
		} else {
			lastLeft = blanksLeft;
		}

		int tradeX = -1;
		int tradeY = -1;
		if (lastLeft == 1 || lastLeft == numCorners + 1) {
			if (down == 0 && right == 0) {
				tradeX = tradeY = numCorners - 1;
				if (lastLeft == numCorners + 1) {
					tradeX++;
					lastLeft--;
					if(tradeY<=1){
						out.println("Impossible");
						return;
					}
				}
			} else if (right > 0) {
				tradeX = numCorners + right - 1;
				tradeY = r - 1;
				if (r == 2) {
					out.println("Impossible");
					return;
				}
			} else {
				tradeY = numCorners + down - 1;
				tradeX = c - 1;
				if (c == 2) {
					out.println("Impossible");
					return;
				}
			}
			lastLeft++;
		}
		if (((tradeX <= 1 && tradeX >= 0) && (tradeY <= 1 && tradeY >= 0))) {
			out.println("Impossible");
			return;
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (i == 0 && j == 0) {
					out.print("c");
					continue;
				}
				if (i == tradeY && j == tradeX) {
					out.print("*");
					continue;
				}
				if (i < numCorners && j < numCorners) {
					out.print(".");
					continue;
				}

				if ((down > 0 && i < numCorners + down)
						|| (right > 0 && j < numCorners + right)) {
					out.print(".");
					continue;
				}

				if (down > 0 && lastLeft > 0) {
					out.print(".");
					lastLeft--;
					continue;
				}
				if (right > 0 && lastLeft > 0 && j == (numCorners + right)) {
					out.print(".");
					lastLeft--;
					continue;
				}

				if (lastLeft > 0) {
					if (j <= numCorners + right) {

						// if (i == numCorners + down && (j + lastLeft >
						// numCorners)) {
						// out.print("*");
						// continue;
						// }
						out.print(".");
						lastLeft--;
						continue;
					}
				}

				out.print("*");
			}
			out.println();
		}

	}
}
