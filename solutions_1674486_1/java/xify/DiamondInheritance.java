package kr.javanese.gcj2012.r1c.a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;

public class DiamondInheritance {

	int inherits[][];
	int n = -1;

	public void init(int n) {
		this.n = n;
		this.inherits = new int[n + 1][n + 1];
	}

	public void addInheritance(int child, int[] parents) {
		for (int parent : parents) {
			inherits[child][parent] = child;
		}
	}

	public boolean isDiamondExists() {

		for (int start = 1; start <= n; start++) {
			boolean[] visited = new boolean[n + 1];
			boolean result = dfs(start, visited);
			if (result) {
				return result;
			}
		}
		return false;
	}

	private boolean dfs(int node, boolean[] visited) {
		if (visited[node]) return true;
		visited[node] = true;
		for (int i=1; i<=n; i++) {
			if (inherits[node][i]>0) {
				if (dfs(i, visited)) {
					return true;
				}
			}
		}
		return false;
	}

	public static void main(String[] args) {
		try {

			BufferedReader reader;
			if (args.length > 0) {
				reader = new BufferedReader(new FileReader(args[0]));
			} else {
				reader = new BufferedReader(new InputStreamReader(System.in));
			}
			String line = null;
			line = reader.readLine();
			int caseCount = Integer.parseInt(line);

			long startTime = System.currentTimeMillis();

			for (int i = 0; i < caseCount; i++) {
				line = reader.readLine();
				int n = Integer.parseInt(line);
				DiamondInheritance instance = new DiamondInheritance();
				instance.init(n);

				for (int j = 1; j <= n; j++) {
					line = reader.readLine();
					String[] tokens = line.split(" ");
					int m = Integer.parseInt(tokens[0]);
					int[] parents = new int[m];
					for (int k = 0; k < m; k++) {
						parents[k] = Integer.parseInt(tokens[k + 1]);
					}
					instance.addInheritance(j, parents);
				}
				System.out.print("Case #");
				System.out.print(i + 1);
				System.out.print(": ");
				System.out.println(instance.isDiamondExists() ? "Yes" : "No");
			}

			System.err.println("Elasped Time : "
					+ (System.currentTimeMillis() - startTime));
			reader.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
