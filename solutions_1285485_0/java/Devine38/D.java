import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Mark Devine
 * 
 */
public class D {
	static final boolean DEBUG = false;
	static Scanner in;
	static PrintStream out;

	public static void main(String[] args) throws FileNotFoundException {
		if (DEBUG) {
			in = new Scanner(new File("t"));
			out = System.out;
		} else {
			in = new Scanner(new File(D.class.getName() + ".in"));
			out = new PrintStream(D.class.getName() + ".out");
		}
		int T = i();
		for (int i = 0; i < T; i++) {
			pl(f("Case #%d: %s", i + 1, solve()));
		}
		out.close();
		in.close();
		System.out.println("Done");
	}

	static String solve() {
		int H = i();
		int W = i();
		int D = i();

		li();

		int x = -1;
		int y = -1;

		for (int i = 0; i < H; i++) {
			char[] row = li().toCharArray();
			for (int j = 0; j < W; j++) {
				if (row[j] == 'X') {
					x = j;
					y = i;
				}
			}
		}

		// Distances to walls
		double north = y + 0.5 - 1;
		double east = W - (x + 0.5) - 1;
		double south = H - (y + 0.5) - 1;
		double west = x + 0.5 - 1;

		long count = 0;

		for (int n = 0;; n++) {
			double dist;
			int down = n / 2;
			int up = n - down;
			double vert = up * north + down * south;
			dist = 2 * Math.sqrt(east*east + vert*vert);
			if (dist > D) {
				break;
			} else {
//				pl("" + dist);
				count++;
			}
		}
		for (int n = 0;; n++) {
			double dist;
			int down = n / 2;
			int up = n - down;
			double vert = up * west + down * east;
			dist = 2 * Math.sqrt(north*north + vert*vert);
			if (dist > D) {
				break;
			} else {
//				pl("" + dist);
				count++;
			}
		}
		for (int n = 0;; n++) {
			double dist;
			int down = n / 2;
			int up = n - down;
			double vert = up * south + down * north;
			dist = 2 * Math.sqrt(west*west + vert*vert);
			if (dist > D) {
				break;
			} else {
//				pl("" + dist);
				count++;
			}
		}
		for (int n = 0;; n++) {
			double dist;
			int down = n / 2;
			int up = n - down;
			double vert = up * east + down * west;
			dist = 2 * Math.sqrt(south*south + vert*vert);
			if (dist > D) {
				break;
			} else {
//				pl("" + dist);
				count++;
			}
		}
//		pl(f("n%f e%f s%f w%f", north, east, south, west));
		return count + "";
	}

	static void p(String x) {
		out.print(x);
	}

	static void pl(String x) {
		out.println(x);
	}

	static String f(String format, Object... args) {
		return String.format(format, args);
	}

	static int i() {
		return in.nextInt();
	}

	static long l() {
		return in.nextLong();
	}

	static String s(String pattern) {
		return in.next(pattern);
	}

	static String li() {
		return in.nextLine();
	}
}