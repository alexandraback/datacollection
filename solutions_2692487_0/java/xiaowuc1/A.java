import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static int[] list;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("a.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			int me = readInt();
			int n = readInt();
			list = new int[n];
			for(int i = 0; i < n; i++)	{
				list[i] = readInt();
			}
			Arrays.sort(list);
			pw.println(solve(me, 0));
		}
		pw.close();
	}

	private static int solve(long me, int i) {
		if(i == list.length)	{
			return 0;
		}
		if(me > list[i])	{
			return solve(me+list[i], i+1);
		}
		if(me == 1)	{
			return 1 + solve(me, i+1);
		}
		return 1 + Math.min(solve(2*me-1, i), solve(me, i+1));
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
