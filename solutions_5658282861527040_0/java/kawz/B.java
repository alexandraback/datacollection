package gcj2014.round1B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class B {
	public static void main(String[] args) throws Exception {
		B main = new B("B_sample.txt");
		main.solve();
	}

	private final BufferedReader in;

	public B(String input) throws Exception {
		in = new BufferedReader(new FileReader(this.getClass().getResource(input).getFile()));
	}

	private void solve() throws Exception {
		int T = getInt();
		for (int c = 1; c <= T; c++) {
			int[] y = getInts();
			int ans = solveOne(y[0], y[1], y[2]);
			System.out.println("Case #" + c + ": " + ans);
		}
	}

	private int solveOne(int A, int B, int K) {
		int sum = 0;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				if ((i & j) < K) {
					sum++;
				}
			}
		}
		return sum;
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
