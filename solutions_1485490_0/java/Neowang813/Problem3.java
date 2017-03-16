import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.*;

public class Problem3 {
	public static class Pair {
		long num;
		int type;

		public Pair(long n, int t) {
			num = n;
			type = t;
		}
		public String toString(){
			return "["+num+":"+type+"]";
		}
	}

	public static void main(String[] args) throws FileNotFoundException {

		String inputFile = "C-small-attempt1.in";
		String outputFile = "pro3.out";
		Scanner inputScanner = new Scanner(new FileInputStream("d:\\codejam\\"
				+ inputFile));
		PrintStream ps = new PrintStream(new FileOutputStream("d:\\codejam\\"
				+ outputFile));
		int totalCaseNum = inputScanner.nextInt();
		inputScanner.nextLine();
		// -----------------------------------------------

		// -----------------------------------------------
		for (int caseNum = 1; caseNum <= totalCaseNum; caseNum++) {
			String line = inputScanner.nextLine();
			String prefix = "Case #" + caseNum + ": ";
			StringBuilder output = new StringBuilder(prefix);
			// -----------------------------------------------
			Scanner sc = new Scanner(line);
			int N = sc.nextInt();
			int M = sc.nextInt();
			line = inputScanner.nextLine();
			Scanner scA = new Scanner(line);
			Pair[] streamA = new Pair[N];
			for (int n = 0; n < N; n++) {
				long na = scA.nextLong();
				int ta = scA.nextInt();
				streamA[n] = new Pair(na, ta);
			}

			Pair[] streamB = new Pair[M];
			line = inputScanner.nextLine();
			Scanner scB = new Scanner(line);
			for (int m = 0; m < M; m++) {

				long nb = scB.nextLong();
				int tb = scB.nextInt();
				streamB[m] = new Pair(nb, tb);
			}

			output.append(calc(0, 0, streamA, streamB));

			// -----------------------------------------------
			System.out.println(output);
			ps.println(output);
		}
	}

	public static long calc(int sa, int sb, Pair[] streamA, Pair[] streamB) {
		if (sa >= streamA.length || sb >= streamB.length) {
			return 0;
		}

		long sum = 0;
		long inter = 0;
		if (streamA[sa].type == streamB[sb].type) {
			inter += Math.min(streamA[sa].num, streamB[sb].num);
			streamA[sa].num -= inter;
			streamB[sb].num -= inter;
		}
		

		long throwA = calc(sa + 1, sb, streamA, streamB);
		long throwB = calc(sa, sb + 1, streamA, streamB);
		sum += inter + Math.max(throwA, throwB);

		if (streamA[sa].type == streamB[sb].type) {
			streamA[sa].num += inter;
			streamB[sb].num += inter;
		}
		return sum;
	}
}
