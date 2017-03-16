
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.TreeMap;
import java.util.TreeSet;


public class GraphList {
	private ArrayList<TreeMap<Integer,Edge>> edges;
	private int[] marks;
	private int numEdges;
	
	public GraphList(int n) {
		edges = new ArrayList<TreeMap<Integer,Edge>>();
		marks = new int[n];
		numEdges = 0;
//		Comparator<Edge> c = new Comparator<Edge>() {
//			public int compare(Edge a, Edge b) {
//				if (a.vertex < b.vertex)
//					return -1;
//				else if (a.vertex > b.vertex)
//					return 1;
//				else return 0;
//			}
//		};
		for (int i = 0; i < n; i++)
			edges.add(new TreeMap<Integer,Edge>());
		
	}
	public int numVs() {
		return marks.length;
	}
	
	public int numEdges() {
		return numEdges;
	}
	
	public int firstN(int vertex) {
		if (edges.get(vertex).isEmpty())
			return marks.length;
		return edges.get(vertex).firstEntry().getValue().vertex;
	}
	
	public int nextN(int vertex,int otherVertex) {
//		if (edges.get(vertex).isEmpty())
//			return marks.length;
		Integer k = edges.get(vertex).higherKey(otherVertex);
		if (k == null)
			return marks.length;
		return edges.get(vertex).get(k).vertex;
		
//		int v;
//		
//		for (int i = 0; i < edges.get(vertex).size(); i++) {
//			v = edges.get(vertex).get(i).getVertex();
//			if (v == otherVertex) {
//				if (i < edges.get(vertex).size() - 1)
//					return edges.get(vertex).get(i + 1).getVertex();
//				return marks.length;
//			}
//		}
//		return marks.length;
	}
	
	public void setEdge(int u, int v, int weight) {
		if (weight == 0)
			return;
		
		Edge e = edges.get(u).get(v);
		
		if (e == null) {
			edges.get(u).put(v, new Edge(v,weight));
			numEdges++;
		} else {
			e.setWeight(weight);
		}
		
//		if (edges.get(u).isEmpty()) {
//			edges.get(u).add(new Edge(v,weight));
//			numEdges++;
//			return;
//		}
//		
//		int vertex;
//		for (int i = 0; i < edges.get(u).size(); i++) {
//			vertex = edges.get(u).get(i).getVertex();
//			if (vertex == v) {
//				edges.get(u).get(i).setWeight(weight);
//				return;
//			}
//		}
//		
//		edges.get(u).add(new Edge(v,weight));
//		numEdges++;
	}
	
	public void incEdge(int u,int v) {
		
		Edge e = edges.get(u).get(v);
		if (e == null) {
			edges.get(u).put(v,new Edge(v,1));
			numEdges++;
			return;
		} else {
			e.weight++;
		}
		
//		int vertex;
//		for (int i = 0; i < edges.get(u).size(); i++) {
//			vertex = edges.get(u).get(i).getVertex();
//			if (vertex == v) {
//				edges.get(u).get(i).incWeight();
//				return;
//			}
//		}
		
//		edges.get(u).add(new Edge(v,1));
//		numEdges++;	
	}
	
	public void deleteEdge(int u, int v) {
		edges.get(u).remove(v);
		
//		if (edges.get(u).isEmpty()) {
//			return;
//		}
//		
//		int vertex;
//		for (int i = 0; i < edges.get(u).size(); i++) {
//			vertex = edges.get(u).get(i).getVertex();
//			if (vertex == v) {
//				edges.get(u).remove(i);
//				numEdges--;
//				return;
//			}
//		}
	}
	
	public boolean edgeExists(int u, int v) {
		if (edges.get(u).isEmpty())
			return false;
		
		return edges.get(u).get(v) != null;
		//if (edges.get(u).get(b) == null)
		
//		int vertex;
//		for (int i = 0; i < edges.get(u).size(); i++) {
//			vertex = edges.get(u).get(i).getVertex();
//			if (vertex == v) {
//				return true;
//			}
//		}
//		return false;
	}
	
	public int edgeWeight(int u, int v) {
		if (edges.get(u).isEmpty())
			return 0;
		
		Edge e = edges.get(u).get(v);
		if (e == null)
			return 0;
		else return e.weight;
		
//		int vertex;
//		for (int i = 0; i < edges.get(u).size(); i++) {
//			vertex = edges.get(u).get(i).getVertex();
//			if (vertex == v) {
//				return edges.get(u).get(i).getWeight();
//			}
//		}
//		
//		return 0;
	}
	
	public void resetMarks() {
		for (int i = 0; i < marks.length; i++)
			marks[i] = 0;
	}
	
	public void setMark(int vertex,int value) {
		marks[vertex] = value;
	}
	
	public int getMark(int vertex) {
		return marks[vertex];
	}
	
	private class Edge {
		private int vertex,weight;
		
		public Edge(int vertex,int weight) {
			this.vertex = vertex;
			this.weight = weight;
		}
		
		public int getVertex() {
			return vertex;
		}
		
		public int getWeight() {
			return weight;
		}
		
		public void incWeight() {
			weight++;
		}
		
		public void setWeight(int w) {
			weight = w;
		}
		
	}

}
