import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class PasswordProblem {
	public static BufferedReader BR;
	
	public static String readLine() {
		try {
			return BR.readLine();
		} catch(Exception E) {
			System.err.println(E.toString());
			return null;
		}
	}
	
	
	// ****** MAIN ******
	
	public static void main(String [] args) throws Exception {
		BR = new BufferedReader(new InputStreamReader(System.in));
	
		int testcases = Integer.parseInt(readLine());
		for (int t = 1; t <= testcases; t++) {
			PasswordProblem instance = new PasswordProblem();
			instance.solve(t);
		}
	
	}
	
	// ****** GLOBAL VARIABLES ******
	
	
	
	public PasswordProblem() {
	}
	
	public boolean solve(int caseNumber) {
		StringTokenizer st = new StringTokenizer(readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		double[] p = new double[a];
		double[] probCorrectTo = new double[a+1]; probCorrectTo[0] = 1;
		st = new StringTokenizer(readLine());
		for (int i = 0; i < a; ++i) {
			p[i] = Double.parseDouble(st.nextToken());
			probCorrectTo[i+1] = probCorrectTo[i] * p[i];
		}
		double best = 2 + b; // option 3
		for (int numBackspace = 0; numBackspace <= a; ++numBackspace) {
			best = Math.min(best, numBackspace + b - (a - numBackspace) + 1 + (1-probCorrectTo[a-numBackspace]) * (1 + b));
		}
		
		System.out.println("Case #" + caseNumber + ": " + best);
		return false;
	}


}
