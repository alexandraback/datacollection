import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Main {

	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");
	
	final String fileName = "c";

	private void run() throws IOException {
		in = new BufferedReader(new FileReader(fileName + ".in"));
		out = new PrintWriter(fileName + ".out");
		
		solve();
		
		in.close();
		out.close();
	}
	
	final int MAX_N = 1000 * 1000;
	
	final int mul[][] = {{0, 0,  0,  0,  0},
			             {0, 1,  2,  3,  4},
			             {0, 2, -1,  4, -3},
			             {0, 3, -4, -1,  2},
			             {0, 4,  3, -2, -1}};
	
	int n;
	long x;
	int s[] = new int[MAX_N];
	int pref[] = new int[MAX_N];
	int suf[] = new int[MAX_N];
//	int temp[] = new int[MAX_N];
	
	int getNum(char ch) {
		switch (ch) {
		case 'i' : return 2;
		case 'j' : return 3;
		case 'k' : return 4;
		}
		throw new NullPointerException();
	}
	
	int mul(int i, int j) {
		int s = 1;
		if (i < 0) {
			i = -i;
			s *= -1;
		}
		if (j < 0) {
			j = -j;
			s *= -1;
		}
		return s * mul[i][j];
	}
	
	void solve() throws IOException {
		int countTest = nextInt();
		for (int test = 1; test <= countTest; ++test) {
			System.err.println(test);
			n = nextInt();
			x = nextLong();
			String str = nextToken();
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < x; ++j)
					s[n * j + i] = getNum(str.charAt(i));
			n *= x;
			
			pref[0] = s[0];
			for (int i = 1; i < n; ++i)
				pref[i] = mul(pref[i - 1], s[i]);
			suf[n - 1] = s[n - 1];
			for (int i = n - 2; i >= 0; --i)
				suf[i] = mul(s[i], suf[i + 1]);
			
//			for (int i = 0; i < n; ++i) {
//				temp[i] = 1;
//				for (int j = 0; j < n; ++j)
//					temp[i] = mul(temp[i], s[(i + j) % n]);
//			}
			
			boolean ans = false;
			for (int l = 0; l < n && !ans; ++l) {
				int b = s[l];
				for (int r = l + 1; r < n && !ans; b = mul(b, s[r++])) {
					int a = l > 0 ? pref[l - 1] : 1;
					int c = suf[r];
					
					if (a == 2 && b == 3 && c == 4)
						ans = true;
					
//					System.err.println();
//					System.err.println(l + " " + r + ") " + a + " " + b + " " + c);
					
//					long needAdd = x - (r >= n ? 2 : 1);
//					
//					int cntL = 0, valL = a;
//					while (cntL <= 4 && valL != 2) {
//						valL = mul(suf[0], valL);
//						++cntL;
//					}
//					int cntR = 0, valR = c;
//					while (cntR <= 4 && valR != 4) {
//						valR = mul(valR, suf[0]);
//						++cntR;
//					}
//					int cntC = 0, valC = b;
//					while (cntC <= 4 && valC != 3) {
//						valC = mul(valC, temp[r % n]);
//						++cntC;
//					}
					
//					System.err.println(valL + " " + valC + " " + valR);
//					System.err.println(cntL + " " + cntC + " " + cntR + " = " + needAdd);
					
//					if (valL == 2 && valC == 3 && valR == 4) {
//						if ((cntL + cntC + cntR) % 4 == needAdd % 4 && (cntL + cntC + cntR) <= needAdd)
//							ans = true;
//					}
				}
			}
			
			out.println("Case #" + test + ": " + (ans ? "YES" : "NO"));
		}
	}

	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String str = in.readLine();
			if (str == null)
				return true;
			st = new StringTokenizer(str);
		}
		return false;
	}

}
