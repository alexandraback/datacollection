package cz.caitt.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {

	private final static PrintStream o = System.out;
	private final static InputStream in = System.in;

	public static void main(String[] args) {

		try (//InputStream in = new FileInputStream("example.in");
				BufferedReader reader = new BufferedReader(
						new InputStreamReader(in));
				Scanner sc = new Scanner(reader)) {

			// int T = Integer.parseInt(reader.readLine());
			int T = sc.nextInt();

			for (int i = 0; i < T; i++) {
				// init data structures
				String word = sc.next();
				int n = sc.nextInt();

				int rank = solve(word, n);
				o.format("Case #%d: %d\n", i + 1, rank);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static int solve(String word, int n) {
		Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o',
				'u'));

		int clos[] = new int[word.length()];
		int j = -1;
		int cons = 0;
		for (int i = word.length() - 1; i >= 0; i--) {
			if (!vowels.contains(word.charAt(i))) {
				cons++;
			} else {
				cons = 0;
			}

			if (cons >= n) {
				j = i;
			}

			clos[i] = j;
		}
		
		int result = 0;
		for (int i = 0; i < clos.length; i++) {
			j = clos[i];
			if(j == -1){
				continue;
			}
			
			result += word.length() - (j+n-1);
		}
		
		return result;
	}
}
