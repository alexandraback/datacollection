package com.google.code.jam;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.List;

import org.apache.commons.io.IOUtils;

import com.google.common.collect.Lists;

/**
 */
public class ProblemOne {
	
	public static String solve(String input) {
		String[] inpArr = input.split("/");
		int inpInt = Integer.valueOf(inpArr[1]); 
		double inp = Double.valueOf(inpArr[1]) / Double.valueOf(inpArr[0]);
		int den = Integer.valueOf(inpArr[1]);
		int num = Integer.valueOf(inpArr[0]);
		
		int gcd = gcd(num,den);
		//System.out.println(num+ " : "+den+ " : "+gcd+" : "+den/gcd);
		if(!isTwoPower(den/gcd)) {
			return "impossible";
		}
		
		for(int k=0; k<= 40; k++) {
			double left = Math.pow(2, k-1);
			double right = Math.pow(2, k);
			//System.out.println("Lef>>" + left + "<< Inp>>" + inp + "<< Right >>" + right + "<<" );
			if((left < inp && inp < right) || inp == left || inp == right) {
				return String.valueOf(k);
			}
		}
		return "impossible";
	}
	
	
    private static boolean isTwoPower(int i) {
    	if( (i & i-1) == 0) {
    		return true;
    	} else {
    		return false;
    	}
	}

	private static int gcd(int num, int den) {
		if (den == 0)
			return num;
	    else
	    	return gcd(den, num%den);
	}


	public static void main(String[] args) throws Exception {
	    final String inputFileLocation = "/home/sravanb/A-small-attempt0.in";
	    final String outputFileLocation = inputFileLocation + "output";
	    // final String fileLocation = "/home/satselva/personal/downloads/dummy-small-practice.in";
	    int readLineCnt = 0;
	    List<String> inputLines = IOUtils.readLines(new FileInputStream(inputFileLocation));
	    List<String> outputLines = Lists.newArrayList();
	    int testCaseCount = Integer.valueOf(inputLines.get(readLineCnt++));
	    for (int testCaseNumber = 1; testCaseNumber <= testCaseCount; testCaseNumber++) {
	        String inp = inputLines.get(readLineCnt++);
	        // Volunteer first selection
	        String testCaseOutput = String.format("Case #%d: %s", testCaseNumber, solve(inp));
	        System.out.println(testCaseOutput);
	        
	        //break;
	    }
	    IOUtils.writeLines(outputLines, "\n", new FileOutputStream(outputFileLocation));
    }

	
}
