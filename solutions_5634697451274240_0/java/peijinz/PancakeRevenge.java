

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class PancakeRevenge {
  static char rev(char a) {
    switch (a) {
    case '+': return '-';
    case '-': return '+';
    default: throw new IllegalArgumentException("Invalid input");
    }
  }
  
  static void flip(char[] arr, int end) {
    char temp = ' ';
    for (int i = 0; i <= end / 2; i++) {
      temp = arr[i];
      arr[i] = rev(arr[end - i]);
      arr[end - i] = rev(temp);
    }
  }
  
  public void solve() throws IOException {
    int T = nextInt();
    for (int t = 1; t <= T; t++) {
      char[] S = nextLine().toCharArray();
      int flips = 0;
      for (int i = S.length - 1; i >= 0; i--) {
        if (S[i] != '+') {
          int start = 0;
          while (S[start] == '+') {
            start++;
          }
          if (start > 0) {
            flips++;
            flip(S, start - 1);
          }
          flips++;
          flip(S, i);
        }
      }
      out.format("Case #%d: %d%n", t, flips);
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
        new InputStreamReader(oj ? System.in : new FileInputStream("B-small-attempt0.in")));
    out = new PrintWriter(oj ? System.out : new FileOutputStream("output.txt"));
    solve();
    out.close();
  }

  public static void main(String[] args) throws IOException {
    new PancakeRevenge().run();
  }
}
