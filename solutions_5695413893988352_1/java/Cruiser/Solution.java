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
			// solveA();
			solveB();
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

	long ds[];
	String jj[];
	String cc[];

	String bestc, bestj;

	long get_best(ArrayList<String> cr, ArrayList<String> jr) {
		bestc = cr.get(0);
		bestj = jr.get(0);

		if (cr.size() < 2) {
			return Math.abs(Long.parseLong(cr.get(0)) - Long.parseLong(jr.get(0)));
		}
		if (Math.abs(Long.parseLong(cr.get(0)) - Long.parseLong(jr.get(0))) < Math
				.abs(Long.parseLong(cr.get(1)) - Long.parseLong(jr.get(1)))) {
			return Math.abs(Long.parseLong(cr.get(0)) - Long.parseLong(jr.get(0)));
		}

		bestc = cr.get(1);
		bestj = jr.get(1);
		return Math.abs(Long.parseLong(cr.get(1)) - Long.parseLong(jr.get(1)));
	}

	ArrayList<String> asc, asj;

	String match(int c, String sc) {
		String h = Integer.toString(c);
		if (h.length() > sc.length())
			return null;
		while (h.length() < sc.length())
			h = "0" + h;
		for (int i = 0; i < h.length(); ++i)
			if (sc.charAt(i) != '?' && sc.charAt(i) != h.charAt(i))
				return null;
		return h;
	}

	void track(String c, String j) {
		String h1, h2;
		for (int i = 0; i < 1000; ++i) {
			h1 = match(i, c);
			if (h1 != null)
				for (int ju = 0; ju < 1000; ju++) {
					h2 = match(ju, j);
					if (h2 != null) {
						asc.add(h1);
						asj.add(h2);
					}

				}
		}
	}

	String tc, tj;

	long tupo(String c, String j) {
		asc = new ArrayList<String>();
		asj = new ArrayList<String>();
		track(c, j);
		long bub = 99999999;
		for (int i = 0; i < asc.size(); ++i) {
			if (Math.abs(Long.parseLong(asc.get(i)) - Long.parseLong(asj.get(i))) < bub) {
				bub = Math.abs(Long.parseLong(asc.get(i)) - Long.parseLong(asj.get(i)));
				tc = asc.get(i);
				tj = asj.get(i);
			}

		}
		return bub;
	}

	long get_ds(String c, String j) {
		int n = c.length();
		if (ds[n] > -1)
			return ds[n];
		if (n == 0) {
			jj[0] = cc[0] = "";
			return ds[n] = 0;
		}

		String cres = "";
		String jres = "";

		int same = 0;
		for (int i = 0; i < c.length(); ++i) {
			if (same == -1) {
				if (c.charAt(i) == '?')
					cres = cres + '9';
				else
					cres = cres + c.charAt(i);
				if (j.charAt(i) == '?')
					jres = jres + '0';
				else
					jres = jres + j.charAt(i);
				continue;
			}
			if (same == 1) {
				if (c.charAt(i) == '?')
					cres = cres + '0';
				else
					cres = cres + c.charAt(i);
				if (j.charAt(i) == '?')
					jres = jres + '9';
				else
					jres = jres + j.charAt(i);
				continue;
			}
			if (c.charAt(i) != '?' && j.charAt(i) != '?') {
				cres = cres + c.charAt(i);
				jres = jres + j.charAt(i);
				if (c.charAt(i) < j.charAt(i))
					same = -1;
				if (c.charAt(i) > j.charAt(i))
					same = 1;
				continue;
			}
			if (c.charAt(i) == '?' && j.charAt(i) == '?') {
				ArrayList<String> cr = new ArrayList<String>();
				ArrayList<String> jr = new ArrayList<String>();
				// try 0 1 digits
				cr.add("0" + c.substring(i + 1).replace('?', '9'));
				jr.add("1" + j.substring(i + 1).replace('?', '0'));
				// try 1 0 digit
				cr.add("1" + c.substring(i + 1).replace('?', '0'));
				jr.add("0" + j.substring(i + 1).replace('?', '9'));
				// try same digits 0 0
				get_ds(c.substring(i + 1), j.substring(i + 1));
				long best = get_best(cr, jr);
				if (best < ds[n - i - 1] || (best == ds[n - i - 1] && (bestc.compareTo("0" + cc[n - i - 1]) < 0
						|| (bestc.equals("0" + cc[n - i - 1]) && bestj.compareTo("0" + jj[n - i - 1]) < 0)))) {

					cc[n] = cres + bestc;
					jj[n] = jres + bestj;
					return ds[n] = Math.abs(Long.parseLong(cc[n]) - Long.parseLong(jj[n]));
				} else {

					cc[n] = cres + "0" + cc[n - i - 1];
					jj[n] = jres + "0" + jj[n - i - 1];
					return ds[n] = Math.abs(Long.parseLong(cc[n]) - Long.parseLong(jj[n]));
				}
			}
			if (c.charAt(i) == '?') {
				ArrayList<String> cr = new ArrayList<String>();
				ArrayList<String> jr = new ArrayList<String>();
				// try j[i] - 1 digit
				if (j.charAt(i) != '0') {
					cr.add("" + (char) (j.charAt(i) - 1) + c.substring(i + 1).replace('?', '9'));
					jr.add(j.substring(i).replace('?', '0'));
				}
				// try j[i] + 1 digit
				if (j.charAt(i) != '9') {
					cr.add("" + (char) (j.charAt(i) + 1) + c.substring(i + 1).replace('?', '0'));
					jr.add(j.substring(i).replace('?', '9'));
				}
				// try same digit
				get_ds(c.substring(i + 1), j.substring(i + 1));
				long best = get_best(cr, jr);
				if (best < ds[n - i - 1] || (best == ds[n - i - 1] && (bestc.compareTo(j.charAt(i) + cc[n - i - 1]) < 0
						|| (bestc.equals(j.charAt(i) + cc[n - i - 1]) && bestj.compareTo(j.charAt(i) + jj[n - i - 1]) < 0)))) {

					cc[n] = cres + bestc;
					jj[n] = jres + bestj;
					return ds[n] = Math.abs(Long.parseLong(cc[n]) - Long.parseLong(jj[n]));
				} else {

					cc[n] = cres + j.charAt(i) + cc[n - i - 1];
					jj[n] = jres + j.charAt(i) + jj[n - i - 1];
					return ds[n] = Math.abs(Long.parseLong(cc[n]) - Long.parseLong(jj[n]));
				}
			}

			if (j.charAt(i) == '?') {
				ArrayList<String> cr = new ArrayList<String>();
				ArrayList<String> jr = new ArrayList<String>();
				// try c[i] - 1 digit
				if (c.charAt(i) != '0') {
					jr.add("" + (char) (c.charAt(i) - 1) + j.substring(i + 1).replace('?', '9'));
					cr.add(c.substring(i).replace('?', '0'));
				}
				// try c[i] + 1 digit
				if (c.charAt(i) != '9') {
					jr.add("" + (char) (c.charAt(i) + 1) + j.substring(i + 1).replace('?', '0'));

					cr.add(c.substring(i).replace('?', '9'));
				}
			//	System.out.println("c = " + c + ", cr = " + cr);
				//System.out.println("j = " + j + ", jr = " + jr);
				// try same digit
				get_ds(c.substring(i + 1), j.substring(i + 1));
				long best = get_best(cr, jr);
				//System.out.println("best = " + best + ", ds = " + ds[n - i - 1]);
				if (best < ds[n - i - 1] || (best == ds[n - i - 1] && (bestc.compareTo(c.charAt(i) + cc[n - i - 1]) < 0
						|| (bestc.equals(c.charAt(i) + cc[n - i - 1]) && bestj.compareTo(c.charAt(i) + jj[n - i - 1]) < 0)))) {

					cc[n] = cres + bestc;
					jj[n] = jres + bestj;
					return ds[n] = Math.abs(Long.parseLong(cc[n]) - Long.parseLong(jj[n]));
				} else {
					cc[n] = cres + c.charAt(i) + cc[n - i - 1];
					jj[n] = jres + c.charAt(i) + jj[n - i - 1];
					return ds[n] = Math.abs(Long.parseLong(cc[n]) - Long.parseLong(jj[n]));
				}
			}

		}

		cc[n] = cres;
		jj[n] = jres;
		return ds[n] = Math.abs(Long.parseLong(cc[n]) - Long.parseLong(jj[n]));
	}

	private void solveB() throws Exception {
		int t = nextInt();
		for (int tt = 0; tt < t; ++tt) {
			long res = 0;

			String c = next(), j = next();
			jj = new String[22];
			cc = new String[22];
			ds = new long[22];
			for (int i = 0; i < 22; ++i)
				ds[i] = -1;
			String cres = "", jres = "";

			get_ds(c, j);
			//System.out.println("res = " + ds[c.length()] + " :   c = " + c + ", j = " + j);

			cout.print("Case #" + (tt + 1) + ": " + cc[c.length()] + " " + jj[c.length()]);

			//long tpo = tupo(c, j);
			//if (tpo != ds[c.length()] || !tc.equals(cc[c.length()]) || !tj.equals(jj[c.length()])) {
			//	cout.println("ALARM: " + tpo + " " + tc + " " + tj);
			//}

			cout.println();
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