import java.util.*;
import java.io.*;

/**
  * @author Mighty Cohadar 
  */
public class Alfa {

	public static void extract(boolean[] B, long p) {
		for (char c : String.valueOf(p).toCharArray()) {
			B[c - '0'] = true;
		}
	}

	public static boolean all(boolean[] B) {
		for (boolean b : B) {
			if (b == false) {
				return false;
			}
		}
		return true;
	}

	static int max = 0;

	public static String solve(int n) {
		long p = n;
		boolean[] B = new boolean[10];
		// max iteration found to be 71 by empiric study.
		// we are using 100 just in case.
		for (int i = 0; i < 100; i++) {
			assert p >= 0 : "overflow for: n=" + n;
			extract(B, p);	
			if (all(B)) {
				if (max < i) {
					max = i;
				}
				return String.valueOf(p);
			}
			p += n;
		}
		return "INSOMNIA";
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		assert 1 <= t && t <= 100 : "out of range, t: " + t;
		for (int it = 1; it <= t; it++) {
			int n = scanner.nextInt();
			assert 0 <= n && n <= 1e6 : "out of range, n: " + n;
			System.out.printf("Case #%d: %s\n", it, solve(n));
		}
		debug(max);
	}

	static void debug(Object...os) {
		System.err.printf("%.65536s\n", Arrays.deepToString(os));
	}	

}
