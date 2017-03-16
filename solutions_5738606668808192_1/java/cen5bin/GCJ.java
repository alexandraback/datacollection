package com.test;

import java.math.BigInteger;

public class GCJ {
	
	private long[] p = new long[2000000];
	private int cnt = 0;
	private void init() {
		p[cnt++] = 2;
		for (int i = 3; i < 2000000; i+=2) {
			boolean yes = false;
			for (int j = 0; p[j] * p[j] <= i; ++j)
				if (i % p[j] == 0) {
					yes = true;
					break;
				}
			if (!yes) p[cnt++] = i;
		}
	}
	private void solve() {
		init();
		System.out.println("Case #1:");
		int n = 16;
		int count = 50;
		int all = 1<<n;
		int[] b = new int[40];
		int[] ans = new int[20];
		for (int i = (1<<(n-1))+1; i < all; i+=2) {
			int x = i;
			for (int j = 0; j < n; ++j) {
				b[n-1-j] = x & 1;
				x >>= 1;
			}
			boolean yes = true;
			for (int j = 2; j <= 10; ++j) {
				BigInteger val = BigInteger.valueOf(0);
				for (int k = 0; k < n; ++k) val = val.multiply(BigInteger.valueOf(j)).add(BigInteger.valueOf(b[k]));
				yes = false;
				for (int k = 0; k < cnt && BigInteger.valueOf(p[k] * p[k]).compareTo(val) <= 0; ++k) {
					if (val.mod(BigInteger.valueOf(p[k])).intValue() == 0) {
						yes = true;
						ans[j] = (int) p[k];
					}
				}
				if (!yes) break;
			}
			if (yes) {
				count--;
				for (int j = 0; j < n; ++j) System.out.print(b[j]);
				for (int j = 2; j <= 10; ++j) System.out.print(" " + ans[j]);
				System.out.println("");
			}
			if (count == 0) break;
		}
	}
	
	
	public static void main(String[] args) {
		new GCJ().solve();
	}
}
