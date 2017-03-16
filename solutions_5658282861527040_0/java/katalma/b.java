package gcj2014.b1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Date;
import java.util.Scanner;

public class b {
		public static void main(String[] args) {
//			readAndSolve("resource/gcj2014/b1/b/sample.in", "resource/gcj2014/b1/b/sample.out");
			readAndSolve("resource/gcj2014/b1/b/B-small-attempt0.in", "resource/gcj2014/b1/b/B-small-attempt0.out");
		}

		/**
		 * @param inputName
		 * @param outputName
		 */
		private static void readAndSolve(String inputName, String outputName) {
			BufferedReader input = null;
			BufferedWriter output = null;
			Date d1 = new Date();
			try {
				input = new BufferedReader(new FileReader(inputName));
				output = new BufferedWriter(new FileWriter(outputName));
				String line1 = null;
				String line2 = null;
				int expectedCases = 0;
				int actualCase = -1;
				line1=input.readLine();
				expectedCases = Integer.parseInt(line1);
				for (actualCase = 1; actualCase<=expectedCases; actualCase++) {
					line2 = input.readLine();
					String result = solve(line2);
					output.write("Case #" + actualCase +": " + result + "\n");				
					System.out.println("Case #" + actualCase +": " + result );				
				}
				input.close();
				output.close();
			} catch (Exception e) {
				e.printStackTrace();
			} finally {
				
			}
		}

		private static String solve(String line2) {
			Scanner sc = new Scanner(line2);
			int a = sc.nextInt();
			int b = sc.nextInt();
			int k = sc.nextInt();
			int result = 0;
			for (int i = 0; i< a; i++) {
				for (int j=0; j<b; j++) {
					int and = i & j;
					if (and >=0 && and < k){
						result++;
					}
				}
			}
			return Integer.toString(result);
		}

}
