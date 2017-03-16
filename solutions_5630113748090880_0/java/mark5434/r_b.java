package codejam2016r1a;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class r_b {
	static String doit(int[] x, int N) {
		int[] cnt = new int[3000];
		Arrays.fill(cnt, 0);
		for (int i=0;i<x.length;i++) {
			cnt[x[i]]++;
		}
		
		int[] r = new int[N];
		int p=0;
		for (int i=0;i<cnt.length;i++) {
			if (cnt[i]%2!=0) r[p++]=i;
		}
		Arrays.sort(r);
		StringBuilder sb = new StringBuilder();
		for (int i : r) {
			sb.append(' ');
			sb.append(i);
		}
		return sb.toString();
	}
	static public void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("d:/in"));
		PrintWriter pw = new PrintWriter("d:/out");
		int cn = sc.nextInt();
		for (int casei=0;casei<cn;casei++) {
			int N = sc.nextInt();
			int[] x = new int[2*N*N-N];
			for (int i=0;i<2*N*N-N;i++) {
				x[i]=sc.nextInt();
			}
			pw.printf("Case #%d:%s\n", casei+1, doit(x, N));
		}
		sc.close();
		pw.close();
	}
}
