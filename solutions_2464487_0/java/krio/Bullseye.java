import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Bullseye {
  public static void main(String[] args){
    FastScanner sc = new FastScanner();
    int T = sc.nextInt();

    for(int i = 1; i <= T; i++) {
      long r = sc.nextLong();
      long t = sc.nextLong();

      double D = (3.0 + 2 * r) * (3.0 + 2 * r) - 4 * 2 * (2 * r + 1.0 - t);
      double solution = (-(3.0 + 2 * r) + Math.sqrt(D)) / (4);
      printCase((int) (solution + 1) + "", i);
    }
  }

  private static long countInInterval(Set<Long> set, long A, long B) {
    long count = 0;
    for(Long s : set) {
      if(s >= A && s <= B) {
        count++;
      }
    }
    return count;
  }

  private static void printCase(String result, int testNum) {
    System.out.println("Case #" + testNum + ": " + result);
  }

  private static class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    public FastScanner(String s) {
      try {
        br = new BufferedReader(new FileReader(s));
      } catch (FileNotFoundException e) {
        e.printStackTrace();
      }
    }

    public FastScanner() {
      br = new BufferedReader(new InputStreamReader(System.in));
    }

    String nextToken() {
      while (st == null || !st.hasMoreElements()) try {
        st = new StringTokenizer(br.readLine());
      } catch (IOException e) {
        e.printStackTrace();
      }
      return st.nextToken();
    }

    int nextInt() {
      return Integer.parseInt(nextToken());
    }

    long nextLong() {
      return Long.parseLong(nextToken());
    }

    double nextDouble() {
      return Double.parseDouble(nextToken());
    }
  }
}