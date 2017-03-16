package gcj;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class GCJ2014R1CA {

	String solve(long p, long q) {
		if (q % p == 0) {
			q = q / p;
			p = 1;
		}

		int ans = 0;
		boolean isNG = false;
		while (p < q) {
			ans++;
			if (q % 2 != 0) {
				isNG = true;
				break;
			}
			q /= 2;
		}

		while (!isNG) {
			p -= q;
			if (p <= 0)
				break;
			while (p < q) {
				if (q % 2 != 0) {
					isNG = true;
					break;
				}
				q /= 2;
			}
		}

		if (isNG || p < 0)
			return "impossible";
		return ans + "";
	}

	String solve(Scanner sc) {
		StringBuilder sb = new StringBuilder();
		int testCaseSize = sc.nextInt();
		for (int tc = 1; tc <= testCaseSize; tc++) {
			String[] ss = sc.next().split("/");
			long p = Long.parseLong(ss[0]);
			long q = Long.parseLong(ss[1]);
			sb.append("Case #").append(tc).append(": ").append(solve(p, q))
					.append('\n');
		}
		return sb.toString();
	}

	String solve(String inputFilePath) throws FileNotFoundException {
		Scanner sc = new Scanner(new FileReader(inputFilePath));
		String ans = solve(sc);
		sc.close();
		return ans;
	}

	final static String WORK_DIR = "dat/gcj2014r1c/";

	public static void main(String[] args) throws IOException {
		//		String fileName = "A-sample";
		String fileName = "A-small-attempt1";
		//		String fileName = "A-large";
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR
				+ outputFileName));
		pw.print(new GCJ2014R1CA().solve(WORK_DIR + inputFileName));
		pw.flush();
		pw.close();
	}

}
