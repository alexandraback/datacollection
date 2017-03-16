import java.io.*;
import java.util.*;

public class gcj1a {
	
	public static void main(String[] args) throws FileNotFoundException {
		 Scanner scanner = new Scanner(new File("/Users/okt777/Documents/a.in.txt"));
		 PrintWriter pw = new PrintWriter("/Users/okt777/Documents/A-large.ou"); 
		 int _case = 1;
		  
		 scanner.nextLine();
		 while(scanner.hasNextLine())
		 {
			 int a = scanner.nextInt();
			 int b = scanner.nextInt();
			 scanner.nextLine();		   
			 double[] c = new double[a];
		   
			 double[] p = new double[a+1];
			 p[0] = 1;
			 for (int i=0;i<a;i++) {
				 c[i] = scanner.nextDouble();
				 p[1+i] = p[i] * c[i];
			 }		 
			 scanner.nextLine();
			 
			 double r;
			 

			 // right way
			 r = b + 2;
			 //System.out.printf("right way:%f\n",r);
			 
			 // back
			 for(int i=0;i<a+1;i++) {
				 double tp;
				 
				 int ok_num = (b-i) +(a-i) +1;
				 
				 tp =  p[i] * ((b-i) +(a-i) +1) + (1-p[i])*(ok_num+b+1);
				 
				 r = Math.min(tp, r);
				 //System.out.printf("back:%d %f\n",i, tp);

			 }

			 
			 System.out.printf("Case #%d: %f\n", _case, r);
		     pw.printf("Case #%d: %f\n", _case, r);
		     _case++;
		  }
		  
		  scanner.close();
		  pw.close();
		}
	}



