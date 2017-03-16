package com.google.codejam.deukmo;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemA {
    private static final String INPUT_FILENAME = "A-small-attempt0.in";
    private static final String OUTPUT_FILENAME = "A-small-attempt0.out";
    
	public static void main(String[] args) throws Exception {
		System.out.println("Start!");
		
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        long r;
        long t;
        double first;
        double total;
        long numOfBlackRing;
        
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
            // START
        	r = input.nextLong();
        	t = input.nextLong();
        	
        	first = 2 * r + 1;
        	numOfBlackRing = (long) (-(first - 2) + Math.sqrt(Math.pow((first - 2), 2) + 8 * t)) / 4;
        	total = first * (double)numOfBlackRing + 2 * (double)numOfBlackRing * ((double)numOfBlackRing - 1);
        	while (t < total) {
        		numOfBlackRing--;
        		total = first * (double)numOfBlackRing + 2 * (double)numOfBlackRing * ((double)numOfBlackRing - 1);
        	}
        	
        	output.format("Case #%d: %d\n", caseNum, numOfBlackRing);
            // END
        }
        
        input.close();
        output.close();
        
		System.out.println("Done!");
	}
}
