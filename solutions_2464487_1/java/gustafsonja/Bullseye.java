package one_a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

import util.Util;

public class Bullseye {

	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new BufferedReader(new FileReader("A-large.in")));
		BufferedWriter bw = new BufferedWriter(new FileWriter("output"));
		int cases = s.nextInt();
		for (int i = 0; i != cases; i++) {
			long t = System.nanoTime();
			BigInteger y = foo(s.nextBigInteger(), s.nextBigInteger());
			System.out.println(System.nanoTime() - t);
			String str = "Case #" + (i+1) + ": " + y.toString();
			System.out.println(str);
			bw.write(str+'\n');
		}
		bw.close();
		s.close();
	}
	
	private static final BigInteger two = BigInteger.ONE.add(BigInteger.ONE);
	private static final BigInteger four = two.add(two);
	private static final BigInteger eight = four.add(four);

	// k = floor(1/4(sqrt(4r^2-4r+8t+1)-2r+1))
	private static BigInteger foo(BigInteger r, BigInteger t) {
		return Util.floorSqrt(r.pow(2).multiply(four).subtract(four.multiply(r)).add(eight.multiply(t)).add(BigInteger.ONE)).subtract(two.multiply(r)).add(BigInteger.ONE).shiftRight(2);
	}

}
