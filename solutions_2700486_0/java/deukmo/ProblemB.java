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
        int n, x, y;
        int u;
        int topIdx;
        int botIdx;
        int m;
        int t;
        int min, max;
        double p;
        double up;
        
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
            // START
        	n = input.nextInt();
        	x = input.nextInt();
        	y = input.nextInt();
        	
        	if (x < 0) x = -x;
        	
    		u = x + y + 1;
    		topIdx = u * (u + 1) / 2;
        	if (x == 0) {
        		if (n >= topIdx) {
        			p = 1.0;
        		} else {
        			p = 0.0;
        		}
        	} else {
        		botIdx = (u - 2) * (u - 1) / 2;
        		t = y + 1;
        		m = (topIdx - botIdx - 1) / 2;
        		min = botIdx + t;
        		max = min + m - 1;
        		if (n < min) {
        			p = 0.0;
        		} else if (n > max) {
        			p = 1.0;
        		} else {
        			m = Math.max(m, n - botIdx);
        			
        			p = 0.0;
        			up = 1.0;
        			for (int i=0; i<m; i++) {
        				up *= 0.5;
        			}
        			for (int i=t; i<=m; i++) {
        				p += coe(m, i) * up;
        			}
        		}
        	}
        	
        	output.format("Case #%d: %f\n", caseNum, p);
            // END
        }
        
        input.close();
        output.close();
        
		System.out.println("Done!");
	}
	
	public static double coe(int n, int k) {
		return fac(n) / (double)(fac(k) * fac(n-k));
	}
	
	public static int fac(int k) {
		int r = 1;
		for (int i=1; i<=k; i++) {
			r = r * i;
		}
		return r;
	}
}
