package codejam2012;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class EqualSums {
	public static void main(String[] args) throws FileNotFoundException {
		new EqualSums().run();
	}

	
	private void run() throws FileNotFoundException {
		in = new Scanner(new FileInputStream(new File("/home/mosaick/sample-in.txt")));
		out = new PrintWriter(new FileOutputStream("/home/mosaick/sample-out.txt"));
		int t = in.nextInt();

		for (test = 0; test < t; test++) {
			int n = in.nextInt();
			A = new int[n];
			for (int j = 0; j < n; j++) A[j] = in.nextInt();
			map = new HashMap<Integer, String>();
			found = false;
			Arrays.sort(A);
			
			dfs(0, 0, "");
			
			if (!found) {
				out.printf("Case #%d: Impossible", (test+1));
				out.println();
			}
		}
		out.flush();
	}
//	Scanner in = new Scanner(System.in);
//	PrintWriter out = new PrintWriter(System.out);
	Scanner in;
	PrintWriter out;
	int test;
	int[] A;
	Map<Integer, String> map;
	boolean found = false;
	
	private void dfs(int ix, int sum, String numStr) {
		if (found) return;
		if (map.containsKey(sum)) {
			if (!map.get(sum).equals(numStr)) {
				out.printf("Case #%d:", (test+1));
				out.println();
				out.printf("%s", map.get(sum));
				out.println();
				out.printf("%s", numStr);
				out.println();
				found = true;
			} 
		} else {
			map.put(sum, numStr);
		}
		if (ix == A.length - 1) {
			return;
		}
		
		for (int i = ix + 1; i < A.length - 1; i++) {
			dfs(i, sum + A[i], numStr + " " + A[i]);
		}
	}
}
