import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class Osmos {
  public static void main(String[] args){
    FastScanner sc = new FastScanner();
    int T = sc.nextInt();
    for(int testNum = 1; testNum <= T; testNum++) {
      int A = sc.nextInt();
      int N = sc.nextInt();
      int[] motes = new int[N];
      int[] additions = new int[N];
      for(int i = 0; i < N; i++) {
        motes[i] = sc.nextInt();
      }

      if(A == 1) {
        printCase(N + "", testNum);
        continue;
      }

      Arrays.sort(motes);
      for(int i = 0; i < N; i++) {
        if(A <= motes[i]) {
          while(A <= motes[i]) {
            A += A - 1;
            additions[i]++;
          }
        }
        A += motes[i];
      }

      long corrections = N;
      long current = 0;
      for(int i = 0; i < N; i++) {
        current += additions[i];
        corrections = Math.min(corrections, current + N - i - 1);
      }

      printCase(corrections + "", testNum);
    }
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