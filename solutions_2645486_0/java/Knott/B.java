package codejam1a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class B {
	
	static int e,r,n,max;
	static int[] v;
	
	private static void helper(int level, int toSpend, int remainingEnergy, int accumulatedValue) {
		if (level == n) {
			if (accumulatedValue > max) {
				max = accumulatedValue;
			}
		} else {
			if (toSpend > remainingEnergy) return;
			remainingEnergy = Math.min(e, remainingEnergy-toSpend+r);
			accumulatedValue += toSpend*v[level];
			for (int i=remainingEnergy; i>=0; i--) {
				helper(level+1, i, remainingEnergy, accumulatedValue);
			}
		}
	}
	
	private static String solve() {
		max = 0;
		for (int i=e; i>=0; i--) {
			helper(0, i, e,  0);
		}
		return Integer.toString(max);
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = null;
		BufferedWriter bw = null;
		try {
			scanner = new Scanner(new File("src/codejam1a/B-small-attempt0.in"));
			int numOfInput = Integer.parseInt(scanner.nextLine());
			bw = new BufferedWriter(new FileWriter(new File("b-result.out")));
			for (int i=0; i<numOfInput; i++) {
				bw.write("Case #");
				bw.write(Integer.toString(i+1));
				bw.write(": ");
				e = scanner.nextInt();
				r = scanner.nextInt();
				n = scanner.nextInt();
				v = new int[n];
				for (int j=0; j<n; j++) {
					v[j] = scanner.nextInt();
				}
				String result = solve();
				bw.write(result);
				if (i < numOfInput-1) {
					bw.write('\n');
				}
				System.out.println("Case #"+(i+1)+": "+result);
			}
			scanner.close();
			bw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
