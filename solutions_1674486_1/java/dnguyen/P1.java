import java.io.*;
import java.util.*;
import java.text.*;

class P1
{
	public static void main (String [] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-large.out")));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int numCases = Integer.parseInt(st.nextToken());
		
		for (int caseIndex = 0; caseIndex < numCases; caseIndex++)
		{
			out.print("Case #" + (caseIndex+1) + ": ");
			
			st = new StringTokenizer(in.readLine());
			int n = Integer.parseInt(st.nextToken());
			
			Node[] nodes = new Node[n];
			
			for (int i = 0; i < n; i++)
			{
				nodes[i] = new Node(i);
			}
			
			for (int i = 0; i < n; i++)
			{
				st = new StringTokenizer(in.readLine());
				int m = Integer.parseInt(st.nextToken());
				
				for (int j = 0; j < m; j++)
				{
					int k = Integer.parseInt(st.nextToken());
					nodes[i].neighbours.add(nodes[k-1]);
				}
			}
			
			boolean finish = false;
			
			for (int i = 0; i < n; i++)
			{
				Node root = nodes[i];
				
				Stack<Node> stack = new Stack<Node>();
				
				stack.push(root);
				
				boolean[] visited = new boolean[n];
				
				for (int j = 0; j < n; j++)
				{
					visited[j] = false;
				}
				
				visited[root.id] = true;
				
				while (!stack.empty())
				{
					Node curNode = stack.pop();
					
					for (int j = 0; j < curNode.neighbours.size(); j++)
					{
						if (!visited[curNode.neighbours.get(j).id])
						{
							visited[curNode.neighbours.get(j).id] = true;
							stack.push(curNode.neighbours.get(j));
						}
						else
						{
							finish = true;
							out.print("Yes");
							break;
						}
					}
					
					if (finish)
						 break;
				}
				
				if (finish)
					break;
			}
			
			if (!finish)
				out.print("No");
			
			out.println();
		}
		
		out.close();
		
	}
}

class Node
{
	ArrayList<Node> neighbours;
	int id;
	
	public Node(int id)
	{
		this.id = id;
		neighbours = new ArrayList<Node>();
	}
}