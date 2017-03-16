package com.fexie.code.jam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class LastWorld {

    public static void main( String[] args ) throws Exception
    {
    	int caseNo = 1;
    	boolean noRead = false;
    	try (BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\fengze\\scala_workspace\\jam\\input.txt")); 
    	    	FileWriter fw = new FileWriter("output.txt")) {
    	    String line;
    	    while ((line = br.readLine()) != null) {
    	       if(!noRead) {
    	    	   noRead = true;
    	    	   continue;
    	       }
    	       else {
    	    	   writeLine(caseNo, line, fw);
    	    	   caseNo ++;
    	       }
    	       
    	    }
    	}
    }

    private static void writeLine(int caseNo, String input, FileWriter fw) throws IOException {

    	LastWorld lw = new LastWorld(input);
    	
    	fw.write("Case #" + caseNo + ": " + lw.getOutput() + "\r\n");
    }


	private char[] array;
	public LastWorld(String input) {
		array = input.trim().toUpperCase().toCharArray();
	}

	public String getOutput() {
		String result = new String();
		for(int i = 0; i < array.length; i ++) {
			char c = array[i];
			if(result.length() == 0) {
				result += c;
			}
			else if(result.charAt(0) <= c) {
				result = c + result;
			}
			else {
				result = result + c;
			}
		}
		return result;
	}
}
