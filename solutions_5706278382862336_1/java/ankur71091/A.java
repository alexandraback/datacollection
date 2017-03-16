/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package a;

/**
 *
 * @author ankur
 */
import java.io.*;
import java.util.*;

public class A {	
private static final String inputFileName = "C:\\Users\\ankur\\Downloads\\Codejam_Round1C\\A-large.in";
       // private static final String inputFileName = "C:\\Users\\ankur\\Downloads\\input.in";
	private static final String outputFileName = "C:\\Users\\ankur\\Downloads\\Codejam_Round1C\\A-large.out";
       // private static final String outputFileName = "C:\\Users\\ankur\\Downloads\\Codejam_Round1C\\output.out";
	private static Scanner in;
	private static PrintWriter out;
      	
	private void solve() {
		//int N = in.nextInt();	   
                String s = in.nextLine();
                int g=0;
                String[] sarr= s.split("/");
               double p=Double.parseDouble(sarr[0]);
               double q=Double.parseDouble(sarr[1]);
               boolean check=false;
               double pq=1;
               if(q%p==0)
               {
                   q=q/p;
                   p=1;
               }
               else
               {
               for(int i=(int)Math.sqrt(p); i>1; i--)
               {
                   while(q%i==0 && p%i==0)
                   {
                       q=q/i;
                       p=p/i;
                   }
               }   
               }
               pq=p;
               pq=pq/q;
               for(int i=1; i<=40; i++)
               { 
                   if(pq>=1)
                   {
                       break;
                   }
                   else
                   {
                       g++;
                   }
                       pq=pq*2;
                       //System.out.println(pq);
               }
               if(g>0)
               {
                  pq=p/q;
                  if(p*Math.pow(2,40)%q==0)
                  {
                    check=true;  
                  }
               }
               if(check)
               { System.out.println(g);
		out.println(g);}
               else
               {
                 System.out.println("impossible");
		out.println("impossible");  
               }
	}

	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new A().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
