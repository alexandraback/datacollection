package gcjpractice.round1C2014;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A {
	static String IMPOSSIBLE = "impossible";

	public static void main(String[] args) {
		String base = "/home/radicsge/gcj2014/";
		String input = base + "a2.in";
		String output = base + "a2.out";

		try {
			Scanner sc = new Scanner(new FileReader(input));
			PrintWriter pw = new PrintWriter(output);

			int T = sc.nextInt();
			sc.nextLine();
			for (int t = 0; t < T; t++) {
				System.out.println("Test case " + (t + 1) + "...");

				String s[] = sc.nextLine().split("/");
				int a = Integer.valueOf(s[0]);
				int b = Integer.valueOf(s[1]);

				int solution = solve(a, b);

				pw.println("Case #" + (t + 1) + ": " + (solution < 0 ? IMPOSSIBLE : solution));
				System.out.println("Case #" + (t + 1) + ": " + (solution < 0 ? IMPOSSIBLE : solution));

			}
			pw.println();
			pw.flush();
			pw.close();
			sc.close();
		} catch (FileNotFoundException ex) {
			ex.printStackTrace();
		}
	}

	private static int solve(int a, int b) {
		BigInteger da = BigInteger.valueOf(a);
		BigInteger db = BigInteger.valueOf(b);

		BigInteger gcd = db.gcd(da);

		a = da.divide(gcd).intValue();
		b = db.divide(gcd).intValue();

		//--- check possible
		int p = b;
		while (p > 1) {
			if ((p & 1) == 1) {
				return -1;
			}
			p = p >> 1;
		}

		//--- calc generation
		int r = 1;
		int q = b / 2;
		int g = 1;
		while (a < q && r < b) {
			g++;
			q /= 2;
			r *= 2;
		}

		return g;
	}
}
