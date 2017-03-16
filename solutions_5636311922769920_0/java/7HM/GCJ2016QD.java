/* Filename: GCJ2016QD.java
 * Author: Mushiyo
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class GCJ2016QD {

	public static void main(String[] args) throws FileNotFoundException {
//		Scanner input = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		 Scanner input = new Scanner(new File("D-small-attempt0.in"));
		 PrintWriter out = new PrintWriter(new File("pD.out"));

		while (input.hasNext()) {
			int T = input.nextInt();

			for (int t = 1; t <= T; ++t) {
				int K = input.nextInt();
				int C = input.nextInt();
				int S = input.nextInt();
				
				out.printf("Case #%d:", t);
				for(int i = 1; i <= S; ++i){
					out.printf(" %d", i);
				}
				out.println();
			}
		}

		out.close();
		input.close();
	}

}
