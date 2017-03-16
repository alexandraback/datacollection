package by.bsu.fpm.semenkev;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

public class Fractiles {

   private static long[] IMPOSSIBLE = new long[0];
	
	public static void main(String[] args) throws Exception {
		solve(args.length > 0 ? args[0] : "D-small-attempt1.in");
	}
	
	private static long[] solve(int k, int c, int s) {
		int num = (k + (c-1)) / c;
		if (num > s) {
			return IMPOSSIBLE;
		}
		long[] answer = new long[num];
		long p0 = 1;
		for(int i=0; i<num; i++, p0 = Math.min(p0 + c, k)) {
			answer[i] = solveCase(k ,c, p0);
		}
		return answer;
	}
	
	private static long solveCase(long k, long c, long p0) {
		long tn = p0;
		long pn = p0;
		long tn1;
		long pn1;
		for(int n=2; n<=c; n++) {
			tn1 = (tn == k) ? k : tn + 1;
			pn1 = (pn - 1)*k + tn1;
			tn = tn1;
			pn = pn1;
		}
		return pn;
	}
	
	private static String getFileName(String filePath) {
		return filePath.replaceAll("\\.([^\\.]*)$", "");
	}
	
	private static void solve(String testFile) throws Exception {
		File inputFile = new File(testFile);
		File outputFile = new File(getFileName(inputFile.getAbsolutePath())+".out");
		BufferedReader input = new BufferedReader(new FileReader(inputFile));
		PrintWriter output = new PrintWriter(outputFile);
		solve(input, output);
		input.close();
		output.close();
	}
	
	private static void solve(BufferedReader input, PrintWriter output) throws Exception {
		int testNum = Integer.parseInt(input.readLine());
		for (int i=0; i<testNum; i++) {
			String[] rcw = input.readLine().split(" ");
			int k = Integer.parseInt(rcw[0]);
			int c = Integer.parseInt(rcw[1]);
			int s = Integer.parseInt(rcw[2]);
			long[] answer = solve(k, c ,s);
			output.format("Case #%d: ", i+1);
			if (answer == IMPOSSIBLE) {
				output.write("IMPOSSIBLE");
			} else if (answer.length > 0) {
				output.write(String.valueOf(answer[0]));
				for (int j=1; j<answer.length; j++) {
					output.write(' ');
					output.write(String.valueOf(answer[j]));
				}
			}
			output.write('\n');
		}
	}
	
	private static int pow2(int x) {
		return x*x;
	}
	
	private static int npow(int x, int n) {
		if (n == 0)
			return 1;
		else if (n == 1)
			return x;
	    else
	        return npow(x, n%2) * pow2(npow(x, n/2));
	}
	
}
