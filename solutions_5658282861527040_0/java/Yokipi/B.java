package round1b_14;

import java.util.*;
import java.io.*;


public class B {
	BufferedReader in;
	StringTokenizer st;
	FileWriter out;
	
	int getint() {
		return Integer.parseInt(st.nextToken());
	}
	
	void run() throws Exception {
		in = new BufferedReader(new FileReader("src/round1b_14/B.in"));
		st = new StringTokenizer(in.readLine());
		out = new FileWriter("src/round1b_14/B.out");
		
		int T = getint();
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(in.readLine());
			int A = getint();
			int B = getint();
			int C = getint();
			
			int count = 0;
			for (int a = 0; a < A; a++) {
				for (int b = 0; b < B; b++) {
					if ((a & b) < C) count++;
				}
			}
			
			out.write(String.format("Case #%d: %s\n", t, Integer.toString(count)));
		}
		
		in.close();
		out.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new B()).run();
	}
}
