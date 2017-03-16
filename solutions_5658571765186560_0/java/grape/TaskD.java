package qual2015;

import static java.lang.Math.*;

import util.io.InputParser;
import util.io.OutputGenerator;


public class TaskD {

	static final OutputGenerator og = new OutputGenerator();
	static final InputParser ip = new InputParser("input/d/D-small-attempt0.in", og);
//	static final InputParser ip = new InputParser("input/d/????.in", og);
	
	
	public static void main(String[] args) {
		final int noCases = ip.i();
		while(true) {
			int[] input = ip.ia();
			final int X = input[0];
			final int R = input[1];
			final int C = input[2];
			og.oCase(evilRichCanSucced(X, R, C) ? "RICHARD" : "GABRIEL");
		}
	}
	
	public static final boolean evilRichCanSucced(int X, int R, int C) {
		if((R * C) % X != 0)		// the numbers don't match, no change for Gabriel...
			return true;
		if(X >= 2 * min(R,C) + 1)		// Rich can form an equal-length-legged L...
			return true;
		if(X >= 7)					// Rich can form a shape that has an eye
			return true;
		if(X == 6 && min(R,C)==3 && max(R,C)==4)	// see drawings
			return true;
		if(X == 4 && min(R,C)==2)					// see drawings...
			return true;
		return false;
	}
}
