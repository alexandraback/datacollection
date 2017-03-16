import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class ManageYourEnergy {
  public static void main(String[] args){
    FastScanner sc = new FastScanner();
    int T = sc.nextInt();

    for(int i = 1; i <= T; i++) {
      int E = sc.nextInt();
      int R = sc.nextInt();
      int N = sc.nextInt();
      int[] v = new int[N];
      for(int j = 0; j < N; j++) {
        v[j] = sc.nextInt();
      }
      printCase(getMaxGain(v, 0, E, R, E, 0) + "", i);
    }
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