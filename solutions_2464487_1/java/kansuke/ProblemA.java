import java.io.*;
import java.util.*;

public class ProblemA {
	static Scanner scan = new Scanner(System.in);
	static PrintStream out = System.out;
	
	static long cal (long n, long r) {
		return 2 * n * r + 2 * n * n - n;
	}
	
	static void test () {
		long r = scan.nextLong(), t = scan.nextLong();
		double shit = (Math.sqrt(8.0*t + (2.0*r-1)*(2.0*r-1))-(2*r-1))/4.0;
		long d1 = (long)shit;
		if (cal (d1, r) <= t) {
			while (d1 < Integer.MAX_VALUE && cal (d1, r) <= t)
				++d1;
			out.println(d1-1);
		} else {
			while (d1 >= 0 && cal (d1, r) > t)
				--d1;
			out.println(d1);
		}
	}
	
	public static void main(String[] args) {
		int T = scan.nextInt();
		for (int i = 1; i <= T; ++i) {
			out.print("Case #" + i + ": ");
			test();
		}
	}
}
