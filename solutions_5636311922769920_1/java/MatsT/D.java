package se.matst.codejam.year2016;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class D {
	public static void main(String[] args) throws IOException {

		String task = "D-large";
		Scanner scanner = new Scanner(new File("C:\\dev\\codejam\\codejam\\src\\resources\\" + task + ".in"));

		PrintWriter out = new PrintWriter("C:\\dev\\codejam\\codejam\\src\\resources\\" + task + ".out");
		int nrTests = scanner.nextInt();
		scanner.nextLine();

		System.out.println("Init done!");
		System.out.flush();
		long start = System.currentTimeMillis();
		for (int i = 0; i < nrTests; i++) {
			int k = scanner.nextInt();
			int c = scanner.nextInt();
			int s = scanner.nextInt();
			out.print("Case #" + (i + 1) + ":");
			System.out.print("Case #" + (i + 1) + ":");
			if (s * c < k) {
				out.println(" IMPOSSIBLE");
				System.out.println(" IMPOSSIBLE");
				continue;
			}
			int nextnumber = 1;
			while (nextnumber <= k) {
				BigInteger pos = BigInteger.ONE;
				for (int ci = 0; ci < c && nextnumber <= k; ci++) {
					pos = pos.add(BigInteger.valueOf(k).pow(ci).multiply(BigInteger.valueOf(nextnumber - 1)));
					nextnumber++;
				}
				out.print(" " + pos);
				System.out.print(" " + pos);
			}
			out.println();
			System.out.println();
		}
		long end = System.currentTimeMillis();
		System.out.println(end - start + " ms");
		out.close();
	}
}