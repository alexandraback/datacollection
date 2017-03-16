import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Diamonds {
	public static int full(int n) {
		return n * (2 *n + 3) + 1;
	}
	
	public static long fac(int n) {
		long r = 1;
		for (int i = 1; i <= n; ++i) {
			r *= i;
		}
		return r;
	}
	
	public static long prob(int n, int h) {
		return fac(n) / (fac(n - h) * fac(h));
	}
	
	public static long pow2(int n) {
		int r = 1;
		for (int i = 0; i < n; ++i) {
			r *= 2;
		}
		return r;
	}
	
	public static float fun(int N, int X, int Y) {
		int w = (X + Y) / 2;
		if (w == 0) {
			return 1f;
		}
		
		if (N >= full(w)) {
			return 1f;
		}
		
		if (N <= full(w - 1)) {
			return 0f;
		}
		
		int n = N - full(w - 1);
		if (n >= Y + 2 * w + 1) {
			return 1f;
		}
		
		if (X == 0 && N < full(w)) {
			return 0f;
		}
		
		int s = 0;
		for (int i = 0; i <= Y; ++i) {
//			System.out.println("P " + N + " " + n + " " + i + " " + prob(n, i));
			s += prob(n, i);
		}
//		System.out.println("S " + s + " " + n);
		return (float)(((double)(pow2(n) - s)) / pow2(n));
	}
	
	public static void main(String[] args) throws IOException {
		String filename = args[0];
		BufferedReader in = new BufferedReader(new FileReader(filename));

		PrintStream out = new PrintStream(filename + ".out");

		int stages = Integer.parseInt(in.readLine());
		
		for (int stage = 1; stage <= stages; ++stage) {
			String[] tokens;
			
			tokens = in.readLine().split("\\s+");
			int N = Integer.parseInt(tokens[0]);
			int X = Integer.parseInt(tokens[1]);
			int Y = Integer.parseInt(tokens[2]);

			out.printf("Case #%d: %06f\n", stage, fun(N, Math.abs(X), Y));
		}
	}

}
