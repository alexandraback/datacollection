import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Stack;

class Graph {
	int v;
	boolean[][] adjMat;

	public Graph(int n) {
		v = n;
		adjMat = new boolean[v][v];

	}

	public void addEdge(int v1, int v2) {
		adjMat[v1][v2] = true;
	}

}

public class MainClass {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("Diamond.out"));

		int T = sc.nextInt();
		outer: for (int i = 0; i < T; i++) {
			out.print("Case #" + (i + 1) + ": ");
			int v = sc.nextInt();
			Graph g = new Graph(v);
			for (int j = 0; j < v; j++) {
				int e = sc.nextInt();
				for (int k = 0; k < e; k++) {
					int v2 = sc.nextInt();
					g.addEdge(j, v2 - 1);
				}
			}
			for (int vertex = 0; vertex < v; vertex++) {
				boolean[] visited = new boolean[v];
				Stack<Integer> s = new Stack<Integer>();
				for (int v2 = 0; v2 < v; v2++) {
					if (g.adjMat[vertex][v2]) {
						s.push(v2);
						visited[v2] = true;
					}
				}
				while (!s.empty()) {
					int newV = s.pop();
					for (int v2 = 0; v2 < v; v2++) {
						if (g.adjMat[newV][v2] && visited[v2]) {
							out.println("Yes");
							continue outer;
						} else if (g.adjMat[newV][v2]) {
							visited[v2] = true;
							s.push(v2);
						}

					}
				}
			}
			out.println("No");

		}
		out.close();

	}
}
