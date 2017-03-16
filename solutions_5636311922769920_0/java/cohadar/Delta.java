import java.util.*;
import java.io.*;

/**
  * @author Mighty Cohadar 
  */
public class Delta {

	final int k;
	final int c;
	final int s;
	
	public Delta(int k, int c, int s) {
		this.k = k;
		this.c = c;
		this.s = s;
	}

	public int[] solve() {
		if (s < k) {
			return null;
		}
		int[] R = new int[s];
		for (int i = 0; i < R.length; i++) {
			R[i] = i + 1;
		}
		return R;
	}

	public static Delta load(Scanner scanner) {
		int k = scanner.nextInt();
		int c = scanner.nextInt();
		int s = scanner.nextInt();
		assert 1 <= k && k <= 100 : "out of range, k: " + k;
		assert 1 <= c && c <= 100 : "out of range, c: " + c;
		assert 1 <= s && s <= 100 : "out of range, s: " + s;
		return new Delta(k, c, s);
	}	

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		assert 1 <= t && t <= 100 : "out of range, t: " + t;
		for (int it = 1; it <= t; it++) {
			Delta o = Delta.load(scanner);
			int[] ret = o.solve();
			System.out.printf("Case #%d: %s\n", it, (ret == null) ? "IMPOSSIBLE" : join(ret, " "));
		}
	}

	static String join(int[] A, String delimiter) {
		StringBuilder sb = new StringBuilder();
		for (int a : A) {
			sb.append(a);
			sb.append(delimiter);
		}
		if (sb.length() >= delimiter.length()) {
			sb.setLength(sb.length() - delimiter.length());
		}			
		return sb.toString();
	}

	static void debug(Object...os) {
		System.err.printf("%.65536s\n", Arrays.deepToString(os));
	}	

}
