package qual2015;

import java.util.Arrays;

import org.w3c.dom.CDATASection;

import util.io.InputParser;
import util.io.OutputGenerator;


public class TaskB {

	static final OutputGenerator og = new OutputGenerator();
//	static final InputParser ip = new InputParser("input/b/B-small-attempt1.in", og);
	static final InputParser ip = new InputParser("input/b/B-large.in", og);
	
	
	
	
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
			
			int minTime = Integer.MAX_VALUE;
			
			for(int ctDwnThresh = 1; ctDwnThresh <= pMax; ctDwnThresh++) {
				int noActions = 0;
				for (int j = p.length-1; j >= 0; j--) {
					noActions += p[j] * ((int)(Math.ceil((double)j / ctDwnThresh)) -1);		// ceil(j / ctDwnThresh) -1
				}
				minTime = Math.min(minTime, noActions + ctDwnThresh);
			}
			og.oCase(minTime);
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
