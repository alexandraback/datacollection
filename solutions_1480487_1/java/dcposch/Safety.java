package r1b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;

public class Safety {
	final BufferedReader reader;
	final PrintStream writer;

	double[] solve(int[] points) {
		int n = points.length;
		double[] ret = new double[n];

		int x = 0;
		for (int i = 0; i < n; i++)
			x += points[i];

		for (int i = 0; i < n; i++) {
			int[] other = new int[n - 1];
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				other[(j > i) ? (j - 1) : j] = points[j] - points[i];
			}
			Arrays.sort(other);

			int cumSum = 0;
			double pMin = 0;
			for (int j = 0; j < n - 1; j++) {
				cumSum += other[j];

				// (cumSum + (1-pMin)x)/k < pMin*x
				// cumSum < k*pMin*x + (pMin-1)x
				// cumSum < k*pmin*x + pmin*x - x
				// (cumSum+x)/((k+1)x) < pMin
				pMin = (double) (cumSum + x) / ((j + 2) * x);

				// pMin defeats up thru and including (j)
				// ... does it defeat everyone??
				if (j < n - 2 && pMin * x <= other[j + 1])
					break;
			}
			ret[i] = pMin < 0 ? 0 : pMin * 100;
		}

		/*double sum = 0.0;
		for (int i = 0; i < n; i++)
			sum += ret[i];
		for (int i = 0; i < n; i++)
			ret[i] = 100.0 * ret[i] / sum;*/

		return ret;
	}

	/**
	 * Just IO
	 */
	void run() {
		int ncases = readInt();
		for (int ncase = 1; ncase <= ncases; ncase++) {
			int[] ns = readInts();
			int[] points = new int[ns.length - 1];
			for (int i = 1; i < ns.length; i++)
				points[i - 1] = ns[i];
			double[] ans = solve(points);
			String line = "Case #" + ncase + ":";
			for (int i = 0; i < ans.length; i++) {
				line += " " + ans[i];
			}
			if (writer != null) {
				writer.println(line);
			}
			System.out.println(line);
		}
	}

	int readInt() {
		try {
			return Integer.parseInt(reader.readLine());
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	int[] readInts() {
		try {
			String[] parts = reader.readLine().split(" ");
			int[] ret = new int[parts.length];
			for (int i = 0; i < parts.length; i++) {
				ret[i] = Integer.parseInt(parts[i]);
			}
			return ret;
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	Safety(String input, String output) {
		InputStream inputStream = this.getClass().getResourceAsStream(input);
		reader = new BufferedReader(new InputStreamReader(inputStream));
		if (output == null) {
			writer = null;
		} else {
			try {
				writer = new PrintStream(output);
			} catch (Exception e) {
				throw new RuntimeException(e);
			}
		}
	}

	public static void main(String[] args) {
		try {
			new Safety("A-large.in", "C:/workspace/codejam/src/r1b/A-large.out").run();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
