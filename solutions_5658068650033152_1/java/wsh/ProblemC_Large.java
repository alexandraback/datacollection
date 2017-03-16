import java.util.Scanner;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class ProblemC_Large {
     public static void main(String[] args) throws IOException {
    	 Scanner in = new Scanner(new File("C-large.in"));
    	 PrintStream out=new PrintStream("C-large.out");      
    	 
     	 //Scanner in = new Scanner(System.in);
     	 //PrintStream out=new PrintStream(System.out);
     	 
    	 while(in.hasNext()) {
        	 int total=in.nextInt();
        	 for (int z=1;z<=total;z++)
        	 {
        		 int n=in.nextInt();
        		 int m=in.nextInt();
        		 int k=in.nextInt();
        		 
        		 
        		 int answer=k;
        		 for (int t1=0;t1<=n;t1++)
        		 {
        			 for (int t2=0;t2<=n-t1;t2++)
        			 {
        				 for (int t3=0;t3<=n-t1-t2;t3++)
        				 {
        					 for (int t4=0;t4<=m-t3;t4++)
        					 {
        						 for (int t5=0;t5<=m-t3-t4;t5++)
        						 {
        							 for (int t6=0;t6<=n-t5;t6++)
        							 {

        								 int t7=n-t5-t6;
        								 if (t7<0) continue;
        								 int t8=m-t1-t7;
        								 if (t8<0) continue;
        								 
        								 int temp=(t1+t2+t3)*(t3+t4+t5)-(t1-1)*t1/2-(t3-1)*t3/2-(t5-1)*t5/2-(t7-1)*t7/2;
        								 //System.out.println(temp);
        								 //System.out.println(t1+" "+t2+" "+t3+" "+t4+" "+t5+" "+t6+" "+t7+" "+t8);
        								 
        								 if (temp>=k && t1+t2+t3+t4+t5+t6+t7+t8<answer)
        								 {

        									 answer=t1+t2+t3+t4+t5+t6+t7+t8;
        									// System.out.println(t1+" "+t2+" "+t3+" "+t4+" "+t5+" "+t6+" "+t7+" "+t8);
        								 }
        								 
        								 if (temp+1>=k && t1+t2+t3+t4+t5+t6+t7+t8+1<answer)
        								 {

        									 answer=t1+t2+t3+t4+t5+t6+t7+t8+1;
        									// System.out.println(t1+" "+t2+" "+t3+" "+t4+" "+t5+" "+t6+" "+t7+" "+t8);
        								 }
        								 if (temp+2>=k && t1+t2+t3+t4+t5+t6+t7+t8+2<answer)
        								 {

        									 answer=t1+t2+t3+t4+t5+t6+t7+t8+1;
        									 //System.out.println(t1+" "+t2+" "+t3+" "+t4+" "+t5+" "+t6+" "+t7+" "+t8);
        								 }
        								 if (temp+3>=k && t1+t2+t3+t4+t5+t6+t7+t8+3<answer)
        								 {

        									 answer=t1+t2+t3+t4+t5+t6+t7+t8+3;
        									 //System.out.println(t1+" "+t2+" "+t3+" "+t4+" "+t5+" "+t6+" "+t7+" "+t8);
        								 }
        								 if (temp+4>=k && t1+t2+t3+t4+t5+t6+t7+t8+4<answer)
        								 {

        									 answer=t1+t2+t3+t4+t5+t6+t7+t8+4;
        									 //System.out.println(t1+" "+t2+" "+t3+" "+t4+" "+t5+" "+t6+" "+t7+" "+t8);
        								 }
        							 }
        						 }
        					 }
        				 }
        			 }
        		 }
        		 out.println("Case #"+z+": "+answer);            	
        	 }
         }   
	}
}
