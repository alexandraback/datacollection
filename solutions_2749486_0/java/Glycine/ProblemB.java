package glycine.gcj2013.rc;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ProblemB {
	static String SPLIT_CHAR = " ";

	static class Solve {
		int targetX, targetY;
		String result = "";
		String plusX = "WE";
		String minusX = "EW";
		String plusY = "SN";
		String minusY = "NS";

		public Solve(String line) {
			String[] tokens = line.split(SPLIT_CHAR);
			targetX = Integer.parseInt(tokens[0]);
			targetY = Integer.parseInt(tokens[1]);
		}

		public void solve() {
			if (targetX > 0) {
				for (int i = 0; i < targetX; ++i) {
					result += plusX;
				}
			} else {
				for (int i = 0; i < -1 * targetX; ++i) {
					result += minusX;
				}
			}
			if (targetY > 0) {
				for (int i = 0; i < targetY; ++i) {
					result += plusY;
				}
			} else {
				for (int i = 0; i < -1 * targetY; ++i) {
					result += minusY;
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		if (args.length != 1) {
			System.err.println("Usage: <program> inputFilename");
			return;
		}
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		String line = reader.readLine();
		int times = Integer.parseInt(line);
		for (int i = 0; i < times; ++i) {
			line = reader.readLine();
			Solve solve = new Solve(line);
			solve.solve();
			System.out.println("Case #" + (i + 1) + ": " + solve.result);
		}

	}
}
