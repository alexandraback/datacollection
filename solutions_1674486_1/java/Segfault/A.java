import java.util.HashSet;
import java.util.Scanner;
import java.util.Vector;

class Node
{
	public HashSet<Integer> parents;
	
	public Node()
	{
		parents = new HashSet<Integer>();
	}
}


public class A {

	public static void main(String[] args) {
		new A();
	}
	
	boolean[] visited;
	Node[] nodes;
	
	public A()
	{
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		
		for(int t = 1; t <= T; ++t)
		{
			int N = sc.nextInt();
			
			nodes = new Node[N + 1];
			visited = new boolean[N + 1];
			
			for(int i = 0; i <= N; ++i)
			{
				nodes[i] = new Node();
			}
			
			for(int i = 1; i <= N; ++i)
			{
				int M = sc.nextInt();
				
				for(int j = 0; j < M; ++j)
				{
					int dest = sc.nextInt();
					
					nodes[i].parents.add(dest);
				}
			}
			
			boolean ans = false;
			for(int i = 1; i<=N; ++i)
			{
				if(solve(i))
				{
					ans = true;
					break;
				}
			}
			
			System.out.printf("Case #%d: ", t);
			
			if(ans)
				System.out.println("Yes");
			else
				System.out.println("No");
			
			
		}
		
	}

	private boolean solve(int i) {
		
		clearVisited();
		
		Vector<Integer> pending = new Vector<Integer>();

		pending.add(i);

		while(pending.size() != 0)
		{
			for(Integer visit: pending)
			{
				if(visited[visit])
					return true;
			}
			
			Vector<Integer> toVisit = pending;
			HashSet<Integer> willVisit = new HashSet<Integer>();
			
			pending = new Vector<Integer>();
			
			for(Integer visit: toVisit)
			{
				visited[visit] = true;
				
				for(int p: nodes[visit].parents)
				{
					if(willVisit.contains(p))
						return true;
					else
						willVisit.add(p);
						
					pending.add(p);
				}
			}
		}
		
		return false;
	}

	private void clearVisited() {
		for(int i = 0; i < visited.length; ++i)
			visited[i] = false;
		
	}
}
