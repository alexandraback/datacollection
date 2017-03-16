import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Slides {
	static int mat[][];
	static int b;
	static long ways[] = new long[50 + 1];
	
	static long f(int u) {
		if (u == b)
			return 1;
		if (ways[u] != -1)
			return ways[u];
		long res = 0;
		for (int i = 1; i <= b; i++)
			if (mat[u][i] == 1)
				res += f(i);
		return res;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new FileReader("B-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
		int maxWays[] = new int[51];
		maxWays[0] = 0;
		maxWays[1] = 0;
		maxWays[2] = 1;
		int cnt = 1;
		for (int i = 3; i <= 50; i++)
			maxWays[i] = maxWays[i - 1] + cnt++;
		/*
		 * for (int i = 0; i < maxWays.length; i++) out.println(i + ": " +
		 * maxWays[i]);
		 */
		int t = Integer.parseInt(bf.readLine());
		for (int tc = 1; tc <= t; tc++) {
			StringTokenizer st = new StringTokenizer(bf.readLine());
			b = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			/*if (m > maxWays[b]) {
				out.println("Case #" + tc + ": IMPOSSIBLE");
				continue;
			}*/
			long paths = 0;
			mat = new int[b + 1][b + 1];
			mat[1][b] = 1;
			Arrays.fill(ways, -1);
			paths = f(1);
			//out.println(paths);
			if (paths > m) {
				mat[1][b] = 0;
			}
			lol: for (int k = 2; k < b; k++) {
				mat[1][k] = 1;
				mat[k][b] = 1;
				Arrays.fill(ways, -1);
				paths = f(1);
				//out.println(paths);
				if (paths == m) {
					break;
				}
				if (paths > m) {
					mat[1][k] = 0;
					mat[k][b] = 0;
				}
				for (int idx = 2; idx < k; idx++) {
					mat[idx][k] = 1;
					Arrays.fill(ways, -1);
					paths = f(1);
					//out.println(paths);
					if (paths == m) {
						break lol;
					}
					if (paths > m) {
						mat[idx][k] = 0;
					}
				}
			}
			Arrays.fill(ways, -1);
			paths = f(1);
			//out.println(paths);
			if (paths == m) {
				out.println("Case #" + tc + ": POSSIBLE");
				for (int i = 1; i <= b; i++) {
					for (int j = 1; j <= b; j++)
						out.print(mat[i][j]);
					out.println();
				}
				continue;
			} else {
				out.println("Case #" + tc + ": IMPOSSIBLE");
				continue;
			}
		}
		out.flush();
		out.close();
	}
}
