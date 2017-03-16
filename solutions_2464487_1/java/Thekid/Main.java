import java.io.*;
import java.math.BigInteger;
import java.util.*;

import com.sun.crypto.provider.RSACipher;

public class Main {
	private static boolean _WRITE_TO_FILE = true;
	private static String _INPUT_FILE = "A-large (1).in";
	private static String _OUTPUT_FILE = "out.txt";
	private static Scanner in;
	private static void core() {
		int ntest = in.nextInt();
		for (int test = 0; test < ntest; test++) {
			writeCase(test);
			long radiusLong = in.nextLong();
			long paintLong = in.nextLong();

			double radius = radiusLong;
			double paint = paintLong;
			double a = 2;
			double b = (2 * radius - 1);
			double c = -paint;
			
			double discriminant = b * b - 4 * a * c;
			double x = (-b + Math.sqrt(discriminant)) / (2 * a);
			
			long res = (long) Math.floor(x);
			while(true) {
				if (good(res, (long) 2, (2 * radiusLong - 1), -paintLong))
					break;
				res = res - 1;
			}
			
			while(good(res + 1, (long) 2, (2 * radiusLong - 1), -paintLong)) {
				res = res + 1;
			}
			
			System.out.println(res);
			System.out.flush();
		}
	}
	private static boolean good(long res, long l, long m, long n) {
		BigInteger a = new BigInteger(l + "");
		BigInteger b = new BigInteger(m + "");
		BigInteger c = new BigInteger(n + "");
		BigInteger x = new BigInteger(res + "");
		
		BigInteger rhs = a.multiply(x).multiply(x);
		rhs = rhs.add(b.multiply(x));
		rhs = rhs.add(c);
		return rhs.compareTo(BigInteger.ZERO) <= 0;
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
