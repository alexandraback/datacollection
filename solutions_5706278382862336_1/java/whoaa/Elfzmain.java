package elfz;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Elfzmain {
	public static void main(String[] args) {

		try {
			Scanner s = new Scanner(new File("/Users/mamud/Desktop/A-large.in"));

			int num_test = s.nextInt();
			s.nextLine();
			int x = 0;
			while (++x <= num_test) {
				System.out.print("Case #" + x + ": ");
				System.out.println(solve(reduce(read(s))));
			}

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}

	public static boolean possibility(Double[] longs, int gen) {
		int x;
		double y = longs[0], z = longs[1];
		for (x = 0; x < 40 - gen; x++)
			y *= 2;
		Double chk = ((double) y) / ((double) z);
		if (Math.abs(Math.round(chk) - chk) < 0.0001) return true;
		return false;
	}

	public static String solve(Double[] r) {
		double x = r[0], y = r[1];
		int g = 0;
		while (++g > 0) {
			x *= 2;
			if (x - y >= 0) {
				if (possibility(new Double[] { (x - y), y }, g)) return String.valueOf(g);
			}
			if (g > 40) break;
		}
		return "impossible";
	}

	public static Double[] read(Scanner kbd) {
		double num = -1.0, denom = -1.0;
		String s = kbd.nextLine();
		StringTokenizer stok = new StringTokenizer(s, "/");
		num = Long.parseLong(stok.nextToken());
		denom = Long.parseLong(stok.nextToken());
		return new Double[] { num, denom };
	}

	public static Double[] reduce(Double[] r) {
		double n = r[0];
		double d = r[1];

		while (d != 0) {
			double t = d;
			d = n % d;
			n = t;
		}

		double gcd = n;

		return new Double[] { r[0] / gcd, r[1] / gcd };
	}

}
