package se.matst.codejam.year2016;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Scanner;

import com.google.common.collect.Lists;

public class C {
	public static void main(String[] args) throws IOException {

		String task = "C-small";
		Scanner scanner = new Scanner(new File("C:\\dev\\codejam\\codejam\\src\\resources\\" + task + ".in"));

		PrintWriter out = new PrintWriter("C:\\dev\\codejam\\codejam\\src\\resources\\" + task + ".out");
		int nrTests = scanner.nextInt();
		scanner.nextLine();

		System.out.println("Init done!");
		System.out.flush();
		for (int i = 0; i < nrTests; i++) {
			out.println("Case #" + (i + 1) + ":");
			System.out.println("Case #" + (i + 1) + ":");
			int length = scanner.nextInt();
			int max = scanner.nextInt();
			int count = 0;
			long current = 0;
			long maxVal = (int) Math.pow(2, length - 2);
			while (current < maxVal) {
				String jamcoin = "1";
				String binaryString = Long.toBinaryString(current);
				for (int padI = 0; padI < length - 2 - binaryString.length(); padI++) {
					jamcoin += "0";
				}
				jamcoin += binaryString;
				jamcoin += "1";

				List<Long> factors = Lists.newArrayList();
				for (int base = 2; base <= 10; base++) {
					long n = Long.parseLong(jamcoin, base);
					long factor = getPrimeFactor(n);
					if (factor == 0) {
						break;
					} else {
						factors.add(factor);
					}
				}
				if (factors.size() == 9) {
					out.print(jamcoin);
					System.out.print(jamcoin);
					for (int base = 2; base <= 10; base++) {
						long factor = factors.get(base - 2);
						out.print(" " + factor);
						System.out.print(" " + factor + "(" + Long.parseLong(jamcoin, base) + ")");
					}
					out.println();
					System.out.println();
					count++;
					if (count >= max) {
						break;
					}
				}
				current++;
			}
		}

		out.close();
	}

	public static int toBase10(String input, int fromBase) {
		int ret = 0;
		int digit = 0;
		for (int i = input.length() - 1; i >= 0; i--) {
			if (input.charAt(i) == '1') {
				ret += Math.pow(fromBase, digit);
			}
			digit++;
		}
		return ret;
	}

	public static long getPrimeFactor(long n) {
		for (long i = 2; i <= n / i; i++) {
			while (n % i == 0) {
				return i;
			}
		}
		return 0;
	}
}