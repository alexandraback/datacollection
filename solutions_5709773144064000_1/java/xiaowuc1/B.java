import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class B {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static final int MOD = 1000002013;

	static int n;

	static double buyFarm;
	static double farmProduce;
	static double goal;
	
	static double[] prefixSum; 
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("b.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("b.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			buyFarm = readDouble();
			farmProduce = readDouble();
			goal = readDouble();
			int min = 0;
			int max = 10000000;
			prefixSum = new double[max+1];
			for(int i = 0; i < prefixSum.length-1; i++) {
				prefixSum[i+1] = prefixSum[i] + buyFarm / (2.0 + i * farmProduce);
			}
			double ret = Double.MAX_VALUE;
			for(int i = 0; i <= 1000000; i++) {
				ret = Math.min(ret, solve(i));
			}
			pw.println(ret);
		}
		pw.close();
	}

	public static double solve(int numFarms) {
		double ret = prefixSum[numFarms];
		return ret + goal / (2.0 + numFarms * farmProduce);
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
