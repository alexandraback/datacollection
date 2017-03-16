package cz.caitt.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;

public class B {

	private final static PrintStream o = System.out;
	private final static InputStream in = System.in;

	public static void main(String[] args) {

		try (//InputStream in = new FileInputStream("example.in");
				BufferedReader reader = new BufferedReader(
						new InputStreamReader(in));
				Scanner sc = new Scanner(reader)) {

			int T = sc.nextInt();

			for (int i = 0; i < T; i++) {
				int X = sc.nextInt();
				int Y = sc.nextInt();
				o.format("Case #%d: %s\n", i + 1, solve(X, Y));
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static String solve(int x, int y) {
		StringBuilder sb = new StringBuilder(500);

		int acc = 1;
		while (x > 0) {
			sb.append('W').append('E');
			x--;
			acc += 2;
		}

		while (x < 0) {
			sb.append('E').append('W');
			x++;
			acc += 2;
		}

		while (y < 0) {
			sb.append("NS");
			y++;
			acc += 2;
		}

		while (y > 0) {
			sb.append("SN");
			y--;
			acc += 2;
		}

		String result = sb.toString();
		return result;
	}
}
