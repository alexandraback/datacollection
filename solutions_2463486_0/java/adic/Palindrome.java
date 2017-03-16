import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;


public class Palindrome {
	
	private static BigInteger[] a, b;
	private static int[] c;
	
	public static final void main(String[] params) throws Exception {
		long tic = System.currentTimeMillis();

		BufferedReader br = new BufferedReader(new FileReader("Palindrome.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("Palindrome.out"));
		int count = Integer.parseInt(br.readLine().trim());
		a = new BigInteger[count];
		b = new BigInteger[count];
		c = new int[count];
		for (int test = 0; test < count; test++) {
			String[] parts = br.readLine().split(" +");
			a[test] = new BigInteger(parts[0]);
			b[test] = new BigInteger(parts[1]);
		}
		
		/*Map<Long, String> s = new TreeMap();
		for (long i = 1; i <= 33000; i++) {
			long[] p = makepal(i);
			if (pal(p[0] * p[0])) {
				s.put(p[0], "" + p[0] + " => " + (p[0] * p[0]));
			}
			if (pal(p[1] * p[1])) {
				s.put(p[1], "" + p[1] + " => " + (p[1] * p[1]));
			}
		}
		int k = 0;
		for (String t: s.values()) {
			System.out.println(++k + ". " + t);
		}*/
		
		/*k = 0;
		for (long i = 1; i <= 2000000L; i++) {
			long[] p2 = makepal(i);
			for (long p: p2) {
				BigInteger st = BigInteger.valueOf(p).pow(2);
				if (pal(st)) {
				//String st = palSquare(p);
				//if (st != null) {
					//System.out.println(++k + ". " + p + " => " + st);
					System.out.println(++k + ". " + p + " => " + st);
				}
			}
		}*/
		
		/*int[] cc = new int[c.length];
		k = 0;
		for (long i = 1; i <= 2800000000L; i++) {
			if (pal(i) && pal(i*i)) {
				System.out.println(++k + ". " + i + " => " + (i * i));
				BigInteger sq = BigInteger.valueOf(i * i);
				for (int j = 0; j < a.length; j++) {
					if (a[j].compareTo(sq) <= 0 && b[j].compareTo(sq) >= 0) {
						cc[j]++;
					}
				}
			}
		}*/
		
		x[0] = '1';
		rec(1, 0);
		x[0] = '2';
		rec(1, 0);
		x[0] = '3';
		rec(1, 0);

		for (int test = 0; test < count; test++) {
			bw.write("Case #" + (test+1) + ": " + c[test]); // + " " + cc[test]);
			bw.newLine();
		}
		bw.close();
		br.close();

		long tac = System.currentTimeMillis();
		System.out.println(tac - tic + "ms");
	}
	
	private static int k = 0, best = 0;
	
	private static char[] x = new char[56]; 
	
	public static void rec(int k, int sod) {
		for (int i = 0; i < k; i++) {
			x[k * 2 - 1 - i] = x[i];
		}
		pal(new String(x, 0, k * 2));
		for (int i = 0; i < k; i++) {
			x[k * 2 - 2 - i] = x[i];
		}
		pal(new String(x, 0, k * 2 - 1));
		if (k <= 26 && sod <= 4) {
			for (char ch = '0'; ch <= '3'; ch++) {
				x[k] = ch;
				rec(k + 1, sod + ch - '0');
			}
		}
	}
	
	private static void pal(String s) {
		BigInteger sq = new BigInteger(s).pow(2);
		if (pal(sq)) {
			int d = 0;
			for (char ch : s.toCharArray()) {
				d += (ch - '0');
			}
			if (d > best) best = d;
			System.out.println(++k + ". " + s + " (" + s.length() + ") => " + sq + " (" + sq.toString().length() + ")   - " + best);
			for (int i = 0; i < a.length; i++) {
				if (a[i].compareTo(sq) <= 0 && b[i].compareTo(sq) >= 0) {
					c[i]++;
				}
			}
		}
	}
	
	private static boolean pal(BigInteger n) {
		String s= n.toString();
		for (int i = 0; i < s.length() / 2; i++) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}

	/*private static long[] makepal(long p) {
		long k = p, p2 = p;
		boolean first = true;
		while (k > 0) {
			p = p * 10 + (k % 10);
			if (!first) p2 = p2 * 10 + (k % 10);
			first = false;
			k /= 10;
		}
		return new long[] {p, p2};
	}

	private static boolean pal(long k) {
		if (k < 0 || k % 10 == 0) return false;
		long p = 0;
		while (p < k) {
			long r = k % 10;
			k /= 10;
			if (p == k) return true;
			p = p * 10 + r;
			if (p == k) return true;
		}
		return false;
	}*/

}
