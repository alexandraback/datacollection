import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class Dijkstra {
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
			Dijkstra instance = new Dijkstra();
			instance.solve(t);
		}
	
	}
		
	public static int mult(int a, int b) {
		int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;
		a = Math.abs(a);
		b = Math.abs(b);
		if (a < 1 || a > 4 || b < 1 || b > 4) throw new IllegalArgumentException();
		if (a == 1 || b == 1) return sign * a * b;
		if (a == b) return sign * -1;
		int result = (9 - a - b) * ((a%3 == b-2) ? -1 : 1);
		return sign*result;
	}
	
	public Dijkstra() {
	}
	
	public boolean solve(int caseNumber) {
		StringTokenizer st = new StringTokenizer(readLine());
		int L = Integer.parseInt(st.nextToken());
		long X = Long.parseLong(st.nextToken());
		int[] s = new int[L];
		String line = readLine();
		int product = 1;
		for (int m = 0; m < L; ++m) {
			s[m] = 2 + (line.charAt(m) - 'i');
			product = mult(product, s[m]);
		}
		int cycleLength = 4;
		if (product == -1) cycleLength = 2;
		if (product == 1) cycleLength = 1;
		int[] powers = new int[cycleLength];
		powers[0] = 1;
		for (int p = 1; p < cycleLength; ++p) powers[p] = mult(powers[p-1], product);
		boolean possible = false;
		if (powers[(int) (X % cycleLength)] == -1) {
			long bestI = -1;
			for (int p = 0; bestI < 0 && p < X && p < cycleLength; ++p) {
				int leftProduct = 1;
				for (int m = 0; bestI < 0 && m < L; ++m) {
					leftProduct = mult(leftProduct, s[m]);
					if (mult(powers[p], leftProduct) == 2) {
						bestI = ((long) L) * p + m + 1;
					}
				}
			}
			long bestK = -1;
			for (int p = 0; bestK < 0 && p < X && p < cycleLength; ++p) {
				int rightProduct = 1;
				for (int m = 0; bestK < 0 && m < L; ++m) {
					rightProduct = mult(s[L-1-m], rightProduct);
					if (mult(rightProduct, powers[p]) == 4) {
						bestK = X * L - L * p - m - 1;
					}
				}
			}
			if (bestI >= 0 && bestK >= 0 && bestI < bestK) possible = true;
		}
		System.out.println("Case #" + caseNumber + ": " + (possible ? "YES" : "NO"));
		return false;
	}


}
