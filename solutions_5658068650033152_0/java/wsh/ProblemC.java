import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class ProblemC {
     public static void main(String[] args) throws IOException {
    	 Scanner in = new Scanner(new File("C-small-attempt2.in"));
    	 PrintStream out=new PrintStream("C-small-attempt2.out");      
    	 
     	 //Scanner in = new Scanner(System.in);
     	 //PrintStream out=new PrintStream(System.out);
     	 
    	 while(in.hasNext()) {
        	 int total=in.nextInt();
        	 for (int z=1;z<=total;z++)
        	 {
        		 int n=in.nextInt();
        		 int m=in.nextInt();
        		 int k=in.nextInt();
        		 
        		 if (m>n)
        		 {
        			 int temp=m;
        			 m=n;
        			 n=temp;
        		 }
        		 
        		 int answer=k;
        		 int tempanswer;
        		 for (int i=0;i<=n;i++)
        		 {
        			 for (int j=0;j<=m;j++)
        			 {
        				 if (i==1||i==2||j==1||j==2)
        				 {
        					 continue;
        				 }
        				 else if (i*j-4>=k && (i-2)*2+(j-2)*2<answer)
        				 {
        					 answer=(i-2)*2+(j-2)*2;
        				 }
        				 else if (i*j-3>=k && (i-2)*2+(j-2)*2+1<answer)
        				 {
        					 answer=(i-2)*2+(j-2)*2+1;
        				 }
        				 else if (i*j-2>=k && (i-2)*2+(j-2)*2+2<answer)
        				 {
        					 answer=(i-2)*2+(j-2)*2+2;
        				 }
        				 else if (i*j-1>=k && (i-2)*2+(j-2)*2+3<answer)
        				 {
        					 answer=(i-2)*2+(j-2)*2+3;
        				 }
        				 else if (i*j>=k && (i-2)*2+(j-2)*2+4<answer)
        				 {
        					 answer=(i-2)*2+(j-2)*2+4;
        				 }
        			 }
        		 }
            	 
        		 if (m==4)
        		 {
        			 if (n==5 && k<=15) if (answer>9) 
        			 {
        				 answer=9; 
        				 System.out.println("changed 1");
        			 }
        			 
        			 if (n==5 && k<=12) if (answer>8)
        			 {
        				 answer=8;  
        				 System.out.println("changed 2");
        			 }
        			 
        			 if (k<=10) if (answer>7) 
        			 {
        				 answer=7;
        				 System.out.println("changed 3");
        			 }
        			 if (k<=8) if (answer>6) 
        			 {
        				 answer=6;
        				 System.out.println("changed 4");
        			 }
        		 }
        		 out.println("Case #"+z+": "+answer);            	
        	 }
         }   
	}
}
