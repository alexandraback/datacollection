import java.io.*;
import java.util.*;
import java.math.*;
public class Solve4 {

  public static void main(String[] args) {
	MyScanner scanner = new MyScanner();
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    int t = scanner.nextInt();
	for(int t1 = 0; t1 < t; t1++) {
      int nr_edges = scanner.nextInt();
	  HashMap<String, Integer> map = new HashMap<String, Integer>();
	  int[][] edge = new int[nr_edges][2];
	  int nr = 0;
	  for(int i = 0; i < nr_edges; i++) {
	    String line = scanner.nextLine();
		String[] tab = line.split(" ");
		if(map.get(tab[0]) == null) map.put(tab[0], nr++);
		if(map.get(tab[1]) == null) map.put(tab[1], nr++);
		edge[i][0] = map.get(tab[0]);
		edge[i][1] = map.get(tab[1]);
	  }
	  /*
	  int n = map.size();
	  int[] pred = new int[n];
	  List<Edge>[] edges = new List[n];
      for (int i = 0; i < n; i++) {
        edges[i] = new ArrayList<>();
      }
      for(int i = 0; i < nr_edges; i++) {
        edges[edge[i][0]].add(new Edge(edge[i][1], 1));
        edges[edge[i][1]].add(new Edge(edge[i][0], 1));
      }
	  */
	  int res = 0;//(int)mst(edges, pred);
	  int all = (1 << nr_edges);
	  for(int i = 0; i < all; i++) {
	    boolean isValid = true;
		int count = 0;
		int k = i;
		while(k > 0) {
		  count += k & 1;
		  k >>= 1;
		}
		for(int j = 0; j < nr_edges && isValid; j++) {
		  if((i & (1<<j)) > 0) {
		    boolean b = false;
		    boolean c = false;
		    for(int l = 0; l < nr_edges; l++) {
			  if((i & (1<<l))== 0) {
			    if(edge[j][0] == edge[l][0]) b = true;
			    if(edge[j][1] == edge[l][1]) c = true;
			  }
			}
			if(!b || !c) isValid = false;
		  }
		}
		
		if(isValid) {
		  if(count > res) res = count;
		}
	  }
	  //System.out.println(res);
 	  out.print("Case #" + (t1 + 1)+ ": " + res);
	  out.println();
	}
	out.close();
  }

    public static long mst(List<Edge>[] edges, int[] pred) {
    int n = edges.length;
    Arrays.fill(pred, -1);
    boolean[] used = new boolean[n];
    int[] prio = new int[n];
    Arrays.fill(prio, Integer.MAX_VALUE);
    prio[0] = 0;
    PriorityQueue<Long> q = new PriorityQueue<>();
    q.add(0L);
    long res = 0;

    while (!q.isEmpty()) {
      long cur = q.poll();
      int u = (int) cur;
      if (used[u])
        continue;
      used[u] = true;
      res += cur >>> 32;
      for (Edge e : edges[u]) {
        int v = e.t;
        if (!used[v] && prio[v] > e.cost) {
          prio[v] = e.cost;
          pred[v] = u;
          q.add(((long) prio[v] << 32) + v);
        }
      }
    }
    return res;
  }

  static class Edge {
    int t, cost;

    public Edge(int t, int cost) {
      this.t = t;
      this.cost = cost;
    }
  }
  public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
 
      long nextLong() {
          return Long.parseLong(next());
      }
 
      double nextDouble() {
          return Double.parseDouble(next());
      }
 
      String nextLine(){
          String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
      }

   }
}
