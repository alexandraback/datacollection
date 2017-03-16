package googlecodejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class Pogo {
	public static void main(String[] args) throws Exception {
		File f = new File("/Users/peter/Downloads/B-small-attempt1.in");
		BufferedReader br = new BufferedReader(new FileReader(f));

		String outputFile = f.getName().substring(0, f.getName().lastIndexOf('.')) + ".out";
		PrintStream ps = new PrintStream(new File(f.getParent(), outputFile));
		// PrintStream ps = System.out;

		int N = Integer.parseInt(br.readLine());

		for (int caseCount = 1; caseCount <= N; caseCount++) {
			String line = br.readLine();

			int x = Integer.valueOf(line.split(" ")[0]);
			int y = Integer.valueOf(line.split(" ")[1]);

			String solution = calculateValue(x, y);

			System.out.print("Case #" + caseCount + ": ");
			ps.print("Case #" + caseCount + ": ");

			System.out.print("" + solution);
			ps.print("" + solution);

			System.out.println();
			ps.println();
		}

		br.close();
		ps.close();
	}

	private static String calculateValue(int x, int y) {
		String result = "";

		if (x > 0) {
			for(int i = 0; i < x; i++) {
				result += "WE";
			}
		} else if (x < 0) {
			for(int i = 0; i < Math.abs(x); i++) {
				result += "EW";
			}
		}

		if (y > 0) {
			for(int i = 0; i < y; i++) {
				result += "SN";
			}
		} else if (y < 0) {
			for(int i = 0; i < Math.abs(y); i++) {
				result += "NS";
			}
		}

		return result;
	}

	private static class Option {
		public Option(String option, int x, int y) {
			this.path = option;
			this.x = x;
			this.y = y;
		}

		public String path;
		public int x;
		public int y;

		@Override
		public String toString() {
			return "Option(" + path + "," + x + "," + y + ")";
		}

		@Override
		public boolean equals(Object o) {
			return ((Option) o).x == x && ((Option) o).y == y;
		}
	}
}
