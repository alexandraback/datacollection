package com.google.code.codejam2012.Round1A;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class B {

	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new BufferedReader(new FileReader(args[0] + ".in")));
		Writer writer = new BufferedWriter(new FileWriter(args[0] + ".out"));
		
		int T = scanner.nextInt();

		for (int x = 1; x <= T; ++x) {
			int N = scanner.nextInt();
			
			int[] a = new int[N];
			int[] b = new int[N];
			Map<Integer, Integer> map = new HashMap<Integer, Integer>(N);
			for (int i = 0; i < N; ++i) {
				a[i] = scanner.nextInt();
				b[i] = scanner.nextInt();
				map.put(i, 2);
			}
			
			int debug = 10;
			if (x == debug) {
				for (int i = 0; i < N; ++i)
				System.out.println("Level " + i + ": " + a[i] + " " + b[i]);
			}
			
			int nStars = 0;
			int y = 0;			
			boolean tooBad = true;
			
			while (!map.isEmpty()) {
				tooBad = true;
				
				for (Map.Entry<Integer, Integer> e: map.entrySet()) {
					if (e.getValue() == 1 && b[e.getKey()] <= nStars) {
						tooBad = false;
						++nStars;
						++y;
						map.remove(e.getKey());
						if (x == debug)
							System.out.println("Level " + e.getKey() + ": 2 stars");
						break;
					}
				}
				
				if (!tooBad)
					continue;
				
				for (Map.Entry<Integer, Integer> e: map.entrySet()) {
					if (e.getValue() == 2 && b[e.getKey()] <= nStars) {
						tooBad = false;
						nStars += 2;
						++y;
						map.remove(e.getKey());
						if (x == debug)
							System.out.println("Level " + e.getKey() + ": 2 stars");
						break;
					}
				}
				
				if (!tooBad)
					continue;
				
				Map<Integer, Integer> easyMap = new TreeMap<Integer, Integer>(Collections.reverseOrder());
				for (Map.Entry<Integer, Integer> e: map.entrySet()) {
					if (e.getValue() == 2) {
						easyMap.put(b[e.getKey()], e.getKey());
					}
				}
				
				for (Map.Entry<Integer, Integer> e: easyMap.entrySet()) {
					if (a[e.getValue()] <= nStars) {
						tooBad = false;
						++nStars;
						++y;
						map.put(e.getValue(), 1);
						if (x == debug)
							System.out.println("Level " + e.getValue() + ": 1 star");
						break;
					}
				}
				
				if (!tooBad) {
					continue;
				} else {
					if (x == debug)
						System.out.println("Case #" + x + ": Too Bad");
					writer.write("Case #" + x + ": Too Bad\n");
					break;
				}
				
			}
			
			if (!tooBad) {
				if (x == debug)
					System.out.println("Case #" + x + ": " + y);
				writer.write("Case #" + x + ": " + y + "\n");
			}
		}
		
		writer.close();
		scanner.close();
	}
	
}
