import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
  static StringTokenizer st = new StringTokenizer("");

  public static String next() {
    try {
    while (!st.hasMoreTokens()) {
      String s = br.readLine();
      if (s == null)
        return null;
      st = new StringTokenizer(s);
    }
    return st.nextToken();
    } catch(Exception e)  {
      return  null;
    }
  }

  public static void main(String[] asda) throws Exception {
    new Thread(null, new A(), "A", 1<<26).start();
  }

  public void run() {
    int cases = Integer.parseInt( next() );
    for (int k = 0; k < cases; k++) {
      String s = next();
      String ans = solveCase(s);
      out.println("Case #" + (k+1) + ": " + ans);
    }
    //
    out.flush();
    System.exit(0);
  }

  final static String[] NUMBERS = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
  };
  final static String[] sorted = {
    "ZERO", "TWO", "SIX", "FOUR", "THREE", "ONE" , "FIVE", "SEVEN", "EIGHT", "NINE"
  };
  final static char[] chars = "0264315789".toCharArray();
  String solveCase(String s)  {
    int N = s.length();
    String result = "";
    cnt = new int[255];
    for (char ch : s.toCharArray())
      cnt[ch]++;

    for (int val = 0; val <= 9; val++)  {
      result += extract(sorted[val], chars[val]);
    }

    for (int k = 0; k < 255; k++) if (cnt[k] > 0) {
      out.println("NOT USED: " + (char)(k));
    }

    char[] ans = result.toCharArray();
    Arrays.sort(ans);
    return new String(ans);
  }

  String extract(String number, char digit) {
    String s = "";
    int min = 1000000;
    for (char ch : number.toCharArray())
      min = Math.min(min, cnt[ch]);

    for (char ch : number.toCharArray())
      cnt[ch] -= min;

    while (min-- > 0)
      s += digit;

    return s;
  }
  int[] cnt;


}
