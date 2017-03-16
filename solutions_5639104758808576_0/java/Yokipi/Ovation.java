package codejam2015;

import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;


public class Ovation {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st = null;
	
	static Integer nextInt() throws Exception {
		if (st == null || !st.hasMoreElements()) {
			String s = in.readLine();
			if (s == null) return null;
			st = new StringTokenizer(s);
		}
		return parseInt(st.nextToken());
	}
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader(new File("src/codejam2015/a.in")));
		out = new PrintWriter(new FileWriter(new File("src/codejam2015/a.out")));
		
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			
			int smax = nextInt();
			int current = 0;
			int index = 0;
			int ans = 0;
			for (char c : st.nextToken().toCharArray()) {
				int x = c - '0';
				if (current < index) {
					ans += index-current;
					current = index;
				}
				index++;
				current += x;
			}
			
			out.printf("Case #%d: %d\n", t+1, ans);
		}
		
		in.close();
		out.close();
	}
}
