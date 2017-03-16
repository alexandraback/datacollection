package qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class CookieClicker {
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
		PrintWriter out = new PrintWriter("out");
		int t = Integer.parseInt(in.readLine());
		
		for(int i = 1; i <= t; i++) {
			
			String ss[] = in.readLine().split(" ");
			double C = Double.parseDouble(ss[0]);
			double F = Double.parseDouble(ss[1]);
			double X = Double.parseDouble(ss[2]);
			int n = (int) Math.ceil((X/C) - (2/F) - 1);
			//System.out.println("n = " + n);
			double T = 0;
			double f = 2;
			for(int j = 1; j <= n; j++) {
				
				T += C/f;
				f += F;
				
			}
			T += X/f;
			out.println("Case #" + i + ": " + (Math.round(T * 10000000.0) / 10000000.0));
			
		}
		out.close();
		
	}

}
