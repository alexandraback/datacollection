import java.io.*;
import java.util.*;

public class CodeJam3 {
	
	public static void main(String[] args) {
		FileReader reader = null;
        try {
        		reader = new FileReader(args[0]);
        } catch (FileNotFoundException fnf) {
        		System.out.println("The input file is not found");
        }
        
        BufferedReader bufreader = new BufferedReader(reader);
        String line = null;		//each line of the data
        
        //read the number of test cases
        try {
			line = bufreader.readLine();
		} catch (IOException e0) {
			System.out.println("An IO error occurs when read the number of test cases");
		}
        
        int numCase = Integer.parseInt(line);
        
        //calculate the fair and square number within 1000 first
        boolean[] resArr = new boolean [1024];
        Arrays.fill(resArr, false);
        for(int i = 1; i <= 32; i++) {
        	String strI = String.valueOf(i);
        	//palindromes number
        	if( new StringBuffer(strI).reverse().toString().equals(strI) ) {
        		int square = i*i;
        		String strSquareI = String.valueOf(square);
        		if( new StringBuffer(strSquareI).reverse().toString().equals(strSquareI) ) {
        			resArr[square] = true;
        		}
        	}
        }
        
        try {
	    	for(int i = 0;i < numCase;i++) {
	    		line = bufreader.readLine();
	    		String[] splitLine = line.split(" ");
    			int n = Integer.parseInt(splitLine[0]);
    			int m = Integer.parseInt(splitLine[1]);
	    	
    			int result = 0;
    	        for(int k = n; k <= m;k++) {
    	        	if(resArr[k])
    	        	result++;
    	        }
	    		int printNumCase = i + 1;
	   			System.out.println("Case #"+printNumCase+": " + result);
	    	}
        } catch(IOException e1) {
        	System.out.println("An IO error occurs when read line");
        }
	}
}