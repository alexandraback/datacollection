import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class ManageYourEnergy {
  public BufferedReader br;
  public int t, e, r, n, ans;
  public int[] v;
  public int[][] dist;
  public boolean[][] inQueue;
  public static class State {
    public int e, n;
    public State(int e, int n) {
      this.e = e;
      this.n = n;
    }
  }
  public void SPFA(int se, int sn) {
    Queue<State> queue = new LinkedList<State>();
    dist[se][sn] = 0;
    inQueue[se][sn] = true;
    queue.add(new State(se, sn));
    while (queue.size() > 0) {
      State curr = queue.poll();
      se = curr.e;
      sn = curr.n;
      if (sn == n)
        continue;
      inQueue[se][sn] = false;
      for (int ue = 0; ue <= se; ue++) {
        int ne = se - ue + r;
        int nn = sn + 1;
        int now = dist[se][sn] + ue * v[sn];
        dist[ne][nn] = max(dist[ne][nn], now);
        if (!inQueue[ne][nn]) {
          inQueue[ne][nn] = true;
          queue.add(new State(ne, nn));
        }
      }
    }
  }
  public void go() throws Throwable {
    br = new BufferedReader(new InputStreamReader(System.in));
    t = Integer.parseInt(br.readLine());
    for (int caseNo = 1; caseNo <= t; caseNo++) {
      String[] ss = br.readLine().split(" +");
      e = Integer.parseInt(ss[0]);
      r = Integer.parseInt(ss[1]);
      n = Integer.parseInt(ss[2]);
      v = new int[n];
      ss = br.readLine().split(" +");
      for (int i = 0; i < n; i++)
        v[i] = Integer.parseInt(ss[i]);
      dist = new int[100][n+1];
      inQueue = new boolean[100][n+1];
      for (int i = 0; i < 100; i++) {
        Arrays.fill(dist[i], -1);
        Arrays.fill(inQueue[i], false);
      }
      SPFA(e, 0);
      ans = 0;
      for (int i = 0; i < 100; i++)
        ans = max(ans, dist[i][n]);
      System.out.println("Case #" + caseNo + ": " + ans);
    }
  }
  public static void main(String[] args) throws Throwable {
    new ManageYourEnergy().go();
  }
}
