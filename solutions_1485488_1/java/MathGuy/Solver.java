package tide;

import java.util.ArrayList;
import java.util.TreeSet;

public class Solver 
{
	static double EPS = 1e-10;
	
	int R, C, H;
	int[][] Ceil, Floor;
	
	ArrayList<Node> graph;
	
	Node endNode;
	
	int encode(int r, int c) { return r*C + c; }
	int decodeR(int x) { return x/C; }
	int decodeC(int x) { return x%C; }
	
	static class Node implements Comparable<Node>
	{
		boolean isDone;
		double bestTime = Double.POSITIVE_INFINITY;
		int r, c;
		ArrayList<Edge> adjacent = new ArrayList<Edge>();
		
		@Override
		public int compareTo(Node o) 
		{
			if (bestTime < o.bestTime) return -1;
			if (bestTime > o.bestTime) return 1;
			if (r < o.r) return -1;
			if (r > o.r) return 1;
			if (c < o.c) return -1;
			if (c > o.c) return 1;
			return 0;
		}

		@Override
		public String toString()
		{
			String ret = "";
			for (Edge e : adjacent) ret += e+",";
			return ret;
		}
		
		public boolean equals(Object o)
		{
			return compareTo((Node)o) == 0;
		}
	}
	
	static class Edge 
	{
		int fromR, fromC, toR, toC;
		double timeFastEnd, timeAllow;
		
		@Override
		public String toString()
		{
			return String.format("E: from=(%d,%d) to=(%d,%d) fastEnd=%f, allow=%f", fromR, fromC, toR, toC, timeFastEnd, timeAllow);
		}
	}
	
	ArrayList<Node> buildGraph()
	{
		ArrayList<Node> graph = new ArrayList<Node>(C*R);
		for (int r = 0; r < R; ++r) 
		{
			for (int c = 0; c < C; ++c) 
			{
				Node node = new Node();
				node.r = r;
				node.c = c;
				for (int dr = -1; dr <= 1; ++dr) 
				{
					for (int dc = -1; dc <= 1; ++dc)
					{
						if (Math.abs(dr) + Math.abs(dc) != 1) continue;
						if (r + dr < 0 || r + dr >= R || c + dc < 0 || c + dc >= C) continue;
						int toR = r+dr, toC = c+dc;
						
						double timeWaterAtFast = (H - (Floor[r][c] + 20))/10.0;
						double timeWaterAtAllow = Math.max( (H - (Ceil[toR][toC] - 50))/10.0 , 0);
						
						if (Floor[r][c] > Ceil[toR][toC] - 50) continue;
						if (Floor[toR][toC] > Ceil[toR][toC] - 50) continue;
						if (Floor[toR][toC] > Ceil[r][c] - 50) continue;
						
						Edge edge = new Edge();
						edge.fromR = r; edge.fromC = c;
						edge.toR = toR; edge.toC = toC;						
						edge.timeFastEnd = timeWaterAtFast;
						edge.timeAllow = timeWaterAtAllow;

						node.adjacent.add(edge);
					}
				}				
				graph.add(node);
			}
		}
		return graph;
	}
	
	public double solve()
	{
		TreeSet<Node> pQueue = new TreeSet<Node>();
		Node start = graph.get(0);
		start.bestTime = 0;

		for (Node n : graph) pQueue.add(n);
		
		while (!pQueue.isEmpty())
		{
			Node currNode = pQueue.pollFirst();
			currNode.isDone = true;
			double currTime = currNode.bestTime;
			if (currNode == endNode) return currTime;
			for (Edge e : currNode.adjacent)
			{
				Node nextNode = graph.get(encode(e.toR, e.toC));
				if (nextNode.isDone) continue;
				pQueue.remove(nextNode);
				double fastEndTime = e.timeFastEnd;
				double allowTime = Math.max(currTime, e.timeAllow);
				double time = fastEndTime > allowTime - EPS ? allowTime+1 : allowTime + 10;
				if (currTime < EPS && allowTime < EPS) time = 0;
				nextNode.bestTime = Math.min(nextNode.bestTime, time);
				pQueue.add(nextNode);
			}
		}
		
		return Double.POSITIVE_INFINITY;
	}
	
	public void print()
	{
		System.out.println("H = "+H);
		for (int i = 0; i < graph.size(); ++i)
		{
			int r = decodeR(i);
			int c = decodeC(i);
			System.out.printf("i=%d, r=%d, c=%d, %s\n",i,r,c,graph.get(i));
		}
	}
	
	public Solver(int[][] Ceil, int[][] Floor, int H)
	{
		this.H = H;
		this.R = Ceil.length;
		this.C = Ceil[0].length;
		this.Ceil = Ceil;
		this.Floor = Floor;
		
		this.graph = buildGraph();
		this.endNode = graph.get(encode(R-1,C-1));
	}
}
