/* Filename: GCJ2016R1A_A.java
 * Author: Mushiyo
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class GCJ2016R1A_A {
	public static void main(String[] args) throws FileNotFoundException {
		// Scanner input = new Scanner(System.in);
		// PrintWriter out = new PrintWriter(System.out);
		 Scanner input = new Scanner(new File("A-small-attempt0.in"));
		 PrintWriter out = new PrintWriter(new File("pA.out"));

		while (input.hasNext()) {
			int T = input.nextInt();

			for (int t = 1; t <= T; ++t) {
				out.printf("Case #%d: ", t);
				String S = input.next();
				StringBuilder ans = new StringBuilder();
				ans.insert(0, S.charAt(0));
				
				for(int i = 1; i < S.length(); ++i){
					if(S.charAt(i) >= ans.charAt(0)){
						ans.insert(0, S.charAt(i));
					} else {
						ans.append(S.charAt(i));
					}
				}
				
				out.println(ans);
			}
		}

		out.close();
		input.close();
	}
}
