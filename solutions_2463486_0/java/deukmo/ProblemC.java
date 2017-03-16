package com.google.codejam.deukmo;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemC {
    private static final String INPUT_FILENAME = "C-small-attempt0.in";
    private static final String OUTPUT_FILENAME = "C-small-attempt0.out";
    
	public static void main(String[] args) throws Exception {
		System.out.println("Start!");
		
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        long a;
        long b;
        long min;
        long max;
        long pow;
        long count;
        
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
            // START
        	a = input.nextLong();
        	b = input.nextLong();
        	
        	min = (long) Math.sqrt(a);
        	max = (long) Math.sqrt(b) + 1;
        	count = 0;
        	for (long i=min; i<=max; i++) {
        		if (isPalindromes(i)) {
        			pow = i * i;
        			if (pow >= a && pow <= b && isPalindromes(pow)) {
        				count++;
        			}
        		}
        	}
        	
        	output.format("Case #%d: %d\n", caseNum, count);
            // END
        }
        
        input.close();
        output.close();
        
		System.out.println("Done!");
	}
	
	private static boolean isPalindromes(long number) {
		long tmp = number;
		long conv = 0;
		
		while (tmp != 0) {
			conv = conv * 10 + tmp % 10;
			tmp = tmp / 10;
		}
		
		return (conv == number);
	}
}
