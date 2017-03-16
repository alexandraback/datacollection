import java.io.*;
import java.util.*;

public class Main {
	
	Scanner in;
	PrintWriter out;
	
	static final String path = "C:/gcj/";
	static final String problemName = "C";
	
	static class MyEx extends Exception {}
	
	int ar[];
	
	int set1[];
	int set2[];
	
	void gen(int i1, int i2, int s1, int s2, int idx, int remSum) throws MyEx {
		if (i1 != 0) {
			if (s1 == s2) {
				for (int i = 0; i < i1; i++) {
					out.print(set1[i] + " ");
				}
				out.println();
				for (int i = 0; i < i2; i++) {
					out.print(set2[i] + " ");
				}
				throw new MyEx();
			}
		}
		if (idx == ar.length) {
			return;
		}
		
		set1[i1] = ar[idx];
		gen(i1 + 1, i2, s1 + ar[idx], s2, idx + 1, remSum);
		
		set2[i2] = ar[idx];
		gen(i1, i2 + 1, s1, s2 + ar[idx], idx + 1, remSum);
		
		gen(i1, i2, s1, s2, idx + 1, remSum);
	}
	
	
	void solveOne() {
		int n = in.nextInt();
		ar = new int[n];
		set1 = new int[n];
		set2 = new int[n];
		
		int sum = 0;
		for (int i = 0; i < n; i++) {
			ar[i] = in.nextInt();
			sum += ar[i];
		}
		
		try {
			gen(0,0,0,0,0,sum);
			out.println("Impossible");
		} catch (MyEx e) {
			
		}
	}
	
	void solve() {
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) {
			out.println("Case #" + i + ":");
			solveOne();
			out.println();
		}
	}
	
	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	
	public void run() {
		try {
			in = new Scanner(new FileReader(path + problemName + ".in"));
			out = new PrintWriter(path + problemName + ".out");
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}