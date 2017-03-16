import java.io.*;
import java.util.*;

public class BFFs {
    private boolean[] marked;        // marked[v] = has vertex v been marked?
    private boolean[] onStack;       // onStack[v] = is vertex on the stack?
    public int largestCycle;
    private int[] depth;
    
    private void dfs(Graph graph, int curr) {
        onStack[curr] = true;
        marked[curr] = true;
        // System.out.format("curr: %d%n", curr);
        // System.out.format("largestCycle: %d%n", largestCycle);
        // System.out.format("depth: %s%n", Arrays.toString(depth));

        // System.out.println(Arrays.toString(onStack));
        for(int w: graph.adj(curr)) {
          if(!marked[w]) {
            depth[w] = depth[curr] + 1;
            dfs(graph, w);
          } else if (onStack[w]) {
            largestCycle = Math.max(largestCycle, depth[curr] + 1 - depth[w]);
          }
        }
        onStack[curr] = false;
    }

    public void largestCycle(Graph graph) {
      for(int i = 0; i < graph.V(); i++) {
        marked = new boolean[graph.V()];
        onStack = new boolean[graph.V()];
        depth = new int[graph.V()];
        depth[i] = 0;
        // System.out.format("Trying %d%n", i);
        dfs(graph, i);
      }
    }

    public static void main(String[] args) throws FileNotFoundException{
      Scanner in = new Scanner(new File(args[0]));
      int t = in.nextInt();
      
     for(int i = 0; i < t; i++) {
       int n = in.nextInt();
       BFFs bffs = new BFFs();
       
       Graph graph = new Graph(n);
       
       for(int j = 0; j < n; j++) {
         int bff = in.nextInt() - 1;
         graph.addEdge(j, bff);
       }
      //  System.out.println(graph);
       bffs.largestCycle(graph);
       System.out.format("Case #%d: %s%n", i+1, bffs.largestCycle);
     }
    }

}