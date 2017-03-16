package r1c2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws Exception {
		// String input = "in";
		// String output = "out";
//		String input = "A-small-attempt0.in";
//		String output = "A-small-attempt0.out";
		 String input = "A-large.in";
		 String output = "A-large.out";

		Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(
				output)));

		int T = Integer.parseInt(scan.nextLine());
		for (int t = 1; t <= T; t++) {
			int N = Integer.parseInt(scan.nextLine());
			boolean[][] grid = new boolean[N][N];
			for (int i = 0; i < N; i++) {
				String[] info = scan.nextLine().split(" ");
				for (int j = 1; j < info.length; j++) {
					int to = Integer.parseInt(info[j]) - 1;
					grid[i][to] = true;
				}
			}

			boolean found = false;
			for (int i = 0; i < N; i++) {
				HashSet<Integer> visited = new HashSet<Integer>();
				LinkedList<Integer> queue = new LinkedList<Integer>();
				for (int j = 0; j < N; j++)
					if (grid[i][j])
						queue.add(j);
				while (queue.size() > 0) {
					int node = queue.poll();
					if (visited.contains(node)) {
						found = true;
						i = N + 1;
						break;
					}
					visited.add(node);
					for (int j = 0; j < N; j++)
						if (grid[node][j])
							queue.add(j);
				}
			}

			if (found)
				pw.println("Case #" + t + ": Yes");
			else
				pw.println("Case #" + t + ": No");
		}

		scan.close();
		pw.close();
	}
}
