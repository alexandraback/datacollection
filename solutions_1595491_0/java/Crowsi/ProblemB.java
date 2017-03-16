package qualification;

import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.Vector;

public class ProblemB {
	
	static Scanner scan = new Scanner(System.in);
	
	public static void main(String[] args) {

		

		int cases = scan.nextInt();
		
		for ( int i = 1; i <= cases; i++ ) {
			
			System.out.println("Case #" + i + ": " + solveCase());
			
			
		}

	}
	
	public static int solveCase() {
		int numGooglers = scan.nextInt();
		int numSurprising = scan.nextInt();
		int p = scan.nextInt();
		
		Vector<Triplet> containsGreaterThanP = new Vector<Triplet>();
		Vector<Triplet> containsPminus1 = new Vector<Triplet>();
		
		for ( int j = 0; j < numGooglers; j++ ) {
			Triplet t = new Triplet();
			
			int score = scan.nextInt();
			int n = Math.round( score / 3f );
			int n_2 = score - 2*n;
			
			// Ordered triplets
			if ( n_2 > n ) {
				t.add(n_2);
				t.add(n);
				t.add(n);
			} else {
				t.add(n);
				t.add(n);
				t.add(n_2);
			}
			
			if ( t.containsGreaterThan(p) ) {
				// Check if it can be made surprising
				containsGreaterThanP.add(t);
			} else if ( t.contains(p-1) > 1 && p > 1 && t.contains(0) <= 1) {
				containsPminus1.add(t);
			}
		}
//				System.out.println("Googlers: " + numGooglers);
//		System.out.println("Surprising: " + numSurprising);
//		System.out.println("P: " + p);
//		System.out.println(containsGreaterThanP);
//		System.out.println(containsPminus1);
		
		return containsGreaterThanP.size() + Math.min(numSurprising, containsPminus1.size());
		

	}
	
	static class Triplet {
		int[] values = new int[3];
		
		int i = 0;
		
		public void add(int a) {
			if ( i > 2)
				throw new InputMismatchException("Bad input");
			
			values[i] = a;
			i++;
		}
		
		public int contains(int v) {
			
			int retval = 0;
			
			retval += values[0] == v ? 1 : 0;
			retval += values[1] == v ? 1 : 0;
			retval += values[2] == v ? 1 : 0;
			
			return retval;

		}
		
		public boolean containsGreaterThan(int v) {
			// Ordered triplets
			return values[0] >= v;
		}
		
		public boolean allEqual() {
			return values[0] == values[1] && values[1] == values[2];
		}
		
		public String toString() {
			return "(" + values[0] + " " + values[1] + " " + values[2] + ")";
		}
	}
}
