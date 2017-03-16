/*
PROG: Prob1AA
LANG: JAVA
ID: sridhar4
*/

import java.io.*;
import java.util.*;

public class Prob1AA{

	public static void main(String [] args) throws IOException {
		//long start = System.currentTimeMillis();
		BufferedReader f = new BufferedReader(new FileReader("Prob1AA.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Prob1AA.out")));
		int T = Integer.parseInt(f.readLine());
		for(int q = 0; q < T; q++){
			String ans = "";
			String[] s = (f.readLine()).split(" ");
			long r = Long.parseLong(s[0]);
			long t = Long.parseLong(s[1]);
			long n = 1;
			//System.out.println(n + " " + r + " " + t);
			while(n*(2*n + 2*r - 1) <= t)
				n++;
			n--;
			out.println("Case #" + (q+1) + ": " + n);
		}
		//long end = System.currentTimeMillis();
		//System.out.println(end - start);
		out.close();
	}
	

}