/* 
 * Google Code Jam - 2015 - Qualification Round - Problem B "Infinite House of Pancakes"
 * Solution for large input by Qiyu Zhu
 * 
 * This program is unfinished and incorrect.
 */

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;


public class Gcj2015QualRoundProbBSmall {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++)
			System.out.printf("Case #%d: %d%n", i + 1, handleCase(in));
	}
	
	
	private static int handleCase(Scanner in) {
		List<Integer> pancakes = new ArrayList<Integer>();
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
					splitPancakes.add((count + i) / parts);
				time += parts - 1;
			}
			time += Collections.max(splitPancakes);
			bestTime = Math.min(time, bestTime);
		}
		return bestTime;
	}
	
	
	private static int solveState(State init) {
		// Breadth-first search
		Queue<State> queue = new ArrayDeque<State>();
		queue.add(init);
		while (!queue.isEmpty()) {
			State state = queue.remove();
			Collection<State> nexts = state.getNextStates();
			if (nexts.isEmpty()) {
				printPath(state);
				return state.depth;
			} else
				queue.addAll(nexts);
		}
		throw new AssertionError();
	}
	
	
	private static void printPath(State state) {
		List<State> path = new ArrayList<State>();
		for (State node = state; node != null; node = node.previous)
			path.add(node);
		Collections.reverse(path);
		for (State st : path)
			System.out.println(Arrays.toString(st.pancakesPeople));
		System.out.println();
	}
	
	
	
	private static final class State {
		
		public final int[] pancakesPeople;  // There are pancakesPeople[i] people who have i pancakes
		public final int depth;
		public final State previous;
		
		
		public State(int[] pancakesPeople, int depth, State previous) {
			if (pancakesPeople == null)
				throw new NullPointerException();
			if (depth < 0)
				throw new IllegalArgumentException();
			this.pancakesPeople = pancakesPeople;
			this.depth = depth;
			this.previous = previous;
		}
		
		
		public Collection<State> getNextStates() {
			boolean isFinished = true;
			int[] waitNext = new int[pancakesPeople.length];
			waitNext[0] = pancakesPeople[0];
			for (int i = 1; i < pancakesPeople.length; i++) {
				isFinished &= pancakesPeople[i] == 0;
				waitNext[i - 1] += pancakesPeople[i];
			}
			
			if (isFinished)
				return Collections.emptyList();
			Collection<State> result = new ArrayList<State>();
			result.add(new State(waitNext, depth + 1, this));
			
			// Split one person with the largest number of pancakes, and make the split as even as possible
//			int[] splitNext = pancakesPeople.clone();
//			for (int i = splitNext.length - 1; i >= 2; i--) {
//				if (splitNext[i] > 0) {
//					splitNext[i]--;
//					splitNext[(i + 0) / 2]++;
//					splitNext[(i + 1) / 2]++;
//					result.add(new State(splitNext, depth + 1, this));
//					break;
//				}
//			}
			
			// XXX Try all possible splits!!
			for (int i = pancakesPeople.length - 1; i >= 2; i--) {
				if (pancakesPeople[i] == 0)
					continue;
				for (int j = 1; j <= i - j; j++) {
					int[] splitNext = pancakesPeople.clone();
					splitNext[i]--;
					splitNext[j]++;
					splitNext[i - j]++;
					result.add(new State(splitNext, depth + 1, this));
				}
			}
			return result;
		}
		
	}
	
}
