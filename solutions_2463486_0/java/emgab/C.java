import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static boolean isPerfect(int x) {
		int tmp = (int) Math.sqrt(x);
		return tmp * tmp == x;
	}

	static boolean isPalin(int x) {
		String s = Integer.toString(x);
		for (int i = 0; i < s.length() / 2; i++)
			if (s.charAt(i) != s.charAt(s.length() - 1 - i))
				return false;
		return true;
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("C.in"));
		PrintWriter out = new PrintWriter("C.out");
		sc = new StringTokenizer(br.readLine());
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			int a = nxtInt();
			int b = nxtInt();
			int c = 0;
			for (int i = a; i <= b; i++)
				if (isPerfect(i) && isPalin(i) && isPalin((int) Math.sqrt(i)))
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