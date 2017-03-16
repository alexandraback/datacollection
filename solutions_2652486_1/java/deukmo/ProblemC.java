package com.google.codejam.deukmo;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemC {
    private static final String INPUT_FILENAME = "C-small-2-attempt3.in";
    private static final String OUTPUT_FILENAME = "C-small-2-attempt3.out";
    
	public static void main(String[] args) throws Exception {
		System.out.println("Start!");
		
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        output.format("Case #%d:\n", numberOfTestCase);
        
        int r = input.nextInt();
        int n = input.nextInt();
        int m = input.nextInt();
        int k = input.nextInt();
        
        int[] numbers = new int[10];
        int[] result = new int[10];
        int resultCount;
        
        long product;
        
        for (int caseNum=1; caseNum<=r; caseNum++) {
            // START
        	for (int i=0; i<10; i++) {
        		result[i] = 0;
        	}
        	
        	resultCount = 0;
        	for (int i=0; i<k; i++) {
        		product = input.nextLong();
        		if (product == 1 | resultCount == n) continue;

            	for (int j=0; j<10; j++) {
            		numbers[j] = 0;
            	}

        		for (int j=2; j<=m; j++) {
        			while (product != 0 && product % j == 0) {
        				numbers[j]++;
        				product = product / j;
        			}
        		}
        		
        		resultCount = 0;
        		for (int j=2; j<=m; j++) {
        			if (result[j] < numbers[j]) {
        				result[j] = numbers[j];
        			}
        			resultCount += result[j];
        		}
        	}
    		
    		while (resultCount > (n + 1) && result[2] >= 3) {
    			result[2] -= 3;
    			result[8]++;
    			resultCount -= 2;
    		}
    		
    		while (resultCount > n && result[2] >= 2) {
    			result[2] -= 2;
    			result[4]++;
    			resultCount--;
    		}
    		
    		while (resultCount > n && result[2] > 0 && result[3] > 0) {
    			result[2]--;
    			result[3]--;
    			result[6]++;
    			resultCount--;
    		}
        	
        	if (resultCount == n) {
	        	for (int i=2; i<=m; i++) {
	        		for (int j=0; j<result[i]; j++) {
	        			output.format("%d", i);
	        		}
	        	}
        	} else {
        		for (int j=0; j<n; j++) {
        			output.format("%d", 2);
        		}
        	}
        	output.format("\n");
            // END
        }
        
        input.close();
        output.close();
        
		System.out.println("Done!");
	}
}
