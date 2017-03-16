import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class ProblemA {
     public static void main(String[] args) throws IOException {
    	 Scanner in = new Scanner(new File("A-large.in"));
    	 PrintStream out=new PrintStream("A-large.out");
          
     	 //Scanner in = new Scanner(System.in);
     	 //PrintStream out=new PrintStream(System.out);
     	 
    	 while(in.hasNext()) {
        	 int n=in.nextInt();
        	 in.nextLine();
        	 for (int z=1;z<=n;z++)
        	 {
        		 String s=in.nextLine();
            	 String[] tokens=s.split("/");
        		 int answer=0;
        		 long fz=Long.parseLong(tokens[0]);
        		 long fm=Long.parseLong(tokens[1]);
            	 
        		 long t=findgys(fz,fm);
        		 fz=fz/t;
        		 fm=fm/t;
        		 
        		 boolean real=true;
        		 long fmtemp=fm;
        		 while (fmtemp!=1 && fmtemp%2==0)
        		 {
        			 fmtemp=fmtemp/2;
        		 }
        		 if (fmtemp!=1)
        		 {
        			 out.println("Case #"+z+": impossible");
        		 }
        		 else
        		 {
        			 long ds=0;
        			 while (fz<fm)
        			 {
        				 fm=fm/2;
        				 ds++;
        			 }
        			 out.println("Case #"+z+": "+ds);
        		 }
        		 
        	 }
         }   
	}

	private static long findgys(long fz, long fm) {
		if (fz>fm)
		{
			long temp=fz;
			fz=fm;
			fm=temp;
		}
		
		if (fm%fz==0) return fz;
		else return findgys(fm%fz,fz);
	}
}
