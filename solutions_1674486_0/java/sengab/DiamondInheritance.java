package Codejamround1;

import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class DiamondInheritance {
	private static Vector<String> v;

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int tCases = Integer.parseInt(scan.nextLine());
		for (int i = 0; i < tCases; i++) {
			v = new Vector<String>();
			int nodes = Integer.parseInt(scan.nextLine());
			int[][] graph = new int[nodes][nodes];
			for (int j = 1; j <= graph.length; j++) {
				String t = scan.nextLine();
				StringTokenizer token = new StringTokenizer(t);
				token.nextToken();
				while (token.hasMoreTokens()) {
					graph[j - 1][Integer.parseInt(token.nextToken()) - 1] = 1;

				}
			}

			boolean entered = false;
			for (int j = 0; j < nodes; j++) {
				boolean[] taken = new boolean[nodes];
				dfs(graph, j, taken, "" + (j + 1) + ",");
			}
			// System.out.println(v);
			for (int j = 0; j < v.size(); j++) {
				for (int j2 = 0; j2 < v.size(); j2++)
					if (j != j2) {
						String s1 = v.get(j);
						String s2 = v.get(j2);
						if (check(s1, s2)) {
							entered = true;
							System.out.println("Case #" + (i + 1) + ":"
									+ " Yes");
							break;
						}
					}
				if (entered)
					break;
			}
			if (!entered) {
				System.out.println("Case #" + (i + 1) + ":" + " No");
			}

		}
	}

	private static boolean check(String s1, String s2) {
		String f1 = first(s1);
		String f2 = first(s2);
		String e1 = end(s1);
		String e2 = end(s2);
		return f1.equals(f2) && e1.equals(e2);
	}

	private static String end(String s1) {
		String n = "";
		for (int i = s1.length() - 1; i >= 0; i--) {
			if (s1.charAt(i) == ',')
				break;
			else
				n += s1.charAt(i);

		}
		return n;
	}

	private static String first(String s1) {
		String n = "";
		for (int i = 0; i < s1.length(); i++) {
			if (s1.charAt(i) == ',')
				break;
			else
				n += s1.charAt(i);

		}
		return n;
	}

	public static void dfs(int[][] connections, int node, boolean[] taken,
			String s) {
		boolean entered = false;
		for (int i = 0; i < connections.length; i++)
			if (!taken[node] && connections[node][i] == 1) {
				entered = true;
				taken[node] = true;
				dfs(connections, i, taken, s += (i + 1) + ",");
				taken[node] = false;
			}
		if (!entered) {
			if (s.length() > 1)
				v.add(s.substring(0, s.length() - 1));
		}
	}

}
