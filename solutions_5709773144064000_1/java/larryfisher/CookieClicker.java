
package com;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.text.DecimalFormat;

public class CookieClicker {

    public static void main(String[] args) {
        
        String base="files/";
        String in=base + "B-large.in";
        String out=base + "output1.txt";
        
        
	    try {
	    	BufferedReader br = new BufferedReader(new FileReader(in));
	        
	        StringBuilder sb = new StringBuilder();
	        String line = br.readLine();
	        
	        int tctotal = 0;
	        int tc = 0;
	        int i = -1;
	        
	        while (line != null) {
	        	i++;
	        	
		        if(i == 0){
	        		tctotal = Integer.parseInt(line);
	        		tc = 1;
	        	} else {
	        		String[] parse = line.split(" ");
	        		double [] node = new double [3];
	        		for(int c=0; c<3; c++){
	        			 node[c] = Double.parseDouble(parse[c]);
	        		}

	        		double c = node[0];
	        		double f = node[1];
	        		double x = node[2];
	        		double r = 2.0;
	        		double total = 0;
	        		
	        		while(goAhead(c,x,f,r)){
	        			total = total + c/r;
	        			r = r+f;
	        		}
	        		
	        		total = total + x/r;
	        		
	        		DecimalFormat format = new DecimalFormat("0.0000000");
	        		String output = "Case #"+tc	+": "+format.format(total);
	        		
	        		sb.append(output);
	        		sb.append(System.lineSeparator());
	        		
	        		tc++;
	        	}
		        
	        	line = br.readLine();
	        }
	        
	        String everything = sb.toString();
	        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(
	                new FileOutputStream("files/output.txt"), "utf-8"));
	          writer.write(everything);
	          writer.close();
	    } catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
	    }
    }
    
    // should i buy the cookie farm?
    private static boolean goAhead(double c, double x, double f, double r){
    	// buy farm!
    	double buy = c/r + x/(r+f);
    	double dontbuy = x/r;
    	
    	if(buy < dontbuy){
    		return true;
    	} else {
    		return false;
    	}
    }
}
