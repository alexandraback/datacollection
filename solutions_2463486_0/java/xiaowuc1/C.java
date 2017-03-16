import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("c.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			int small = readInt();
			int big = readInt();
			int ret = 0;
			for(int i = 1; i <= 100; i++)	{
				if(palin(i) && palin(i*i) && i*i >= small && i * i <= big)	{
					ret++;
				}
			}
			pw.println(ret);
		}
		pw.close();
	}
	
	public static boolean palin(int curr)	{
		String str = Integer.toString(curr);
		return str.equals(new StringBuilder(str).reverse().toString());
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
