package se.matst.codejam.year2016;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Scanner;

import com.google.common.collect.Lists;

public class A {
	public static void main(String[] args) throws IOException {

		String task = "A-small-attempt0";
		Scanner scanner = new Scanner(new File("C:\\dev\\codejam\\codejam\\src\\resources\\" + task + ".in"));

		PrintWriter out = new PrintWriter("C:\\dev\\codejam\\codejam\\src\\resources\\" + task + ".out");
		int nrTests = scanner.nextInt();

		System.out.println("Init done!");
		System.out.flush();
		for (int i = 0; i < nrTests; i++) {
			final int start = scanner.nextInt();
			if (start == 0) {
				out.println("Case #" + (i + 1) + ": INSOMNIA");
				continue;
			}
			List<Integer> unseenDigits = Lists.newArrayList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
			int current = 0;
			while (!unseenDigits.isEmpty()) {
				current += start;
				int n = current;
				while (n > 0) {
					int d = n / 10;
					Integer k = n - d * 10;
					unseenDigits.remove(k);
					n = d;
				}
			}
			out.println("Case #" + (i + 1) + ": " + current);
		}

		out.close();
	}
}