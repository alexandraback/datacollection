import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) throws FileNotFoundException {

		Scanner sc = new Scanner(new File("A1in.txt"));
		PrintWriter writer = new PrintWriter(new File("A1out.txt"));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int n = sc.nextInt();

			LinkedList<Integer>[] list = new LinkedList[n + 1];
			for (int j = 0; j <= n; j++)
				list[j] = new LinkedList<Integer>();
			for (int j = 1; j <= n; j++) {
				int m = sc.nextInt();
				for (int k = 0; k < m; k++)
					list[j].add(sc.nextInt());

			}
			int count = 0;
			boolean check = true;
			for (int j = 1; j <= n && check; j++)
				for (int k = 1; k <= n && check; k++)
					if (j != k) {
						count = bfs(list, j, k);
						if (count >= 2)
							check = false;
					}
			if (check)
				writer.println("Case #" + i + ": No");
			else
				writer.println("Case #" + i + ": Yes");

		}
		writer.close();
	}

	private static int bfs(LinkedList<Integer>[] list, int start, int end) {
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(start);
		int count = 0;

		while (!queue.isEmpty()) {
			int x = queue.poll();
			if (x == end) {
				count++;

			} else {
				for (int y : list[x])
					queue.add(y);
			}
		}

		return count;
	}
}
