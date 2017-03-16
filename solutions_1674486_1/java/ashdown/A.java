import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayDeque;
import java.util.Formatter;
import java.util.Queue;
import java.util.Scanner;


public class A {

	static boolean multipleRoutes(final boolean[][] M, int start) {
		final int N = M.length - 1;
		boolean[] found = new boolean[N+1];
		Queue<Integer> q = new ArrayDeque<Integer>(N);
		q.add(start);
		while (!q.isEmpty()) {
			int here = q.poll();
			if (found[here]) return true;
			found[here] = true;
			for (int next=1; next<=N; next++) {
				if (M[here][next]) {
					q.add(next);
				}
			}
		}
		return false;
	}
	
	static String solve(final boolean[][] M) {
		final int N = M.length - 1;
		for (int i=1; i<=N; i++) {
			if (multipleRoutes(M,i))
				return "Yes";
		}
		return "No";
	}

	public static void main(String[] args) throws FileNotFoundException {
		//String filename = "A-test.in";
		//String filename = "A-small-attempt0.in";
		String filename = "A-large.in";
		assert filename.endsWith(".in");
		Scanner in = new Scanner(new File(filename));
		Formatter out = new Formatter(new File(filename.replace(".in", ".out")));

		assert in.hasNext();
		int T = in.nextInt();
		in.nextLine();
		for (int t = 0; t < T; t++) {
			int N = in.nextInt();
			boolean M[][] = new boolean[N+1][N+1];
			for (int i = 0; i < N; i++) {
				int num = in.nextInt(); 
				for (int j = 0; j < num; j++) {
					int next = in.nextInt(); 
					M[i+1][next] = true;
				}
			}
			
			String ans = solve(M);

			String result;
			if (t < T - 1)
				result = String.format("Case #%d: %s%n", t + 1, ans);
			else
				result = String.format("Case #%d: %s", t + 1, ans);
			out.format(result);
			System.out.format(result);
		}

		out.flush();
		out.close();
	}

}
