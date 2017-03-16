import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static boolean check(char c) {
		return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("A.in"));
		PrintWriter out = new PrintWriter("A.out");
		sc = new StringTokenizer(br.readLine());
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			String s = nxtTok();
			int n = nxtInt();
			int ans = 0;
			for (int i = 0; i < s.length(); i++) {
				for (int j = i; j <= s.length(); j++) {
					String sb = s.substring(i, j);
					for (int k = 0; k < sb.length(); k++) {
						int c = 0;
						for (int l = k; l < sb.length(); l++) {
							if (check(sb.charAt(l)))
								c++;
							else
								break;
						}
						if (c >= n) {
							ans++;
							break;
						}
					}
				}
			}
			out.println("Case #" + t + ": " + ans);
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