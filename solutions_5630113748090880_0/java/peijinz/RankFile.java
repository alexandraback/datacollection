

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class RankFile {
  
  public void solve() throws IOException {
    int T = nextInt();
    for (int t = 1; t <= T; t++) {
      int N = nextInt();
      int[] counts = new int[2500];
      
      for (int i = 0; i < 2 * N - 1; i++) {
        for (int j = 0; j < N; j++) {
          int e = nextInt();
          counts[e - 1]++;
        }
      }
      
      List<Integer> line = new ArrayList<Integer>(N);
      for (int i = 0; i < 2500; i++) {
        if (counts[i] % 2 != 0) {
          line.add(i + 1);
        }
      }
      Collections.sort(line);
      
      StringBuilder sb = new StringBuilder();
      for (int i = 0; i < line.size(); i++) {
        if (i != 0) {
          sb.append(" ");
        } 
        sb.append(line.get(i));
      }
      
      out.format("Case #%d: %s%n", t, sb.toString());
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
        new InputStreamReader(oj ? System.in : new FileInputStream("B-small-attempt1.in")));
    out = new PrintWriter(oj ? System.out : new FileOutputStream("output.txt"));
    solve();
    out.close();
  }

  public static void main(String[] args) throws IOException {
    new RankFile().run();
  }
}
