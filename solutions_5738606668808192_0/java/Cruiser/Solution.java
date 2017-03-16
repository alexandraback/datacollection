import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.*;

public class Solution implements Runnable {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread(new Solution()).start();
	}

	PrintWriter cout;

	BufferedReader cin;

	StringTokenizer stok;

	public void run() {
		try {
			cout = new PrintWriter("output.txt");
			cin = new BufferedReader(new FileReader("input.txt"));
			solve();
			cin.close();
			cout.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(234);
		}
	}
	
	long[] p = new long[12];
	
	boolean ok(String s) throws Exception {
		for (int base = 2; base <= 10; ++base) {
			BigInteger b = new BigInteger(s, base);
			if (b.isProbablePrime(31))
				return false;
		}
		for (int base = 2; base <= 10; ++base) {
			long b = Long.parseLong(s, base);
			long q = (long)Math.sqrt(0. + b) + 1;
			boolean ok = false;
			for (long d = 2; d <= q; ++d) {
				if (b % d == 0) {
					p[base] = d;
					ok = true;
					break;
				}
			}
			if (!ok) {
				cout.println("Zrya ty tak(");
				throw new Exception("Huinya");
			}
			
		}
		return true;
	}

	private void solve() throws Exception {
		int tnotused = nextInt();
		int n = nextInt();
		int m = nextInt();
		cout.println("Case #1:");
		for (long i = 0; i < (1L << (n - 2)); ++i) {
			if (m == 0) break;
			String ts = Long.toBinaryString(i);
			while (ts.length() < n - 2)
				ts = "0" + ts;
			String s = "1" + ts + "1";
			if (ok(s)) {
				--m;				
				cout.print(s);
				for (int j = 2; j <= 10; ++j)
					cout.print(" " + p[j]);
				if (m > 0)
					cout.println();
			}
		}

	}

	private int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	private String next() throws Exception {
		while (stok == null || !stok.hasMoreTokens()) {
			stok = new StringTokenizer(cin.readLine());
		}
		return stok.nextToken();
	}

}