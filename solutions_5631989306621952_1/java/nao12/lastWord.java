package codejam_R1A;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class lastWord {
	
	public static void main(String[] args) throws IOException {
	FileInputStream in = null;
	PrintWriter out = null;

      try {
         in = new FileInputStream("A-large.in");
         out = new PrintWriter( "outputA-large.txt" );

         Scanner sc = new Scanner (in);
         String line = sc.nextLine();
           
         int T = Integer.parseInt(line);
         
         for(int i=1; i<=T; i++) {
        	 line = sc.nextLine();
        	 String front = "";
        	 String end = "";
        	 
        	 for(int j = line.length()-1; j>=0; j--) {
        		 char c = line.charAt(j);
        		 boolean toEnd = false;
        		 for(int k=j-1; k>=0; k--) {
        			 if(line.charAt(k) > c) {
        				 toEnd = true;
        				 break;
        			 }
        		 }
        		 if (toEnd == true) {
        			 end = c + end;
        		 } else {
        			 front = front + c;
        		 }
        	 }
        	 	 
             String output = "Case #" + i + ": " + front + end;
        	 out.println( output );
         }
      } finally {
         if (in != null) {
            in.close();
         }
         if (out != null) {
            out.close();
         }
      }
	}
}
