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
        String name;
        int n, length;
        int left;
        int match;
        int matchLeft;
        int result;
        
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
            // START
        	name = input.next();
        	n = input.nextInt();
        	
        	length = name.length();
        	left = 0;
        	match = 0;
        	matchLeft = 0;
        	result = 0;
        	for (int i=0; i<length; i++) {
        		if (!isVowel(name.charAt(i))) {
        			match++;
        		} else {
        			match = 0;
        		}
        		
        		if (match >= n) {
        			matchLeft = i - n + 1;
        			result += (matchLeft - left + 1) * (length - i);
        			left = matchLeft + 1;
        			match--;
        		}
        	}
        	
        	output.format("Case #%d: %d\n", caseNum, result);
            // END
        }
        
        input.close();
        output.close();
        
		System.out.println("Done!");
	}
	
	public static boolean isVowel(char c) {
		return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	}
}
