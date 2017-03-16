import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class taskB {

	PrintWriter out;
	BufferedReader br;
	StringTokenizer st;

	String nextToken() throws IOException {
		while ((st == null) || (!st.hasMoreTokens()))
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public void solve() throws IOException {
		int n = nextInt();
		String[] s = new String[n];
		boolean[][] cont = new boolean[n][256];
		for (int i = 0; i < n; i++) {
			s[i] = nextToken();
			for (int j = 0; j < s[i].length(); j++) {
				cont[i][s[i].charAt(j)] = true;
			}
		}
		char[][] ns = new char[n][2];
		for (int i = 0; i < n; i++) {
			ArrayList<Character> t = new ArrayList<Character>();
			for (int j = 0; j < s[i].length(); j++) {
				if (t.size() == 0 || t.get(t.size() - 1) != s[i].charAt(j)) {
					t.add(s[i].charAt(j));
				}
			}
			char[] nns = new char[t.size()];
			for (int j = 0; j < nns.length; j++) {
				nns[j] = t.get(j);
			}
			for (int j = 0; j < nns.length; j++) {
				for (int k = j + 1; k < nns.length; k++) {
					if (nns[k] == nns[j]) {
						out.println(0);
						return;
					}
				}
			}
			for (int j = 1; j < nns.length - 1; j++) {
				for (int k = 0; k < n; k++) {
					if (k != i && cont[k][nns[j]]) {
						out.println(0);
						return;
					}
				}
			}
			ns[i][0] = nns[0];
			ns[i][1] = nns[nns.length - 1];
		}

		char cur = 'a' - 1;
		BigInteger result = BigInteger.ONE;
		int it = 0;
		while (ns.length != 1 && it < 26) {
			it++;
			cur++;
			if (cur > 'z')
				cur = 'a';
			int cntFull = 0;
			int cntBeg = 0;
			int cntEnd = 0;
			char next = cur;
			char prev = cur;
			for (int i = 0; i < n; i++) {
				if (ns[i][0] == cur && ns[i][1] == cur) {
					cntFull++;
				}
				if (ns[i][0] == cur && ns[i][1] != cur) {
					cntEnd++;
					next = ns[i][1];
				}
				if (ns[i][0] != cur && ns[i][1] == cur) {
					cntBeg++;
					prev = ns[i][0];
				}
			}
			if (cntBeg + cntEnd + cntFull == 0) {
				continue;
			}
			if (cntBeg > 1 || cntEnd > 1) {
				out.println(0);
				return;
			}
			for (int k = 1; k <= cntFull; k++) {
				result = result.multiply(BigInteger.valueOf(k));
			}
			ArrayList<char[]> nns = new ArrayList<char[]>();
			char[] b = new char[] { prev, next };
			if (b[0] == b[1] && b[0] != cur) {
				out.println(0);
				return;
			}
			nns.add(b);
			for (int i = 0; i < n; i++) {
				if (ns[i][0] != cur && ns[i][1] != cur) {
					nns.add(ns[i]);
				}
			}
			n = nns.size();
			ns = new char[n][];
			for (int i = 0; i < n; i++) {
				ns[i] = nns.get(i);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = 0; k < 2; k++) {
					for (int l = 0; l < 2; l++) {
						if (ns[i][k] == ns[j][l]) {
							out.println(0);
							return;
						}
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			result = result.multiply(BigInteger.valueOf(i));
		}

		out.println(result);
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			br = new BufferedReader(new FileReader("taskB.in"));
			out = new PrintWriter("taskB.out");
			int n = nextInt();
			for (int i = 0; i < n; i++) {

				out.print("Case #" + (i + 1) + ": ");
				solve();
			}
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new taskB().run();
	}
}
