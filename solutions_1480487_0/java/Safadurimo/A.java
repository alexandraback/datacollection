package Runde1B;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.text.DecimalFormat;

public class A {
public static void main(String[] args) throws Exception {
		
		BufferedReader f = new BufferedReader(new FileReader("input.txt"));
		PrintStream out = new PrintStream(new File("output.txt"));
		
		// number of test cases
		int t = Integer.parseInt(f.readLine());
		
		// handle every testcase
		for (int i = 1; i <= t; i++) {
			String[] st = f.readLine().split(" ");
			int n = Integer.parseInt(st[0]);
			int[] s = new int[n];
			for (int j = 0; j < n; j++) {
				s[j] = Integer.parseInt(st[j+1]);
			}
			out.println("Case #" + i + ": " + solve(n,s) );
		}
	}

private static String solve(int n, int[] s) {
	double m[] = new double[n];
	int X =0;
	for (int i = 0; i < s.length; i++) {
		X += s[i];
	}
	for (int i = 0; i < m.length; i++) {
		m[i]= solve2(X, i,n,s,0.0,1.0);
	}
	String ret = " ";
	DecimalFormat f = new DecimalFormat("0.000000");
	for (int i = 0; i < m.length; i++) {
		ret = ret + f.format(100*m[i]).replace(',', '.') + " ";
	}
	return ret;
}

private static double solve2(int X, int i, int n, int[] s, double min, double max) {
	double middle = (max + min)/2;
	double sum = 0;
	for (int j = 0; j < n; j++) {
		if (j!=i) sum += Math.max(0,middle*X+s[i]-s[j]);
	}
	double points = (1-middle)*X;
	if(Math.abs(points-sum)< 0.000000001 || middle < 0.000000001 || middle > 1-0.000000001)
		return middle;
	if(sum<(1-middle)*X) // middle muss vergroessert werden
		return solve2(X, i,n,s,middle,max);
	else
		return solve2(X, i,n,s,min,middle);
}
}
