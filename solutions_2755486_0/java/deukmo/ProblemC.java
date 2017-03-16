package com.google.codejam.deukmo;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class ProblemC {
    private static final String INPUT_FILENAME = "C-small-attempt0.in";
    private static final String OUTPUT_FILENAME = "C-small-attempt0.out";

    private static int[] heights = new int[401]; // idx = coord + 200;
    private static int[] updateHeights = new int[401];
    
	public static void main(String[] args) throws Exception {
		System.out.println("Start!");
		
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        int n;
        ArrayList<Tribe> tribes = new ArrayList<Tribe>();
        ArrayList<Tribe> removeList = new ArrayList<Tribe>();
        int success;
        long day, nextDay;
        
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
            // START
        	n = input.nextInt();
        	tribes.clear();
        	for (int i=0; i<n; i++) {
        		Tribe t = new Tribe();
        		t.d = input.nextLong();
        		t.n = input.nextInt();
        		t.w = input.nextInt();
        		t.e = input.nextInt();
        		t.s = input.nextInt();
        		t.deltaD = input.nextInt();
        		t.deltaP = input.nextInt();
        		t.deltaS = input.nextInt();
        		tribes.add(t);
        	}
        	
        	for (int i=0; i<heights.length; i++) {
        		heights[i] = 0;
        	}
        	
        	day = 0;
        	success = 0;
        	while (!tribes.isEmpty()) {
            	for (int i=0; i<updateHeights.length; i++) {
            		updateHeights[i] = 0;
            	}
            	
            	nextDay = -1;
        		for (Tribe t : tribes) {
        			if (t.d == day && t.attack()) {
        				success++;
        			}
        			
    				if (nextDay == -1 || nextDay > t.d) {
    					nextDay = t.d;
    				}
    				
        			if (t.n == 0) {
        				removeList.add(t);
        			}
        		}
        		
            	for (int i=0; i<heights.length; i++) {
            		if (heights[i] < updateHeights[i]) {
            			heights[i] = updateHeights[i];
            		}
            	}
        		
        		tribes.removeAll(removeList);
        		removeList.clear();
        		
        		day = nextDay;
        	}
        	
        	output.format("Case #%d: %d\n", caseNum, success);
            // END
        }
        
        input.close();
        output.close();
        
		System.out.println("Done!");
	}
	
	public static class Tribe {
		long d;
		int n;
		int w, e;
		int s;
		int deltaD;
		int deltaP;
		int deltaS;
		
		public boolean attack() {
			boolean success = false;
			for (int i=w; i<e; i++) {
				if (heights[i + 200] < s) {
					if (updateHeights[i + 200] < s) {
						updateHeights[i + 200] = s;
					}
					success = true;
				}
			}
			
			d += deltaD;
			w += deltaP;
			e += deltaP;
			s += deltaS;
			n--;
			
			return success;
		}
	}
}
