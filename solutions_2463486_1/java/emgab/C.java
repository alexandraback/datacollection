import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) throws IOException {
		long[] dp = { 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944,
				1002001, 1234321, 4008004, 100020001, 102030201, 104060401,
				121242121, 123454321, 125686521, 400080004, 404090404,
				10000200001L, 10221412201L, 12102420121L, 12345654321L,
				40000800004L, 1000002000001L, 1002003002001L, 1004006004001L,
				1020304030201L, 1022325232201L, 1024348434201L, 1210024200121L,
				1212225222121L, 1214428244121L, 1232346432321L, 1234567654321L,
				4000008000004L, 4004009004004L };
		br = new BufferedReader(new FileReader("C.in"));
		PrintWriter out = new PrintWriter("C.out");
		sc = new StringTokenizer(br.readLine());
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			long a = nxtLng();
			long b = nxtLng();
			int c = 0;
			for (int i = 0; i < dp.length; i++)
				if (dp[i] >= a && dp[i] <= b)
					c++;
			out.println("Case #" + t + ": " + c);
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