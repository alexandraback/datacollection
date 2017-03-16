package b1;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("C-small.in"));
		PrintWriter out = new PrintWriter(new FileWriter(
				new File("c-small.out")));
		int n = sc.nextInt();

		for (int T = 1; n-- > 0; T++) {
			long N = sc.nextLong();
			int total= 0;
			int[][] hikers = new int[2][3];
			for(int i = 0;i<N;i++) {
				hikers[i][0] = sc.nextInt();
				hikers[i][2] = sc.nextInt();
				hikers[i][1] = sc.nextInt();
			}
			if(N == 0 || N == 1) {
				out.println("Case #" + T + ": " + total);
				System.out.println("Case #" + T + ": " + total);
				continue;
			}
			double timeToEnd0 = ((double) hikers[0][1] * (double)(360 - hikers[0][0]) )/ 360.0;
			double timeToEnd1 = ((double) hikers[1][1] * (double)(360 - hikers[1][0]) )/ 360.0;
			
			if(timeToEnd0 < timeToEnd1) {
				// 0 est plus rapide
				if(timeToEnd0 + hikers[0][1] <= timeToEnd1) {
					total = 1;
				}
			} else {
				// 1 est plus rapide
				if(timeToEnd1 + hikers[1][1] <= timeToEnd0) {
					total = 1;
				}
			}
			
			out.println("Case #" + T + ": " + total);
			System.out.println("Case #" + T + ": " + total);
		}
		out.flush();
	}
}