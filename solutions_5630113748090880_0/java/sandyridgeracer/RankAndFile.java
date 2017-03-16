
/**
 * https://code.google.com/codejam/contest/dashboard?c=32003#s=p0
 */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class RankAndFile {
	static String inputFile = "";
	static String outputFile = "";
	static Scanner in;

	static {
		outputFile = "B.out";
	}

	public static void main(String[] args) throws IOException {
		in = new Scanner(new BufferedReader((new FileReader("/Users/sandz/Downloads/B-small-attempt0.in"))));
		BufferedWriter out = new BufferedWriter(new FileWriter(outputFile));
		int testCases = in.nextInt();
		StringBuilder stringBuilder = new StringBuilder();
		for (int i = 1; i <= testCases; i++) {
			int n = in.nextInt();
			String ans = solve(n);
			stringBuilder.append("CASE #" + (i) + ": " + ans + "\n");
		}
		System.out.println(stringBuilder.toString());
		out.write(stringBuilder.toString());
		out.flush();
		in.close();
		out.close();
	}

	private static String solve(int n) {
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				int row = in.nextInt();
				Integer count = map.get(row);
				if (count == null) {
					count = 0;
				}
				map.put(row, ++count);
			}
		}
		List<Integer> x = new LinkedList<Integer>();
		for (Integer key : map.keySet()) {
			int count = map.get(key);
			if (count % 2 == 1) {
				x.add(key);
			}
		}
		Collections.sort(x);

		StringBuffer buffer = new StringBuffer();
		for (Integer integer : x) {
			buffer.append(integer + " ");
		}
		return buffer.toString();
	}

	static long[] primeDivisiors(String s) {
		long divisors[] = new long[9];
		for (int i = 2; i <= 10; i++) {
			System.out.println(i);
			long n = (Long.parseLong(s, i));
			long di = findDivisors(n);
			if (di == -1)
				return null;
			divisors[i - 2] = di;
		}
		return divisors;
	}

	static long findDivisors(long n) {
		for (long i = 2; i <= Math.sqrt(n) + 1; i++) {
			if (n % i == 0) {
				return i;
			}
		}
		return -1;
	}

	static void flip(char[] x, int end) {
		for (int i = 0; i < end; i++) {
			x[i] = x[i] == '-' ? '+' : '-';
		}
	}

}