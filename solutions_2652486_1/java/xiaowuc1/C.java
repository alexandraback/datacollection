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
	
	static Set<Integer> set;
	
	static int[][] factorizations;
	
	static int[] use;
	
	static int[] ourFactorization = new int[4];
	
	static int r,n,m,k;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("c.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d:\n", casenum);
			r = readInt();
			n = readInt();
			m = readInt();
			k = readInt();
			factorizations = new int[k][];
			for(int qqq = 0; qqq < r; qqq++)	{
				System.out.println(qqq);
				set = new HashSet<Integer>();
				for(int a = 0; a < k; a++)	{
					factorizations[a] = factor(readLong());
				}
				use = new int[n];
				ourFactorization = new int[4];
				if(!dfs(0))	{
					System.out.println(qqq + " BROKEN");
					return;
				}
			}
		}
		pw.close();
	}
	
	public static int[] factor(long curr){
		int[] p = new int[]{2,3,5,7};
		int[] ret = new int[4];
		for(int i = 0; i < ret.length; i++)	{
			while(curr%p[i]==0)	{
				curr /= p[i];
				ret[i]++;
			}
		}
		return ret;
	}
	
	public static boolean dfs(int curr)	{
		if(curr == use.length)	{
			return solve();
		}
		for(int i = curr>0?use[curr-1]:2; i <= m; i++){
			use[curr] = i;
			int[] ourFactor = factor(i);
			for(int a = 0; a < ourFactor.length; a++){
				ourFactorization[a] += ourFactor[a];
			}
			if(dfs(curr+1))	{
				return true;
			}
			for(int a = 0; a < ourFactor.length; a++){
				ourFactorization[a] -= ourFactor[a];
			}
		}
		return false;
	}
	
	public static boolean solve(){
		boolean win = true;
		for(int i = 0; win && i < factorizations.length; i++)	{
			for(int j = 0; win && j < 4; j++)	{
				win = ourFactorization[j] >= factorizations[i][j];
			}
		}
		if(win){
			for(int out: use)	{
				pw.print(out);
			}
			pw.println();
			return true;
		}
		return false;
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
