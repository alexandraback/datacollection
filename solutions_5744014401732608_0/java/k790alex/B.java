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
      boolean ok = solveCaseSlow();
      String ans = ok ? "POSSIBLE" : "IMPOSSIBLE";
      out.println("Case #" + (k+1) + ": " + ans);
      if (ok) {
        for (int[] v : g) {
          for (int x : v)
            out.print(x);
          out.println();
        }
      }
    }
    //
    out.flush();
    System.exit(0);
  }

  int N, M;
  boolean solveCaseSlow()  {
    N = Integer.parseInt( next() );
    M = Integer.parseInt( next() );
    g = new int[N][N];
    return solve(0);
  }

  boolean solve(int index)  {
    if (index + 1 == N) {
      // N have no outgoing links
      return countWays() == M;
    }

    int max = N - 1;
    for (int mask = 0; mask < 1<<max; mask++)  {
      for (int k = 0, m = 0; m < N; m++) if (m != index) {
        boolean ok = ((1<<k)&mask) != 0;
        g[index][m] = ok ? 1 : 0;
        k++;
      }

      if (solve(index+1)) {
        return true;
      }
    }
    return false;
  }
  int[][] g;

  int countWays() {
    int start = 0;
    int dest = N - 1;
    int[] inDegree = new int[N];
    for (int a = 0; a < N; a++) for (int b = 0; b < N; b++) if (g[a][b] == 1) {
      inDegree[b]++;
    }
    if (inDegree[start] != 0) {
      return -1;
    }

    int[] ways = new int[N];
    ways[start] = 1;
    boolean[] marked = new boolean[N];
    Queue<Integer> queue = new LinkedList<>();
    queue.add(start);
    marked[start] = true;
    while (!queue.isEmpty()) {
      int cur = queue.poll();
      for (int to = 0; to < N; to++) if (g[cur][to] == 1) {
        ways[to] += ways[cur];
        if (--inDegree[to] == 0) {
          queue.add(to);
          marked[to] = true;
        }
      }
    }

    for (int x : inDegree) if (x != 0)
      return -1;

    return ways[dest];
  }
}

