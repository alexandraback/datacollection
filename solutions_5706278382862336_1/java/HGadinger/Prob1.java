package r1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Prob1 {

	public static void main(String[] args) {
		(new Prob1()).go();
	}

	boolean debug = true;
	String line = null;
	String ret = null;
	int caseId = 0;

	public void print(String p) {
		if (debug)
			System.out.print(p);
	}

	public void println(String p) {
		if (debug)
			print(p + "\n");
	}

	// LinkedList<Integer> list = new LinkedList<Integer>();

	private void go() {

		BufferedReader in = null;
		PrintWriter pw = null;
		StringTokenizer tk = null;
		BigInteger bigtop = null;
		BigInteger bigbot = null;
		BigInteger first = null;

		BigInteger fact = null;
		BigInteger temp = null;
		BigInteger ones = null;
		BigDecimal test = new BigDecimal("1.0");

		try {
			in = new BufferedReader(new FileReader("A-large.in"));
			pw = new PrintWriter(new FileWriter("output.txt"));

			int cases = Integer.parseInt(in.readLine());

			first = new BigInteger("2");
			first = first.pow(40);

			for (caseId = 0; caseId < cases; caseId++) {
				ret = null;

				line = in.readLine();
				tk = new StringTokenizer(line, "/");
				bigtop = new BigInteger(tk.nextToken());
				bigbot = new BigInteger(tk.nextToken());

				ones = bigtop.multiply(first);

				temp = ones.remainder(bigbot);

				System.out.println(bigtop);
				System.out.println(bigbot);
				System.out.println(temp);

				if (temp.compareTo(BigInteger.ZERO) == 0) {

					ones = ones.divide(bigbot);

					if (ones.testBit(0) == false) {

						int bits = ones.add(BigInteger.ONE).bitLength();
						ret = "" + (41 - bits);

					} else {
						ret = "impossible";

					}
				} else {
					ret = "impossible";
				}

				System.out.println("Case #" + (caseId + 1) + ": " + ret);
				pw.println("Case #" + (caseId + 1) + ": " + ret);

			}
			in.close();
			pw.flush();
			pw.close();
		} catch (Exception e) {
			System.out.println("Main Loop Exception");
			e.printStackTrace();
		}
	}
}

/*
 * if (bigtop.compareTo(bigbot) == 0) { ret = "0"; } else {
 * 
 * temp = first.remainder(bigbot);
 * 
 * System.out.println(bigtop); System.out.println(bigbot);
 * System.out.println(temp);
 * 
 * if (temp.compareTo(BigInteger.ZERO) == 0) { fact = first.divide(bigbot); ones
 * = bigtop.multiply(fact);
 * 
 * if (ones.testBit(0) == false) {
 * 
 * int bits = ones.add(BigInteger.ONE).bitLength(); ret = "" + (41 - bits);
 * 
 * } else { ret = "impossible";
 * 
 * }
 * 
 * } else { ret = "impossible";
 * 
 * } }
 */
