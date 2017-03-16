package gcj2014.round1C;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class C {
	public static void main(String[] args) throws Exception {
		C main = new C("C_sample.txt");
		main.solve();
	}

	private final BufferedReader in;

	public C(String input) throws Exception {
		in = new BufferedReader(new FileReader(this.getClass().getResource(input).getFile()));
	}

	private void solve() throws Exception {
		int T = getInt();
		for (int c = 1; c <= T; c++) {
			int[] n = getInts();
			long ans = solveOne(n[0], n[1], n[2]);
			System.out.println("Case #" + c + ": " + ans);
		}
	}

	private long solveOne(final int N, final int M, final int K) {
		int sum = 0;
		if (N < 3 || M < 3) {
			return K;
		}
		int minStone = Integer.MAX_VALUE;
		for (int i = 3; i <= N; i++) {
			for (int j = 3; j <= M; j++) {
				// solve based on ixj rectangle
				int area = i * j - 4;
				int stones = (i - 2 + j - 2) * 2;
				// System.out.println("stone " + stones + ", area " + area);
				if (area <= K) {
					stones += (K - area);
					if (stones < minStone) {
						minStone = stones;
					}
				}
			}
		}

		return minStone == Integer.MAX_VALUE ? K : minStone;
	}

	/*
	 * File processing
	 */
	private int getInt() throws Exception {
		return Integer.valueOf(in.readLine()).intValue();
	}

	private int[] getInts() throws Exception {
		List<Integer> ints = getIntegers();
		int[] i = new int[ints.size()];
		for (int j = 0; j < ints.size(); j++) {
			i[j] = ints.get(j);
		}
		return i;
	}

	private List<Integer> getIntegers() throws Exception {
		List<Integer> list = new ArrayList<Integer>();
		for (String s : getStrs()) {
			list.add(Integer.valueOf(s));
		}
		return list;
	}

	private List<String> getStrs() throws Exception {
		return Arrays.asList(in.readLine().split(" "));
	}

}
