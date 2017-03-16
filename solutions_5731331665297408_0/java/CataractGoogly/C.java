package gcj2014_1b;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Stack;


public class C {

	static String best;

	static void doit(int numVisited, boolean[] visited, Stack<Integer> stack, String sofar, int N, String[] Z, boolean[][] G) {
		if (stack.isEmpty()) {
			if (numVisited == N) {
				if (sofar.length() != N * 5)
					throw new AssertionError("sofar = " + sofar + " expected to have length " + (N*5));
				if (best==null || sofar.compareTo(best) < 0)
					best = sofar;
			}
		} else {
			int loc = stack.peek();
			// pop
			stack.pop();
			doit(numVisited, visited, stack, sofar, N, Z, G);

			stack.push(loc);
			for (int i=0; i<N; i++) if (!visited[i] && G[loc][i]) {
				visited[i] = true;
				stack.push(i);
				doit(numVisited+1, visited, stack, sofar+Z[i], N, Z, G);
				stack.pop();
				visited[i] = false;
			}
		}
	}

	static String solve(int N, int M, String[] Z, boolean[][] G) {
		best = null;
		for (int i=0; i<N; i++) {
			boolean[] visited = new boolean[N];
			visited[i] = true;
			Stack<Integer> stack = new Stack<Integer>();
			stack.push(i);
			doit(1, visited, stack, Z[i], N, Z, G);
		}
		return best;
	}

	public static void main(String[] args) {
		try {
			File fin = new File("C-small-attempt0.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("C-out.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			for (int cn=1; cn<=T; cn++) {
				int N = sc.nextInt();
				int M = sc.nextInt();
				String[] Z = new String[N];
				for (int i=0; i<N; i++)
					Z[i] = sc.next();
				boolean[][] G = new boolean[N][N];
				for (int i=0; i<M; i++) {
					int city1 = sc.nextInt() - 1;
					int city2 = sc.nextInt() - 1;
					G[city1][city2] = true;
					G[city2][city1] = true;
				}
				pw.write("Case #" + cn + ": " + solve(N, M, Z, G) + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
