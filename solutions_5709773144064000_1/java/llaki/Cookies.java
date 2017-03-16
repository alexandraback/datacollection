import java.util.*;
import java.io.*;

public class Cookies {
 	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int numTests = sc.nextInt();
		PrintWriter pw = new PrintWriter(System.out);
		double[] timeFor = new double[200000];
		for(int test=1; test<=numTests; test++){
			C = sc.nextDouble();
			F = sc.nextDouble();
			X = sc.nextDouble();
			timeFor[0] = 0;
			for(int nf=1; nf < timeFor.length; nf++){
				timeFor[nf] = timeFor[nf-1];
				double rate = 2.0 + (nf-1)*F;
				timeFor[nf] += C/rate;
			}
			
			double T = X/2.0;
			for(int nf=0; nf < timeFor.length; nf++){
				double curTime = timeFor[nf];
				double rate = 2 + nf*F;
				curTime += X/rate;
				T = Math.min(T, curTime);
			}
			pw.println("Case #"+test+": "+T);
		}
		pw.flush();
		pw.close();
	}
 	
 	
 	static double C, F, X;
 	
 	
}
