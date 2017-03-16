package codejam;

import java.io.*;
import java.util.Scanner;

public class coinjam {
	
	public static void main(String args[]) throws IOException {
	
		
		FileInputStream in = null;
		PrintWriter out = null;

	    try {
	         in = new FileInputStream("C-large.in");
	         out = new PrintWriter( "outputC-large.txt" );
	        	    
	        	    
	         Scanner sc = new Scanner (in);
	         String line = sc.nextLine();
	           
	         int T = Integer.parseInt(line);
	         
	         String output = "Case #" + T + ":";
        	 out.println( output );
        	 
        	 line = sc.nextLine();
        	 int N = Integer.parseInt(line.split(" ")[0]);
        	 int J = Integer.parseInt(line.split(" ")[1]);
        	 
        	 int middleLength = N/2-2;
        	
        	 String halfString = null;
             for(int i=0 ; i < J ; i++) {
            	 halfString = "1";
            	 String x = Integer.toBinaryString(i);
            	 int padding = middleLength-x.length();
            	 for( int j=0; j<padding ; j++) 
            		 halfString += "0";
            	 halfString += x;
            	 halfString += "1";
            	 
            	 String output2 = halfString+halfString;
            	 for (int b = 2; b <= 10; b++) {
            		 long a = 0;
            		 long k = 1;
            		 for (int c = halfString.length()-1; c >=0 ; c--) {
            			 String s = String.valueOf(halfString.charAt(c));
            			 a += Integer.parseInt(s)*k;
            			 k *= b;
            		 }
            		 output2 += " " + String.valueOf(a);
            	 }
            	 out.println( output2 );
             }
     
	         
	         
	     }finally {
	         if (in != null) {
	            in.close();
	         }
	         if (out != null) {
	            out.close();
	         }
	      }
	}

}
