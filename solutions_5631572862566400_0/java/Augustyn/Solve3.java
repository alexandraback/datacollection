import java.io.*;
import java.util.*;
public class Solve3 {
  static class Tab implements Comparable<Tab>{
    int[] tab;
	Tab(int[] t) {
	  this.tab = t;
	}
	public int compareTo(Tab other) {
      return tab[0] - other.tab[0];
    }
  }

  public static void main(String[] args) {
	MyScanner scanner = new MyScanner();
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	int t = scanner.nextInt();
    for(int a = 0; a < t; a++) {
	  int n = scanner.nextInt();
	  int[] tab = new int[n];
	  for(int i = 0; i < n; i++)
	    tab[i] = scanner.nextInt();
	  int[] visited = new int[n];
	  int res = 0;
      for(int i = 0; i < n; i++) {
        int deep = dfs(i, i, 0, visited, tab);
		Arrays.fill(visited, 0);
		res = Math.max(res, deep);
      }	
      Arrays.fill(visited, 0);
      int res2 = 0;	  
	  for(int i = 0; i < n; i++) {
	    if(visited[i] == 0) {
		  if(i == tab[tab[i]-1] -1) {
		    res2+=2;
			visited[i] = 1;
			visited[tab[i]-1] = 1;
		  }
		}
	  }
	  int[] t2 = new int[n];
	  for(int i = 0; i < n; i++) {
	    if(visited[i] == 0) {
		  dfs2(i + 3, i, i, 0, visited, tab, t2);
		}
	  }
	  for(int i = 0; i < n; i++) {
	    if(visited[i] == 1) {
		  res2 += t2[i];
		}
	  }
	  res = Math.max(res, res2);
	  out.println("Case #" + (a + 1)+ ": " + res);
	}
	out.close();
	
  }
  static void dfs2(int k, int start, int node, int depth, int[] visited, int[] tab, int[] t2) {
    if(visited[node]==1) {
	  t2[node] = Math.max(t2[node], depth); 
	} else if(visited[node] < k){
	  visited[node]=k;
	  dfs2(k, start, tab[node]-1, depth+1, visited, tab, t2);
	}
  }
  static int dfs(int start, int node, int depth, int[] visited, int[] tab) {
    if(visited[node]==1) {
	  if (start == node)
	    return depth;
	  else
	    return -1;
	} else {
	  visited[node]=1;
	  return dfs(start, tab[node]-1, depth+1, visited, tab);
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
