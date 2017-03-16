import java.util.Scanner;

public class Diamond {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int size = in.nextInt();
		int count = 0;
		while (count < size) {
			int dimention = in.nextInt();
			boolean[][] graph = new boolean[dimention][dimention];
			boolean[][] paths = new boolean[dimention][dimention];
			// reading graph
			for (int i = 0; i < dimention; i++) {
				int linkNum = in.nextInt();
				for (int j = 0; j < linkNum; j++) {
					int to = in.nextInt();
					graph[i][to - 1] = true;
				}
			}

			// check for paths
			int i = 0;
			for (i = 0; i < dimention; i++) {
				boolean containDim = checkPath(i, i, graph, paths);
				if (containDim) {
					System.out.format("Case #%d: %s\n", count + 1, "Yes");
					break;
				}
			}
			if (i == dimention) {
				System.out.format("Case #%d: %s\n", count + 1, "No");
			}
			count++;
		}
	}

	private static boolean checkPath(int src, int from, boolean[][] graph,
			boolean[][] paths) {
		if (from != src && paths[src][from]) {
			return true;
		}

		paths[src][from] = true;
		for (int i = 0; i < paths.length; i++) {
			boolean containDim = false;
			if (graph[from][i])
				containDim = checkPath(src, i, graph, paths);
			if (containDim)
				return true;

		}
		return false;
	}
}
