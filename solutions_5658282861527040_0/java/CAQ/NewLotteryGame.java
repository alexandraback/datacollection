package gcj2014;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class NewLotteryGame {
	static String PATH = "data/gcj2014/1b/", PROBLEM = "B", SIZE = "small",
			ATTEMPT = "0";

	static long solve1(long A, long B, long K) {
		long win = 0;
		for (long a = 0; a < A; a++)
			for (long b = 0; b < B; b++)
				if ((a & b) < K)
					win++;
		return win;
	}

	public static void main(String[] args) throws IOException {
		String filename = PATH + PROBLEM + "-" + SIZE;
		if (SIZE.equals("small"))
			filename += "-attempt" + ATTEMPT;
		Scanner sc = new Scanner(new File(filename + ".in"));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(filename + ".out"));
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			System.out.println("Case " + t);

			long A = sc.nextLong();
			long B = sc.nextLong();
			long K = sc.nextLong();

			long result = solve1(A, B, K);

			bw.write("Case #" + (t + 1) + ": " + result);
			bw.newLine();
		}
		sc.close();
		bw.close();
	}
}
