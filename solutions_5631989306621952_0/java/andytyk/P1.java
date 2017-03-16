import java.io.*;
import java.util.*;

public class P1 {
	
	public static void main(String [] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("/Users/andykong/Downloads/gcj2016/R1A/p1.small.in"));
		PrintWriter out = new PrintWriter(new FileWriter("/Users/andykong/Downloads/gcj2016/R1A/p1.small.out"));
		int T = Integer.parseInt(in.readLine());
		for(int cc = 1; cc <= T; cc++) {
			String s = in.readLine();
			String t = "";
			for(int i = 0; i < s.length(); i++) {
				String p = s.charAt(i) + t;
				String q = t + s.charAt(i);
				if(p.compareTo(q) > 0)
					t = p;
				else
					t = q;
			}
			out.printf("Case #%d: %s\n",cc,t);
		}
		in.close();
		out.close();
	}
}
