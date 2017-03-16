package com.google.codejam.deukmo;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ProblemA {
    private static final String INPUT_FILENAME = "A-small-attempt3.in";
    private static final String OUTPUT_FILENAME = "A-small-attempt3.out";
    
	public static void main(String[] args) throws Exception {
		System.out.println("Start!");
		
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        int a, n;
        ArrayList<Integer> motes = new ArrayList<Integer>();
        int[] cnts;
        
        int mote;
        int cnt;
        
        int min;
        
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
            // START
        	a = input.nextInt();
        	n = input.nextInt();
        	motes.clear();
        	for (int i=0; i<n; i++) {
        		motes.add(input.nextInt());
        	}
        	
        	Collections.sort(motes);
        	
        	cnt = 0;
        	cnts = new int[n];
        	for (int i=0; i<n; i++) {
        		mote = motes.get(i);
        		
        		if (mote < a) {
        			a += mote;
        		} else {
        			if (a == 1) {
        				cnt += 101;
        			} else {
	        			while (mote >= a) {
	        				a = a + a - 1;
	        				cnt++;
	        			}
	        			a += mote;
        			}
        		}
        		
        		cnts[i] = cnt + (n - 1 - i);
        	}
        	
        	min = n;
        	for (int i=0; i<n; i++) {
        		if (cnts[i] < min) {
        			min = cnts[i];
        		}
        	}
        	
        	output.format("Case #%d: %d\n", caseNum, min);
            // END
        }
        
        input.close();
        output.close();
        
		System.out.println("Done!");
	}
}
