import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class OminousOmino {
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
			OminousOmino instance = new OminousOmino();
			instance.solve(t);
		}
	
	}
	
	// ****** GLOBAL VARIABLES ******
	
	
	
	public OminousOmino() {
	}
	
	public boolean solve(int caseNumber) {
		StringTokenizer st = new StringTokenizer(readLine());
		int X = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		int L = Math.max(R, C);
		int S = Math.min(R, C);
		String result = "RICHARD";
		if (L >= X && S >= (X+1)/2 && X < 7 && (R*C) % X == 0) {
			if (X == 4) {
				if (S > 2) result = "GABRIEL";
			} else if (X == 5) {
				if (S > 3) result = "GABRIEL";
			} else if (X == 6) {
				if (S > 3) result = "GABRIEL";
			} else {
				result = "GABRIEL";
			}
		}
		System.out.println("Case #" + caseNumber + ": " + result);
		return false;
	}


}
