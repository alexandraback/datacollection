import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class GoodLuck {
  public static void main(String[] args){
    FastScanner sc = new FastScanner();
    int T = sc.nextInt();
    int R = sc.nextInt();
    int N = sc.nextInt();
    int M = sc.nextInt();
    int K = sc.nextInt();

    System.out.println("Case #1:");
    for(int i = 1; i <= R; i++) {
      int max3 = 0, max2 = 0;
      int[] maxPows = new int[M + 1];
      for(int j = 0; j < K; j++) {
        int answer = sc.nextInt();
        for(int p = 2; p <= M; p++) {
          maxPows[p] = Math.max(maxPows[p], getPow(answer, p));
        }
      }

      StringBuilder sb = new StringBuilder();
      for(int k = 0; k < maxPows[3]; k++) {
        sb.append(3);
      }

      for(int k = 0; k < maxPows[5]; k++) {
        sb.append(5);
      }

      for(int k = 0; k < maxPows[4]; k++) {
        sb.append(4);
      }

      for(int k = 0; k < N - maxPows[4] - maxPows[3] - maxPows[5]; k++) {
        sb.append(2);
      }

      System.out.println(sb.toString());
    }
  }

  private static int getPow(int number , int divisor) {
    int pow = 0;
    while(number % divisor == 0) {
      number = number /divisor;
      pow++;
    }
    return pow;
  }

  private static long getMaxGain(int[] v, int step, int E, int R, int currentEnergy, long currentGain) {
    if(step == v.length) return currentGain;

    long maxGain = 0;
    for(int spent = 0; spent <=currentEnergy; spent++) {
      int newCurrentEnergy = Math.min(E, currentEnergy + R - spent);
      long newCurrentGain = currentGain + spent * v[step];
      maxGain = Math.max(maxGain, getMaxGain(v, step + 1, E, R, newCurrentEnergy, newCurrentGain));
    }
    return maxGain;
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