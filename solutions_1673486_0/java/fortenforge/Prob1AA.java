/*
PROG: ProbA
2012 Google CodeJam Round 1A
Problem A
*/

import java.io.*;
import java.util.*;

public class Prob1AA{

	public static void main(String [] args) throws IOException {
		//long start = System.currentTimeMillis();
		BufferedReader f = new BufferedReader(new FileReader("Prob1AAIN"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Prob1AA.out")));
		int N = Integer.parseInt(f.readLine());
		//System.out.println(N);
		for(int i = 0; i < N; i++){
			String[] s = (f.readLine()).split(" ");
			int A = Integer.parseInt(s[0]);
			int B = Integer.parseInt(s[1]);
			String[] charstyped = (f.readLine()).split(" ");
			double[] probs = new double[A];
			for(int j = 0; j < A; j++){
				probs[j] = Double.parseDouble(charstyped[j]);
			}
			double expected1 = 0;
			double[] fronproducts = new double[A+1];
			//double[] backproducts = new double[A+1];
			fronproducts[0] = 1;
			for(int j = 1; j <= A; j++){
				fronproducts[j] = probs[j-1]*fronproducts[j-1];
			}
			/*backproducts[0] = 1;
			for(int j = 1; j <= A; j++){
				backproducts[j] = probs[A - j]*backproducts[j-1];
			}*/
			double min = 100000*2 + 3;
			for(int j = 0; j <= A; j++){
				double expected = fronproducts[A-j]*(B - A + 2*j + 1) + (1-fronproducts[A-j])*(B + B - A + 2*j + 2);
				//System.out.println(expected);
				if(expected < min)
					min = expected;
			}
			double expectedstar = 2 + B;
			if(expectedstar < min)
				min = expectedstar;
			out.println("Case #" + (i+1) + ": " + min);
		}
		//long end = System.currentTimeMillis();
		//System.out.println(end - start);
		out.close();
	}
	

}
