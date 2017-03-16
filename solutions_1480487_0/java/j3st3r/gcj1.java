import java.io.*;
import java.util.*;
 
public class Main {
    static Scanner in; static int next() throws Exception {return in.nextInt();}
    static PrintWriter out;

 
    public static void main(String[] args) throws Exception {
        in = new Scanner(System.in);

        out = new PrintWriter(System.out);
       
       int tests = next();
 
       for (int test = 1; test <= tests; test++) {
           int n = next();
           int[] x = new int[n];
           for (int j = 0; j < n; j++) x[j] = next();
           
           int sum = 0;
           for (int i = 0; i < n; i++) sum += x[i];
           
           out.print("Case #" + test + ":");
           for (int i = 0; i < n; i++) {
               double L = 0;
               double R = 1;
               
               for (int iter = 0; iter < 100; iter++) {
                   double M = (L + R)/2;
                   
                   double score = x[i] + M*sum;
                   double sumA = 0;
                   for (int j = 0; j < n; j++) if (j != i) {
                       sumA += Math.max(0, (score - x[j])/sum);
                   }
                   if (sumA + M > 1) R = M;
                   else L = M;
               }
               out.print(" " + (100*L));
           }
           out.println();
       }
 
        out.close();
    }
}