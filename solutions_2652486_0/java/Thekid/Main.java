import java.io.*;
import java.util.*;

import javax.annotation.Generated;

public class Main {
	private static boolean _WRITE_TO_FILE = true;
	private static String _INPUT_FILE = "C-small-1-attempt0.in";
	private static String _OUTPUT_FILE = "out.txt";
	private static Scanner in;
	private static void core() {
		int ntest = in.nextInt();
		for (int test = 0; test < ntest; test++) {
			writeCase(test);
			System.out.println();
			int nSet = in.nextInt();
			int n = in.nextInt();
			int m = in.nextInt();
			int length = in.nextInt();
			for (int i = 0; i < nSet; i++) {
				int[] a = new int[length];
				for (int j = 0; j < a.length; j++) {
					a[j] = in.nextInt();
				}
				String string = solve(a);
				System.out.println(string);
			}
			System.out.flush();
		}
	}
	private static String solve(int[] array) {
		for (int a = 2; a <= 5; a++) {
			for (int b = a; b <= 5; b++) {
				for (int c = b; c <= 5; c++) {
					HashSet<Integer> set = generate(a, b, c);
					boolean flag = true;
					for (int k : array) {
						flag &= set.contains(k);
					}
					if (flag)
						return "" + a + b + c;
				}
			}
		}
		return "";
	}
	private static HashSet<Integer> generate(int a, int b, int c) {
		HashSet<Integer> res = new HashSet<Integer>();
		res.add(1);
		res.add(a); res.add(b); res.add(c);
		res.add(a * b); res.add(b * c); res.add(c * a);
		res.add(a * b * c);
		return res;
	}
	private static void writeCase(int test) {
		System.out.printf("Case #%d: ", test+1);
	}
	static void debug(Object...os) {
		System.out.println(Arrays.deepToString(os));
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(_INPUT_FILE));
		if (_WRITE_TO_FILE) 
			System.setOut(new PrintStream(new BufferedOutputStream(
					new FileOutputStream(_OUTPUT_FILE))));
		in = new Scanner(System.in);
		core();
		System.out.close();
	}
	static class Scanner {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public Scanner(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
			tokenizer = new StringTokenizer("");
		}
		public String next() {
			try {
				while(!tokenizer.hasMoreElements())
					tokenizer = new StringTokenizer(reader.readLine());
				return tokenizer.nextToken();
			} catch (Exception e) {
				e.printStackTrace();
				throw new RuntimeException(e);
			}
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
