import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static String[] g = new String[4];

	static int solve() {
		int ans = -1;
		for (int i = 0; i < 4; i++) {
			String s = g[i];
			if (s.matches("XXXX") || s.matches("XXXT") || s.matches("XXTX")
					|| s.matches("XTXX") || s.matches("TXXX"))
				ans = 0;
		}
		for (int i = 0; i < 4; i++) {
			String s = "" + g[0].charAt(i) + g[1].charAt(i) + g[2].charAt(i)
					+ g[3].charAt(i);
			if (s.matches("XXXX") || s.matches("XXXT") || s.matches("XXTX")
					|| s.matches("XTXX") || s.matches("TXXX"))
				ans = 0;
		}
		String s = "" + g[0].charAt(0) + g[1].charAt(1) + g[2].charAt(2)
				+ g[3].charAt(3);
		if (s.matches("XXXX") || s.matches("XXXT") || s.matches("XXTX")
				|| s.matches("XTXX") || s.matches("TXXX"))
			ans = 0;
		s = "" + g[0].charAt(3) + g[1].charAt(2) + g[2].charAt(1)
				+ g[3].charAt(0);
		if (s.matches("XXXX") || s.matches("XXXT") || s.matches("XXTX")
				|| s.matches("XTXX") || s.matches("TXXX"))
			ans = 0;
		for (int i = 0; i < 4; i++) {
			s = g[i];
			if (s.matches("OOOO") || s.matches("OOOT") || s.matches("OOTO")
					|| s.matches("OTOO") || s.matches("TOOO")) {
				if (ans == 0)
					return 2;
				ans = 1;
			}
		}
		for (int i = 0; i < 4; i++) {
			s = "" + g[0].charAt(i) + g[1].charAt(i) + g[2].charAt(i)
					+ g[3].charAt(i);
			if (s.matches("OOOO") || s.matches("OOOT") || s.matches("OOTO")
					|| s.matches("OTOO") || s.matches("TOOO")) {
				if (ans == 0)
					return 2;
				ans = 1;
			}
		}
		s = "" + g[0].charAt(0) + g[1].charAt(1) + g[2].charAt(2)
				+ g[3].charAt(3);
		if (s.matches("OOOO") || s.matches("OOOT") || s.matches("OOTO")
				|| s.matches("OTOO") || s.matches("TOOO")) {
			if (ans == 0)
				return 2;
			ans = 1;
		}
		s = "" + g[0].charAt(3) + g[1].charAt(2) + g[2].charAt(1)
				+ g[3].charAt(0);
		if (s.matches("OOOO") || s.matches("OOOT") || s.matches("OOTO")
				|| s.matches("OTOO") || s.matches("TOOO")) {
			if (ans == 0)
				return 2;
			ans = 1;
		}
		if (ans == -1) {
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (g[i].charAt(j) == '.')
						return 3;
			return 2;
		}
		return ans;
	}

	public static void main(String[] args) throws IOException {
		String[] ans = { "X won", "O won", "Draw", "Game has not completed" };
		br = new BufferedReader(new FileReader("A.in"));
		PrintWriter out = new PrintWriter("A.out");
		sc = new StringTokenizer(br.readLine());
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			for (int i = 0; i < 4; i++)
				g[i] = nxtTok();
			out.println("Case #" + t + ": " + ans[solve()]);
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