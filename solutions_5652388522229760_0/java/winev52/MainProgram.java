import java.io.*;
import java.util.*;

public class MainProgram {

	public static long gcd(long a, long b) {
		while (a != 0 && b != 0) // until either one of them is 0
		{
			long c = b;
			b = a % b;
			a = c;
		}
		return a + b; // either one is 0, so return the non-zero value
	}

	public static void main(String args[]) throws FileNotFoundException {
		// System.out.println("yokoso!");

		//String inFile = "input.in";
		//String outFile = "output.out";
		 String inFile = "A-small-attempt0.in";
		 String outFile = "A-small-attempt0.out";
		// String inFile = "A-large-practice.in";
		// String outFile = "A-large-practice.out";

		File file = new File(inFile);
		Scanner scan = new Scanner(file);
		PrintWriter writer = new PrintWriter(outFile);

		int t = scan.nextInt();
		for (int i = 0; i < t; i++) {
			// TODO
			long n = scan.nextInt();
			int d = 1;
			int l = String.valueOf(n).length();
			int[] f = new int['9' - '0' + 1]; // false

			long nn = 0;
			int s = 0;
			long ll = 1;
			for (int u = 0; u < l; u++)
				ll = ll * 10;
			if (n == 0) {
				writer.printf("Case #%d: %s", i + 1, "INSOMNIA");

				writer.println();
				continue;
			}
			while (s != 10) {
				nn = n * d;
				String str = String.valueOf(nn);
				for (int u = 0; u < str.length(); u++)
					if (f[str.charAt(u) - '0'] == 0)
						f[str.charAt(u) - '0'] = 1;
				s = 0;
				for (int u = 0; u < 10; u++)
					s += f[u];
				d++;
			}

			if (s == 10) {
				writer.printf("Case #%d: %d", i + 1, nn);

				writer.println();
			} else {
				writer.printf("Case #%d: %s", i + 1, "INSOMNIA");

				writer.println();
			}
			///////
			// writer.printf("Case #%d: %s", i+1, "impossible");
			//
			// writer.println();
		}

		writer.close();
	}
}

/*
 * double c = scan.nextDouble(); double f = scan.nextDouble(); double x =
 * scan.nextDouble();
 * 
 * double t1, t2; double p = 2; double s = 0; do { t1 = x/p; t2 = c/p + x/(f+p);
 * if (t1 > t2) { s += c/p; p += f;
 * 
 * } else { s += x/p; } } while (t1 > t2);
 */

/*
 * static int p; static int q; static Map<Map<Integer, Integer>, Integer> d;
 * static int[] f;
 * 
 * public static int solve(int a, int b) { if (a>=b) return 0; Map<Integer,
 * Integer> x = new HashMap<Integer, Integer>(); x.put(a, b); if
 * (d.containsKey(x)) return d.get(x); int y = Integer.MAX_VALUE; for (int u =
 * 0; u < q; u++) { if (f[u] >= a && f[u] <= b) { int tmp = b-a+ solve(a,
 * f[u]-1) + solve(f[u]+1, b); if (y > tmp) { y = tmp; } } } if (y ==
 * Integer.MAX_VALUE) d.put(x, 0); else d.put(x, y); return d.get(x); }
 */

/*
 * String str = scan.nextLine(); int[] f = new int['z' - '0'+1]; for (int j =
 * '0'; j <= 'z'; j++) f[j-'0'] = -1; int b = 1; for (int j = 0; j <
 * str.length(); j++) { if (f[str.charAt(j) - '0']==-1) { f[str.charAt(j) - '0']
 * = b; if (b == 1) b = 0; else if (b == 0) b = 2; else b++; } } b = Math.max(2,
 * b); long cnt = 0; for (int j= 0; j < str.length(); j++) { long s; if (j ==
 * str.length() - 1) s = 1; else s = b; for (int u = 0; u < str.length() - j -
 * 2; u++) s *= b; cnt += f[str.charAt(j) - '0']*s; }
 */

