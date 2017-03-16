import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static int[][] a;
	static int n, m;

	static boolean row(int i, int val) {
		for (int j = 0; j < m; j++)
			if (a[i][j] > val)
				return false;
		return true;
	}

	static boolean col(int j, int val) {
		for (int i = 0; i < n; i++)
			if (a[i][j] > val)
				return false;
		return true;
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("B.in"));
		PrintWriter out = new PrintWriter("B.out");
		sc = new StringTokenizer(br.readLine());
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			n = nxtInt();
			m = nxtInt();
			a = new int[n][m];
			boolean[][] v = new boolean[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					a[i][j] = nxtInt();
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					v[i][j] = row(i, a[i][j]) | col(j, a[i][j]);
			boolean ans = true;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					ans &= v[i][j];
			out.println("Case #" + t + ": " + (ans ? "YES" : "NO"));
		}
		br.close();
		out.close();
	}

	static BufferedReader br;

	static StringTokenizer sc;

	static String nxtTok() throws IOException {
		while (!sc.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null)
				return null;
			sc = new StringTokenizer(s.trim());
		}
		return sc.nextToken();
	}

	static int nxtInt() throws IOException {
		return Integer.parseInt(nxtTok());
	}

	static long nxtLng() throws IOException {
		return Long.parseLong(nxtTok());
	}
}