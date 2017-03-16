package se.matst.codejam.year2016;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class D {
	public static void main(String[] args) throws IOException {

		String task = "D-small-attempt1";
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
			BigInteger total = BigInteger.valueOf(k).pow(c);
			out.print("Case #" + (i + 1) + ":");
			System.out.print("Case #" + (i + 1) + ":");
			if (s < k) {
				out.println(" IMPOSSIBLE");
				System.out.println(" IMPOSSIBLE");
				continue;
			}
			for (int j = 0; j < k; j++) {
				BigInteger pos = total.divide(BigInteger.valueOf(k)).multiply(BigInteger.valueOf(j)).add(BigInteger.ONE);
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