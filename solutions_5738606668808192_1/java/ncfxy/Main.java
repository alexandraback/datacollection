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
		getPrime();
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int t = cin.nextInt();
			for (int caseNumber = 1; caseNumber <= t; caseNumber++) {
				int n = cin.nextInt();
				totalBit = n;
				j = cin.nextInt();
				System.out.println("Case #1:");
				sol(n);
			}
			break;
		}
	}

	public static void getPrime() {
		Arrays.fill(cover, 0);
		for (int i = 2; i < myMax; i++) {
			if (cover[i] == 0) {
				for (int j = i + i; j < myMax; j += i) {
					cover[j] = 1;
				}
			}
		}
		for (int i = 2; i < myMax; i++) {
			if (cover[i] == 0) {
				// System.out.println(i + "  = " + getBinaryString(i));
				prime[top++] = i;
			}
		}
	}

	public static String getBinaryString(int i) {
		return Integer.toBinaryString(i);
	}

	public static int sol(int n) {
		candidate[n - 1] = 1;
		candidate[0] = 1;
		dfs(n - 1);

		int result = 0;
		return result;
	}

	public static void dfs(int n) {
		if (getNumbers >= j) {
			return;
		}
		for (int i = 0; i < 2; i++) {
			candidate[n - 1] = i;
			if (n == 2) {
				if (cal()) {
					for (int j = totalBit-1; j >= 0; j--) {
						System.out.print(candidate[j].toString());
					}
					for (int j = 2; j <= 10; j++) {
						System.out.print(" " + solution[j]);
					}
					getNumbers++;
					if(getNumbers < j)
						System.out.println();
				}
			} else {
				dfs(n - 1);
			}
		}
	}

	public static boolean cal() {
		for (Integer i = 2; i <= 10; i++) {
			BigInteger ans = new BigInteger("0");
			BigInteger temp = new BigInteger("1");
			for (int j = 0; j < totalBit; j++) {
				ans = ans.add(temp.multiply(new BigInteger(candidate[j]
						.toString())));
				temp = temp.multiply(new BigInteger(i.toString()));
			}
			if (isPrime(ans, i)) {
				return false;
			}
		}

		return true;
	}

	public static boolean isPrime(BigInteger t, Integer index) {
		for (Integer i = 0; i < top; i++) {
			BigInteger div = new BigInteger(prime[i].toString());
			if (div.compareTo(t) != -1) {
				break;
			}
			if (t.divideAndRemainder(div)[1].equals(new BigInteger(new Integer(
					0).toString()))) {
				solution[index] = prime[i].toString();
				return false;
			}
		}
		return true;
	}
}
