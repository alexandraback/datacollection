import java.util.*;
import java.io.*;

/**
  * @author Mighty Cohadar 
  */
public class Delta {

	final int kk;
	final int cc;
	final int ss;
	
	public Delta(int kk, int cc, int ss) {
		this.kk = kk;
		this.cc = cc;
		this.ss = ss;
	}

	public String fromIndex(int index) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < kk; i++) {
			sb.append('0');
		}
		sb.setCharAt(index, '1');
		return sb.toString();			
	}

	public String gold() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < kk; i++) {
			sb.append('1');
		}
		return sb.toString();
	}

	public String expand(String r, String start) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < r.length(); i++) {
			if (r.charAt(i) == '1') {
				sb.append(gold());
			} else {
				sb.append(start);
			}
		}
		return sb.toString();
	}

	public String generate(int index) {
		String r = fromIndex(index);		
		String start = r;
		for (int i = 1; i < cc; i++) {
			r = expand(r, start);
		}
		return r;
	}

	public int right(int l) {
		return Math.min(kk - 1, l + cc - 1);
	}

	public long solve(int l, int r) {
		assert r - l + 1 <= cc; 
		long index = 0;
		for (int i = l; i <= r; i++) {
			index *= kk;
			index += i;
		}
		return index;
	}

	public Long[] solve() {
		// String[] K = new String[kk];
		// for (int i = 0; i < kk; i++) {
		// 	K[i] = generate(i);
		// }
		// debug(K);
		int min = Integer.MAX_VALUE;
		if (cc >= kk) {
			min = 1;
		} else {
			min = kk / cc;
			if (kk % cc != 0) {
				min++;
			}
		}
		if (ss < min) {
			return null;
		}
		Set<Long> R = new HashSet<>();
		int offset = 0;
		for (int i = 0; i < min; i++) {
			R.add(solve(offset, right(offset)) + 1);
			offset += cc;
		}
		return R.toArray(new Long[R.size()]);
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
			Long[] ret = o.solve();
			System.out.printf("Case #%d: %s\n", it, (ret == null) ? "IMPOSSIBLE" : join(ret, " "));
		}
	}

	static String join(Long[] A, String delimiter) {
		StringBuilder sb = new StringBuilder();
		for (long a : A) {
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

	static void debug(String[] K) {
		for (int i = 0; i < K.length; i++) {
			System.err.println(K[i]);
		}
	}

}
