/**
 * File Name: Main.java
 * Package Name: com.ncfxy.MyAlgorithm
 * Description： TODO 
 *
 *   ver					date			author
 * ──────────────────────────────────
 *   1.0-SNAPSHOT			2016年4月9日			Administrator
 *
 * Copyright (c) 2016, ncfxy All Rights Reserved.
 */

package com.ncfxy.MyAlgorithm;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: Main<br/>
 * Description: TODO ADD Description
 *
 * @author Administrator
 * @version 1.0-SNAPSHOT
 * @Date 2016 2016年4月9日 上午9:45:38
 */
public class Main {
	static int myMax = 100000;
	static int cover[] = new int[myMax];
	static Integer prime[] = new Integer[10000];
	static int top = 0;
	static int getNumbers = 0;
	static int j = 0;
	static Integer candidate[] = new Integer[32];
	static int totalBit = 0;
	static String solution[] = new String[11];

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int t = cin.nextInt();
			for (int caseNumber = 1; caseNumber <= t; caseNumber++) {
				int k = cin.nextInt();
				int c = cin.nextInt();
				int s = cin.nextInt();
				System.out.print("Case #" + caseNumber + ": ");
				if (c * s < k) {
					System.out.println("IMPOSSIBLE");
				} else {
					sol(k, c, s);
				}
			}
			break;
		}
	}

	public static void sol(long k, long c, long s) {
		long x = 0, y = 0;
		long length = (long) Math.pow((double) k, (double) c);
		if (k % c == 0) {
			x = k / c;
		} else {
			x = k / c + 1;
			y = k % c;
		}
		
		for (long i = 0; i < x; i++) {
			long tmpC = 1;
			for (long j = 1; j < c; j++) {
				tmpC *= k;
			}
			long start = i * c;
			long ans = 0;
			if (i == x - 1 && y != 0)
				c = y;
			for (long indexC = 0; indexC < c; indexC++) {
				ans += start * tmpC;
				if(tmpC == 1)ans++;
				start++;
				tmpC /= k;
			}
			System.out.print(ans + " ");
		}
		System.out.println();

	}
}
