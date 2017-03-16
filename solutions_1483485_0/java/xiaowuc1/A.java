
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
 
public class A {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		int qq = Integer.parseInt(br.readLine());
		char[] translate = new char[256];
		Arrays.fill(translate, ' ');
		translate['a'] = 'y';
		translate['b'] = 'h';
		translate['c'] = 'e';
		translate['d'] = 's';
		translate['e'] = 'o';
		translate['f'] = 'c';
		translate['g'] = 'v';
		translate['h'] = 'x';
		translate['i'] = 'd';
		translate['j'] = 'u';
		translate['k'] = 'i';
		translate['l'] = 'g';
		translate['m'] = 'l';
		translate['n'] = 'b';
		translate['o'] = 'k';
		translate['p'] = 'r';
		translate['q'] = 'z';
		translate['r'] = 't';
		translate['s'] = 'n';
		translate['t'] = 'w';
		translate['u'] = 'j';
		translate['v'] = 'p';
		translate['w'] = 'f';
		translate['x'] = 'm';
		translate['y'] = 'a';
		translate['z'] = 'q';
		for(int casenum = 1; casenum <= qq; casenum++)	{
			String s = br.readLine();
			StringBuilder ret = new StringBuilder();
			for(int i = 0; i < s.length(); i++)
				ret.append(translate[s.charAt(i)]);
			pw.println("Case #" + casenum + ": " + ret.toString());
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
