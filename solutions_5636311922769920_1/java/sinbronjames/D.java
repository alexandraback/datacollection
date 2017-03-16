import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {

	public static void main(String[] args) throws IOException {
		// Scanner in = new Scanner (System.in);
		Scanner in = new Scanner(new File("D-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("D-large.txt"));
		int T = in.nextInt();
		for (int test = 1; test <= T; test++) {
			int K = in.nextInt();
			int C = in.nextInt();
			int S = in.nextInt();
			out.print("Case #" + test + ":");
			if (S < K - C + 1) {
				out.print(" IMPOSSIBLE");
			} else {
				long start = 1;

				for (int i = 1; i <= C - 1; i++) {
					if (i <= K - 1) {
						start = K * (start - 1) + i+1;
					} else {
						start = K * (start - 1) + 1;
					}
				}
				for (int j = 0; j < Math.max(1, K - C + 1); j++) {
					out.print(" ");
					out.print(start + j);
				}
			}
			out.println();
		}

		out.close();
	}

}
