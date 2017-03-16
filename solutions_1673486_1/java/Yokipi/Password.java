package password;

import java.util.*;
import java.io.*;
import java.math.*;


public class Password {
	public static void main(String args[]) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader(new File("src/password/password.in")));
		FileWriter out = new FileWriter(new File("src/password/password.out"));
		
		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			String s = in.readLine();
			StringTokenizer st = new StringTokenizer(s);
			
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			
			String s2 = in.readLine();
			StringTokenizer st2 = new StringTokenizer(s2);
			
			double[] probs = new double[A];
			
			for (int p = 0; p < A; p++) {
				probs[p] = Double.parseDouble(st2.nextToken());
			}
			
			double E = Double.MAX_VALUE;
			double[] expecteds = new double[A+2];
			expecteds[A+1] = B+2;
			
			int i = 0;
			for (i = A; i >= 0; i--) {
				if (2*i > A+1) expecteds[i] = B+2;
				else break;
			}
			for (; i >= 0; i--) {
				double P = 1.0;
				for (int j = 0; j < A-i; j++) {
					P *= probs[j];
				}
				expecteds[i] = i + (B-A+i+1) + ((1-P) * (B+1));
			}
			
			for (double d : expecteds) {
				E = Math.min(d, E);
				if (E == B+2) break;
			}
			
			
			Formatter format = new Formatter();
			format.format("%.6f", E);
								 
			out.write("Case #" + t + ": " + format.toString() + "\n");
		}
		in.close();
		out.close();
		
	}
}
