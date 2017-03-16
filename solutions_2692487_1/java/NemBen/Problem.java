import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class Problem {

	public static int calc(int A, int N, int[] motes, int i) {
		// Absorb
		while (i < N && A > motes[i]) {
			A += motes[i];
			++i;
		}

		if (i < N) {
			// Throw away
			int changed2 = 1 + calc(A, N, motes, i + 1);

			// Add
			int changed1 = 0;
			int A2 = A;
			while (A2 <= motes[i]) {
				A2 = A2 + A2 - 1;
				++changed1;
			}
			changed1 += calc(A2, N, motes, i);

			return (changed1 < changed2) ? changed1 : changed2;
		} else {
			return 0;
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
				int A = Integer.parseInt(cols[0]);
				int N = Integer.parseInt(cols[1]);

				int[] motes = new int[N];
				cols = reader.readLine().split("\\s");
				for (int i = 0; i < N; ++i) {
					motes[i] = Integer.parseInt(cols[i]);
				}
				Arrays.sort(motes);

				writer.write("Case #" + n + ": " + ((A == 1) ? N : calc(A, N, motes, 0)));
				writer.newLine();

			}
		} finally {
			writer.close();
			reader.close();
		}
	}

	public static void main(String[] args) throws Exception {
		solve("large");
	}

}
