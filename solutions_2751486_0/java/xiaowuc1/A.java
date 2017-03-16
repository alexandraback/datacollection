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

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("a.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			String str = nextToken();
			int n = readInt();
			int ret = 0;
			for(int i = 0; i < str.length(); i++)	{
				for(int j = i+1; j <= str.length(); j++)	{
					String curr = str.substring(i,j);
					int best = 0;
					int now = 0;
					String vowel = "aeiou";
					for(int a = 0; a < curr.length(); a++)	{
						if(vowel.indexOf(curr.charAt(a)+"") == -1)	{
							now++;
						}
						else	{
							now = 0;
						}
						best = Math.max(best, now);
					}
					if(best >= n)	{
						ret++;
					}
				}
			}
			pw.println(ret);
		}
		pw.close();
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
