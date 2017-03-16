/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package c;

/**
 *
 * @author ankur
 */
import java.io.*;
import java.util.*;
public class C {

	//private static final String islarge = "-large";
	//private static final String fileName = "results/con2013R1B/"+C.class.getSimpleName().toLowerCase();//+islarge;
	private static final String inputFileName = "C:\\Users\\ankur\\Downloads\\Codejam_Round1C\\C-small-attempt2.in";
    // private static final String inputFileName = "C:\\Users\\ankur\\Downloads\\input.in";
	private static final String outputFileName = "C:\\Users\\ankur\\Downloads\\Codejam_Round1C\\C-small-attempt2.out";
     // private static final String outputFileName = "C:\\Users\\ankur\\Downloads\\Codejam_Round1C\\output.out";
	private static Scanner in;
	private static PrintWriter out;
	
      
	private void solve() {
		int N = in.nextInt();                
                int M = in.nextInt();  
                int K = in.nextInt();                
               int count=4;
               int cb=5;
               int cb1=Math.min(N, M);
               
               if(K<=4)
               {
               System.out.println(K);
		out.println(K);
               }
               else
               { if(K>(int)Math.sqrt(M) && K>(int)Math.sqrt(N))
               {
                   System.out.println(K-(int)Math.sqrt(K));
		out.println(K-(int)Math.sqrt(K));
               }
               else
               {
                   System.out.println(K);
		out.println(K);
               }
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
			new C().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
