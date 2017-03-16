import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class D {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("d.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("d.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			int n = readInt();
			double[] a = new double[n];
			double[] b = new double[n];
			for(int i = 0; i < n; i++) {
				a[i] = readDouble();
			}
			for(int i = 0; i < n; i++) {
				b[i] = readDouble();
			}
			Arrays.sort(a);
			Arrays.sort(b);
			pw.println(solveYes(a, b) + " " + solveNo(a, b));
		}
		pw.close();
	}

	public static int solveYes(double[] a, double[] b) {
		int ret = 0;
		int index = 0;
		for(int i = 0; i < b.length; i++) {
			while(index < a.length && a[index] <= b[i]) {
				index++;
			}
			if(index == a.length) {
				break;
			}
			index++;
			ret++;
		}
		return ret;
	}
	
	public static int solveNo(double[] a, double[] b) {
		int ret = 0;
		boolean[] used = new boolean[b.length];
		for(int i = 0; i < a.length; i++) {
			int smallest = -1;
			for(int j = 0; j < used.length; j++) {
				if(b[j] > a[i] && !used[j]) {
					smallest = j;
					break;
				}
			}
			if(smallest == -1) {
				ret++;
				smallest = 0;
				while(used[smallest]) {
					smallest++;
				}
				used[smallest] = true;
			}
			else {
				used[smallest] = true;
			}
		}
		return ret;
	}
	
	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}

	public static String readLine() throws IOException	{
		st = null;
		return br.readLine();
	}

}
