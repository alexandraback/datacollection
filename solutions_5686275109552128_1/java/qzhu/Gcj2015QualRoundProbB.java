/* 
 * Google Code Jam - 2015 - Qualification Round - Problem B "Infinite House of Pancakes"
 * Solution for large input by Qiyu Zhu
 */

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Gcj2015QualRoundProbB {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++)
			System.out.printf("Case #%d: %d%n", i + 1, handleCase(in));
	}
	
	
	/* 
	 * Mathematical intuition:
	 * - First do all the splits ("special minute"), because there is no benefit
	 *   in postponing them for later.
	 * - Allocate the split pancakes to a new diner who previously had zero on
	 *   his plate, because there is no benefit to stacking them on a diner who
	 *   already has pancakes.
	 * - Scan through the list of pancake stacks and do multiple splits on any
	 *   person who has more than the upper limit. For example, if someone has 9
	 *   pancakes and the limit is 3, then he will be split into [3, 3, 3].
	 *   Another example - having 14 pancakes and the upper limit is 4, the
	 *   split will be [3, 3, 4, 4]. (Note that we perform multiple splits
	 *   so that the result set has a difference of at most 1. We do not do
	 *   balanced binary splitting like [9] -> [4, 5] -> [2, 3, 4] -> [2, 2, 2, 3]
	 *   which is suboptimal compared to [9] -> [3, 6] -> [3, 3, 3].
	 * - Try all possible values of the upper limit (but at least 3,
	 *   because below that it's better to just wait).
	 * - After all the splits are done, simply count down from the maximum
	 *   number of remaining pancakes.
	 */
	private static int handleCase(Scanner in) {
		List<Integer> pancakes = new ArrayList<Integer>();  // Each entries represents the number of pancakes held by a non-zero diner
		int initNonEmpty = in.nextInt();
		for (int i = 0; i < initNonEmpty; i++)
			pancakes.add(in.nextInt());
		
		int maxInitPancakes = Collections.max(pancakes);
		int bestTime = maxInitPancakes;
		for (int upperLimit = 3; upperLimit <= maxInitPancakes; upperLimit++) {
			int time = 0;
			List<Integer> splitPancakes = new ArrayList<Integer>();
			for (int count : pancakes) {
				int parts = (count + upperLimit - 1) / upperLimit;  // ceil(count / upperLimit)
				for (int i = 0; i < parts; i++)
					splitPancakes.add((count + i) / parts);  // All of these parts add up to 'count'
				time += parts - 1;  // Number of splits made
			}
			time += Collections.max(splitPancakes);
			bestTime = Math.min(time, bestTime);
		}
		return bestTime;
	}
	
}
