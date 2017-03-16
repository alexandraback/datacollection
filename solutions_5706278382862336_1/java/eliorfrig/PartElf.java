import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class PartElf {

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		String inputFilename = "A-large.in";
		StringBuilder answer = new StringBuilder();
		try {
			FileInputStream fis = new FileInputStream(inputFilename);
			Scanner sc = new Scanner(fis);
			int testCases = sc.nextInt();
			for (int i=1; i<=testCases; i++) {
				String[] pq = sc.next().split("/");
				BigInteger P = new BigInteger(pq[0]);
				BigInteger Q = new BigInteger(pq[1]);
				String ans = solve(P, Q);
				answer.append("Case #" + i + ": " + ans + System.lineSeparator());
			}
			sc.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		writeOutput(answer.toString());
		System.out.println("in " + (System.currentTimeMillis() - start));
	}

	private static String solve(BigInteger p, BigInteger q) {
		BigInteger gcd = p.gcd(q);
		p = p.divide(gcd);
		q = q.divide(gcd);
		double log2Qd = (Math.log10(q.doubleValue())/Math.log10(2));
		int log2Q = (int) log2Qd;
		if (log2Q != log2Qd) {
			return "impossible";
		}
		if (p.longValue() == 1) {
			return "" + log2Q;
		}
		int gen = 1;
		BigInteger two = new BigInteger("2");
		while ((p.doubleValue()/q.doubleValue() < 1.0/2) && gen<40) {
			q = q.divide(two);
			gen++;
		}
		if (gen >= 40) {
			return "impossible";
		}
		return ""+gen;
	}

	private static void writeOutput(String string) {
		try {
			String outputFilename = "output.txt";
			BufferedWriter bw = new BufferedWriter(new FileWriter(outputFilename));
			bw.write(string);
			bw.close();
			System.out.println("success!");
		} catch (Exception e) {
			System.out.println("error!");
		}
	}

}
