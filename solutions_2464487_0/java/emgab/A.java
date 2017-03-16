import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("A.in"));
		PrintWriter out = new PrintWriter("A.out");
		sc = new StringTokenizer(br.readLine());
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			long c = 0;
			long R = nxtLng();
			long T = nxtLng();
			long in, ou;
			in = R;
			ou = in + 1;
			while (true) {
				if (T >= ou * ou - in * in) {
					T -= ou * ou - in * in;
					in += 2;
					ou += 2;
					c++;
				} else
					break;
			}
			out.println("Case #" + t + ": " + c);
			System.out.println("Case #" + t + ": " + c);
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