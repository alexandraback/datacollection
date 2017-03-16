package codejam;

import java.io.*;
import java.util.Scanner;

public class countingSheep {

	static boolean[] digitArray;
	
	public static void main(String args[]) throws IOException {
		
		digitArray = new boolean[10];
		for(int i=0; i<10; i++){
			digitArray[i] = false;
		}
		
		FileInputStream in = null;
		PrintWriter out = null;

	      try {
	         in = new FileInputStream("A-small-attempt0.in");
	         out = new PrintWriter( "outputA.txt" );
	        	    
	        	    
	         Scanner sc = new Scanner (in);
	         String line = sc.nextLine();
	           
	         int T = Integer.parseInt(line);
	         
	         for(int i=1; i<=T; i++) {
	        	 int N = Integer.parseInt(sc.nextLine());
	        	 
	        	 String output;
	        	 if (N == 0) {
		        	 output = "Case #" + i + ": INSOMNIA" ;
	        	 }
	        	 else {
	        		 int lastNumber = calculateLastNumber(N);
	        		 output = "Case #" + i + ": " + lastNumber;
	        	 }
	        	 
	        	 out.println( output );
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
	
	public static int calculateLastNumber (int N) {
		
		int x = 1;
		int currentN = 0;
		while ( !allDigitSeen() ) {
			currentN = N*x;
			int number = currentN;
			
			while (number > 0) {
				int digit = number%10;
				digitArray[digit] = true;
				number = number / 10;
			}
			x++;
		}
		
		digitArray = new boolean[10];
		for(int i=0; i<10; i++){
			digitArray[i] = false;
		}
		
		return currentN;
	}
	
	static boolean allDigitSeen() {
		for(int i=0; i<10; i++) {
			if (digitArray[i] == false)
				return false;
		}
		return true;
	}
}
