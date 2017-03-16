package codejams;

import java.io.BufferedReader;
import java.io.PrintWriter;

public class Cookie {
	
	public Cookie() {
		
	}
	
	public void testCase(BufferedReader br, PrintWriter pw) {
		try {
			String[] s = br.readLine().split(" ");
			double C = Double.parseDouble(s[0]);
			double F = Double.parseDouble(s[1]);
			double X = Double.parseDouble(s[2]);
			if (Main.debug) System.out.println(C+ " " +X+ " " + F);
			int n = 0;
			double r = compute(C,X,F,n);
			double r2 = r;
			while (r <= r2) {
				r2 = r;
				n++;
				r = compute(C,X,F,n);
			}
			pw.print(String.format("%.7f",r2));
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private double compute(double C,double X, double F,int n) {
		double r = 0;
		for (int a = 0;a < n;a++) {
			r += C / (2 + F*a);
		}
		r += X/(2+F*n);
		return r;
	}
	
}