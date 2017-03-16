package codejam2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class RecycledNumbers {

	public static void main(String[] args) throws Exception {

		Scanner scanner = new Scanner(new BufferedReader(new FileReader(
				"A-large-practice.in.txt")));
		Output out = new Output("B.out");

		int T = scanner.nextInt();

		for (int t = 1; t <= T; t++) {

			int A = scanner.nextInt();
			int B = scanner.nextInt();
			
			int count = 0;

			for(int m = A; m < B; m++ ){
				
				String strM = "" + m;
				HashSet<String> cache = new HashSet<String>();
				
				for(int p = 1; p < strM.length(); p ++){
					
					if(strM.charAt(p) < strM.charAt(0)){
						continue;
					}
					
					String strN = strM.substring(p) + strM.substring(0, p);
					
					int n = Integer.parseInt(strN);
					if(n > m && n <= B && !cache.contains(strN)){
						cache.add(strN);
						count ++;
						//System.out.println(strM + " " + strN);
					}
				}
			}

			out.format("Case #%d: %d\n", t, count);
		}

		scanner.close();
		out.close();
	}

	static class Output {

		PrintWriter pw;

		public Output(String filename) throws IOException {
			pw = new PrintWriter(new BufferedWriter(new FileWriter(filename)));
		}

		public void print(String s) {
			pw.print(s);
			System.out.print(s);
		}

		public void println(String s) {
			pw.println(s);
			System.out.println(s);
		}

		public void format(String format, Object... args) {
			pw.format(format, args);
			System.out.format(format, args);
		}

		public void close() {
			pw.close();
		}
	}

}
