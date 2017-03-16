package com.joseprio.codejam;

import java.util.*;

public class A extends Solver {

	@Override
	public void solve(int numCase) {
		int[] params = readInts();
		
		int r = params[0];
		int c = params[1];
		int w = params[2];
		int total = w;
		
		// All rows but the last
		total += (r-1)*(c/w);
		
		total += (c-w)/w;
		if ((c-w)%w > 0) {
			total++;
		}
		printLine(total);
	}

}
