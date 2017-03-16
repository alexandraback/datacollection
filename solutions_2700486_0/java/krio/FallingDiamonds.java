import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class FallingDiamonds {
  public static void main(String[] args){
    FastScanner sc = new FastScanner();
    int T = sc.nextInt();
    for(int testNum = 1; testNum <= T; testNum++) {
      int N = sc.nextInt();
      int X = sc.nextInt();
      int Y = sc.nextInt();

      int layer = (Math.abs(X) + Math.abs(Y)) / 2;
      int used = 0;
      int needForLayer = 1;
      int currentLayer = 0;
      while(used + needForLayer <= N) {
        used += needForLayer;
        needForLayer+=4;
        currentLayer++;
      }

      int remains = N - used;
      if(layer < currentLayer) {
        printCase("1.0", testNum);
      } else if (layer > currentLayer) {
        printCase("0.0", testNum);
      } else {
        if(X == 0) {
          printCase("0.0", testNum);
          continue;
        }

        if(((needForLayer - 1)/2 + Y + 1) <= remains) {
          printCase("1.0", testNum);
          continue;
        }
        double powPart = Math.pow(0.5, remains);
        double result = 0;
        for(int i = Y + 1; i <= remains; i++) {
          result += powPart * cnk(remains, i);
        }
        printCase(result + "", testNum);
      }
    }
  }

  private static long cnk(int n, int k) {
    return fac(n) / (fac(n - k) * fac(k));
  }

  private static long fac(int n) {
    long result = 1;
    for(int i = 1; i <= n; i++) {
      result *= i;
    }
    return result;
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