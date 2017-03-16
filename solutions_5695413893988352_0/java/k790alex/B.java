import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {
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
    new Thread(null, new B(), "B", 1<<26).start();
  }

  public void run() {
    int cases = Integer.parseInt( next() );
    for (int k = 0; k < cases; k++) {
      String ans = solveCaseSlow();
      out.println("Case #" + (k+1) + ": " + ans);
    }
    //
    out.flush();
    System.exit(0);
  }
  String solveCaseSlow()  {
    coder = next().toCharArray();
    jammer = next().toCharArray();
    N = coder.length;
    minDiff = 10000000;
    minCoder = minJammer = minDiff;
    dfs(0);

    return lpad(minCoder, N) + " " + lpad(minJammer, N);
  }
  String lpad(int x, int n) {
    String s = x + "";
    while (s.length() < n)
      s = '0' + s;
    return s;
  }
  int N;
  int minCoder, minJammer;
  int minDiff;
  char[] coder, jammer;
  void dfs(int index) {
    if (index >= 2*N) {
      int c = Integer.parseInt( new String(coder) );
      int j = Integer.parseInt( new String(jammer) );
      int diff = Math.abs(c - j);
      if (diff < minDiff) {
        minDiff = diff;
        minCoder = c;
        minJammer = j;
      } else if (diff == minDiff) {
        if (c < minCoder) {
          minCoder = c;
          minJammer = j;
          minDiff = diff;
        } else if (c == minCoder) {
          if (j < minJammer) {
            minCoder = c;
            minDiff = diff;
            minJammer = j;
          }
        }
      }
      return;
    }

    char[] values = coder;
    int key = index;
    if (key >= N) {
      key -= N;
      values = jammer;
    }
    if (values[key] != '?') {
      dfs(index + 1);
    } else for (char d = '0'; d <= '9'; d++) {
      values[key] = d;
      dfs(index + 1);
      values[key] = '?';
    }
  }
}

