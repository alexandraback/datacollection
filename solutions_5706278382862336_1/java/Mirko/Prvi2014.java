import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.math.BigInteger;


public class Prvi2014 {

	public static long GCD(long a, long b) {
		   if (b==0) return a;
		   return GCD(b,a%b);
		}
	
	public static void main (String [] args) throws IOException {
		
		 PrintWriter out2 = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		 //Input in= new Input(new FileInputStream(new File("input.txt")));
		 BufferedReader in = new BufferedReader(new FileReader("A-small.in"));
		 
		 //Input in= new Input(new FileInputStream(new File("A-small.in")));
		 //Input in= new Input(new FileInputStream(new File("Asmall.txt")));
		 //BufferedReader in = new BufferedReader(new FileReader("Asmall.in"));
		 
		 
		 int t= Integer.parseInt(in.readLine());
		 
		 for(int i=0; i<t;i++)
		 {	
			 String line = in.readLine();
			 String[] field = line.split("/");
			 boolean possible = false;
			 long p = Long.parseLong(field[0]);
			 long q = Long.parseLong(field[1]);
			 
			 long gcd = GCD(p,q);
			 p = p/gcd;
			 q = q/gcd;
			 double num = (double)p / (double)q;
			 int n = 0;
			 int res = 0;
			 
			 while(q%2 == 0)
				 q/=2;
			 
			 if (q == 1)
				 possible = true;
			 
			 for( res = 1; num-1/(double)(2*res) < 0; res*=2)
			 { 
				 n++;
			 };
				 
			 
			 out2.print("Case #"); 	     
		     out2.print(i+1);
		     out2.print(": ");
		     //out2.println();
		     if (!possible)
		    	 out2.println("impossible");
		     else
		    	  out2.println(n+1);
		    	
		     out2.flush();
		 }
	}
	}

