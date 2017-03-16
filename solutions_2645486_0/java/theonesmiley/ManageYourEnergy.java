import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class ManageYourEnergy {
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
			ManageYourEnergy instance = new ManageYourEnergy();
			instance.solve(t);
		}
	
	}
	
	// ****** GLOBAL VARIABLES ******
	
	long[] v;
	long R;
	long E;
	int n;
	Map<Long, Long> memo;
	
	public ManageYourEnergy() {
	}
	
	public long maxGain(int i, long energy) {
		if (i >= n) return 0;
		long key = (energy << 20) + i;
		if (!memo.containsKey(key)) {
			long best = 0;
			for (long spent = 0; spent <= energy; ++spent) {
				long gain = spent * v[i];
				best = Math.max(best, gain + maxGain(i+1, Math.min(E, energy - spent + R)));
			}
			memo.put(key, best);
		}
		return memo.get(key);
	}
	
	public boolean solve(int caseNumber) {
		StringTokenizer st = new StringTokenizer(readLine());
		E = Long.parseLong(st.nextToken());
		R = Long.parseLong(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		v = new long[n];
		st = new StringTokenizer(readLine());
		memo = new HashMap<Long, Long>();
		for (int i = 0; i < n; ++i) v[i] = Long.parseLong(st.nextToken());
		
		System.out.println("Case #" + caseNumber + ": " + maxGain(0, E));
		return false;
	}


}
