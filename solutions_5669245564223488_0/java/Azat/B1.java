import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class B1 {

	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	
	public static void main(String[] args) throws IOException{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int testNumber = nextInt();
		for (int test = 1; test <= testNumber; test++) {
			pw.print("Case #"+test+": ");
			int n = nextInt();
			int mod = (int) (1e9+7);
			int[]p = new int[n+1];
			for (int i = 1; i <= n; i++) {
				p[i] = i;
			}
			int ans = 0;
			String[]s = new String[n+1];
			for (int i = 1; i <= n; i++) {
				s[i] = next();
			}
			int[][]begin = new int[n+1][26], end = new int[n+1][26];
			int[]cnt = new int[26];
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < s[i].length(); j++) {
					cnt[s[i].charAt(j)-97]++;
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < 26; j++) {
					begin[i][j] = s[i].indexOf((char)(j+97));
					end[i][j] = s[i].lastIndexOf((char)(j+97));
				}
			}
			int[]leng = new int[n+1];
			for (int i = 1; i <= n; i++) {
				leng[i] = s[i].length();
			}
			int[]b = new int[26], e = new int[26];
			while (true) {
				boolean ok = true;
				int ind = 0;
				Arrays.fill(b, -1);
				Arrays.fill(e, -1);
				for (int i = 1; i <= n; i++) {
					for (int j = 0; j < 26; j++) {
						if (begin[p[i]][j] != -1) {
							if (b[j]==-1)
								b[j] = ind+begin[p[i]][j];
						}
						if (end[p[i]][j] != -1) {
							e[j] = ind+end[p[i]][j];
						}
					}
					ind += leng[p[i]];
				}
				for (int i = 0; i < 26; i++) {
					if (e[i]==-1)
						continue;
					if (e[i]-b[i]+1 != cnt[i]) {
						ok = false;
						break;
					}
				}
				if (ok)
					ans++;
				int ind1 = n;
				while (ind1 > 1 && p[ind1] < p[ind1-1])
					ind1--;
				if (ind1==1)
					break;
				int ind2 = n;
				while (p[ind2] < p[ind1-1])
					ind2--;
				int t = p[ind1-1];
				p[ind1-1] = p[ind2];
				p[ind2] = t;
				for (int i = 0; ind1+i < n-i; i++) {
					t = p[ind1+i];
					p[ind1+i] = p[n-i];
					p[n-i] = t;
				}
			}
			pw.println(ans);
		}
		pw.close();
	}

	private static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	private static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	private static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	private static String next() throws IOException{
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

}
