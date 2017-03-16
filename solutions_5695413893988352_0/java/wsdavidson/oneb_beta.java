import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class oneb_beta {
	public static void main(String[] args) {
		try {
			process();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static void process()
	throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int testCases = Integer.parseInt(reader.readLine());
		
		for (int i = 0; i < testCases; ++i) {
			System.out.println("Case #" + (i+1) + ":" + processTestCase(reader));
		}
		
		reader.close();
	}
	
	private static String processTestCase(BufferedReader reader)
	throws IOException {
		String[] arr = reader.readLine().split(" ");
		
		String C = arr[0];
		String J = arr[1];
		
		int[] arrC = new int[C.length()];
		int[] arrJ = new int[C.length()];
		
		for (int i = 0; i < arrC.length; ++i) {
			arrC[arrC.length-1-i] = C.charAt(i) == '?' ? -1 : C.charAt(i) - '0';
			arrJ[arrJ.length-1-i] = J.charAt(i) == '?' ? -1 : J.charAt(i) - '0';
		}
		
		// System.out.println("Testing " + C + " " + J);
		
		bestDiff = Long.MAX_VALUE;
		bestLC = 0;
		bestLJ = 0;
		bestLCS = "";
		bestLJS = "";
		
		recSolveC(arrC, arrJ, 0);
		
		return " " + bestLCS + " "+ bestLJS;
	}
	
	private static void recSolveC(int[] arrC, int[] arrJ, int index) {
		if (index == arrC.length) {
			recSolveJ(arrC, arrJ, 0);
		}
		else if (arrC[index] != -1) {
			recSolveC(arrC, arrJ, index+1);
		}
		else {
			arrC[index] = 0;
			recSolveC(arrC, arrJ, index+1);
			arrC[index] = 1;
			recSolveC(arrC, arrJ, index+1);
			arrC[index] = 8;
			recSolveC(arrC, arrJ, index+1);
			arrC[index] = 9;
			recSolveC(arrC, arrJ, index+1);
			
			if (arrJ[index] != -1) {
				if (arrJ[index] != 0) {
					arrC[index] = arrJ[index]-1;
					recSolveC(arrC, arrJ, index+1);
				}
				if (arrJ[index] != 9) {
					arrC[index] = arrJ[index]+1;
					recSolveC(arrC, arrJ, index+1);
				}
				arrC[index] = arrJ[index];
				recSolveC(arrC, arrJ, index+1);
			}
			arrC[index] = -1;
		}
	}
	
	private static long bestDiff = Long.MAX_VALUE;
	private static long bestLC = Long.MAX_VALUE;
	private static long bestLJ = Long.MAX_VALUE;
	private static String bestLCS = "";
	private static String bestLJS = "";
	
	private static void recSolveJ(int[] arrC, int[] arrJ, int index) {
		if (index == arrC.length) {
			long lc = 0;
			long lj = 0;
			String lcs = "";
			String ljs = "";
			
			// System.out.println("comparing " + Arrays.toString(arrC) + " " + Arrays.toString(arrJ));
			
			for (int i = 0; i < arrC.length; ++i) {
				lc += (long) arrC[i] * Math.pow(10, i);
				lj += (long) arrJ[i] * Math.pow(10, i);
				lcs = "" + arrC[i] + lcs;
				ljs = "" + arrJ[i] + ljs;
			}
			
			// System.out.println("  -- " + lc + " " + lj);
			
			long diff = Math.abs(lc-lj);
			if (diff < bestDiff) {
				bestDiff = diff;
				bestLC = lc;
				bestLJ = lj;
				bestLCS = lcs;
				bestLJS = ljs;
				// System.out.println("  -- new best " + bestDiff + " " + lc + " " + lj);
			}
			else if (diff == bestDiff) {
				if (lc < bestLC || (lc == bestLC && lj < bestLJ)) {
					bestLC =  lc;
					bestLJ =  lj;
					bestLCS = lcs;
					bestLJS = ljs;
					// System.out.println("  -- new best " + bestDiff + " " + lc + " " + lj + " " + bestLC + " " + bestLJ);
				}
			}
		}
		else if (arrJ[index] != -1) {
			recSolveJ(arrC, arrJ, index+1);
		}
		else {
			arrJ[index] = 0;
			recSolveJ(arrC, arrJ, index+1);
			arrJ[index] = 1;
			recSolveJ(arrC, arrJ, index+1);
			arrJ[index] = 8;
			recSolveJ(arrC, arrJ, index+1);
			arrJ[index] = 9;
			recSolveJ(arrC, arrJ, index+1);
			
			if (arrC[index] != -1) {
				if (arrC[index] != 0) {
					arrJ[index] = arrC[index]-1;
					recSolveJ(arrC, arrJ, index+1);
				}
				if (arrC[index] != 9) {
					arrJ[index] = arrC[index]+1;
					recSolveJ(arrC, arrJ, index+1);
				}
				arrJ[index] = arrC[index];
				recSolveJ(arrC, arrJ, index+1);
			}
			arrJ[index] = -1;
		}
	}
}