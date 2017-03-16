
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class Node
{
	public Set<Node> subNodes = new HashSet<Node>();
	
	public boolean traverse(Set<Node> visited)
	{
		if (visited.contains(this)) return false;
		visited.add(this);
		for (Node subNode : subNodes)
		{
			if (!subNode.traverse(visited))
			{
				return false;
			}
		}
		return true;
	}
}

public class ProblemA
{
	private void solve()
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++)
		{
			int N = sc.nextInt();
			Node[] nodes = new Node[N];
			for (int i = 0; i < N; i++)
			{
				nodes[i] = new Node();
			}
			
			for (int i = 0; i < N; i++)
			{
				int Mi = sc.nextInt();
				for (int j = 0; j < Mi; j++)
				{
					int k = sc.nextInt();
					nodes[k - 1].subNodes.add(nodes[i]);
				}
			}
			System.out.printf("Case #%d: %s\n", t, check(nodes) ? "No" : "Yes");
		}
	}

	private boolean check(Node[] nodes)
	{
		Set<Node> visited = new HashSet<Node>();
		for (Node node : nodes)
		{
			visited.clear();
			if (!node.traverse(visited))
			{
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args)
	{
		try { System.setIn(new FileInputStream("A-small-attempt0.in")); } catch (Exception e) {}
		try { System.setOut(new PrintStream("A-small-attempt0.out")); } catch (Exception e) {}
		
		new ProblemA().solve();
	}
}
/*
3
3
1 2
1 3
0
5
2 2 3
1 4
1 5
1 5
0
3
2 2 3
1 3
0
*/
