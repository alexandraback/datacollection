/* 
 * Google Code Jam - 2015 - Round 1B - Problem A "Counter Culture"
 * Solution for small input by Qiyu Zhu
 */

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;


public class ProblemASmall {
	
	public static void main(String[] args) {
		int[] distance = new int[1000001];
		Arrays.fill(distance, Integer.MAX_VALUE);
		distance[1] = 1;
		Queue<Integer> queue = new ArrayDeque<Integer>();
		queue.add(1);
		while (!queue.isEmpty()) {
			int n = queue.remove();
			int d = distance[n] + 1;
			int m = n + 1;
			if (m < distance.length && d < distance[m]) {
				distance[m] = d;
				queue.add(m);
			}
			m = Integer.parseInt(new StringBuilder(Integer.toString(n)).reverse().toString());
			if (m < distance.length && d < distance[m]) {
				distance[m] = d;
				queue.add(m);
			}
		}
		
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++)
			System.out.printf("Case #%d: %d%n", i + 1, distance[in.nextInt()]);
	}
	
}
