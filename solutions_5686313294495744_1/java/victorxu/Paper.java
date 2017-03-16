import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.LinkedList;

//Ford-fulkerson algorithm code taken from 
//http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/

public class Paper {
	public static void main(String[] args) throws IOException{
		BufferedReader buf = new BufferedReader(new FileReader("paper.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("paper.out")));
		int q = Integer.parseInt(buf.readLine());
		for(int i = 1; i <= q; i++){
			int n = Integer.parseInt(buf.readLine());
			int acount = 0;
			int bcount = 0;
			HashMap<String, Integer> a = new HashMap<String, Integer>();
			HashMap<String, Integer> b = new HashMap<String, Integer>();
			ArrayList<ArrayList<Integer>> edges = new ArrayList<ArrayList<Integer>>();
			for(int j = 0; j < n; j++){
				String[] s = buf.readLine().split(" ");
				String first = s[0];
				String second = s[1];
				if(!a.containsKey(first)) {
					a.put(first, acount);
					acount++;
					edges.add(new ArrayList<Integer>());
				}
				if(!b.containsKey(second)) {
					b.put(second, bcount);
					bcount++;
				}
				edges.get(a.get(first)).add(b.get(second));
			}
			int size = acount + bcount + 2;
			int[][] graph = new int[size][size];
			for(int j = 0; j < acount; j++){
				graph[0][2+j] = 1;
			}			
			for(int j = 0; j < bcount; j++){
				graph[2+acount+j][1] = 1;
			}
			for(int j = 0; j < edges.size(); j++){
				for(int k : edges.get(j)){
					graph[2+j][2+acount+k] = 1;
				}
			}
			int flow = acount + bcount - fordFulkerson(graph,0,1,size);
			out.println("Case #" + i + ": " + (n - flow));
		}
		out.close();
	}
	//Ford-fulkerson algorithm code taken from 
	//http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
	public static boolean bfs(int rGraph[][], int s, int t, int parent[], int n)
	{
	    // Create a visited array and mark all vertices as not visited
	    boolean[] visited = new boolean[n];
	 
	    // Create a queue, enqueue source vertex and mark source vertex
	    // as visited
	    LinkedList<Integer> q = new LinkedList<Integer>();
	    q.addLast(s);
	    visited[s] = true;
	    parent[s] = -1;
	 
	    // Standard BFS Loop
	    while (!q.isEmpty())
	    {
	        int u = q.peek();
	        q.pop();
	 
	        for (int v=0; v<n; v++)
	        {
	            if (visited[v]==false && rGraph[u][v] > 0)
	            {
	                q.push(v);
	                parent[v] = u;
	                visited[v] = true;
	            }
	        }
	    }
	 
	    // If we reached sink in BFS starting from source, then return
	    // true, else false
	    return (visited[t] == true);
	}
	 
	// Returns tne maximum flow from s to t in the given graph
	public static int fordFulkerson(int graph[][], int s, int t, int n)
	{
	    int u, v;
	 
	    // Create a residual graph and fill the residual graph with
	    // given capacities in the original graph as residual capacities
	    // in residual graph
	    int[][] rGraph = new int[n][n]; // Residual graph where rGraph[i][j] indicates 
	                     // residual capacity of edge from i to j (if there
	                     // is an edge. If rGraph[i][j] is 0, then there is not)  
	    for (u = 0; u < n; u++)
	        for (v = 0; v < n; v++)
	             rGraph[u][v] = graph[u][v];
	 
	    int[] parent = new int[n];  // This array is filled by BFS and to store path
	 
	    int max_flow = 0;  // There is no flow initially
	 
	    // Augment the flow while tere is path from source to sink
	    while (bfs(rGraph, s, t, parent, n))
	    {
	        // Find minimum residual capacity of the edhes along the
	        // path filled by BFS. Or we can say find the maximum flow
	        // through the path found.
	        int path_flow = Integer.MAX_VALUE;
	        for (v=t; v!=s; v=parent[v])
	        {
	            u = parent[v];
	            path_flow = Math.min(path_flow, rGraph[u][v]);
	        }
	 
	        // update residual capacities of the edges and reverse edges
	        // along the path
	        for (v=t; v != s; v=parent[v])
	        {
	            u = parent[v];
	            rGraph[u][v] -= path_flow;
	            rGraph[v][u] += path_flow;
	        }
	 
	        // Add path flow to overall flow
	        max_flow += path_flow;
	    }
	 
	    // Return the overall flow
	    return max_flow;
	}
}
