package com.goograming.codejam.year2016.round1a;

import java.util.Scanner;

public class A {
	public static void main(final String[] args) {
		final Scanner in = new Scanner(System.in);
		final Integer testCases = in.nextInt();
		for (Integer test = 1; test <= testCases; test++) {
			final String word  = in.next();
			String lastWord = "";
			for (char c : word.toCharArray()) {
				if (lastWord.isEmpty()) {
					lastWord = lastWord + c; 
				} else if (lastWord.charAt(0) <= c) {
					lastWord = c + lastWord; 
				} else {
					lastWord = lastWord + c; 
				}
			}
			System.out.println("Case #" + test + ": " + lastWord);
		}
		in.close();
	}
}
