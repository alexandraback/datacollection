
/**
 * https://code.google.com/codejam/contest/dashboard?c=32003#s=p0
 */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class TheLastWord {
	static String inputFile = "";
	static String outputFile = "";

	static {
		outputFile = "A.out";
	}

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new BufferedReader((new FileReader("/Users/sandz/Downloads/A-small-attempt0.in"))));
		BufferedWriter out = new BufferedWriter(new FileWriter(outputFile));
		int testCases = in.nextInt();
		StringBuilder stringBuilder = new StringBuilder();
		for (int i = 1; i <= testCases; i++) {
			String n = in.next();
			String ans = solve(n);
			stringBuilder.append("CASE #" + (i) + ": " + ans + "\n");
		}
		System.out.println(stringBuilder.toString());
		out.write(stringBuilder.toString());
		out.flush();
		in.close();
		out.close();
	}

	private static String solve(String s) {
		List<Character> cs = new LinkedList<Character>();
		StringBuffer buffer = new StringBuffer();
		char[] c = s.toCharArray();
		char first = c[0];
		cs.add(c[0]);
		for (int i = 1; i < c.length; i++) {
			char curr = c[i];
			if (curr >= first) {
				first = curr;
				cs.add(0, curr);
			} else {
				cs.add(curr);
			}
		}

		for (Character cee : cs) {
			buffer.append(cee);
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