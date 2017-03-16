/* 
 * Google Code Jam - 2015 - Round 1B - Problem A "Counter Culture"
 * Solution for large input by Qiyu Zhu
 */

import java.util.Scanner;


public class ProblemALarge {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++)
			System.out.printf("Case #%d: %d%n", i + 1, handleCase(in.nextLong()));
	}
	
	
	private static long handleCase(long target) {
		long count = 1;
		long current = 1;
		long waypoint = Math.min(9, target);
		while (current < target) {
			boolean dec = waypoint % 10 == 0;  // Fixup for targets ending in 0
			count += minMoves(current, waypoint - (dec ? 1 : 0));
			current = waypoint;
			count += dec ? 1 : 0;
			if (current < target) {
				current++;
				count++;
				waypoint = Math.min(waypoint * 10 + 9, target);
			}
		}
		return count;
	}
	
	
	private static long minMoves(long from, long to) {
		String fromStr = Long.toString(from);
		String toStr = Long.toString(to);
		if (fromStr.length() != toStr.length() || !fromStr.matches("10*"))
			throw new IllegalArgumentException();
		String toRevStr = reverse(toStr);
		
		long min = to - from;
		for (int i = 0; i < fromStr.length(); i++) {
			long mid = Long.parseLong(fromStr.substring(0, i) + toRevStr.substring(i));
			if (mid >= from && reverse(mid) <= to) {
				long moves = (mid - from) + 1 + (to - reverse(mid));
				min = Math.min(moves, min);
			}
		}
		return min;
	}
	
	
	private static long reverse(long n) {
		return Long.parseLong(reverse(Long.toString(n)));
	}
	
	
	private static String reverse(String s) {
		return new StringBuilder(s).reverse().toString();
	}
	
}
