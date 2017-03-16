import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;


public class Q1 {
	private static void run(int CASE) throws Exception {
		int N = parseInt(readLine());
		int[][] list = new int[N+1][];
		boolean[] roots = new boolean[N+1];
		Arrays.fill(roots, true);
		for (int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(readLine());
			int M = parseInt(st.nextToken());
			list[i] = new int[M];
			for (int j = 0; j < M; j++) {
				list[i][j] = parseInt(st.nextToken());
				roots[list[i][j]] = false;
			}
		}
		
		boolean printed = false;
		boolean[] visited = new boolean[N+1];
		for (int i = 1; i <= N; i++) {
			if(!roots[i]) continue;
			Arrays.fill(visited, false);
			// check
			visited[i] = true;
			if(visit(i, list, visited, CASE)) {
				printed = true;
				break;
			}
		}
		if(!printed) printf("Case #%d: No\n", CASE);
	}
	// return true if break
	private static boolean visit(int i, int[][] list, boolean[] visited, int CASE) {
		for (int j = 0; j < list[i].length; j++) {
			if(visited[list[i][j]]) {
				printf("Case #%d: Yes\n", CASE);
				return true;
			}
			visited[list[i][j]] = true;
			if(visit(list[i][j], list, visited, CASE)) return true;
		}
		return false;
	}

	//-- Supporting --//
	static BufferedReader in;
	static PrintWriter out;
	static {
		try {
			in = new BufferedReader(new FileReader("A-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("out.txt"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) throws Exception {
		int N = Integer.parseInt(readLine());
		for (int c = 1; c <= N; c++) {
			run(c);
		}
		in.close();
		out.close();
	}

	private static String readLine() throws IOException {
		return in.readLine();
	}

	private static void printf(String str, Object... o) {
		System.out.printf(str, o);
		out.printf(str, o);
	}

	private static int parseInt(String t) {
		return Integer.parseInt(t);
	}
}
