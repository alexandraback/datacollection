package com.google;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import org.apache.commons.collections.CollectionUtils;

/**
 * @author Debraj
 */
public class TicTacToe {

	/**
	 * @param args
	 */
	public static void main(final String[] args) {
		final String X = "X won";
		final String O = "O won";
		final String D = "Draw";
		final String G = "Game has not completed";

		final List<String> lx = new ArrayList<>();
		lx.add("XXXX");
		lx.add("TXXX");
		lx.add("XTXX");
		lx.add("XXTX");
		lx.add("XXXT");

		final List<String> lo = new ArrayList<>();
		lo.add("OOOO");
		lo.add("TOOO");
		lo.add("OTOO");
		lo.add("OOTO");
		lo.add("OOOT");

		final List<String> l = new ArrayList<>();

		final Scanner sc = new Scanner(System.in);
		final int t = sc.nextInt();
		String temp;
		char[][] c;
		boolean b;
		for (int i = 0; i < t;) {
			c = new char[4][4];
			b = false;
			for (int j = 0; j < 4; j++) {
				l.add(temp = sc.next());
				c[j] = temp.toCharArray();
				if (!b && temp.contains(".")) {
					b = true;
				}
			}
			l.add(new StringBuilder().append(c[0][0]).append(c[1][0]).append(c[2][0]).append(c[3][0]).toString());
			l.add(new StringBuilder().append(c[0][1]).append(c[1][1]).append(c[2][1]).append(c[3][1]).toString());
			l.add(new StringBuilder().append(c[0][2]).append(c[1][2]).append(c[2][2]).append(c[3][2]).toString());
			l.add(new StringBuilder().append(c[0][3]).append(c[1][3]).append(c[2][3]).append(c[3][3]).toString());

			l.add(new StringBuilder().append(c[0][0]).append(c[1][1]).append(c[2][2]).append(c[3][3]).toString());
			l.add(new StringBuilder().append(c[0][3]).append(c[1][2]).append(c[2][1]).append(c[3][0]).toString());

			if (CollectionUtils.containsAny(l, lx)) {
				System.out.println("Case #" + ++i + ": " + X);
			} else if (CollectionUtils.containsAny(l, lo)) {
				System.out.println("Case #" + ++i + ": " + O);
			} else if (b) {
				System.out.println("Case #" + ++i + ": " + G);
			} else {
				System.out.println("Case #" + ++i + ": " + D);
			}

			l.clear();
		}

	}

}