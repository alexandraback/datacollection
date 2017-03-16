package util.io;

import util.io.InputParser;
import util.io.OutputGenerator;


public class TaskB {

	static final OutputGenerator og = new OutputGenerator();
	static final InputParser ip = new InputParser("input/b/B-small-attempt0.in", og);
//	static final InputParser ip = new InputParser("input/b/B-large-practice.in", og);
	
	
	
	
	public static void main(String[] args) {
		int noCases = ip.i();
		while(true) {
			final int noNonEmptyPlates = ip.i();
			int[] pancakes = ip.ia();
			assert(pancakes.length == noNonEmptyPlates);
			
			int pMax = max(pancakes);
			int[] p = new int[pMax+1];		// p[i] is the number of plates that have i pancakes on them
			
			for (int i : pancakes)
				p[i]++;
			
//			for (int i = p.length-1; i >= 0; i--)
//				System.out.println(i + " Pancakes:\t" + p[i] + "x");
	
			
			int minTime = Integer.MAX_VALUE;
			int actionsPerformed = 0;
			
			for (int i = p.length-1; i >= 0; i--) {
				minTime = Math.min(minTime, i + actionsPerformed);
				actionsPerformed += p[i];
				int smallHalf = i / 2;
				int bigHalf = i / 2 + i % 2;
				p[smallHalf] += p[i];
				p[bigHalf] += p[i];	
			}

			System.out.println(minTime);
		}
	}
	

	public static final int max(int[] arr) {
		int max = -Integer.MAX_VALUE;
		for (int i = 0; i < arr.length; i++) {
			if(arr[i] > max)
				max = arr[i];
		}
		return max;
	}	
}
