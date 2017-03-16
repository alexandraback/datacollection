

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class CountingSheep {
  
  public void solve() throws IOException {
    int T = nextInt();
    for (int t = 1; t <= T; t++) {
      int N = nextInt();
      long ans = -1;
      if (N != 0) {
        boolean[] hit = new boolean[10];
        int count = 0;
        long value = N;
        while (value > 0 && count < 10) {
          long temp = value;
          while (temp > 0) {
            int digit = (int) (temp % 10);
            if (!hit[digit]) {
              hit[digit] = true;
              count++;
            }
            temp /= 10;
          }
          if (count == 10) {
            ans = value;
          }
          value += N;
        }
      }
      if (ans == -1) {
        out.format("Case #%d: INSOMNIA%n", t);
      } else {
        out.format("Case #%d: %d%n", t, ans);
      }
    }
  }

  public BufferedReader br;
  public StringTokenizer st;
  public PrintWriter out;

  public String nextToken() throws IOException {
    while (st == null || !st.hasMoreTokens()) {
      st = new StringTokenizer(br.readLine());
    }

    return st.nextToken();
  }

  public String nextLine() throws IOException {
    return br.readLine();
  }

  public int nextInt() throws IOException {
    return Integer.parseInt(nextToken());
  }

  public long nextLong() throws IOException {
    return Long.parseLong(nextToken());
  }

  public double nextDouble() throws IOException {
    return Double.parseDouble(nextToken());
  }

  public void run() throws IOException {
    boolean oj = System.getProperty("ONLINE_JUDGE") != null;
    oj = false;
    br = new BufferedReader(
        new InputStreamReader(oj ? System.in : new FileInputStream("A-large.in")));
    out = new PrintWriter(oj ? System.out : new FileOutputStream("output.txt"));
    solve();
    out.close();
  }

  public static void main(String[] args) throws IOException {
    new CountingSheep().run();
  }
}
