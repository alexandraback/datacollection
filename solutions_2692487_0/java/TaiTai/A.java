package gcj2013R1B;

import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run(new Scanner(System.in));
	}

	void run(Scanner sc) {
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}

	void solve(Scanner sc, int case_num) {
		int a = sc.nextInt();
		int n = sc.nextInt();
		int[] list = new int[n];
		for(int i = 0; i < n; i++)
			list[i] = sc.nextInt();
		Arrays.sort(list);
//		for(int i = 0; i < n; i++)
//			System.out.print(list[i]+" ");
//		System.out.println();
		if(a == 1) {
			System.out.printf("Case #%d: %d\n", case_num, n);
			return;
		}
		int[][] dp = new int[n + 1][n + 1];
		for(int[] t : dp) 
			Arrays.fill(t, -1);
		dp[0][0] = a;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				int val = dp[i][j];
				if(val > list[i]) dp[i + 1][j] = Math.max(dp[i + 1][j], val + list[i]);
				dp[i + 1][j + 1] = Math.max(dp[i + 1][j + 1], val);
//				System.out.println(i+" "+j+" "+val);
				for(int k = j + 1; k < n; k++) {
					val = (val + val - 1);
					if(val > list[i]) dp[i + 1][k] = Math.max(dp[i + 1][k], val + list[i]);
				}
			}
		}
		int ans = -1;
		for(int i = 0; i <= n; i++) {
			if(dp[n][i] != -1) {
				ans = i; break;
			}
		}
		System.out.printf("Case #%d: %d\n", case_num, ans);
	}
}
