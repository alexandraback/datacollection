package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public abstract class CodeJamBase {
	public final static String SPACE_CHAR = " ";
	
	protected void start() {
    	Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));	    	
    	int totalCount = Integer.parseInt(in.nextLine());
    	String solution, line = "";
    	int lineNum = 1;
    	while(in.hasNextLine()) {
    		line = in.nextLine();    		
    		solution = doResolve(totalCount, line, lineNum);
    		if(!isEmpty(solution)) {
    			outputSolution(lineNum, solution);
    		}
    		lineNum++;
    	}
    	in.close();
	}
	
	protected void outputSolution(int caseNum, String line) {
		String solution = "Case #" + caseNum + ": " + line;
		System.out.println(solution);
	}
	
	private static boolean isEmpty(String str) {
    	return str == null || str.length() == 0;
    }	
	
	public abstract String doResolve(int count, String line, int lineNum);
}
