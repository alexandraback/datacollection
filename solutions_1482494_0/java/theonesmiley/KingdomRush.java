import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class KingdomRush {
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
			KingdomRush instance = new KingdomRush();
			instance.solve(t);
		}
	}
	
	// ****** GLOBAL VARIABLES ******
	
	
	
	public KingdomRush() {
	}
	
	public boolean solve(int caseNumber) {
		int n = Integer.parseInt(readLine());
		int[][] starsRequired = new int[n][2];
		for (int i = 0; i < n; ++i) {
			StringTokenizer st = new StringTokenizer(readLine());
			starsRequired[i][0] = Integer.parseInt(st.nextToken());
			starsRequired[i][1] = Integer.parseInt(st.nextToken());
		}
		int[] starsEarnedOn = new int[n];
		int stars = 0;
		int played = 0;
		while (true) {
			boolean earnTwo = false, earnOneFromPlayed = false, earnOne = false;
			for (int i = 0; i < n && !earnTwo; ++i) if (stars >= starsRequired[i][1] && starsEarnedOn[i] == 0) {
				stars += 2;
				starsEarnedOn[i] = 2;
				earnTwo = true;
			}
			if (!earnTwo) for (int i = 0; i < n && !earnOneFromPlayed; ++i) if (stars >= starsRequired[i][1] && starsEarnedOn[i] == 1) {
				++stars;
				starsEarnedOn[i] = 2;
				earnOneFromPlayed = true;
			}
			if (!earnTwo && !earnOneFromPlayed) {
				int level = -1;
				for (int i = 0; i < n; ++i) {
					if (stars >= starsRequired[i][0] && starsEarnedOn[i] == 0 && (level < 0 || starsRequired[i][1] > starsRequired[level][1])) {
						level = i;
					}
				}
				if (level >= 0) {
					++stars;
					starsEarnedOn[level] = 1;
					earnOne = true;
				}
			}
			if (earnTwo || earnOneFromPlayed || earnOne) {
				++played;
			} else {
				break;
			}
		}
		System.out.println("Case #" + caseNumber + ": " + (stars == n*2 ? ("" + played) : "Too Bad"));
		return false;
	}


}
