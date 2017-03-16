

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class BFF {
  static class Pair {
    List<Integer> leftpath;
    List<Integer> rightpath;
    public Pair() {
      this.leftpath = new ArrayList<Integer>();
      this.rightpath = new ArrayList<Integer>();
    }
  }
  
  public void solve() throws IOException {
    int T = nextInt();
    for (int t = 1; t <= T; t++) {
      int N = nextInt();
      int[] friends = new int[N];
      for (int i = 0; i < N; i++) {
        friends[i] = nextInt() - 1;
      }
      
      int longest = 0;
      Map<Integer, Pair> twocycles = new HashMap<Integer, Pair>();
      for (int i = 0; i < N; i++) {
        int cur = i;
        List<Integer> path = new ArrayList<Integer>();
        while (!path.contains(cur)) {
          path.add(cur);
          cur = friends[cur];
        }
        if (cur == path.get(path.size() - 2)) {
          // Chain into a 2-cycle. Can put a bunch together
          int cycle = Math.min(cur, friends[cur]);
          if (!twocycles.containsKey(cycle)) {
            twocycles.put(cycle, new Pair());
          }
          
          // Remove the cycle, only keep track of the chain
          path.remove(path.size() - 1);
          path.remove(path.size() - 1);
          
          if (cur == cycle) {
            if (path.size() > twocycles.get(cycle).leftpath.size()) {
              twocycles.get(cycle).leftpath = path;
            }
          } else {
            if (path.size() > twocycles.get(cycle).rightpath.size()) {
              twocycles.get(cycle).rightpath = path;
            }
          }
        } else if (cur == i) {
          // Cycle, can only have one
          longest = Math.max(longest, path.size());
        }
      }
      
      int appends = 0;
      for (int cycle : twocycles.keySet()) {             
        appends += twocycles.get(cycle).leftpath.size() + 
                   twocycles.get(cycle).rightpath.size() + 2;
      }
      
      out.format("Case #%d: %d%n", t, Math.max(longest, appends));
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
        new InputStreamReader(oj ? System.in : new FileInputStream("C-large.in")));
    out = new PrintWriter(oj ? System.out : new FileOutputStream("output.txt"));
    solve();
    out.close();
  }

  public static void main(String[] args) throws IOException {
    new BFF().run();
  }
}
