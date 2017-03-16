import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class one implements Runnable {

	boolean bfs(ArrayList<Integer>[] arr, int start) {
		boolean[] been = new boolean[arr.length];

		Queue<Integer> q = new LinkedList<Integer>();
		q.add(start);

		been[start] = true;
		while (!q.isEmpty()) {
			int i = q.remove();
			for (int j = 0; j < arr[i].size(); j++) {
				int current = arr[i].get(j);
				if (been[current] && current != start) {
					return true;
				}
				if (!been[current]) {
					been[current] = true;
					q.add(current);
				}
			}
		}
		return false;
	}

	public void run() {
		int t = nextInt();
		ArrayList<Integer> arr[] = new ArrayList[1000];
		for (int k = 1; k <= t; k++) {
			out.print("Case #");
			out.print(k);
			out.print(": ");

			// ////

			int n = nextInt();
			for (int i = 0; i < n; i++) {
				arr[i] = new ArrayList<Integer>();
			}

			for (int i = 0; i < n; i++) {
				int m = nextInt();
				for (int j = 0; j < m; j++) {
					int b = nextInt() - 1;
					arr[i].add(b);
				}
			}
			String ans = "No";
			for (int i = 0; i < n; i++) {
				if (bfs(arr, i)) {
					ans = "Yes";
					break;
				}
			}

			out.println(ans);
		}

		// --------------------------------------------------------------------------------------------
		out.close();
		System.exit(0);
	}

	private static boolean fileIOMode = true;
	private static String problemName = "A-small-attempt0";
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer tokenizer;

	public static void main(String[] args) throws Exception {
		if (fileIOMode) {
			in = new BufferedReader(new FileReader(problemName + ".in"));
			out = new PrintWriter(problemName + ".out");
		} else {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		}
		tokenizer = new StringTokenizer("");

		new Thread(new one()).start();
	}

	private static String nextLine() {
		try {
			return in.readLine();
		} catch (IOException e) {
			return null;
		}
	}

	private static String nextToken() {
		while (!tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(nextLine());
		}
		return tokenizer.nextToken();
	}

	private static int nextInt() {
		return Integer.parseInt(nextToken());
	}
}
