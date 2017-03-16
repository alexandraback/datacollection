package se.matst.codejam.year2016;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.List;
import java.util.Scanner;

import com.google.common.collect.Lists;

public class C {
	public static void main(String[] args) throws IOException {

		String task = "C-large";
		Scanner scanner = new Scanner(new File("C:\\dev\\codejam\\codejam\\src\\resources\\" + task + ".in"));

		PrintWriter out = new PrintWriter("C:\\dev\\codejam\\codejam\\src\\resources\\" + task + ".out");
		int nrTests = scanner.nextInt();
		scanner.nextLine();

		System.out.println("Init done!");
		System.out.flush();
		long start = System.currentTimeMillis();
		for (int i = 0; i < nrTests; i++) {
			out.println("Case #" + (i + 1) + ":");
			System.out.println("Case #" + (i + 1) + ":");
			int length = scanner.nextInt();
			int max = scanner.nextInt();
			int count = 0;
			BigInteger current = BigInteger.ZERO;
			BigInteger maxVal = BigInteger.valueOf(2).pow(length - 2);
			while (current.compareTo(maxVal) < 0) {
				String jamcoin = "1";
				String binaryString = current.toString(2);
				for (int padI = 0; padI < length - 2 - binaryString.length(); padI++) {
					jamcoin += "0";
				}
				jamcoin += binaryString;
				jamcoin += "1";

				List<BigInteger> factors = Lists.newArrayList();
				for (int base = 2; base <= 10; base++) {
					BigInteger n = new BigInteger(jamcoin, base);
					BigInteger factor = maybeGetPrimeFactor(n);
					if (factor == null) {
						break;
					} else {
						factors.add(factor);
					}
				}
				if (factors.size() == 9) {
					out.print(jamcoin);
					System.out.print((count + 1) + " - " + jamcoin);
					for (int base = 2; base <= 10; base++) {
						BigInteger factor = factors.get(base - 2);
						out.print(" " + factor);
						System.out.print(" " + factor);
					}
					out.println();
					System.out.println();
					count++;
					if (count >= max) {
						break;
					}
				}
				current = current.add(BigInteger.ONE);
			}
		}

		long end = System.currentTimeMillis();
		System.out.println(end - start + " ms");
		out.close();
	}

	static List<BigInteger> firstPrimes = Lists.newArrayList(BigInteger.valueOf(2), BigInteger.valueOf(3), BigInteger.valueOf(5), BigInteger.valueOf(7), BigInteger.valueOf(11),
			BigInteger.valueOf(13), BigInteger.valueOf(17), BigInteger.valueOf(19), BigInteger.valueOf(23), BigInteger.valueOf(29));

	public static BigInteger maybeGetPrimeFactor(BigInteger n) {
		for (BigInteger prime : firstPrimes) {
			//for (BigInteger prime = BigInteger.valueOf(2); prime.multiply(prime).compareTo(n) <= 0; prime = prime.add(BigInteger.ONE)) {
			if (n.mod(prime).equals(BigInteger.ZERO)) {
				return prime;
			}
		}
		return null;
	}
}