package codejam2016rq;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class rq_d {
	
	static String doit(int k, int c, int s) {
		
		StringBuilder sb = new StringBuilder();
		if (k==s) {
			for (int i=0;i<s;i++) {
				sb.append(" ");
				sb.append(i+1);
			}
		}
		else {
			return " not support";
		}
		return sb.toString();
	}
	static public void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("d:/D-small-attempt0.in"));
		PrintWriter pw = new PrintWriter("d:/out");
		int cn = sc.nextInt();
		for (int casei=0;casei<cn;casei++) {
			int k = sc.nextInt();
			int c = sc.nextInt();
			int s = sc.nextInt();
			if (c*s<k)
				pw.printf("Case #%d: IMPOSSIBLE\n", casei+1);
			else
				pw.printf("Case #%d:%s\n", casei+1, doit(k, c, s));
		}
		sc.close();
		pw.close();
	}
}
