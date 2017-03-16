package gcj2015.qr;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Date;

public class b1 {
	public static void main(String[] args) {
//		readAndSolve("resource/gcj2015/qr/b1/sample.in", "resource/gcj2015/qr/b1/sample.out");
		readAndSolve("resource/gcj2015/qr/b1/B-small-attempt0.in", "resource/gcj2015/qr/b1/B-small-attempt0.out");
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
				line1=input.readLine();
				line2=input.readLine();
				String result = solve(line1, line2);
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

	private static String solve(String line1, String line2) {
		String[] strArray = line2.split(" ");
		int[] p = new int[strArray.length];
		for(int i = 0; i < strArray.length; i++) {
			p[i] = Integer.parseInt(strArray[i]);
		}
		Arrays.sort(p);
		int max = p[p.length-1];
		int from = 0;
		for (int j = 1; j <p[p.length-1]; j++) {
			for (int i = j; i> 0; i--) {
				if (canDo(p, i, (j-i))) {
					return Integer.toString(j);
				}
			}
		}
		return Integer.toString(max);
	}

	private static boolean canDo(int[] p, int i, int j) {
		if (p[p.length-1] <= i) {
			return true;
		}
		int count = 0;
		for (int k = p.length-1; k>=0 && p[k]>i ; k--) {
			count += ((p[k] +i-1) /i) -1;
		}
		return count <=j;
	}

	
}
