package gcj2015.qr;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class a1 {
	public static void main(String[] args) {
//		readAndSolve("resource/gcj2015/qr/a1/sample.in", "resource/gcj2015/qr/a1/sample.out");
//		readAndSolve("resource/gcj2015/qr/a1/A-small-attempt0.in", "resource/gcj2015/qr/a1/A-small-attempt0.out");
		readAndSolve("resource/gcj2015/qr/a1/A-large.in", "resource/gcj2015/qr/a1/A-large.out");
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
			int expectedCases = 0;
			int actualCase = -1;
			line1=input.readLine();
			expectedCases = Integer.parseInt(line1);
			for (actualCase = 1; actualCase<=expectedCases; actualCase++) {
				line1=input.readLine();
				String result = solve(line1);
				output.write("Case #" + actualCase +": " + result + "\n");				
//				System.out.println("Case #" + actualCase +": " + result );				
			}
			input.close();
			output.close();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			
		}
	}

	private static String solve(String line1) {
		Scanner sc = new Scanner(line1);
		int maxS = sc.nextInt();
		String shys = sc.next();
		int[] s = new int [maxS +1];
		char[] chs = shys.toCharArray();
		char _0 = '0';
		int needed = 0;
		int available = 0;
		for (int i = 0; i < chs.length; i++) {
			s[i] = chs[i] - _0;
			int d = i - available - needed;
//			System.out.println("i " + i + " available: " + available + " needed: " + needed + " d: " + d);
			if (d>0) {
				needed +=d;
			}
			available +=  s[i];
		}
		
		
		return Integer.toString(needed);
	}


	
	
}
