import java.io.File;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class Diamond {
	static int[][] graph;
	static int[][] graphcopy;
	static int[][] pathCount;
	
	public static void main(String[] args) throws Exception{
		Scanner scan = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(new File("output-diamond.txt"));
		int t = scan.nextInt();
		
		while(scan.hasNext()){
			for(int k=1; k<=t; k++){
				int n = scan.nextInt();
				graph = new int[n+1][n+1];
				graphcopy = new int[n+1][n+1];
				pathCount = new int[n+1][n+1];
				
				for(int i=0;i<n+1;i++)
					for(int j=0;j<n+1;j++){
						graph[i][j] = 0;
						graphcopy[i][j] = 0;
						pathCount[i][j] = 0;
					}
				
				for(int i=1; i<=n;i++){
					int m = scan.nextInt();
					for(int j=1; j<=m;j++){
						int clazz = scan.nextInt();
						graph[i][clazz] = 1;
						graphcopy[i][clazz] = 1;
						pathCount[i][clazz] = 1;
					}
				}
			
				//System.out.println("Case #" + k +": " + solve(n));
				pw.println("Case #" + k +": " + doDFSGraph(n));
				pw.flush();
			}
			
		}
		scan.close();
		pw.close();
	}


	
	static boolean[] visited;
	
	private static String doDFSGraph(int n){
		for(int i = 1; i <=n; i++){
			visited = new boolean[n+1];
			for(int j=0; j < visited.length; j++){
				visited[j] = false;
			}
			visited[i] = true;
			
			if(doBFSNode(i, n)){
				return "Yes";
			}
		}
		return "No";
	}




	private static boolean doBFSNode(int i, int n) {
		LinkedList<Integer> queue = new LinkedList<Integer>();
		queue.addLast(i);
		
		while(!queue.isEmpty()){
			int s = queue.removeFirst();
			visited[s] = true;
			for(int j=1;j<n+1;j++){
				if(graph[s][j]==1){
					if(visited[j]){
						return true;
					} else {
						visited[j] = true;
						queue.addLast(j);
					}
				}
			}
		}
		
		return false;
	}


}
