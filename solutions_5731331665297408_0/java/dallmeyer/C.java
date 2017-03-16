import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;


public class C {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for (int caseNo = 1; caseNo <= T; caseNo++)
		{
			int N = in.nextInt(),
				M = in.nextInt();
			
			Node[] nodes = new Node[N];
			for (int i = 0; i < N; i++)
			{
				nodes[i] = new Node(in.nextInt());
			}
			
			for (int i = 0; i < M; i++)
			{
				int a = in.nextInt()-1,
					b = in.nextInt()-1;

				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			
			Arrays.sort(nodes);
			for (int i = 0; i < N; i++)
			{
				Collections.sort(nodes[i].adj);
			}
			
			ArrayList<Node> path = new ArrayList<Node>();
			path.add(nodes[0]);
			
			System.out.println("Case #" + caseNo + ": " + DFS(nodes, nodes[0], path));
		}
	}
	
	private static String DFS(Node[] nodes, Node cur, ArrayList<Node> path)
	{
		if (path.size() == nodes.length)
		{
			return concatPath(path);
		}
		
		String min = null;
		int iCur = path.indexOf(cur);
		for (Node next : cur.adj)
		{
			if (min != null)
				return min;
			
			//try moving to new node from cur
			if (!path.contains(next))
			{
				next.prev = cur;
				path.add(next);
				String temp = DFS(nodes, next, path);
				path.remove(path.size()-1);
				next.prev = null;
				
				if (temp != null && (min == null || temp.compareTo(min) < 0))
				{
					min = temp;
				}
			}
		}
			//try taking return flight from cur
		if (cur.prev != null)
		{
			String temp = DFS(nodes, cur.prev, path);
						
			if (temp != null && (min == null || temp.compareTo(min) < 0))
			{
				min = temp;
			}
		}		
		
		return min;
	}
	
	private static String concatPath(ArrayList<Node> path)
	{
		String s = "";
		for (Node n : path)
		{
			s += n.toString();
		}
		return s;
	}
	
	private static class Node implements Comparable<Node>
	{
		int n;
		ArrayList<Node> adj;
		Node prev = null;
		
		public Node (int n)
		{
			this.n = n;
			adj = new ArrayList<Node>();
		}

		public int compareTo(Node o) {
			return this.n - o.n;
		}
		
		public String toString()
		{
			return n + "";
		}
		
		public int hashCode()
		{
			return n;
		}
	}

}
