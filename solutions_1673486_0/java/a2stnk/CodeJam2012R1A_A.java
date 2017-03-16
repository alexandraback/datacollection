
import java.io.*;
import java.util.*;
import java.lang.*;

public class CodeJam2012R1A_A {
	public double calc(int A, int B, double[] p) {

		double continueInput = B-A+1;
		double returnNow = B+2;
		
		double bestExpected=B+A+1;
		double correct=1;
		for(int i=0; i<A; i++) {
			correct *= p[i];
			double expected = correct*(B-A+2*(A-i-1)+1)+(1-correct)*(2*B-A+2*(A-i-1)+2);
			bestExpected = Math.min(bestExpected, expected);
		}
		
		return Math.min(bestExpected, B+2);
	}
	
	public static void main(String[] args) {
		try{
			(new CodeJam2012R1A_A()).exec("2012R1A_1A-small.in", "2012R1A_1A-small.out");
//			(new CodeJam2012R1A_A()).exec("2012R1A_1A-large.in", "2012R1A_1A-large.out");
			}catch(Exception ex) {
				
			}
	}

	public final void exec(String inFileName, String outFileName) throws Exception{
		BufferedReader	inReader	= new BufferedReader(new FileReader(inFileName));
		PrintWriter		outWriter	= new PrintWriter(new BufferedWriter(new FileWriter(outFileName)));
		int caseNums=0;
		caseNums = Integer.parseInt(inReader.readLine());
		
		for(int i=0; i<caseNums; i++) {
			String[] input = inReader.readLine().split(" ");
			int A = Integer.valueOf(input[0]);
			int B = Integer.valueOf(input[1]);
			input = inReader.readLine().split(" ");
			double[] p = new double[A];
			for(int j=0; j<A; j++) {
				p[j] = Double.valueOf(input[j]);
			}
			double outStr = calc(A, B, p);

			String fmtOutStr="Case #" + (i+1) + ": " + outStr;	
			outWriter.println(fmtOutStr);
			System.out.println(fmtOutStr);
		}

		outWriter.close();
		inReader.close();
	}
}
