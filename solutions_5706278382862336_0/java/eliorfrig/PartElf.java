import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.Scanner;

public class PartElf {

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		String inputFilename = "A-small-attempt0.in";
		StringBuilder answer = new StringBuilder();
		try {
			FileInputStream fis = new FileInputStream(inputFilename);
			Scanner sc = new Scanner(fis);
			int testCases = sc.nextInt();
			for (int i=1; i<=testCases; i++) {
				String[] pq = sc.next().split("/");
				int P = Integer.parseInt(pq[0]);
				int Q = Integer.parseInt(pq[1]);
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

	private static String solve(double p, double q) {
		if (!isPowerOfTwo(q)) {
			return "impossible";
		}
		if (p == 1) {
			return "" + (int) (Math.log10(q)/Math.log10(2));
		}
		int gen = 1;
		while ((p/q < 1.0/2) && gen<40) {
			q = q/2;
			gen++;
		}
		if (gen >= 40) {
			return "impossible";
		}
		return ""+gen;
	}

	private static boolean isPowerOfTwo(double q) {
		return q == 1 || q == 2 || q == 4 || q == 8 || q == 16 || q == 32 ||
				q == 64 || q == 128 || q == 256 || q == 512;
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
