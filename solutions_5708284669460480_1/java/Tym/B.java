package round1C.java;

import java.util.Arrays;
import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		for(int caseno = 1; caseno <= cases; caseno++)
			System.out.printf("Case #%d: %s%n", caseno, new B().solve(input));
	}
	
	int earliestoverlap(String target, String seen) {
		for(int i = 0; i < seen.length(); i++)
			if(target.startsWith(seen.substring(i)))
				return i;
		return seen.length();
	}
	
	String solve(Scanner input) {
		int k = input.nextInt(), l = input.nextInt(), s = input.nextInt();
		String keys = input.next(), target = input.next(); 
		
		int max = 1 + (s-l) / (1 + earliestoverlap(target, target.substring(1)));
		
		for(int i = 0; i < l; i++) {
			boolean ok = false;
			for(int j = 0; j < k; j++)
				if(target.charAt(i) == keys.charAt(j))
					ok = true;
			if(!ok)
				max = 0;
		}
		
		
		int[][] next = new int[l][k];
		int[][] ok = new int[l][k];
		
		for(int i = 0; i < l; i++)
			for(int j = 0; j < k; j++)
			{
				String got = target.substring(0,i) + keys.charAt(j);
				if(got.equals(target)) {
					ok[i][j] = 1;
					got = got.substring(1);
				}
				
				next[i][j] = got.length() - earliestoverlap(target, got);
			}
		
		double[] exp = new double[l], temp = new double[l];
		
		for(int t = 0; t < s; t++) {
			for(int i = 0; i < l; i++) temp[i] = 0;
			
			for(int i = 0; i < l; i++)
				for(int j = 0; j < k; j++)
					temp[i] += (ok[i][j] + exp[next[i][j]]) / k;
			
			double[] swap = exp; exp = temp; temp = swap;
		}
		
		return "" + (max - exp[0]);
	}
}
