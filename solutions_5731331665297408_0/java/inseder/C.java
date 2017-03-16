package codejam_round1_14;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class C {

	static class Graph {

		ArrayList<Node> nodes;

		public Graph(int n, ArrayList<String> zips) {
			nodes = new ArrayList<Node>();
			for (int i = 0; i < n; i++) {
				nodes.add(new Node(i, zips.get(i)));
			}
		}

		public void addEdge(int a, int b) {
			nodes.get(a).addEdge(nodes.get(b));
			nodes.get(b).addEdge(nodes.get(a));
		}

		public String getConex(int idx) {
			visited = new int[nodes.size()];

			for (Node n : nodes) {
				Collections.sort(n.neigh);
			}

			return dfs(nodes.get(idx));
		}

		int visited[];
		int min;

		public String dfs(Node n) {
			String x = "";
			if (visited[n.id] == 0) {
				x = n.zip;
				visited[n.id] = 1;
				for (Node neigh : n.neigh) {
					x += dfs(neigh);
				}
			}
			return x;
		}
	}

	static class Node implements Comparable<Node> {

		ArrayList<Node> neigh;
		String zip;

		public Node(int i, String zip) {
			this.id = i;
			this.neigh = new ArrayList<Node>();
			this.zip = zip;
		}

		public void addEdge(Node node) {
			neigh.add(node);
		}

		int id;

		@Override
		public int compareTo(Node o) {
			return zip.compareTo(o.zip);
		}

	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {

		BufferedReader br = new BufferedReader(
				new InputStreamReader(System.in), 1024 * 1024 * 2);

		int t = Integer.parseInt(br.readLine());

		StringBuilder sb = new StringBuilder();
		for (int x = 1; x <= t; x++) {

			int p[] = readArrayLine(br.readLine(), 2);
			int n = p[0];
			int m = p[1];

			ArrayList<String> zips = new ArrayList<String>();
			String min = "99999";
			int minidx = 0;
			for (int i = 0; i < n; i++) {
				String zip = br.readLine();
				zips.add(zip);
				if (min.compareTo(zip) >= 0) {
					min = zip;
					minidx = i;
				}
			}

			Graph g = new Graph(n, zips);

			for (int i = 0; i < m; i++) {
				p = readArrayLine(br.readLine(), 2);
				g.addEdge(p[0] - 1, p[1] - 1);
			}

			sb.append("Case #" + x + ": " + g.getConex(minidx) + "\n");
		}
		BufferedWriter bw = new BufferedWriter(new FileWriter("ii/outCJam.txt"));
		bw.write(sb.toString());
		bw.close();
		System.out.println(sb.toString());
	}

	public static int[] readArrayLine(String line, int n) {
		int[] ret = new int[n];
		int start = 0;
		int end = line.indexOf(' ', start);
		for (int i = 0; i < n; i++) {
			if (end > 0)
				ret[i] = Integer.parseInt(line.substring(start, end));
			else
				ret[i] = Integer.parseInt(line.substring(start));
			start = end + 1;
			end = line.indexOf(' ', start);
		}
		return ret;
	}
}
