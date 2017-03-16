import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class C {

  static final String FILENAME = "C-large";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;
  
  private boolean path(int u, boolean[] visited, boolean[][] edge, int[] mx, int[] my) {
    for(int v = 0; v < visited.length; v++) {
      if(edge[u][v] && !visited[v]) {
        visited[v] = true;
        if(my[v] == -1 || path(my[v], visited, edge, mx, my)) {
          mx[u] = v;
          my[v] = u;
          return true;
        }
      }
    }
    return false;
  }
  
  private void solve() throws IOException {
    int n = sc.nextInt();
    boolean[][] edge = new boolean[n][n];
    HashMap<String, Integer> fst = new HashMap<>();
    HashMap<String, Integer> snd = new HashMap<>();
    for(int i = 0; i < n; i++) {
      String f = sc.next();
      String s = sc.next();
      if(!fst.containsKey(f)) {
        fst.put(f, fst.size());
      }
      if(!snd.containsKey(s)) {
        snd.put(s, snd.size());
      }
      edge[fst.get(f)][snd.get(s)] = true;
    }
    int[] mx = new int[n];
    int[] my = new int[n];
    for(int i = 0; i < n; i++) {
      mx[i] = my[i] = -1;
    }
    int match = 0;
    for(int i = 0; i < fst.size(); i++) {
      if(mx[i] == -1) {
        boolean[] visited = new boolean[snd.size()];
        match += path(i, visited, edge, mx, my) ? 1 : 0;
      }
    }
    out.write(Integer.toString(n - fst.size() - snd.size() + match));
    out.newLine();
  }

  private void run() throws IOException {
    sc = new Scanner(new File(IN));
    out = new BufferedWriter(new FileWriter(OUT));
    int t = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      out.write("Case #" + i + ": ");
      solve();
    }
    sc.close();
    out.close();
  }

  public static void main(String args[]) throws Exception {
    new C().run();
  }
}
