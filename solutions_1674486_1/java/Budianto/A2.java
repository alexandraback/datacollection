import java.util.*;
import java.io.*;

public class A2 {
	public static ArrayList<ArrayList<Integer>> adjList;
	public static int[] color;
	public static int N;
	
	public static boolean tryDFS(int u) {
		color = new int[N]; Arrays.fill(color, 0);
		
		color[u]++;
		dfs(u);
		
		for(int i=0;i<N;i++) {
			if (color[i] > 1) return true;
		}
		return false;
	}
	
	public static void dfs(int u) {
		
		for(int i=0;i<adjList.get(u).size();i++) {
			int v = adjList.get(u).get(i);
			
			color[v]++;
			if (color[v] == 1) {
				dfs(v);
			}
		}
	}
	
	public static void main(String[] args)  throws Exception{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for(int caseNo = 1; caseNo <= T; caseNo++) {
			N = in.nextInt();
			
			adjList = new ArrayList<ArrayList<Integer>>();
			for(int i=0;i<N;i++) {
				adjList.add(new ArrayList<Integer>());
			}
			
			for(int i=0;i<N;i++) {				
				int cnt = in.nextInt();
				for(int k=0;k<cnt;k++) {
					int j = in.nextInt()-1;
					adjList.get(i).add(j);
				}
			}
			
			boolean can = false;
			for(int i=0;i<N;i++) {
				can = tryDFS(i);
				if (can) break;
			}
			
			System.out.println("Case #"+caseNo+": "+(can ? "Yes" : "No"));
		}
	}
}