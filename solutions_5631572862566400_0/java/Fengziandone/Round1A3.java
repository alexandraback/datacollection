import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Round1A3 {

	public static void main(String... strings) {

		Scanner sc = new Scanner(System.in);
		 PrintStream ps = System.out;
		 try {
		 System.setOut(new PrintStream(new FileOutputStream("out3.txt")));
		 } catch (FileNotFoundException e) {
		 // TODO Auto-generated catch block
		 e.printStackTrace();
		 }
		 ps.close();
		int numCases = Integer.valueOf(sc.nextLine());

		for (int i = 0; i < numCases; i++) {
			int V = sc.nextInt(), maxLen = 0;
			boolean[] visited = new boolean[V];
			Arrays.fill(visited, false);
			ArrayList<ArrayList<Integer>> adjList;
			adjList = new ArrayList<>();

			for (int k = 0; k < V; k++) {
				adjList.add(new ArrayList<Integer>());
			}
			for (int j = 0; j < V; j++) {
				int a = sc.nextInt() - 1;
				if (!adjList.get(j).contains(a)) {
					adjList.get(j).add(a);
				}
				if (!adjList.get(a).contains(j)) {
					adjList.get(a).add(j);
				}
			}

			for (int m = 0; m < V; m++) {
				if (!visited[m]) {
					int temp = dfsRecurse(m, adjList, visited);
					if (temp > maxLen)
						maxLen = temp;
				}
			}
			System.out.printf("Case #%d: %d\n", i + 1, maxLen);
		}
		sc.close();
	}

	private static int dfsRecurse(int m, ArrayList<ArrayList<Integer>> adjList, boolean[] visited) {
		int len = 0;
		visited[m] = true;
		for (Integer v : adjList.get(m)) {
			if (!visited[v]) {
				len++;
				len += dfsRecurse(v, adjList, visited);
			}
		}
		return len;
	}

}
