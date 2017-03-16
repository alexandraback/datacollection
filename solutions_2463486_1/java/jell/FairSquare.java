package com.elleson.joe;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;


public class FairSquare {

	public static void main(String[] args) throws Exception {
		List<Long> fairAndSquare = new ArrayList<Long>();
		for (int i = 0; i <= 10000000; i++) {
			if (isFair(i)) {
				long square = (long)i*i;
				if (isFair(square)) {
					fairAndSquare.add(square);
				}
			}
		}

		for (int i = 0; i < fairAndSquare.size(); i++) {
			System.out.println(fairAndSquare.get(i));
		}
		
		BufferedReader in = new BufferedReader(new FileReader("D:/codejam/fas/in"));
		PrintStream out = new PrintStream("D:/codejam/fas/out");
		
		int T = Integer.parseInt(in.readLine());
		
		for (int t = 1; t <= T; t++) {
			String[] next = in.readLine().split(" ");
			Long start = Long.parseLong(next[0]);
			Long end = Long.parseLong(next[1]);
			
			int count = 0;
			for (Long l : fairAndSquare) {
				if (l >= start && l <= end) {
					count++;
				}
			}
			
			out.println("Case #" + t + ": " + count);
		}
	}
	public static boolean isFair(long number) {
		String s = Long.toString(number);
		for (int i = 0; i < s.length() / 2; i++) {
			if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
				return false;
			}
		}
		return true;
	}
}


