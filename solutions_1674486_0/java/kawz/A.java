package gcj2012.round1C;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 2012 Code Jam Round 1C
 * 
 * @author kawabon
 * 
 */
public class A {
	public static void main(String[] args) throws Exception {
		A main = args.length > 0 ? new A(args[0]) : new A(A.class.getSimpleName() + ".in");
		main.solve();
	}

	private final BufferedReader in;

	public A(String input) throws Exception {
		in = new BufferedReader(new FileReader(this.getClass().getResource(input).getFile()));
	}

	private class Graph {
		List<List<Integer>> links = new ArrayList<List<Integer>>();

		Graph(int nodes) {
			for (int i = 0; i < nodes; i++) {
				links.add(new ArrayList<Integer>());
			}
		}

		void add(int from, int to) {
			links.get(from - 1).add(to - 1);
		}

		List<Integer> get(int from) {
			return links.get(from);
		}
	}

	private void solve() throws Exception {
		int T = getInt();
		for (int c = 1; c <= T; c++) {
			int N = getInt();
			Graph g = new Graph(N);
			for (int i = 0; i < N; i++) {
				int[] in = getInts();
				for (int to = 0; to < in[0]; to++) {
					g.add(i + 1, in[to + 1]);
				}
			}
			String ans = solveOne(N, g);
			System.out.println("Case #" + c + ": " + ans);
		}
	}

	private String solveOne(int N, Graph g) {
		String result = "No";

		for (int from = 0; from < N; from++) {
			Map<Integer, Boolean> visited = new HashMap<Integer, Boolean>();

			if (visit(visited, g, from, from)) {
				result = "Yes";
				break;
			}
		}

		return result;
	}

	private boolean visit(Map<Integer, Boolean> visited, Graph g, int root, int from) {
		for (Integer to : g.get(from)) {
			if (to.intValue() == root) {
				return false;
			} else if (visited.containsKey(to)) {
				return true;
			} else {
				visited.put(to, Boolean.TRUE);
				if (visit(visited, g, root, to)) {
					return true;
				}
			}
		}

		return false;
	}

	/*
	 * File processing
	 */
	private int getInt() throws Exception {
		return Integer.valueOf(in.readLine()).intValue();
	}

	private int[] getInts() throws Exception {
		List<Integer> ints = getIntegers();
		int[] i = new int[ints.size()];
		for (int j = 0; j < ints.size(); j++) {
			i[j] = ints.get(j);
		}
		return i;
	}

	private List<Integer> getIntegers() throws Exception {
		List<Integer> list = new ArrayList<Integer>();
		for (String s : getStrs()) {
			list.add(Integer.valueOf(s));
		}
		return list;
	}

	private List<String> getStrs() throws Exception {
		return Arrays.asList(in.readLine().split(" "));
	}

}
