import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
  public static void main (String[] args)  throws java.lang.Exception { 
    Scanner sc = new Scanner(System.in);
    BufferedWriter out = new BufferedWriter(new FileWriter("ans.out"));
    
    int T = sc.nextInt();
    long P, Q;
    StringBuilder ans = new StringBuilder();
    for (int k = 1; k <= T; k++) {
      String[] temp = sc.next().split("/");
      P = Long.parseLong(temp[0]);
      Q = Long.parseLong(temp[1]);
      long factor = gcm(P, Q);
      P /= factor;
      Q /= factor;
      Long tempo = Q;
      while (tempo != 1) {
        if ((tempo%2) != 0) {
          output(out, k, "impossible");
          break;
        }
        tempo /= 2;
      }
      if (tempo != 1) continue;
      int count = 0;
      while (Q > P) {
        Q /= 2;
        count++;
      }
      output(out, k, "" + count);
    }
    out.close();
  }
  
  public static long gcm(long a, long b) {
    return b == 0 ? a : gcm(b, a % b);
  }
  
  public static String asFraction(long a, long b) {
    long gcm = gcm(a, b);
    return (a / gcm) + "/" + (b / gcm);
  }
  
  public static void output(BufferedWriter out, int caseNum, String string) throws IOException{
    out.write("Case #" + caseNum + ": " + string + "\n"); }
}