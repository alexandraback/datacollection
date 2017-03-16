import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

@SuppressWarnings("unused")
public class prog1 {
	public static long gcd(long x, long y) {
		long t;
		while (y != 0) {
			t = x % y;
			x = y;
			y = t;
		}
		return x;
	}

	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(
				"C:\\Users\\KIRA\\Downloads\\input.in"));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(
				new FileOutputStream("C:\\Users\\KIRA\\Downloads\\output.out")));
		// BufferedReader in=new BufferedReader(new
		// InputStreamReader(System.in));
		// PrintWriter out=new PrintWriter(System.out);
		Scanner sc = new Scanner(in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int ans = 0;
			String s[]=sc.next().split("/");
			long P = Long.parseLong(s[0]);
			long Q = Long.parseLong(s[1]);
			long gcd = gcd(P, Q);
			P /= gcd;
			Q /= gcd;
			if (((Q & (Q - 1)) != 0) || ((Q >> 41) != 0)) {
				out.printf("Case #%d: impossible\n", i);
				continue;
			}

			while (P < Q) {
				ans++;
				P<<=1;
			}
			out.printf("Case #%d: %d\n", i, ans);
		}

		sc.close();
		out.close();
	}
}
