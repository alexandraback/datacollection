import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;



public class DiamondInheritance {

	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("outputA2.txt"));

		int caseCount = sc.nextInt();
		sc.nextLine();

		int N;
		int adjCount;
		ArrayList<ArrayList<Integer>> graph;
		ArrayList<Integer> tmp;
		boolean ans;

		for (int caseNum = 0; caseNum < caseCount; caseNum++) {

			N = sc.nextInt();
			sc.nextLine();

			adjCount = 0;
			graph = new ArrayList<ArrayList<Integer>>();

			for (int i = 0; i < N; i++) {
				tmp = new ArrayList<Integer>();

				adjCount = sc.nextInt();
				for (int j = 0; j < adjCount; j++) {
					tmp.add(sc.nextInt() - 1);
				}

				graph.add(tmp);
			}
			
			ans = false;
			for (int i = 0; i < N; i++) {
				if(bfs(graph, N, i) == true) {
					ans = true;
				}
			}

			if (ans == true) {
				pw.write("Case #" + (caseNum + 1) + ": Yes\n");
			}
			else {
				pw.write("Case #" + (caseNum + 1) + ": No\n");
			}

		}

		pw.flush();
		pw.close();
		sc.close();
	}

	static boolean bfs(ArrayList<ArrayList<Integer>> graph, int N, int start) {


		Queue<Integer> q = new LinkedList<Integer>();
		boolean[] visited = new boolean[N];
		int t;

		q.offer(start);
		visited[start] = true;

		while (!q.isEmpty()) {
			t = q.poll();

			for (Integer adj : graph.get(t)) {
				if (visited[adj]) {
					return true;
				}
				else {
					q.offer(adj);
					visited[adj] = true;
				}
			}
		}

		return false;
	}
}
