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
			solveA();
			// solveB();
			// solveC();
			cin.close();
			cout.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(234);
		}
	}

	private void solveA() throws Exception {
		int t = nextInt();
		for (int tt = 0; tt < t; ++tt) {
			int[] res = new int[11];

			String s = next();
			int a[] = new int[55];
			for (char c : s.toCharArray()) {
				a[c - 'A']++;
			}
			if (a['Z' - 'A'] > 0) {
				res[0] += a['Z' - 'A'];
				a['Z' - 'A'] -= res[0];
				a['E' - 'A'] -= res[0];
				a['R' - 'A'] -= res[0];
				a['O' - 'A'] -= res[0];
			}	
			if (a['X' - 'A'] > 0) {
				res[6] += a['X' - 'A'];
				a['S' - 'A'] -= res[6];
				a['I' - 'A'] -= res[6];
				a['X' - 'A'] -= res[6];
			}
			if (a['W' - 'A'] > 0) {
				res[2] += a['W' - 'A'];
				a['T' - 'A'] -= res[2];
				a['W' - 'A'] -= res[2];
				a['O' - 'A'] -= res[2];
			}
			if (a['U' - 'A'] > 0) {
				res[4] += a['U' - 'A'];
				a['F' - 'A'] -= res[4];
				a['O' - 'A'] -= res[4];
				a['U' - 'A'] -= res[4];
				a['R' - 'A'] -= res[4];
			}
			if (a['G' - 'A'] > 0) {
				res[8] += a['G' - 'A'];
				a['E' - 'A'] -= res[8];
				a['I' - 'A'] -= res[8];
				a['G' - 'A'] -= res[8];
				a['H' - 'A'] -= res[8];
				a['T' - 'A'] -= res[8];
			}
			if (a['S' - 'A'] > 0) {
				res[7] += a['S' - 'A'];
				a['S' - 'A'] -= res[7];
				a['E' - 'A'] -= res[7];
				a['V' - 'A'] -= res[7];
				a['E' - 'A'] -= res[7];
				a['N' - 'A'] -= res[7];
			}
			if (a['O' - 'A'] > 0) {
				res[1] += a['O' - 'A'];
				a['O' - 'A'] -= res[1];
				a['N' - 'A'] -= res[1];
				a['E' - 'A'] -= res[1];
			}
			if (a['T' - 'A'] > 0) {
				res[3] += a['T' - 'A'];
				a['T' - 'A'] -= res[3];
				a['H' - 'A'] -= res[3];
				a['R' - 'A'] -= res[3];
				a['E' - 'A'] -= res[3];
				a['E' - 'A'] -= res[3];
			}
			if (a['F' - 'A'] > 0) {
				res[5] += a['F' - 'A'];
				a['F' - 'A'] -= res[5];
				a['I' - 'A'] -= res[5];
				a['V' - 'A'] -= res[5];
				a['E' - 'A'] -= res[5];
			}
			res[9] += a['I' - 'A'];
			cout.print("Case #" + (tt + 1) + ": ");
			for (int i = 0; i < 10; ++i)
				for (int j = 0; j < res[i]; ++j)
					cout.print(i);
			cout.println();
		}
	}

	private void solveB() throws Exception {
		int t = nextInt();
		for (int tt = 0; tt < t; ++tt) {
			long res = 0;

			cout.print("Case #" + (tt + 1) + ": ");
			cout.println(res);
		}
	}

	private void solveC() throws Exception {
		int t = nextInt();
		for (int tt = 0; tt < t; ++tt) {
			long res = 0;

			cout.print("Case #" + (tt + 1) + ": ");
			cout.println(res);
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