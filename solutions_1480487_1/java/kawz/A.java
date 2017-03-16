package gcj2012.round1B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 2012 Code Jam Round 1B
 * 
 * @author kawabon
 * 
 */
public class A {
	public static void main(String[] args) throws Exception {
		A main = args.length > 0 ? new A(args[0]) : new A(A.class.getSimpleName() + ".in");
		main.solve();
	}

	private final BufferedReader in;

	public A(String input) throws Exception {
		in = new BufferedReader(new FileReader(this.getClass().getResource(input).getFile()));
	}

	private void solve() throws Exception {
		int T = getInt();
		for (int c = 1; c <= T; c++) {
			List<Integer> ints = getIntegers();
			int n = ints.remove(0);
			String ans = solveOne(n, ints);
			System.out.println("Case #" + c + ":" + ans);
		}
	}

	private String solveOne(int n, List<Integer> s) {
		double sum = 0;

		for (Integer i : s) {
			sum += i.intValue();
		}
		double target = sum * 2.0 / n;

		double passed = 0;
		double passSum = 0;
		StringBuilder answer = new StringBuilder();
		for (Integer i : s) {
			if (i.intValue() > target) {
				passed++;
				passSum += i.intValue();
			}
		}
		double actualTarget = (2 * sum - passSum) / (n - passed);

		for (Integer i : s) {
			double num;
			if (i.intValue() > target) {
				num = 0;
			} else {
				num = Math.round((actualTarget - i.intValue()) * 100000000D / (sum)) / 1000000D;
				if (num < 0) {
					num = 0;
				}
			}
			answer.append(" " + String.format("%6f", num));
		}
		return answer.toString();
	}

	/*
	 * File processing
	 */
	private int getInt() throws Exception {
		return Integer.valueOf(in.readLine()).intValue();
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
