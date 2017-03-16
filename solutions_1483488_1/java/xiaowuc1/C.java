
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
 
public class C {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int a = readInt();
			int b = readInt();
			int ret = 0;
			for(int i = a; i <= b; i++)	{
				String s = Integer.toString(i);
				Set<Integer> set = new HashSet<Integer>();
				for(int j = 0; j < s.length(); j++)	{
					int test = Integer.parseInt(s.substring(j) + s.substring(0,j));
					if(a <= i && i < test && test <= b && s.length() == Integer.toString(test).length())	{
						set.add(test);
					}
				}
				ret += set.size();
			}
			pw.println("Case #" + casenum + ": " + ret);
		}
		pw.close();
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}
