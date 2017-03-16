import java.util.*;
import java.io.*;
import java.math.*;

public class CoinJam {
  
  private static String gen(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    return gen(n/2) + ((n%2 == 0) ? "0" : "1");
  }
  
  // adds 1 on ends and makes it length n
  private static String pad (String s, int n) {
    String build = s;
    int req = n - s.length() - 2;
    for (int i = 0; i < req; i++) {
      build = "0" + build;
    }
    build = "1" + build + "1";
    return build;
  }
  
  // returns zero if doesn't exist
  private static BigInteger divisor (BigInteger a) {
    int[] p = new int[]{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
    for (int i = 0; i < p.length; i++) {
      BigInteger t = BigInteger.valueOf(p[i]);
      if (t.compareTo(a) < 0 && a.remainder(t).equals(BigInteger.ZERO)) return t;
    }
    return BigInteger.ZERO;
  }

  public static void main(String[] args) throws Exception {
    //Scanner in = new Scanner(System.in);
    Scanner in = new Scanner(new File("A.in"));
    PrintWriter out = new PrintWriter(new FileWriter("small.txt"));
    out.println("Case #1:");
    int n = 16;
    int j = 50;
    int count = 0;
    int tests = (int)Math.pow(2,n-2);
    outer:
    for (int t = 0; t < tests; t++) {
      if (count == j) break;
      String coin = pad(gen(t),n);
      String[] bases = new String[9];
      for (int i = 2; i <= 10; i++) {
        BigInteger based = new BigInteger(coin, i);
        BigInteger db = divisor(based);
        if (db.equals(BigInteger.ZERO)) continue outer;
        bases[i-2] = db.toString(10);
      }
      out.print(coin);
      for(int i = 0; i < bases.length; i++) {
        out.print(" " + bases[i]);
      }
      out.println();
      count++;
    } 
    if (count != j) System.out.println("uhoh");  
    in.close();
    out.close();
  }
}