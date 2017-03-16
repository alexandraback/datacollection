import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;


public class Diamond {
	static class Node{
		int id;
		ArrayList<Integer> outVertex;

		public Node(int id){
			this.id = id;
			this.outVertex = new ArrayList<Integer>();
		}

		public void addOutVertex(int i){
			outVertex.add(i);
		}
	}

	static HashMap<Integer, Node> graphMap;

	public static void main(String[] args) throws Exception{
		Scanner scan = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(new File("output-diamond.txt"));
		int t = scan.nextInt();

		while(scan.hasNext()){
			for(int k=1; k<=t; k++){
				int n = scan.nextInt();
				graphMap = new HashMap<Integer, Node>();

				for(int i=1; i<=n;i++){
					int m = scan.nextInt(); // no. of outgoing edges
					for(int j=1; j<=m;j++){
						int clazz = scan.nextInt();
						Node node = graphMap.get(i);
						if(node==null){
							node = new Node(i);
						}
						node.addOutVertex(clazz);

						graphMap.put(i, node);
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

			if(graphMap.get(i)!=null){
				if(doBFSNode(i, n)){
					return "Yes";
				}				
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
			if(graphMap.get(s)!=null){
			ArrayList<Integer> outVertex = graphMap.get(s).outVertex;

			for(Integer j : outVertex){
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
