import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		String name = "A-small";
		Scanner s = new Scanner(new File(name + ".in"));
		int c = s.nextInt();
		out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
//		out = new PrintWriter(System.out);
		for (int i = 1; i <= c; i++) {
			out.print("Case #" + i + ":");
			int n = s.nextInt();
			int[] j = new int[n];
			int x = 0;
			for(int k=0; k<n; k++) {
			    j[k] = s.nextInt();
			    x += j[k];
			}
			double[] res = solve(n, j, x);
            for(int k=0; k<n; k++) {
                out.print(" ");
                out.print(String.format("%f", res[k] * 100));
            }
			out.println();			
		}
		out.close();
	}

	static double[] solve(int n, int[] j, int x) {
		double[] res = new double[n];
	    for(int i=0; i<n; i++) {
	        double min = 0d;
	        double max = 1d;
	        double d = 0d;
	        for(int k=0; k<1000; k++) {
	            d = (min + max) / 2;
	            double r = 0;
	            for(int l=0; l<n; l++) {
	                if(i==l) continue;
	                if(j[l]<j[i]+x*d) {
	                    r += (j[i] + x*d - j[l]) / x;
	                }
	            }
	            if(r==1-d) {
	                break;
	            }
	            if(r>1-d) {
	                max = d;
	            } else {
	                min = d;
	            }
	        }
	        if(d < 0.0000000001) {
	            d = 0d;
	        }
            res[i] = d;
	    }
	    return res;
	}

}
