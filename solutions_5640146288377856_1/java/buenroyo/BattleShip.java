package R1C;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class BattleShip {

	public static int numCase = 0;
	public static Scanner in;

	private static void solve() {
		int r = in.nextInt();
		int c = in.nextInt();
		int w = in.nextInt();

		long numOfShoots = getMinShoots(r, c, w);

		printTestCase(numOfShoots);
	}

	private static long getMinShoots(int r, int c, int w) {
		long shoots = 0;

		if (w == 1) {
			shoots = r * c;
		} else if (w == c) {
			shoots = r - 1 + c;
		} else if (r == 1) {
			int half = (c - 1) / w;
			shoots = half + w;
		} else {
			int half = (c - 1) / w;
			shoots += half * r;
			shoots += w;
		}

		return shoots;
	}

	private static void printTestCase(final long result) {
		System.err.println("Case #" + numCase + ": " + result);
		System.out.println("Case #" + numCase + ": " + result);
	}

	public static void main(final String[] args) {
		try (FileInputStream input = new FileInputStream("in.txt")) {
			System.setIn(input);
			System.setOut(new PrintStream(new FileOutputStream("out.txt")));
			in = new Scanner(System.in);
			int numCases = in.nextInt();
			in.nextLine();
			for (numCase = 1; numCase <= numCases; numCase++) {
				solve();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}