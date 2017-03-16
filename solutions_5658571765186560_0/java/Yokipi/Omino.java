package codejam2015;

import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;


public class Omino {
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
		in = new BufferedReader(new FileReader(new File("src/codejam2015/d.in")));
		out = new PrintWriter(new FileWriter(new File("src/codejam2015/d.out")));
		
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			
			int X = nextInt(), R = nextInt(), C = nextInt();
			
			if (R > C) {
				int temp = C;
				C = R;
				R = temp;
			}
			
			boolean possible = true;
			if (X > R*C) possible = false;
			else if (X > 6) possible = false;
			else if (R*C%X != 0) possible = false;
			else if (X > C) possible = false;
			else if (R == 1 && X > 2) possible = false;
			else if (R == 2 && X > 3) possible = false;
			else if (R == 3 && X > 5) possible = false;
			else if (R == 3 && X > 4 && C < 10) possible = false;
			
			
			out.printf("Case #%d: %s\n", t+1, possible ? "GABRIEL" : "RICHARD");
		}
		
		in.close();
		out.close();
	}
}
