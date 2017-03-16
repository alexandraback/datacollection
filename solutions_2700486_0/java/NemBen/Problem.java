import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class Problem {

	static long cmb(int A, int B) {
		long nom = 1L;
		long denom = 1L;
		for (int i = 0; i < B; ++i) {
			nom *= (A - i);
			denom *= (i + 1);
		}
		return nom / denom;
	}

	static int getSum(int ring) {
		return ring * (2 * ring - 1);
	}

	static int getRing(int X, int Y) {
		if (X <= 0) {
			return (Y - X) / 2 + 1;
		} else {
			return (X + Y) / 2 + 1;
		}
	}

	static double calc(int N, int X, int Y) {
		int ring = getRing(X, Y);
		int ringSum = getSum(ring);
		if (N >= ringSum) {
			return 1.0d;
		} else {
			if (X == 0) {
				return 0.0d;
			} else {
				int rem = N - getSum(ring - 1);
				int pos = Y + 1;
				int height = (ring - 1) * 2;

				if (rem < pos) {
					return 0.0d;
				} else if (rem >= height + pos) {
					return 1.0d;
				} else {
					long all = 0L;
					long good = 0L;
					if (rem <= height) {
						all = 1L << rem;

						for (int i = pos; i <= rem; ++i) {
							good += cmb(rem, i);
						}
					} else {
						for (int i = rem - height; i <= height; ++i) {
							all += cmb(rem, i);
						}

						for (int i = pos; i <= height; ++i) {
							good += cmb(rem, i);
						}
					}

					// if (rem > height) {
					// System.out.println(rem + ", " + height + ", " + pos);
					// System.out.println(good + " / " + all + " = " +
					// (((double) good) / ((double) all)));
					// }

					return ((double) good) / ((double) all);
				}
			}
		}
	}

	public static void solve(String file) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(new File("./" + file + ".in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("./" + file + ".out"), false));

		try {
			int num = Integer.parseInt(reader.readLine());

			String[] cols;
			for (int n = 1; n <= num; ++n) {
				cols = reader.readLine().split("\\s");
				int N = Integer.parseInt(cols[0]);
				int X = Integer.parseInt(cols[1]);
				int Y = Integer.parseInt(cols[2]);

				writer.write("Case #" + n + ": " + String.format("%.8f", calc(N, X, Y)));
				writer.newLine();

			}
		} finally {
			writer.close();
			reader.close();
		}
	}

	public static void main(String[] args) throws Exception {
		solve("small6");
	}

}
