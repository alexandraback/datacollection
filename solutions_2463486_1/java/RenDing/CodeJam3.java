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
        ArrayList<Long> fairSquareList = new ArrayList<Long>();
        //calculate the fair and square number within 10000000 first
        for(long i = 1; i <= 10000000; i++) {
        	String strI = String.valueOf(i);
        	//palindromes number
        	if( new StringBuffer(strI).reverse().toString().equals(strI) ) {
        		long square = i*i;
        		String strSquareI = String.valueOf(square);
        		if( new StringBuffer(strSquareI).reverse().toString().equals(strSquareI) ) {
        			fairSquareList.add(square);
        		}
        	}
        }
        /*
        for(int i = 0;i< fairSquareList.size();i++) {
        	System.out.println(fairSquareList.get(i));
        }
        */
        try {
	    	for(int i = 0;i < numCase;i++) {
	    		line = bufreader.readLine();
	    		String[] splitLine = line.split(" ");
    			long n = Long.parseLong(splitLine[0]);
    			long m = Long.parseLong(splitLine[1]);
	    	
    			long result = 0;
    			for(int k = 0;k< fairSquareList.size();k++) {
    				if(fairSquareList.get(k)>=n && fairSquareList.get(k) <= m)
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