
package com.goograming.codejam.year2016.round1a;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class B {
	public static void main(final String[] args) {
		final Scanner in = new Scanner(System.in);
		final Integer testCases = in.nextInt();
		for (Integer test = 1; test <= testCases; test++) {
			final Integer N = in.nextInt();
			final Map<Integer, Integer> count = new HashMap<>(); 
			for (int i = 0; i < 2 *(N * N) - N; i++) {
				Integer h = in.nextInt(); 
				if (count.containsKey(h)) {
					count.put(h, count.get(h) + 1); 
				} else {
					count.put(h, 1);
				}
			}
			List<Integer> missingHeights = new ArrayList<>(); 
			for (Integer h : count.keySet()) {
				if ((count.get(h) % 2) != 0) {
					missingHeights.add(h); 
				}
			}
			Collections.sort(missingHeights);
			System.out.print("Case #" + test + ": ");
			for (Integer h : missingHeights) {
				System.out.print(h + (missingHeights.indexOf(h) != missingHeights.size() - 1 ? " " : ""));
			}
			System.out.println();
		}
		in.close();
	}
}
