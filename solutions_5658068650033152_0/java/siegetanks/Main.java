import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
  public static void main (String[] args)  throws java.lang.Exception { 
    sc.init(System.in);
    BufferedWriter out = new BufferedWriter(new FileWriter("ans.out"));
    
    int T = sc.nextInt();
    int N, M, K;
    int min;
    int a = 0;
    int b = 0;
    
    boolean ans = false;
    
    for (int k = 1; k <= T; k++) {
      N = sc.nextInt();
      M = sc.nextInt();
      K = sc.nextInt();
      min = 10000000;
      ans = false;
      
      if (N <= 2 || M <= 2) {
        min = K;
        output(out, k, "" + min);
        continue;
      }
      
      int temp = N * M - 4;
      if (K >= temp) {
        min = 2 * (N + M - 4);
        min += K - temp;
        output(out, k, "" + min);
        continue;
      }
      
      min = 10000000;      
      int oldK = K;
      int besta = 0;
      int bestb = 0;
      int bestK = 0;
      K += 4;
      while (!ans) {
        for (a = 1; a <= N; a++) {
          if (K % a == 0) {
            b = K / a;
            if (b > M) continue;
            int tempint = 2*(a + b - 4);
            if (tempint < min) {
              min = tempint;
              besta = a;
              bestb = b;
              bestK = K - 4;
              ans = true;
            }
          }
        }
        K++;
      }
    //  System.out.println(besta + " " + bestb + " " + min + " " + bestK + " " + oldK);
      boolean canreduce = false;
      if (bestK - 1 == oldK || bestK - 2 == oldK) canreduce = true;
      if ((besta * bestb >= 12) && canreduce) min--;
      output(out, k, "" + min);
    }
    out.close();
  }
  
  public static void output(BufferedWriter out, int caseNum, String string) throws IOException{
    out.write("Case #" + caseNum + ": " + string + "\n"); }
}

class sc {
    static BufferedReader reader;
    static StringTokenizer tokenizer;
    static void init(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }
    static String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) { tokenizer = new StringTokenizer(reader.readLine()); }
        return tokenizer.nextToken();
    }
    static int nextInt() throws IOException { return Integer.parseInt( next() ); }
    static double nextDouble() throws IOException { return Double.parseDouble( next() ); }
}