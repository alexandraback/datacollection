

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Fractiles {
  public void solve() throws IOException {
    int T = nextInt();
    for (int t = 1; t <= T; t++) {
      int K = nextInt();
      int C = nextInt();
      int S = nextInt();
      
      int minS = (int) Math.ceil(K * 1.0 / C);
      
      if (S >= minS) {
        long[] pow = new long[C];
        pow[0] = 1;
        for (int i = 1; i < C; i++) {
          pow[i] = pow[i - 1] * K;
        }
        
        StringBuilder sb = new StringBuilder();       
        int pos = 0;
        for (int i = 0; i < minS; i++) {
          long query = 1;
          for (int j = 1; j <= C && pos < K; j++, pos++) {
            query += pos * pow[C - j];
          }
          if (sb.length() != 0) {
            sb.append(" ");
          }
          sb.append(query);
        } 
        out.format("Case #%d: %s%n", t, sb.toString());
      } else {
        out.format("Case #%d: IMPOSSIBLE%n", t);
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
        new InputStreamReader(oj ? System.in : new FileInputStream("D-large.in")));
    out = new PrintWriter(oj ? System.out : new FileOutputStream("output.txt"));
    solve();
    out.close();
  }

  public static void main(String[] args) throws IOException {
    new Fractiles().run();
  }
}
