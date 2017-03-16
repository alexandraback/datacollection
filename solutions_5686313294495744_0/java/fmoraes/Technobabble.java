import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;


public class Technobabble {
  public static void main(String[] args)
  {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    PrintWriter out = new PrintWriter(outputStream);
    Technobabble solver = new Technobabble();
    solver.solve(1, new InputStreamReader(inputStream), out);
    out.close();
  }
  
  static List<Edge>[] graph;

  static class Edge {
    int t, rev, cap, f;

    public Edge(int t, int rev, int cap)
    {
      this.t = t;
      this.rev = rev;
      this.cap = cap;
    }
  }

  @SuppressWarnings("unchecked")
  public static void createGraph(int nodes)
  {
    graph = new List[nodes];
    for(int i = 0; i < nodes; i++)
      graph[i] = new ArrayList<>();
  }

  public static void addEdge(int s, int t, int cap)
  {
    graph[s].add(new Edge(t, graph[t].size(), cap));
    graph[t].add(new Edge(s, graph[s].size() - 1, 0));
  }

  static boolean dinicBfs(int src, int dest, int[] dist)
  {
    Arrays.fill(dist, -1);
    dist[src] = 0;
    int[] Q = new int[graph.length];
    int sizeQ = 0;
    Q[sizeQ++] = src;
    for(int i = 0; i < sizeQ; i++) {
      int u = Q[i];
      for(Edge e : graph[u]) {
        if(dist[e.t] < 0 && e.f < e.cap) {
          dist[e.t] = dist[u] + 1;
          Q[sizeQ++] = e.t;
        }
      }
    }
    return dist[dest] >= 0;
  }

  static int dinicDfs(int[] ptr, int[] dist, int dest, int u, int f)
  {
    if(u == dest)
      return f;
    for(; ptr[u] < graph[u].size(); ++ptr[u]) {
      Edge e = graph[u].get(ptr[u]);
      if(dist[e.t] == dist[u] + 1 && e.f < e.cap) {
        int df = dinicDfs(ptr, dist, dest, e.t, Math.min(f, e.cap - e.f));
        if(df > 0) {
          e.f += df;
          graph[e.t].get(e.rev).f -= df;
          return df;
        }
      }
    }
    return 0;
  }

  public static int maxFlow(int src, int dest)
  {
    int flow = 0;
    int[] dist = new int[graph.length];
    while(dinicBfs(src, dest, dist)) {
      int[] ptr = new int[graph.length];
      while(true) {
        int df = dinicDfs(ptr, dist, dest, src, Integer.MAX_VALUE);
        if(df == 0)
          break;
        flow += df;
      }
    }
    return flow;
  }

  

  public void solve(int test, Reader input, PrintWriter out)
  {
    MyScanner in = new MyScanner(input);
    
    int T = in.nextInt();
    
    for(int t = 1; t <= T; t++) {
      int n = in.nextInt();
      
      HashMap<String, Integer> first = new HashMap<>();
      HashMap<String, Integer> second = new HashMap<>();
      HashMap<String, String> edges = new HashMap<>();
      
      int index = 0;
      
      for(int i = 0; i < n; i++) {
        String f = in.next();
        String s = in.next();
        
        if(!first.containsKey(f)) {
          first.put(f, index++);
        }
        if(!second.containsKey(s)) {
          second.put(s,  index++);
        }
        edges.put(f, s);
      }
      int res = 0;
      if(first.size() != 1 && second.size() != 1) {
        int source = index++;
        createGraph(first.size() + second.size() + 2);
        for(String f : first.keySet()) {
          int i = first.get(f);
          addEdge(source, i, 1);
        }
        int sink = index++;
        for(String s : second.keySet()) {
          int i = second.get(s);
          addEdge(i, sink, 1);
        }
        for(Map.Entry<String, String> e : edges.entrySet()) {
          int f = first.get(e.getKey());
          int s = second.get(e.getValue());
          addEdge(f, s, 1);
        }
        int r = maxFlow(source, sink);
        res = Math.max(first.size(), second.size()) - r;
      }
      out.printf("Case #%d: %d\n", t, res);
    }

  }

  //-----------MyScanner class for faster input----------
  public static class MyScanner {
    BufferedReader br;

    StringTokenizer st;

    public MyScanner(Reader reader)
    {
      br = new BufferedReader(reader);
    }

    String next()
    {
      while(st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(br.readLine());
        }
        catch(IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    String rest()
    {
      StringBuilder res = new StringBuilder();
      while(st != null && st.hasMoreTokens()) {
        res.append(st.nextToken());
        if(st.hasMoreTokens())
          res.append(' ');
      }
      return res.toString();
    }

    int nextInt()
    {
      return Integer.parseInt(next());
    }

    int[] nextIntArray(int n)
    {
      int[] r = new int[n];
      for(int i = 0; i < n; i++)
        r[i] = nextInt();
      return r;
    }

    long nextLong()
    {
      return Long.parseLong(next());
    }

    double nextDouble()
    {
      return Double.parseDouble(next());
    }

    String nextLine()
    {
      String str = "";
      try {
        str = br.readLine();
      }
      catch(IOException e) {
        e.printStackTrace();
      }
      return str;
    }

  }
  //--------------------------------------------------------
}
