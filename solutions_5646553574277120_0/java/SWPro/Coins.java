package com.jam;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Coins {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int testsNum = in.nextInt();
		for (int i = 1; i <= testsNum; ++i) {
			int c = in.nextInt();
			int d = in.nextInt();
			long v = in.nextLong();
			int dominationAdded = 0;
			ArrayList<Integer> coins = new ArrayList();
			for (int j = 0; j < d; ++j) {
				coins.add(in.nextInt());
			}
			for (int j = 1; j <= v; ++j) {
				int tempJ = j;
				for (int k = d - 1; k >= 0 && tempJ != 0; --k) {
					for (int l = 0; l < c && tempJ != 0; ++l)
						if (tempJ >= coins.get(k))
							tempJ = tempJ - coins.get(k);
				}
				if (tempJ != 0) {
					dominationAdded++;
					d++;
					int insertionPoint = Arrays
							.binarySearch(coins.toArray(), j);
					coins.add(~insertionPoint, j);
				}
			}

			System.out.println("Case #" + i + ": " + dominationAdded);
		}

	}

}
