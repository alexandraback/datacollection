package codejam2016rq;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class rq_d {
	
	static String doit(int k, int c, int s) {
		StringBuilder sb = new StringBuilder();
		int x=0;
		while (x<k) {
			long num=0;
			for (int i=x;i<x+c;i++) {
				num*=k;
				num+=i;
			}
			sb.append(" ");
			sb.append(num+1);
			x+=c;
		}
		return sb.toString();
	}
	static public void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("d:/D-large.in"));
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
