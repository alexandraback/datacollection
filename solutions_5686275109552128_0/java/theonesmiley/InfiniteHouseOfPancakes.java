import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class InfiniteHouseOfPancakes {
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
			InfiniteHouseOfPancakes instance = new InfiniteHouseOfPancakes();
			instance.solve(t);
		}
	
	}
	
	// ****** GLOBAL VARIABLES ******
	
	
	
	public InfiniteHouseOfPancakes() {
	}
	
	public boolean solve(int caseNumber) {
		int d = Integer.parseInt(readLine());
		int[] plates = new int[d];
		StringTokenizer st = new StringTokenizer(readLine());
		for (int i = 0; i < d; ++i) {
			plates[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(plates);
		int result = Integer.MAX_VALUE;
		for (int tallest = 1; tallest <= plates[d-1]; ++tallest) {
			int pauses = 0;
			for (int i = 0; i < d; ++i) if (plates[i] > tallest) {
				pauses += (plates[i] + tallest - 1) / tallest - 1;
			}
			result = Math.min(result, tallest + pauses);
		}
		System.out.println("Case #" + caseNumber + ": " + result);
		return false;
	}


}
