package com.teamg9.codejam;

import java.io.File;

public class DancingWithTheGooglers extends Solver {

	public static void main(String...args) {
		DancingWithTheGooglers solver = new DancingWithTheGooglers();
//		solver.solve(new File("inouts/DancingWithTheGooglers/B-sample.in"));
//		solver.solve(new File("inouts/DancingWithTheGooglers/B-small-attempt2.in"));
		solver.solve(new File("inouts/DancingWithTheGooglers/B-large.in"));
//		System.out.println(solver.solve("3 1 5 15 13 11"));
//		System.out.println(solver.solve("3 0 8 23 22 21"));
//		System.out.println(solver.solve("2 1 1 8 0"));
//		System.out.println(solver.solve("6 2 8 29 20 8 18 18 21"));
	}
	
	@Override
	public String evaluate() {
		int n = in.nextInt();
		int s = in.nextInt();
		int p = in.nextInt();
		
		int c = 0;
		for(int i=0; i<n; i++) {
			int t = in.nextInt();
			if(p*3-2<=t) {
				c++;
			} else if(s>0) {
				if(t>1 && p<=(t-2)/3+2) {
					s--;
					c++;
				}
			}
		}
		
		return String.valueOf(c);
	}
	
	
}
