import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class StandingOvation {
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
			StandingOvation instance = new StandingOvation();
			instance.solve(t);
		}
	
	}
	
	// ****** GLOBAL VARIABLES ******
	
	
	
	public StandingOvation() {
	}
	
	public boolean solve(int caseNumber) {
		StringTokenizer st = new StringTokenizer(readLine());
		int sMax = Integer.parseInt(st.nextToken());
		int[] s = new int[sMax+1];
		String sString = st.nextToken();
		for (int k = 0; k <= sMax; ++k) {
			s[k] = (int) (sString.charAt(k) - '0');
		}
		int result = sMax;
		for (int friends = 0; friends <= sMax; ++friends) {
			int standing = friends;
			boolean done = true;
			for (int k = 0; k <= sMax; ++k) {
				if (standing >= k) {
					standing += s[k];
				} else {
					done = false;
					break;
				}
			}
			if (done) {
				result = friends;
				break;
			}
		}
		System.out.println("Case #" + caseNumber + ": " + result);
		return false;
	}


}
