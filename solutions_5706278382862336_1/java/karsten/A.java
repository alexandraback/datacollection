import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class A {
  public static void main(String[] args) throws Exception {
    if (args.length != 2) {
      System.err.println("Usage: java " + A.class.getName()
          + " [input] [output]");
      System.exit(1);
    }
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    BufferedWriter bw = new BufferedWriter(new FileWriter(args[1]));
    int testCases = Integer.parseInt(br.readLine());
    for (int testCase = 1; testCase <= testCases; testCase++) {
      bw.write("Case #" + testCase + ": ");
      String[] pq = br.readLine().split("/");
      long p = Long.parseLong(pq[0]);
      long q = Long.parseLong(pq[1]);
      int minGenerations = minGenerations(p, q, 0);
      bw.write(minGenerations < Integer.MAX_VALUE ?
          String.valueOf(minGenerations) : "impossible");
      bw.write("\n");
    }
    br.close();
    bw.close();
  }
  
  private static int minGenerations(long p, long q, int generations) {
    if (generations > 40) {
      return Integer.MAX_VALUE;
    } else if (p == 0 || p == q) {
      return generations;
    } else if (p * 2 <= q) {
      return minGenerations(p * 2, q, generations + 1);
    } else if (minGenerations(p * 2 - q, q, generations + 1)
        < Integer.MAX_VALUE) {
      return generations + 1;
    } else {
      return Integer.MAX_VALUE;
    }
  }
}
