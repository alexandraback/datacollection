package codejam;

import java.io.*;
import java.util.Scanner;

public class fractiles {
	
	public static void main(String args[]) throws IOException {
	
		
		FileInputStream in = null;
		PrintWriter out = null;

	    try {
	         in = new FileInputStream("D-large.in");
	         out = new PrintWriter( "outputD-large.txt" );
	        	    
	        	    
	         Scanner sc = new Scanner (in);
	         String line = sc.nextLine();
	           
	         int T = Integer.parseInt(line);
	         
	         for(int i=1; i<=T; i++) {
	        	 
	        	 line = sc.nextLine();
	        	 int K = Integer.parseInt(line.split(" ")[0]);
	        	 int C = Integer.parseInt(line.split(" ")[1]);
	        	 int S = Integer.parseInt(line.split(" ")[2]);
	        	 
	        	 if ( S*C < K ) {
	        		 String output = "Case #" + i + ": IMPOSSIBLE";
	        		 out.println( output );
	        	 }
	        	 else {
	        		 String output = "Case #" + i + ": ";
	        		 long b = 1;
	        		 for (int j = 0; j < Math.ceil(((double)K/C)); j++) {
	        			 long a = 0;
	        			 for (int k = 0; k < C; k++) {
	        				 a += Math.min(b-1, K-1);
	        				 if (k + 1 < C) {
		        				 a *= K;	        					 
	        				 }
	        				 b++;
	        			 }
	        			 a++;
	        			 output = output + " " + a;
	        		 }
	        		 out.println(output);
	        	 }
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