/*
 * int n = scan.nextInt(); char[][] m = new char[n][n]; int k = scan.nextInt();
 * scan.nextLine(); for (int u = 0; u < n; u++) { String str = scan.nextLine();
 * for (int v = 0; v < n; v++) m[u][v] = str.charAt(v); for (int v = n-1; v>=0;
 * v--) { if (m[u][v]!='.') { for (int x = v+1; x < n; x++) { if (m[u][x] !='.')
 * break; char tmp = m[u][x]; m[u][x] = m[u][x-1]; m[u][x-1] = tmp; } } } }
 * 
 * int[] f = new int['R' - 'B'+1];
 * 
 * for (int u = 0; u <n; u++) { for (int v = 0; v < n; v++) { if (m[u][v] !=
 * '.') { int x = v; while ((x<v+k-1) && (x < n-1)) { if (m[u][x] == m[u][x+1])
 * x++; else break; } if (x == v+k-1) f[m[u][v]-'B'] = 1;
 * 
 * x = u; while ((x<u+k-1) && (x < n-1)) { if (m[x][v] == m[x+1][v]) x++; else
 * break; } if (x == u+k-1) f[m[u][v]-'B'] = 1;
 * 
 * x = u; int y = v; while ((x<u+k-1) && (x < n-1) && (y<v+k-1) &&(y<n-1)) { if
 * (m[x][y] == m[x+1][y+1]) { x++; y++; } else break; } if (x == u+k-1)
 * f[m[u][v]-'B'] = 1;
 * 
 * 
 * x = u; y = v; while ((x<u+k-1) && (x < n-1) && (y>v-k) &&(y>0)) { if (m[x][y]
 * == m[x+1][y-1]) { x++; y--; } else break; } if (x == u+k-1) f[m[u][v]-'B'] =
 * 1; } } }
 * 
 * String cnt = null; if ((f['R'-'B'] == 0) &&(f[0] == 0)) cnt = "Neither"; else
 * { if (f['R'-'B']!=1) cnt = "Blue"; else { if (f[0]!=1) cnt = "Red"; else cnt
 * = "Both"; } }
 */

/*
 * String tmp = "welcome to code jam"; int[] cnt = new int[tmp.length()]; String
 * str = scan.nextLine(); for (int j = 0; j < str.length(); j++) { for (int k =
 * 0; k < tmp.length(); k++) { if (str.charAt(j) == tmp.charAt(k)) { if
 * (str.charAt(j) == 'w') cnt[k]++; else {
 * 
 * cnt[k] += cnt[k-1]; } if (cnt[k] >= 10000) cnt[k] = cnt[k] % 10000; } }
 * 
 * }
 */

/*
 * int h = scan.nextInt(); int w = scan.nextInt(); int[][] dat = new int[h +
 * 2][w + 2]; for (int u = 0; u < h + 2; u++) { dat[u][0] = 10001; dat[u][w + 1]
 * = 10001; } for (int v = 0; v < w + 2; v++) { dat[0][v] = 10001; dat[h + 1][v]
 * = 10001; } int[] x = new int[] { -1, 0, 0, 1 }; int[] y = new int[] { 0, -1,
 * 1, 0 }; for (int u = 1; u < h + 1; u++) for (int v = 1; v < w + 1; v++) {
 * dat[u][v] = scan.nextInt(); }
 * 
 * char[][] f = new char[h + 2][w + 2]; // false for (int u = 0; u < h + 2; u++)
 * for (int v = 0; v < w + 2; v++) f[u][v] = ' '; char l = 'a'; for (int a = 1;
 * a < h + 1; a++) for (int b = 1; b < w + 1; b++) { if (f[a][b] != ' ')
 * continue;
 * 
 * List<Integer> stackx = new ArrayList<Integer>(); List<Integer> stacky = new
 * ArrayList<Integer>(); int u = a; int v = b; do { int min = dat[u][v]; int
 * minx = u; int miny = v; for (int j = 0; j < 4; j++) { if (dat[u + x[j]][v +
 * y[j]] < min) { min = dat[u + x[j]][v + y[j]]; minx = u + x[j]; miny = v +
 * y[j]; } } if (min < dat[u][v]) { if (f[minx][miny] == ' ') { stackx.add(u);
 * stacky.add(v); f[u][v] = l; u = minx; v = miny; continue; } else { for (int j
 * = 0; j < stackx.size(); j++) { f[stackx.get(j)][stacky.get(j)] =
 * f[minx][miny]; } f[u][v] = f[minx][miny]; break; } } else { f[u][v] = l; l++;
 * break; } } while (true); }
 */

/*
 * int r = scan.nextInt(); int c = scan.nextInt(); int n = scan.nextInt();
 * 
 * int cnt = 0; int m = (r * c) / 2; if (m >= n) cnt = 0; else { int k = 0; int
 * u = (r * 2 + (c - 2) * 2) / 2; while (m + u < n) { m += u; if (k == 0) { if
 * ((r % 2 == 0) || (c % 2 == 0)) { cnt += 2 * 2 + (u - 2) * 3; } else cnt += (u
 * - 4) * 3 + 4*2; } else cnt += u*4;
 * 
 * r -= 2; c -= 2; u = (r * 2 + (c - 2) * 2) / 2;
 * 
 * k++; } if (k == 0) { if ((r % 2 == 0) || (c % 2 == 0)) { if (n - m <= 2) {
 * cnt += 2 * (n - m); } else cnt += 2*2 + (n - m -2) * 3; } else { if (n - m <=
 * 4) cnt += (n-m)*2; else cnt += 4 * 2 + (n - m - 4)*3; }
 * 
 * } else { cnt += (n - m)*4; } }
 */

