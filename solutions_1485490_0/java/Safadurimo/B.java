package Runde2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;

public class B {
public static void main(String[] args) throws Exception {
		
		BufferedReader f = new BufferedReader(new FileReader("input.txt"));
		PrintStream out = new PrintStream(new File("output.txt"));
		
		// number of test cases
		int t = Integer.parseInt(f.readLine());
		
		// handle every testcase
		for (int i = 1; i <= t; i++) {
			String[] st = f.readLine().split(" ");
			int N = Integer.parseInt(st[0]);
			int M = Integer.parseInt(st[1]);
			long[] a = new long[N];
			int[] A = new int[N];
			
			st = f.readLine().split(" ");
			for (int j = 0; j < st.length; j++) {
				if(j%2==0)
					a[j/2]=Long.parseLong(st[j]);
				else
					A[j/2] = Integer.parseInt(st[j]);
			}
			
			long[] b = new long[M];
			int[] B = new int[M];
			st = f.readLine().split(" ");
			for (int j = 0; j < st.length; j++) {
				if(j%2==0)
					b[j/2]=Long.parseLong(st[j]);
				else
					B[j/2] = Integer.parseInt(st[j]);
			}
			
			out.println("Case #" + i + ": " + solve(1, 1, a,A,b,B));
		}
	}

	private static long solve(int n, int m, long[] a, int[] A, long[] b, int[] B) {
		if(A.length<n || B.length <m) return 0; // schon alles konsumiert
		if(A[n-1] == B[m-1]) { // es kann konsumiert werden
			if(a[n-1] == b[m-1]){
				long sum = a[n-1];
				n++;
				m++;
				return sum + solve(n, m, a, A, b, B);
			}
			if(a[n-1] > b[m-1]){
				long sum = b[m-1];
				long[] a2 = (long[]) a.clone();
				a2[n-1] = a[n-1]-b[m-1];
				m++;
				return sum + solve(n, m, a2, A, b, B);
			}
			if(a[n-1] < b[m-1]){
				long sum = a[n-1];
				long[] b2 = (long[]) b.clone();
				b2[m-1] = b[m-1] -a[n-1];
				n++;
				return sum + solve(n, m, a, A, b2, B);
			}
			
		}
		// Geschenke wegwerfen
		int n2 =n;
		int m2 =m;
		while(n2-1 < A.length && A[n2-1] != B[m2-1]) n2++;
		long g1 = solve(n+1, m, a, A, b, B);
		
		// Kartons wegwerfen
	    n2 =n;
		m2 =m;
		while(m2-1 < B.length && A[n2-1] != B[m2-1]) m2++;
		long g2 = solve(n, m+1, a, A, b, B);
		return Math.max(g1, g2);
		
	}
}
