package com.google.codejam.deukmo;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemB {
    private static final String INPUT_FILENAME = "B-small-attempt0.in";
    private static final String OUTPUT_FILENAME = "B-small-attempt0.out";
    
	public static void main(String[] args) throws Exception {
		System.out.println("Start!");
		
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        long e;
        long r;
        long n;
        long v;
        long total;
        long max;
        long result;
        
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
            // START
        	e = input.nextLong();
        	r = input.nextLong();
        	n = input.nextLong();
        	total = 0;
        	max = 0;
        	for (long i=0; i<n; i++) {
        		v = input.nextLong();
        		total += v;
        		if (max < v) {
        			max = v;
        		}
        	}
        	
        	if (e >= r) {
        		result = (total - max) * r + max * e;
        	} else {
        		result = total * e;
        	}
        	
        	output.format("Case #%d: %d\n", caseNum, result);
            // END
        }
        
        input.close();
        output.close();
        
		System.out.println("Done!");
	}
}
