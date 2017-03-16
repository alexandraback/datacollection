/* Filename: GCJ2016QC.java
 * Author: Mushiyo
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class GCJ2016QC {
	public static void main(String[] args) throws FileNotFoundException {
		// Scanner input = new Scanner(System.in);
		// PrintWriter out = new PrintWriter(System.out);
		Scanner input = new Scanner(new File("C-large.in"));
		PrintWriter out = new PrintWriter(new File("pC.out"));

		while (input.hasNext()) {
			int T = input.nextInt();

			for (int t = 1; t <= T; ++t) {
				out.printf("Case #%d:\n", t);

				int N = input.nextInt();
				int J = input.nextInt();

				int count = 0;
				int coin = buildCoin(N / 2);

				while (count < J && coin < 65536) {
					StringBuilder coinStr = new StringBuilder(
							Integer.toBinaryString(coin));
					coinStr.append(coinStr);
					
					out.print(coinStr);
					for(int base = 2; base <=10; ++base){
						out.printf(" %s", Long.parseLong(Integer.toBinaryString(coin), base));
					}
					out.println();
					
					coin += 2;
					
					++count;
				}
			}
		}

		out.close();
		input.close();
	}

	static int buildCoin(int N) {
		int num = 1;

		for (int i = 1; i < N; ++i) {
			num <<= 1;
		}

		num ^= 1; // same as ++num

		return num;
	}

}
