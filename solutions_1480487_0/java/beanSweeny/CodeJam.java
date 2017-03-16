package codejam.network172.com;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class CodeJam {
	public static void main(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("/home/harry/Downloads/cj.in")));
			PrintWriter out = new PrintWriter(new FileWriter("/home/harry/Downloads/cj.out"));
			jam(in, out);
			out.close();
		} catch (Exception e) {
			System.out.print("Exception thrown: " + e.toString());
		}
	}
	
	private static void jam(BufferedReader in, PrintWriter out) throws NumberFormatException, IOException {
		int cases = Integer.parseInt(in.readLine());
		for (int i = 0; i < cases; i++) {
			solveCase(i, in, out);
		}
	}
	
	private static void solveCase(int c, BufferedReader in, PrintWriter out) throws NumberFormatException, IOException {
		String[] inStrs = in.readLine().split(" ");
		int n = Integer.parseInt(inStrs[0]);
		double[] pts = new double[n];
		double x = 0;
		for (int i = 0; i < pts.length; i++) {
			int j = Integer.parseInt(inStrs[i+1]);
			pts[i] = j;
			x += j;
		}
		out.printf("Case #%d:", c+1);
		double yx = x;
		double dn = n;
		double newDn = n;
		for (int i = 0; i < pts.length; i++)
			if ((((2*x)/dn - pts[i])/x) <= 0.0) {
				newDn -= 1.0;
				yx -= pts[i];
			}
		for (int i = 0; i < pts.length; i++)
			if ((((2*x)/dn - pts[i])/x) <= 0.0)
				out.print(" 0.0");
			else
				out.printf(" %f", 100.0*((x+yx)/newDn - pts[i])/x);
		out.println();
	}
}
