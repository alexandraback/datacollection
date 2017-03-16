import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Hashtable;


public class A {

	private static int[][] edges;
	private static int[][] sym;
	private static int N;
	private static ArrayList<Integer> sources;
	
	private static void findSources() {
		sources = new ArrayList<Integer>();
		
		for (int i = 0;i < N; ++i) {
			boolean existIncomingEdges = false;
			
			for (int j = 0;j < N;++j) {
				if (i == j) {
					continue;
				}
				
				if (edges[j][i] == 1) {
					existIncomingEdges = true;
					break;
				}
			}
			
			if (!existIncomingEdges) {
				sources.add(i);
			}
		}
	}
	
	private static ArrayList<Integer> layer;
	private static ArrayList<Integer> front;
	private static ArrayList<Integer> visited;
	private static Hashtable<Integer, Integer> predecessor;
	
	private static boolean isPredecessor(int v, int u) {		
		if (u == v) {
			return true;
		}
		
		if (!predecessor.containsKey(v)) {
			return false;
		}
		
		return isPredecessor(predecessor.get(v), u);
	}
	
	private static boolean processLayer() {
		for (int i = 0;i < layer.size(); ++i) {
			int v = layer.get(i);
			
			for (int j = 0; j < N; ++j) {
				if (edges[v][j] == 1) {
					if (visited.contains(j)) {
						if (!isPredecessor(v, j)) {
							return true;
						}
					} else {
						front.add(j);
						visited.add(j);
						predecessor.put(v, j);
					}
				}
			}
		}
		return false;
	}
	
	private static boolean topologicalTraverse(int v) {
		layer = new ArrayList<Integer>();
		front = new ArrayList<Integer>();
		visited = new ArrayList<Integer>();
		predecessor = new Hashtable<Integer, Integer>();
		
		layer.add(v);
		
		do {
			if (processLayer()) {
				return true;
			}
			
			layer = front;
			front = new ArrayList<Integer>();
		} while(!layer.isEmpty());
		
		return false;
	}
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("A-large (2).in")));
		FileOutputStream fos = new FileOutputStream("Aout.txt"); 
		OutputStreamWriter out = new OutputStreamWriter(fos);
		StreamTokenizer tokenizer = new StreamTokenizer(in);
		int T;

		tokenizer.nextToken();
		T = (int)tokenizer.nval;
		
		for (int t = 0;t < T; ++t) {
			tokenizer.nextToken();
			N = (int)tokenizer.nval;
			
			edges = new int[N][N];
			sym = new int[N][N];
			
			for (int i = 0;i < N; ++i) {
				int M;
				
				tokenizer.nextToken();
				M = (int)tokenizer.nval;
				
				for (int j = 0;j < M; ++j) {
					int from;
					tokenizer.nextToken();
					from = (int)tokenizer.nval;
					
					sym[from-1][i] = sym[i][from-1] = edges[from-1][i] = 1;
				}
				
			}
			
			findSources();
			
			boolean found = false;
			
			for (int i = 0;i < sources.size(); ++i) {
				if (topologicalTraverse(sources.get(i))) {
					out.append("Case #" + (t+1) + ": Yes\n");
					found = true;
					break;
				}
			}
			
			 if (!found) {
				out.append("Case #" + (t+1) + ": No\n");
			}
			 
			out.flush(); 
		}
	}

}
