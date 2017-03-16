package google.codejam._2014.round_1C;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class PartElf {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("src/in.txt"));
		PrintWriter out = new PrintWriter("out.txt");

		int t = in.nextInt();
		in.nextLine();

		for (int tc = 1; tc <= t; tc++) {
			String str = in.nextLine().trim();
			int index = str.indexOf('/');
			long p = Long.parseLong(str.substring(0, index));
			long q = Long.parseLong(str.substring(index + 1));

			long gcd = gcd(p, q);
			p = p / gcd;
			q = q / gcd;

			int count = 0;
			if (q % 2 == 1) {
				count = -1;
			} else {
				while (q % 2 == 0 && p < q && count <= 40) {
					q = q / 2;
					count++;
				}
			}

			if (count > 40 || p < q) {
				count = -1;
			}

			if (count >= 0) {
				boolean first = p % q == 0;

				while (q != 1 && q % 2 == 0) {
					q /= 2;
				}

				if (!(first || q == 1)) {
					System.out.println("nu este" + tc);
					count = -1;
				}
			}

			if (count >= 0) {
				out.println("Case #" + tc + ": " + count);
			} else {
				out.println("Case #" + tc + ": impossible");
			}
		}

		in.close();
		out.close();
	}

	private static long gcd(long a, long b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
}
