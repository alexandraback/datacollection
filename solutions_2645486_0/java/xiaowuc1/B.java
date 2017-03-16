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

	static int max, r;
	static int[] list;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("b.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("b.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			max = readInt();
			r = readInt();
			int n = readInt();
			list = new int[n];
			for(int i = 0; i < n; i++)	{
				list[i] = readInt();
			}
			pw.println(solve(max, 0));
		}
		pw.close();
	}

	public static int solve(int currE, int index)	{
		if(index == list.length)	{
			return 0;
		}
		int ret = 0;
		for(int i = 0; i <= currE; i++)	{
			ret = Math.max(ret, list[index] * i + solve(Math.min(max, currE-i+r), index+1));
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
