import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class FairAndSquare {
  private static long MAX_VALUE = 100000000000000L;

  public static void main(String[] args){
    FastScanner sc = new FastScanner();
    Set<Long> set = precalc();
    int T = sc.nextInt();

    for(int i = 1; i <= T; i++) {
      long A = sc.nextLong();
      long B = sc.nextLong();
      long count = countInInterval(set, A, B);
      printCase(Long.toString(count), i);
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

  private static Set<Long> precalc() {
    Set<Long> set = new TreeSet<Long>();
    for(long i = 0; i < Math.sqrt(MAX_VALUE) + 1; i++) {
      if(isPalindrome(i) && isPalindrome(i * i)) {
        set.add(i * i);
      }
    }
    return set;
  }

  private static boolean isPalindrome(Long num) {
    String numStr = num.toString();
    for(int i = 0, j = numStr.length() - 1; i <= numStr.length() / 2; i++,j--) {
      if(numStr.charAt(i) != numStr.charAt(j)) {
        return false;
      }
    }
    return true;
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