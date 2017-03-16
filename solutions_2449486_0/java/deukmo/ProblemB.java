package com.google.codejam.deukmo;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ProblemB {
    private static final String INPUT_FILENAME = "B-small-attempt0.in";
    private static final String OUTPUT_FILENAME = "B-small-attempt0.out";
    
	public static void main(String[] args) throws Exception {
		System.out.println("Start!");
		
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        int N;
        int M;
        int[][] lawn;
        ArrayList<Integer> height = new ArrayList<Integer>();
        int min;
        int max;
        boolean[] row;
        boolean[] col;
        boolean sameHeight;
        boolean isPossible;
        
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
            // START
        	N = input.nextInt();
        	M = input.nextInt();
        	lawn = new int[N][M];
        	row = new boolean[N];
        	col = new boolean[M];
        	height.clear();
        	for (int i=0; i<N; i++) {
        		for (int j=0; j<M; j++) {
        			lawn[i][j] = input.nextInt();
        			if (!height.contains(lawn[i][j])) {
        				height.add(lawn[i][j]);
        			}
        		}
        	}
        	
        	Collections.sort(height);
        	
        	min = height.remove(0);
        	while(!height.isEmpty()) {
        		max = height.remove(0);
        		
        		// row
	        	for (int i=0; i<N; i++) {
	        		row[i] = false;
	        		
	        		if (lawn[i][0] != min) continue;
	        		sameHeight = true;
	        		for (int j=1; j<M; j++) {
	        			if (lawn[i][j] != min) {
	        				sameHeight = false;
	        				break;
	        			}
	        		}
	        		if (sameHeight) {
	        			row[i] = true;
	        		}
	        	}
	        	
        		// col
	        	for (int i=0; i<M; i++) {
	        		col[i] = false;
	        		
	        		if (lawn[0][i] != min) continue;
	        		sameHeight = true;
	        		for (int j=1; j<N; j++) {
	        			if (lawn[j][i] != min) {
	        				sameHeight = false;
	        				break;
	        			}
	        		}
	        		if (sameHeight) {
	        			col[i] = true;
	        		}
	        	}
	        	
	        	// grow up
	        	for (int i=0; i<N; i++) {
	        		if (row[i]) {
	        			for (int j=0; j<M; j++) {
		        			lawn[i][j] = max;
		        		}
	        		}
	        	}
	        	for (int i=0; i<M; i++) {
	        		if (col[i]) {
	        			for (int j=0; j<N; j++) {
		        			lawn[j][i] = max;
		        		}
	        		}
	        	}
	        	
	        	min = max;
        	}
        	
        	isPossible = true;
        	max = lawn[0][0];
        	for (int i=0; i<N; i++) {
        		for (int j=0; j<M; j++) {
        			if (lawn[i][j] != max) {
        				isPossible = false;
        			}
        		}
        	}
        	
        	if (isPossible) {
        		output.format("Case #%d: YES\n", caseNum);
        	} else {
        		output.format("Case #%d: NO\n", caseNum);
        	}
            // END
        }
        
        input.close();
        output.close();
        
		System.out.println("Done!");
	}
}
