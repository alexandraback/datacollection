/* Filename: GCJ2016QA.java
 * Author: Mushiyo
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class GCJ2016QA {

	public static void main(String[] args) throws FileNotFoundException {
//		Scanner input = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner input = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new File("pA.out"));

		while (input.hasNext()) {
			int T = input.nextInt();

			for (int t = 1; t <= T; ++t) {
				out.printf("Case #%d: ", t);
				
				int N = input.nextInt();
				
				if(N == 0){
					out.println("INSOMNIA");
					continue;
				}
				
				int current = N;
				int[] countDigit = new int[10];
				count(current, countDigit);
				
				while(isAllDigitViewed(countDigit) == false){
					current += N;
					count(current, countDigit);
				}
				
				out.println(current);
			}
			
		}

		out.close();
		input.close();
	}
	
	static boolean isAllDigitViewed(int[] countDigit){
		for(int i = 0; i < countDigit.length; ++i){
			if(countDigit[i] == 0){
				return false;
			}
		}
		
		return true;
	}

	static void count(int num, int[] countDigit){
		String numStr = Integer.toString(num);

		for(int i = 0; i < numStr.length(); ++i){
			++countDigit[numStr.charAt(i) - '0'];
		}
	}
}
