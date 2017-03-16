package code.jam.r1c;

import java.io.*;
import java.util.*;

class Node
{
	int n;
	boolean visited = false;
	Node parent;

	public Node(int n)
	{
		this.n = n;
	}

}

class Graph
{
	public Node rootNode;
	public List<Node> nodes = new ArrayList<Node>();
	public int[][] adjMatrix;// Edges will be represented as adjacency
	int size;
	boolean diamond = false;

	public void setRootNode(Node n)
	{
		this.rootNode = n;
	}

	public Node getRootNode()
	{
		return this.rootNode;
	}

	public void addNode(Node n)
	{
		nodes.add(n);
	}

	public void connectNode(Node start, Node end)
	{
		if (adjMatrix == null)
		{
			size = nodes.size();
			adjMatrix = new int[size][size];
		}

		int startIndex = nodes.indexOf(start);
		int endIndex = nodes.indexOf(end);
		adjMatrix[startIndex][endIndex] = 1;
		// adjMatrix[endIndex][startIndex] = 1;
	}

	private Node getUnvisitedChildNode(Node n)
	{

		int index = nodes.indexOf(n);
		int j = 0;
		while (j < size)
		{
			Node child = ((Node) nodes.get(j));
			if (adjMatrix[index][j] == 1 && child.visited == true && child.parent != null && child.parent != n)
			{
				diamond = true;
				return null;
			}

			if (adjMatrix[index][j] == 1 && child.visited == false)
			{
				return child;
			}
			j++;
		}
		return null;
	}

	// BFS traversal of a tree is performed by the bfs() function
	public void bfs()
	{

		// BFS uses Queue data structure
		Queue<Node> q = new LinkedList<Node>();
		q.add(this.rootNode);
		printNode(this.rootNode);
		rootNode.visited = true;
		while (!q.isEmpty())
		{
			Node n = (Node) q.remove();
			Node child = null;
			while ((child = getUnvisitedChildNode(n)) != null)
			{
				child.visited = true;
				child.parent = n;
				// printNode(child);
				q.add(child);
			}
			if (diamond)
				return;
		}
	}

	public void clearNodes()
	{
		int i = 0;
		while (i < size)
		{
			Node n = (Node) nodes.get(i);
			n.visited = false;
			n.parent = null;
			i++;
		}
	}

	private void printNode(Node n)
	{
		//System.out.print(n.n + " ");
	}
}

public class A
{
	// static String input = "A-small-attempt.in";

	static String input = "A-large.in";
	// static String input = "A-small-practice.in";
	// static String input = "A-large-practice.in";

	static String base = "D:/Martin/Downloads/";
	static String output = "output.txt";
	static PrintWriter out;
	static Scanner sc;

	public static void main(String[] args) throws Exception
	{
		out = new PrintWriter(base + output);
		sc = new Scanner(new File(base + input));

		int T = sc.nextInt();
		for (int i = 0; i < T; i++)
		{
			Graph g = new Graph();
			int N = sc.nextInt();

			for (int j = 1; j <= N; j++)
				g.addNode(new Node(j));

			for (int j = 1; j <= N; j++)
			{
				Node n = g.nodes.get(j - 1);
				int M = sc.nextInt();
				for (int k = 0; k < M; k++)
				{
					int mi = sc.nextInt();
					g.connectNode(n, g.nodes.get(mi - 1));
				}
			}

			List<Node> startNodes = new ArrayList<Node>(g.nodes);
			while (startNodes.size() != 0)
			{
				g.setRootNode(startNodes.remove(0));
				g.bfs();
				if (g.diamond)
					break;
				else
				{
					for (Node node : g.nodes)
					{
						if (node.visited)
							startNodes.remove(node);
					}
				}
				g.clearNodes();
			}

			if (g.diamond)
				log("Case #" + (i + 1) + ": Yes");
			else
				log("Case #" + (i + 1) + ": No");

		}

		close();
	}

	static void log(String result) throws Exception
	{
		System.out.println(result);
		out.println(result);
	}

	static void close()
	{
		sc.close();
		out.flush();
		out.close();
	}
}
