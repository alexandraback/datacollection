import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemC {
	String PROBLEM_ID = "problemC";

	enum TestType {
		EXAMPLE, SMALL, LARGE
	}

//	TestType TYPE = TestType.EXAMPLE;
	 TestType TYPE = TestType.SMALL;
//	TestType TYPE = TestType.LARGE;

	public String getFileName() {
		String result = PROBLEM_ID + "_";
		switch (TYPE) {
		case EXAMPLE:
			result += "example";
			break;
		case SMALL:
			result += "small";
			break;
		case LARGE:
			result += "large";
			break;
		}
		return result;
	}

	public String getInFileName() {
		return getFileName() + ".in";
	}

	public String getOutFileName() {
		return getFileName() + ".out";
	}

	public static void main(String[] args) throws Exception {
		new ProblemC();
	}

	public ProblemC() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			int m = scan.nextInt();
			boolean[][] adj = new boolean[n][n];
			int[] zip = new int[n];
			for ( int i = 0; i < n; i++) zip[i] = scan.nextInt();
			for ( int i = 0; i < m; i++) {
				int a = scan.nextInt() - 1;
				int b = scan.nextInt() - 1;
				adj[a][b] = true;
				adj[b][a] = true;
			}
			int[] visit = new int[n];
			int[] parent = new int[n];
			for ( int i = 0; i < n; i++) visit[i] = i;
			String best = null;
			do {
				Arrays.fill(parent, -1);
				int current = visit[0];
				String s = "" + zip[current];
				boolean ok = true;
				for ( int i = 1; i < n && ok; i++) {
					int next = visit[i];
					int v = current;
					while ( v != -1 && !adj[v][next] ) v = parent[v];
					if ( v == -1 ) ok = false;
					else {
						s += zip[next];
						parent[next] = v;
						current = next;
					}
				}
				if ( ok ) {
					if ( best == null || s.compareTo(best) < 0) {
						best = s;
					}
				}
			} while ( nextPermutation(visit));
			
			String resultStr = String.format("Case #%d: %s", test + 1, best);
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	}
	public boolean nextPermutation(int[] a) {
		if (a.length <= 1)
			return false;
		int k = a.length - 2;
		while (k >= 0 && a[k] >= a[k + 1])
			k--;
		int m = a.length - 1;
		if (k < 0) {
			reverse(a, 0, m);
			return false;
		}
		while (a[m] <= a[k])
			m--;
		swap(a, m, k);
		reverse(a, k + 1, a.length - 1);
		return true;
	}

	public void reverse(int[] a, int s, int t) {
		while (s < t)
			swap(a, s++, t--);
	}

	public void swap(int[] a, int s, int t) {
		int b = a[s];
		a[s] = a[t];
		a[t] = b;
	}
}
