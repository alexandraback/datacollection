
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
 
public class B {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int s = readInt();
			int max = readInt();
			int ret = 0;
			while(n-- > 0)	{
				int curr = readInt();
				boolean awesome = false;
				boolean semiawesome = false;
				for(int a = 0; a <= 10; a++)	{
					for(int b = a; b <= 10; b++)	{
						for(int c = b; c <= a+2; c++)	{
							if(a+b+c == curr && c-a <= 1 && c >= max)
								awesome = true;
							else if(a+b+c == curr && c >= max)
								semiawesome = true;
						}
					}
				}
				if(awesome)
					ret++;
				else if(semiawesome && s > 0)	{
					s--;
					ret++;
				}
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
