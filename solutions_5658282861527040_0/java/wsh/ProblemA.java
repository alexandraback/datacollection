
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class ProblemA {
     public static void main(String[] args) throws IOException {
    	 Scanner in = new Scanner(new File("B-small-attempt0.in"));
    	 PrintStream out=new PrintStream("B-small-attempt0.out");
         
    	 
     	 //Scanner in = new Scanner(System.in);
     	 //PrintStream out=new PrintStream(System.out);
     	 
    	 while(in.hasNext()) {
        	 int n=in.nextInt();
        	 for (int z=1;z<=n;z++)
        	 {
        		 int a=in.nextInt();
        		 int b=in.nextInt();
        		 int k=in.nextInt();
        		 
        		 int answer=0;
        		 for (int i=0;i<a;i++)
        		 {
        			 for (int j=0;j<b;j++)
        			 {
        				 if ((i&j)<k)
        				 {
        					 answer++;
        				 }
        			 }
        		 }
            	 
        		 out.println("Case #"+z+": "+answer);
            	
        	 }
         }   
	}
}
