package pl.helman;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

import static java.math.BigInteger.*;

public class Bullseye {

	private static BigInteger TWO = new BigInteger("2");

	/**
	 * @param args
	 * @throws IOException
	 */

	public static void main(String[] args) throws IOException {
		FileReader fr = new FileReader("d:\\cj\\bull.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter fo = new FileWriter("d:\\cj\\bull.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		for (int c = 1; c <= t; c++) {

			line = br.readLine().trim();
			String[] elems = line.split(" ");
			BigInteger r = new BigInteger(elems[0]);
			BigInteger p = new BigInteger(elems[1]);

			p = p.add(paintForR(r.subtract(ONE)));

			BigInteger ret = ZERO;

			while (true) {

				BigInteger k = ONE;

				while (paintForR(ret.add( k.multiply(TWO))).compareTo(p) < 0) {
					k = k.multiply(TWO);
				}

				if (paintForR(ret.add(k)).compareTo(p) <= 0) {
					ret = ret.add(k);
				} else {
					break;
				}
			}

			if (ret.mod(TWO).equals(r.mod(TWO))) {
				ret = ret.subtract(ONE);
			}

			ret = ret.divide(TWO).subtract(r.subtract(ONE).divide(TWO));

			fo.write("Case #" + c + ": " + ret.toString() + "\n");
		}

		fr.close();
		fo.close();

	}

	private static BigInteger paintForR(BigInteger r) {

		if (r.compareTo(ONE) <= 0) {
			return ZERO;
		}

		return r.add(ONE).multiply(r).divide(TWO);
	}

}
