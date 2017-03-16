package com.google.codejam.deukmo;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemB {
    private static final String INPUT_FILENAME = "B-small-attempt1.in";
    private static final String OUTPUT_FILENAME = "B-small-attempt1.out";
    
	public static void main(String[] args) throws Exception {
		System.out.println("Start!");
		
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        int x, y;
        int mX, mY;
        String result = "";
        
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
            // START
        	x = input.nextInt();
        	y = input.nextInt();
        	
        	for (int t = 1; t <= 500; t++) {
        		result = "";
        		mX = x;
        		mY = y;
        		for (int i=t; i>=1; i--) {
        			if (Math.abs(mX) >= Math.abs(mY)) {
        				if (mX < 0) {
        					mX += i;
        					result = "W" + result;
        				} else {
        					mX -= i;
        					result = "E" + result;
        				}
        			} else {
        				if (mY < 0) {
        					mY += i;
        					result = "S" + result;
        				} else {
        					mY -= i;
        					result = "N" + result;
        				}
        			}
        		}
        		
        		if (mX == 0 && mY == 0) {
        			break;
        		}
        	}
        	
        	output.format("Case #%d: %s\n", caseNum, result);
            // END
        }
        
        input.close();
        output.close();
        
		System.out.println("Done!");
	}
}
