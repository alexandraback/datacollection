package R1C_2012;

import java.io.*;
import java.util.*;

public class A {

	static BufferedWriter writer;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		writer = new BufferedWriter(new FileWriter("output.out"));
		Scanner reader = new Scanner(new FileReader("input.in"));
		int nt = reader.nextInt();
		reader.nextLine();
		for (int tc = 1; tc <= nt; tc++) {
			writer.write("Case #" + tc + ": ");
			int nv = reader.nextInt();
			int[][] g = new int[nv][nv];
			for(int i = 0; i < nv; i++) {
				int ne = reader.nextInt();
				for(int j = 0; j < ne; j++) {
					int dest = reader.nextInt() - 1;
					g[i][dest] = 1;
				}
			}
			if(solve(nv, g)) {
				writer.write("Yes");
			} else {
				writer.write("No");
			}
			writer.newLine();
		}
		writer.close();
		System.out.println("Done.");
	}

	private static boolean solve(int nv, int[][] g) {
		for(int i = 0; i < g.length; i++) {
			for(int j = 0; j < g.length; j++) {
				if(i != j) {
					int[] parent = hasPath(nv, g, i, j);
					if(parent[j] != -1) {
						int cur = j;
						LinkedList<E> path = new LinkedList<E>();
						while(parent[cur] != -1) {
							path.add(new E(parent[cur], cur));
							cur = parent[cur];
						}
						for(E e : path) {
							g[e.orig][e.dest] = 0;
							int[] parent2 = hasPath(nv, g, i, j);
							if(parent2[j] != -1) {
								return true;
							}
							g[e.orig][e.dest] = 1;
						}
					}
				}
			}
		}
		return false;
	}
	
	static class E {
		int orig, dest;
		public E(int orig, int dest) {
			this.orig = orig;
			this.dest = dest;
		}
	}
	
	private static int[] hasPath(int nv, int[][] g, int orig, int dest) {
		boolean[] visited = new boolean[nv];
		int[] parent = new int[nv];
		Arrays.fill(parent, -1);
		Queue<Integer> Q = new LinkedList<Integer>();
		Q.add(orig);
		visited[orig] = true;
		while(!Q.isEmpty()) {
			int cur = Q.poll();
			for(int i = 0; i < nv; i++) {
				if(g[cur][i] != 0) {
					parent[i] = cur;
					visited[i] = true;
					Q.add(i);
				}
			}
		}
		return parent;
	}
}


