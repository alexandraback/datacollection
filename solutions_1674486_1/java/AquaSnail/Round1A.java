import java.io.*;
import java.util.*;
public class Round1A {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("input.txt"));
		FileWriter writer = new FileWriter("output.txt");
		int total = sc.nextInt();
		for(int turn = 1; turn <= total; turn++) {
			boolean hasDiamond = false;
			int size = sc.nextInt();
			boolean[][] matrix = new boolean[size][size];
			for(int i = 0; i < size; i++) {
				int inherit = sc.nextInt();
				for(int j = 0; j < inherit; j++) {
					int next = sc.nextInt()-1;
					matrix[i][next] = true;
				}
			}

			int[] indegree = new int[size];
			int[] degree = new int[size];
			int[][] neighbors = new int[size][size];
			
			for(int i = 0; i < size;i++) {
				for(int j = 0; j < size; j++) {
					if(matrix[j][i]) {
						indegree[i]++;
						neighbors[j][degree[j]++] = i;
					}
				}
			}
			
			//topological sort
			int[] sorted = new int[size];
			int start = 0, last = 0;
			for(int i = 0; i < size; i++) {
				if(indegree[i] == 0) sorted[last++] = i;
			}
			while(start < last) {
				int cur = sorted[start++];
				for(int j = 0; j < size; j++) {
					if(matrix[cur][j]) {
						indegree[j]--;
						if(indegree[j] == 0) sorted[last++] = j;
					}
				}
			}
			
			//traverse
			for(int i = 0; i < size; i++) {
				boolean[] visited = new boolean[size];
				int[] queue = new int[size];
				queue[0] = sorted[i];
				int st = 0, end = 1;
				visited[sorted[i]] = true;
				while(st < end) {
					int cur = queue[st++];
					for(int j = 0; j < degree[cur]; j++) {
						if(visited[neighbors[cur][j]]) {
							hasDiamond = true;
							break;
						}
						queue[end++] = neighbors[cur][j];
						visited[neighbors[cur][j]] = true;
					}
					if(hasDiamond) break;
				}
				if(hasDiamond) break;
			}

			writer.write("Case #" + turn + ": " + (hasDiamond ? "Yes" : "No") + "\n");
		}
		writer.close();
	}
}
