package com.google.partelf;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;

public class PartElf {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new FileReader(args[0]));

		int numCases = Integer.parseInt(br.readLine());

		for (int i = 0; i < numCases; i++) {
			solve(br, i+1);
		}

	}

	private static void solve(BufferedReader br, int i) throws IOException {
		
		String[] PQvalues = br.readLine().split("/");
		
		int P = Integer.parseInt(PQvalues[0]);
		int Q = Integer.parseInt(PQvalues[1]);
		
		BigInteger b = new BigInteger("1099511627776"); // 2 ^ 40
		b = b.multiply(new BigInteger("" + P));
		BigInteger[] rems = b.divideAndRemainder(new BigInteger("" + Q));
		
		String result = "impossible";
		
		if (rems[1].intValue() != 0) {
			System.out.println("Case #" + i + ": impossible");
			return;
		} else {
			for (int j = 0; j < 40; j++) {
				if (rems[0].testBit(40 - j)) {
					System.out.println("Case #" + i + ": " + j);
					return;
				}
			}
		}
		System.out.println("Case #" + i + ": impossible ");
		return;
	}

}
