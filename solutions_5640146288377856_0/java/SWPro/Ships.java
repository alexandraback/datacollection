package com.jam;

import java.util.Scanner;
import java.util.Stack;

public class Ships {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int testsNum = in.nextInt();
		for (int i = 1; i <= testsNum; ++i) {
			int r = in.nextInt();
			int c = in.nextInt();
			int w = in.nextInt();
			System.out.println("Case #" + i + ": "
					+ (c / w * r + (w - 1) + (c % w > 0 ? 1 : 0)));
		}

	}

}
