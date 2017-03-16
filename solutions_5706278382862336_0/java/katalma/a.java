package gcj2014.c1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Date;
import java.util.Scanner;

public class a {
	public static void main(String[] args) {
//		readAndSolve("resource/gcj2014/c1/a/sample.in",	"resource/gcj2014/c1/a/sample.out");
		 readAndSolve("resource/gcj2014/c1/a/A-small-attempt0.in", "resource/gcj2014/c1/a/A-small-attempt0.out");
//		 readAndSolve("resource/gcj2014/c1/a/A-large.in", "resource/gcj2014/c1/a/A-large.out");
	}

	/**
	 * @param inputName
	 * @param outputName
	 */
	private static void readAndSolve(String inputName, String outputName) {
		BufferedReader input = null;
		BufferedWriter output = null;
		Date d1 = new Date();
		try {
			input = new BufferedReader(new FileReader(inputName));
			output = new BufferedWriter(new FileWriter(outputName));
			String line1 = null;
			String line2 = null;
			int expectedCases = 0;
			int actualCase = -1;
			line1 = input.readLine();
			expectedCases = Integer.parseInt(line1);
			for (actualCase = 1; actualCase <= expectedCases; actualCase++) {
				line2 = input.readLine();
				String result = solve(line2);
				output.write("Case #" + actualCase + ": " + result + "\n");
				System.out.println("Case #" + actualCase + ": " + result);
			}
			input.close();
			output.close();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {

		}
	}

	private static String solve(String line2) {
		Scanner sc = new Scanner(line2);
		sc.useDelimiter("/");
		long counter = sc.nextLong();
		long modulus = sc.nextLong();
		if (counter > modulus) {
		    return "impossible";			
		}
		if (counter == modulus) {
			return counter > 0 ?"0" : "impossible";
		}
//		kozos oszto keresese
		long div = lnko(modulus, counter);
//		System.out.println("counter: " + counter + ", modulus: " + modulus + ", lnko: " + div);
//		kozos osztoval osztjuk mind a kettot
		if (div > 1) {
			modulus = modulus / div;
			counter = counter / div;
		}
		double m = Math.log(modulus)/Math.log(2);
//		System.out.println(m);
		double c = Math.log(counter)/Math.log(2);
//		System.out.println(c);
		long ml = (long) m;
		if ((m - ml) > 0.00000000000001) {
		    return "impossible";
		} 
		long cl = (long) c;
		return Long.toString(ml - cl);
		 
	}

	private static long lnko(long a, long b) {
		long q = (long) (a / b);
//		System.out.println(q);
		long r =  a - (q * b);
		if (r == 0) {
			return b;
		} 
		return lnko(b, r);
//		return 0;
	}

}
