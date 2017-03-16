package codejam2016;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class rq_a {
	static int doit(int n) {
		boolean seen[] = new boolean[10];
		Arrays.fill(seen, false);
		int r = n;
		while (true) {
			int x = r;
			while (x!=0) {
				seen[x%10]=true;
				x/=10;
			}
			boolean fin = true;
			for (boolean i : seen) {
				fin = fin && i;
			}
			if (fin) break;
			r+=n;
		}
		return r;
	}
	static public void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("d:/A-large.in"));
		PrintWriter pw = new PrintWriter("d:/out");
		int cn = sc.nextInt();
		for (int casei=0;casei<cn;casei++) {
			int n = sc.nextInt();
			if (n==0)
				pw.printf("Case #%d: INSOMNIA\n", casei+1);
			else
				pw.printf("Case #%d: %d\n", casei+1, doit(n));
		}
		sc.close();
		pw.close();
	}
}
