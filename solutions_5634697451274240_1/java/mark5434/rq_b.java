package codejam2016;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class rq_b {
	static int doit(String in) {
		int r=0;
		boolean is_doing =false;
		for (int i=0;i<in.length();i++) {
			if (in.charAt(i)=='-' && !is_doing) {
				r+=2;
				is_doing=true;
			}
			if (in.charAt(i)=='+') is_doing=false;
		}
		if (in.charAt(0)=='-') r--;
		return r;
	}
	static public void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("d:/B-large.in"));
		PrintWriter pw = new PrintWriter("d:/out");
		int cn = sc.nextInt();
		for (int casei=0;casei<cn;casei++) {
			String n = sc.next();
			pw.printf("Case #%d: %d\n", casei+1, doit(n));
		}
		sc.close();
		pw.close();
	}
}
