package gcj;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class GCJ2014R1BB {

	String solve(int a, int b, int k) {
		int ans = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if ((i & j) < k) {
					ans++;
				}
			}
		}
		return ans + "";
	}

	String solve(Scanner sc) {
		StringBuilder sb = new StringBuilder();
		int testCaseSize = sc.nextInt();
		for (int tc = 1; tc <= testCaseSize; tc++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int k = sc.nextInt();
			sb.append("Case #").append(tc).append(": ").append(solve(a, b, k))
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

	final static String WORK_DIR = "dat/gcj2014r1b/";

	public static void main(String[] args) throws IOException {
//		String fileName = "B-sample";
				String fileName = "B-small-attempt0";
		//		String fileName = "B-large";
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR
				+ outputFileName));
		pw.print(new GCJ2014R1BB().solve(WORK_DIR + inputFileName));
		pw.flush();
		pw.close();
	}

}
