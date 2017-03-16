import java.util.*;

public class Main implements Runnable {
  Scanner in;
  int t, n, m, en;
  int[] head, cnt;
  Edge[] edge;
  boolean flag;
  
  public class Edge {
    int u, v, next;
    
    public Edge(int u, int v) {
      this.u = u;
      this.v = v;
      this.next = head[u];
    }
  }
  
  public void add_edge(int u, int v) {
    edge[en] = new Edge(u, v);
    head[u] = en++;
  }
  
  public void DFS(int u) {
    cnt[u]++;
    for (int idx = head[u]; idx != -1; idx = edge[idx].next) {
      int v = edge[idx].v;
      if (cnt[v] == 0)
        DFS(v);
      else if (cnt[v] == 1) {
        cnt[v]++;
        break;
      }
    }
  }
  
  public void run() {
    in = new Scanner(System.in);
    t = in.nextInt();
    
    for (int caseNo = 1; caseNo <= t; caseNo++) {
      n = in.nextInt();
      
      head = new int[n+1];
      edge = new Edge[100000];
      cnt = new int[n+1];
      
      Arrays.fill(head, -1);
      Arrays.fill(cnt, 0);
      
      en = 0;
      
      for (int i = 1; i <= n; i++) {
        m = in.nextInt();
        for (int j = 0; j < m; j++) {
          int v = in.nextInt();
          add_edge(i, v);
        }
      }
      
      flag = false;
      for (int i = 1; i <= n; i++) {
        Arrays.fill(cnt, 0);
        DFS(i);
        for (int j = 1; j <= n; j++)
          if (cnt[j] >= 2)
            flag = true;
        if (flag)
          break;
      }
      
      if (flag)
        System.out.println("Case #" + caseNo + ": Yes");
      else
        System.out.println("Case #" + caseNo + ": No");
    }
  }
  
  public static void main(String[] args) {
    new Thread(new Main()).start();
  }
  
}
