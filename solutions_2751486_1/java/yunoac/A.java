package R1C_2013;

import java.io.*;
import java.util.*;

public class A {

	static BufferedWriter writer;

	public static void main(String[] args) throws IOException {
		writer = new BufferedWriter(new FileWriter("output.out"));
		Scanner reader = new Scanner(new FileReader("A-large (2).in"));
		int nt = reader.nextInt();
		reader.nextLine();
		for (int tc = 1; tc <= nt; tc++) {
			writer.write("Case #" + tc + ": ");
			//TODO: code here
			String s = reader.next();
			int n = reader.nextInt();
			long count = solve2(s, n);
			writer.write(count + "");
			writer.newLine();
		}
		writer.close();
		System.out.println("Done.");
	}
	
	static long solve2(String s, int n) {
		int m = s.length();
		int[] a = new int[m];
		TreeSet<Integer> T = new TreeSet<Integer>();
		
		for(int i = 0; i < m; i++) {
			if(s.charAt(i) != 'a' && s.charAt(i) != 'e' && s.charAt(i) != 'i' && s.charAt(i) != 'o' && s.charAt(i) != 'u') {
				if(i == 0) {
					a[i] = 1;
				} else {
					a[i] = 1 + a[i - 1];
				}
				if(a[i] >= n) {
					T.add(i);
				}
			}
		}
	
		long count = 0;
		for(int i = 0; i <= m - n; i++) {
			Integer j = T.ceiling(i + n - 1);
			if(j != null) {
				count += m - j;				
			}
		}
	
		return count;
	}

	static long solve(String s, int n) {
		int m = s.length();
		int[] a = new int[m];
		for(int i = 0; i < m; i++) {
			if(s.charAt(i) != 'a' && s.charAt(i) != 'e' && s.charAt(i) != 'i' && s.charAt(i) != 'o' && s.charAt(i) != 'u') {
				a[i] = 1;
			}
		}
		int[] acSum = new int[m];
		acSum[0] = a[0];
		for(int i = 1; i < m; i++) {
			acSum[i] = a[i] + acSum[i - 1];
		}
		long count = 0;
		for(int i = 0; i <= m - n; i++) {
			int j = findSmallest(acSum, i, n);
			count += m - j;
		}
		return count;
	}

	static int findSmallest(int[] acSum, int i, int n) {
		int m = acSum.length;
		int L = i;
		int R = m - 1;
		while(R - L > 0) {
			int M = (L + R) / 2;
			int q = query(acSum, i, M);
			if(q >= n) {
				R = M;
			} else {
				L = M + 1;
			}
		}
		return R;
	}

	static int query(int[] acSum, int i, int j) {
		if(i == 0) {
			return acSum[j];
		}
		return acSum[j] - acSum[i - 1]; 
	}

}


