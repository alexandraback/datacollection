package codejam_sub_round_b_2012;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.io.Writer;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
/**
 * Date     : May 5, 2012
 * Time     : 6:55:26 PM
 * Email    : denys.astanin@gmail.com
 */

public class A_small {
	public static void main(String[] args) throws IOException {
		new A_small().run();
	}

	int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

	String nextString() throws IOException {
		in.nextToken();
		return (String) in.sval;
	}

	StreamTokenizer in;
	Writer writer;
	Reader reader;
	Set<Integer> ends = new HashSet<Integer>();
	boolean[][] matrix ;
	boolean[] visited;
	int n ;
	void run() throws IOException {
		boolean oj = System.getProperty("ONLINE_JUDGE") != null;
		reader = oj ? new InputStreamReader(System.in, "ISO-8859-1")
				: new FileReader("src/codejam_sub_round_b_2012/A_small.txt");
		writer = oj ? new OutputStreamWriter(System.out, "ISO-8859-1") : new FileWriter("src/codejam_sub_round_b_2012/A_small.out");
		in = new StreamTokenizer(new BufferedReader(reader));
		PrintWriter out = new PrintWriter(writer);
		int T = nextInt();
		for (int t = 1; t <= T; t++) {
			n = nextInt();
			matrix = new boolean[n + 1][n + 1];
			visited = new boolean[n + 1];
			for (int i = 1; i <= n; i++) {
				int count = nextInt();
				for (int j = 1; j <= count;j++) {
					int temp = nextInt();
					matrix[i][temp] = true;
				}
			}
			boolean is = false;
			for (int i = 1;i <=n ;i++) {
				Arrays.fill(visited, false);
				if (check(i)) {
					is = true;
					break;
				}
			}
			out.println("Case #" + t + ": " + (is ? "Yes" : "No"));
		}
		out.flush();
		out.close();
	}

	private boolean check(int i) {
		if (!visited[i]) {
			visited[i] = true;
		} else {
			return true;
		}
		for (int j = 1; j <= n; j++) {
			if (matrix[i][j]) {
				if (check(j)) {
					return true;
				}
			}
		}
		return false;
	}
}
