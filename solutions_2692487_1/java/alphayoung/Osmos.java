package codejam13;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class Osmos {
	private Integer[] minOps = null;

	public void solve(String input, String output) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(input));
		BufferedWriter out = new BufferedWriter(new FileWriter(output));
		String line = in.readLine();
		int T = Integer.parseInt(line);
		int index = 1;

		while (T > 0) {
			String[] dims = in.readLine().split(" ");
			int A = Integer.parseInt(dims[0]);
			int N = Integer.parseInt(dims[1]);

			dims = in.readLine().split(" ");
			int[] motes = new int[N];
			minOps = new Integer[N + 1];
			minOps[N] = 0;
			for (int i = 0; i < N; ++i) {
				motes[i] = Integer.parseInt(dims[i]);
			}

			int result = getNumOperations(A, N, motes);

			out.write("Case #" + index + ": " + result);
			out.newLine();

			--T;
			++index;
		}

		in.close();
		out.close();
	}

	private int getNumOperations(int A, int N, int[] motes) {
		long current = A;
		if (current == 1) {
			return N;
		}
		Arrays.sort(motes);
		return getNumRec(current, 0, N, motes);
	}

	private int getNumRec(long cur, int index, int N, int[] motes) {
		if (minOps[index] == null) {
			if (cur > motes[index]) {
				minOps[index] = getNumRec(cur + motes[index], index + 1, N,
						motes);
			} else {
				minOps[index] = Math.min(
						getNumRec(cur * 2 - 1, index, N, motes) + 1,
						N - index);
			}
		}
		return minOps[index];
	}
}