/*
 * int n = scan.nextInt(); int[] m = new int[n]; m[0] = scan.nextInt(); int y =
 * 0; int z = 0; int max = 0; for (int j = 1; j < n; j++) { m[j] =
 * scan.nextInt(); if (m[j-1] > m[j]) { y += m[j-1] - m[j]; if (max <
 * (m[j-1]-m[j])) max = m[j-1]-m[j]; } }
 * 
 * for (int j = 0; j < n-1; j++) { if (m[j] > max) z += max; else z += m[j]; }
 */

/*
 * String[] keys = new String[27]; int[] groups = new int[27];
 * 
 * keys[0] = "2"; groups[0] = 2; keys[1] = "22"; groups[1] = 2; keys[2] = "222";
 * groups[2] = 2;
 * 
 * keys[3] = "3"; groups[3] = 3; keys[4] = "33"; groups[4] = 3; keys[5] = "333";
 * groups[5] = 3;
 * 
 * keys[6] = "4"; groups[6] = 4; keys[7] = "44"; groups[7] = 4; keys[8] = "444";
 * groups[8] = 4;
 * 
 * keys[9] = "5"; groups[9] = 5; keys[10] = "55"; groups[10] = 5; keys[11] =
 * "555"; groups[11] = 5;
 * 
 * keys[12] = "6"; groups[12] = 6; keys[13] = "66"; groups[13] = 6; keys[14] =
 * "666"; groups[14] = 6;
 * 
 * keys[15] = "7"; groups[15] = 7; keys[16] = "77"; groups[16] = 7; keys[17] =
 * "777"; groups[17] = 7; keys[18] = "7777"; groups[18] = 7;
 * 
 * keys[19] = "8"; groups[19] = 8; keys[20] = "88"; groups[20] = 8; keys[21] =
 * "888"; groups[21] = 8;
 * 
 * keys[22] = "9"; groups[22] = 9; keys[23] = "99"; groups[23] = 9; keys[24] =
 * "999"; groups[24] = 9; keys[25] = "9999"; groups[25] = 9;
 * 
 * keys[26] = "0"; groups[26] = 10;
 * 
 * int N = scan.nextInt(); scan.nextLine();
 * 
 * for (int i= 0; i< N; i++) { String str = scan.nextLine(); int[] idx = new
 * int[str.length()]; String res = ""; for (int j = 0; j< str.length(); j++) {
 * char ch = str.charAt(j);
 * 
 * if (ch == ' ') idx[j] = 26; else idx[j] = ch - 'a';
 * 
 * if ((j == 0) || (groups[idx[j]] != groups[idx[j-1]])) { res = res +
 * keys[idx[j]]; } else if (groups[idx[j]] == groups[idx[j-1]]) res = res + " "
 * + keys[idx[j]]; }
 * 
 * writer.println("Case #" + (i+1) + ": " + res); }
 */

/*
 * Store Credit
 * 
 * int N = scan.nextInt(); for (int i= 0; i<N; i++) { int P = scan.nextInt();
 * int C = scan.nextInt();
 * 
 * int[] Idx = new int[1005]; //default is false for (int j = 0; j< 1005; j++)
 * Idx[j] = -1;
 * 
 * for (int j = 0; j<C; j++) { int item = scan.nextInt();
 * 
 * if ((P - item) > 0) { if ((Idx[P-item] > -1) && (j != Idx[P-item])) {
 * writer.println("Case #" + (i+1) + ": " + (Math.min(j, Idx[P-item])+1) + " " +
 * (Math.max(j, Idx[P-item])+1)); } } Idx[item] = j; } }
 */

/*
 * Reverse words
 * 
 * int N = scan.nextInt(); scan.nextLine();
 * 
 * for (int i = 0; i< N; i++) { String str = scan.nextLine(); String[] words =
 * str.split(" ");
 * 
 * String newStr = ""; for (int j = words.length-1; j >= 0; j--) newStr = newStr
 * + " " + words[j];
 * 
 * newStr = newStr.trim(); writer.println("Case #" + (i+1) + ": " + newStr); }
 */