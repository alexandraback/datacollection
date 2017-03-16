import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemB {

	static BufferedWriter out;

	public static void solve(Scanner sc) throws IOException {
		int N = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();

		X = Math.abs(X);
		int row = (X + Y) / 2;
		
		int otherRowsFull = (2 * row - 1) * (2 * row) / 2;
		// surely hit
		if (N >= otherRowsFull + 2 * row + Y + 1) {
			System.out.println("1.0");
			out.write("1.0\n");
			out.flush();
			return;
		}
		// X must be greater than 0 now
		// cannot be hit
		if (N < otherRowsFull + Y + 1) {
			System.out.println("0.0");
			out.write("0.0\n");
			out.flush();
			return;
		}
		
		if (X == 0) {
			if (N == otherRowsFull + 4 * row + 1) {
				System.out.println("1.0");
				out.write("1.0\n");
				out.flush();
				return;
			} else {
				System.out.println("0.0");
				out.write("0.0\n");
				out.flush();
				return;
			}
		}
		
		// remaining stones
		N = N - otherRowsFull;
		
		double notHit = 0;
		for (int i = 0; i < Y + 1; i++) {
			// n choose i / 2^n
			notHit += choose(N, i) / Math.pow(2, N);
		}
		notHit = 1 - notHit;
		System.out.println(notHit);
		out.write(notHit + "\n");
		out.flush();
	}
	
	public static long choose(int N, int K) {
		if (K>N) return 0;
		if (K==N || K == 0) return 1;

		long r = Math.max(K, N-K)+1;

		long d = 2;
		for (long m = (long)r+1; m <= N; m++, d++ ) {
		    r *= m;
		    r /= d;
		}
		return r;
	}

	public static void main(String[] args) throws IOException {
//		System.out.println(choose(5, 0));
//		String name = "B-practice";
//		 String name = "B-small-attempt0";
		 String name = "B-large";
		Scanner sc = new Scanner(new File(name + ".in"));
		sc.useLocale(Locale.US);

		FileWriter fstream = new FileWriter(name + ".out");
		out = new BufferedWriter(fstream);

		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			out.write("Case #" + i + ": ");
			solve(sc);
		}
		sc.close();
	}
}
