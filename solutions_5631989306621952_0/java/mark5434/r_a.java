package codejam2016r1a;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class r_a {
	static String doit(String x) {
		LinkedList<Character> sb = new LinkedList<Character>();
		sb.add(x.charAt(0));
		for (int i=1;i<x.length();i++) {
			char n = x.charAt(i);
			if (n>=sb.getFirst()) {
				sb.addFirst(n);;
			}
			else {
				sb.addLast(n);
			}
		}
		StringBuilder res = new StringBuilder();
		for (Character c : sb) res.append(c);
		return res.toString();
	}
	static public void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("d:/in"));
		PrintWriter pw = new PrintWriter("d:/out");
		int cn = sc.nextInt();
		for (int casei=0;casei<cn;casei++) {
			String x = sc.next();
			pw.printf("Case #%d: %s\n", casei+1, doit(x));
		}
		sc.close();
		pw.close();
	}
}
