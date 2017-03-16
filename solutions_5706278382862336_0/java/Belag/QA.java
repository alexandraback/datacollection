package blah;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class QA {
	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));

		int caseCnt = sc.nextInt();
		sc.nextLine();

		// Case number
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			pw.write("Case #" + caseNum + ": ");
			System.out.println("Case #" + caseNum + ": ");
			
			String frac = sc.next();
			String [] fraction = frac.split("/");
			double num = Double.parseDouble(fraction[0]);
			double dem = Double.parseDouble(fraction[1]);
			
			long numLong = Long.parseLong(fraction[0]);
			long demLong = Long.parseLong(fraction[1]);
			
			long[] reduceFrac = asFraction(numLong, demLong);
			long numReduce = reduceFrac[0];
			long demReduce = reduceFrac[1];
			
			boolean isOk = false;
			for(int i = 0;i<=40;i++) {
				if((long)Math.pow(2, i) == demReduce) {
					isOk = true;
					break;
				}
			}
			if(!isOk) {
				System.out.println("impossible");
				pw.print("impossible");
			}
			else {
			double result = num/dem;
				for(int i = 0;i<=40;i++) {
					if(1.0/Math.pow(2, i) <= result) {
						System.out.println(i);
						pw.print(i);
						break;
					}
				}
			}
			
			pw.print("\n");
		}

		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static long gcm(long a, long b) {
	    return b == 0 ? a : gcm(b, a % b); // Not bad for one line of code :)
	}

	public static long[] asFraction(long a, long b) {
	    long gcm = gcm(a, b);
	    long[] result = new long[2];
	    result[0] = a/gcm;
	    result[1] = b/gcm;
	    return result;
	}
}
