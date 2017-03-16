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
			pw.printf("Case #%d:\n", casenum);
			int r = readInt();
			int n = readInt();
			int m = readInt();
			int k = readInt();
			for(int qqq = 0; qqq < r; qqq++)	{
				Set<Integer> set = new HashSet<Integer>();
				for(int a = 0; a < k; a++)	{
					set.add(readInt());
				}
				for(int mask = 1; true; mask++)	{
					String ans = Integer.toString(mask, m);
					if(ans.length() > n) break;
					if(ans.length() < n || ans.contains("0")) continue;
					int[] use = new int[ans.length()];
					for(int i = 0; i < use.length; i++)	{
						use[i] = ans.charAt(i) - '0' + 1;
					}
					Set<Integer> used = new HashSet<Integer>();
					for(int now = 0; now < 1 << use.length; now++)	{
						int curr = 1;
						for(int aa = 0; aa < use.length; aa++)	{
							if((now&(1<<aa)) != 0)	{
								curr *= use[aa];
							}
						}
						if(set.contains(curr))
							used.add(curr);
					}
					if(used.size() == set.size()){
						for(int out: use)	{
							pw.print(out);
						}
						pw.println();
						break;
					}
				}
			}
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
