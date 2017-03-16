import java.util.*;
import java.io.*;
import java.math.*;

public class TrivialFractal {

  public static void main(String[] args) throws Exception {
    //Scanner in = new Scanner(System.in);
    Scanner in = new Scanner(new File("D-large.in"));
    PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
    int tests = in.nextInt();
    for (int t = 1; t <= tests; t++) {
      int k = in.nextInt();
      int c = in.nextInt();
      int s = in.nextInt();
      int min = (k + c - 1) / c;
      out.print("Case #" + t + ":");
      if (min > s) {
        out.println(" IMPOSSIBLE");
        continue;
      }
      // else
      int ele = min * c;
      int[] helpIndices = new int[ele];
      for (int i = 0; i < k; i++) helpIndices[i] = i;
      for (int i = 0; i < ele; i += c) {
        BigInteger sum = BigInteger.ONE;
        for (int x = c-1; x >= 0; x--) {
          sum = sum.add(BigInteger.valueOf(k).pow(x).multiply(BigInteger.valueOf(helpIndices[i+x])));
        }
        out.print(" " + sum.toString());
      }
      out.println();
    }
    in.close();
    out.close();
  }
}