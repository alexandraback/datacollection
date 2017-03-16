import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class iCode2012DiamondInheritance {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int index = 1; index <= T; index++) {
			int N = in.nextInt();
			ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
			adj.add(null);
			for (int i = 1; i <= N; i++) {
				ArrayList<Integer> list = new ArrayList<Integer>();
				adj.add(list);
				int M = in.nextInt();
				for (int j = 0; j < M; j++)
					list.add(in.nextInt());
			}
			
			boolean diamond = false;

			//BFS
			LinkedList<Integer> queue = new LinkedList<Integer>();
			BFS:
				for (int start = 1; start <= N; start++) {
					//if (seen[start])
						//continue;
					boolean[] seen = new boolean[N + 1];
					queue.add(start);
					while (!queue.isEmpty()) {
						int current = queue.poll();
						if (seen[current]) {
							diamond = true;
							break BFS;
						} else
							seen[current] = true;
						for (int next : adj.get(current)) {
							if (seen[next]) {
								diamond = true;
								break BFS;
							} else
								queue.add(next);
						}
					}
				}

			System.out.print("Case #" + index + ": ");
			if (diamond)
				System.out.println("Yes");
			else
				System.out.println("No");
		}
	}

}
/*
3
3
1 2
1 3
0
5
2 2 3
1 4
1 5
1 5
0
3
2 2 3
1 3
0
*/