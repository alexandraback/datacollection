import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		String name = "C-small";
		Scanner s = new Scanner(new File(name + ".in"));
		int c = s.nextInt();
		out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
//		out = new PrintWriter(System.out);
		for (int i = 1; i <= c; i++) {
			out.print("Case #" + i + ": ");
            out.println();          
			int n = s.nextInt();
			long[] a = new long[n];
			for(int j=0; j<n; j++) {
			    a[j] = s.nextLong();
			}
			long res = solve(n, a);
			if(res == -1) {
	            out.print("Impossible");
	            out.println();          			    
			} else {
			    long l = res;
			    boolean f = true;
	            for(int j=0; j<n; j++) {
	                if(l%3 == 1) {
	                    if(!f) {
	                        out.print(" ");
	                    }
                        f = false;
	                    out.print(a[j]);
	                }
	                l/=3;
	            }
                out.println();                          
                l = res;
                f = true;
                for(int j=0; j<n; j++) {
                    if(l%3 == 2) {
                        if(!f) {
                            out.print(" ");
                        }
                        f = false;
                        out.print(a[j]);
                    }
                    l/=3;
                }
                out.println();                          
			}
		}
		out.close();
	}

	static long solve(int n, long[] a) {
	    long w = 81L*81*81*81*81;
	    for(long i=0; i<w; i++) {
	        long l = i;
	        long s1 = 0;
	        long s2 = 0;
	        for(int j=0; j<n; j++) {
	            if(l%3 == 1) {
	                s1 += a[j];
	            } else if(l%3 == 2) {
	                s2 += a[j];
	            }
	            l/=3;
	        }
	        if(s1 > 0 && s1 == s2) {
	            return i;
	        }
	    }
	    return -1;
	}

}
