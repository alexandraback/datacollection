package round1a;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class C {

	static int[] getp(int n) {
		int p = 2;
		int[] counts = new int[9];
		while (p*p <= n) {
			while (n%p == 0) {
				counts[p]++;
				n/=p;
			}
			++p;
		}
		if (n > 1) {
			counts[n]++;
		}
		return counts;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int R = sc.nextInt();
		int N = sc.nextInt();
		int M = sc.nextInt();
		int K = sc.nextInt();
		
		System.out.println("Case #1:");
		for (int i = 1; i <= R; i++) {
			int v[] = new int[N];
			int counts[] = new int[9];
			
			for (int j = 0; j < K; j++) {
				int n = sc.nextInt();
				int tmpc[] = getp(n);
				for (int l = 2; l < tmpc.length; l++) {
					counts[l] = Math.max(counts[l], tmpc[l]);
				}
			}
			
			int p = 0;
			StringBuilder sb = new StringBuilder();
			for (int j = 0; j < counts[3]; j++, p++) {
				sb.append(3);
			}
			for (int j = 0; j < counts[5]; j++, p++) {
				sb.append(5);
			}
			int r = N - p;
			while (counts[2] > r) {
				sb.append(4);
				counts[2] -= 2;
				--r;
			}
			while (r > 0) {
				sb.append(2);
				--r;
			}
			
			System.out.println(sb.toString());
		}
	}

}
