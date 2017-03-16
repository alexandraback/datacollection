import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class manage {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("manage.in"));
    PrintWriter out = new PrintWriter(new File("manage.out"));
    int cases = in.nextInt();
    int caseOn = 1;
    while (cases-- != 0) {
      int e = in.nextInt();
      max = e;
      r = in.nextInt();
      int n = in.nextInt();
      arr = new int[n];
      for (int i = 0; i < n; i++) {
        arr[i] = in.nextInt();
      }
      
      memo = new long[e + 1][n];
      for (long[] a : memo) {
        Arrays.fill(a, -1);
      }
      
      long best = go(e, 0);
      out.printf("Case #%d: %d\n", caseOn++, best);
    }
    out.close();
  }
  
  static int r, max;
  static long[][] memo;
  static int[] arr;
  
  static long go(int e, int i) {
    if (i == arr.length) return 0;
    if (memo[e][i] != -1) return memo[e][i];
    long best = 0;
    for (int use = 0; use <= e; use++) {
      best = Math.max(arr[i] * use + go(Math.min(e - use + r, max), i + 1),
          best);
    }
    return memo[e][i] = best;
  }
}
