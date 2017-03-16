package cookieClickerAlpha;

import java.util.*;
import java.io.*;


public class CookieClickerAlpha {
	double result;
	String res;

	double getTime(long numFarms, double C, double F, double X){
		long i = 0;
		result = X/(2+numFarms*F);
		while (i<numFarms){
			result += C/(2+i*F);
			i++;
		}
		return result;
	}

	String solve(double C, double F, double X){
		int numFarms = 0;
		double last = X/2;
		double test = (C/2 + X/(2+F));
		while (test<last){
			numFarms++;
			last = X/(2+F*numFarms);
			test = (C/(2+numFarms*F))+(X/(2+(numFarms+1)*F));
		}
		result = getTime(numFarms,C,F,X);
		return String.format("%.7f", result);
	}

	public void doMain() throws Exception {
		Scanner fr = new Scanner(new FileReader("src/cookieClickerAlpha/B-small.in"));
		PrintWriter fw = new PrintWriter(new FileWriter("src/cookieClickerAlpha/B-small.out"));
		
		int caseCnt = fr.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			double C;
			double F;
			double X;
			C = fr.nextDouble();
			F = fr.nextDouble();
			X = fr.nextDouble();

			res = solve(C,F,X);

			
			fw.println("Case #" + caseNum + ": " + res);
			
			System.out.println("Finished " + caseNum + " in " + (System.currentTimeMillis() - time) + "ms.");
		}
		
		fw.flush();
		fw.close();
		fr.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new CookieClickerAlpha()).doMain();
	}
}
