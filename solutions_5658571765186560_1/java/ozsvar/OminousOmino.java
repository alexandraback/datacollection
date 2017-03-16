import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class OminousOmino {

	class TestCase {

		TestCase(int x, int r, int c) {
			this.X = x;
			this.R = r;
			this.C = c;
		}

		public int X;
		public int R;
		public int C;
	};

	List<Boolean> winner = new ArrayList<Boolean>();
	List<TestCase> testCases = new ArrayList<TestCase>();

	/*
	 * Read file method
	 */
	public void readFile(String fileName) {
		Scanner scanner;
		try {
			scanner = new Scanner(new File(fileName));

			int testCaseNumber = scanner.nextInt();

			scanner.nextLine();
			for (int i = 0; i < testCaseNumber; ++i) {

				int x = scanner.nextInt();
				int r = scanner.nextInt();
				int c = scanner.nextInt();

				TestCase t = new TestCase(x, r, c);
				testCases.add(t);

			}

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}

	/*
	 * Write file method
	 */
	public void writeFile(String fileName) {
		PrintWriter writer;
		try {
			writer = new PrintWriter(fileName);

			int counter = 0;
			for (boolean res : winner) {
				String name = res ? "GABRIEL" : "RICHARD";
				writer.print("Case #" + (++counter) + ": " + name);
				if (counter < winner.size()) {
					writer.println();
				}
			}

			writer.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}

	public void solve() {
		for (TestCase t : testCases) {

			boolean wins = true;

			if (t.X >= 7) {
				wins = false;
			} else if (t.X > t.R && t.X > t.C) {
				wins = false;
			} else if (t.R * t.C % t.X != 0) {
				wins = false;
			} else if (((t.X + 1) / 2) > Math.min(t.R, t.C)) {
				wins = false;
			} else if (1 <= t.X && t.X <= 3) {
				wins = true;
			} else if (t.X == 4) {
				wins = Math.min(t.R, t.C) > 2 ? true : false;
			} else if (t.X == 5) {
				wins = !((Math.min(t.R, t.C) == 3 ? true : false) && (Math.max(
						t.R, t.C) == 5 ? true : false));
			} else if (t.X == 6) {
				wins = Math.min(t.R, t.C) > 3;
			}

			winner.add(wins);
		}
	}

	public static void main(String[] args) {
		OminousOmino oo = new OminousOmino();

		oo.readFile("D-large.in");

		oo.solve();

		oo.writeFile("D-large.out");
	}

}
