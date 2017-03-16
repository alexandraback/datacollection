import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;

public class Lawnmower {

	public static void main(String[] args) throws Exception {
		String filename = "B-large.in";
		BufferedReader in = new BufferedReader(new FileReader(filename));

		int T = Integer.parseInt(in.readLine());

		for (int test = 1; test <= T; test++) {
			String[] tokens = in.readLine().split(" ");
			int N = Integer.parseInt(tokens[0]);
			int M = Integer.parseInt(tokens[1]);
			int[][] a = new int[N][M];
			for (int n = 0; n < N; n++) {
				tokens = in.readLine().split(" ");
				for (int m = 0; m < M; m++) {
					a[n][m] = Integer.parseInt(tokens[m]);
				}
			}
			System.out.println("Case #" + test + ": " + solve(a));
		}
		in.close();
	}

	private static String solve(int[][] a) {
		int[] maxR = new int[a.length];
		int[] maxC = new int[a[0].length];
		Arrays.fill(maxR, 0);
		Arrays.fill(maxC, 0);
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				maxR[i] = Math.max(maxR[i], a[i][j]);
				maxC[j] = Math.max(maxC[j], a[i][j]);
			}
		}
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				if (a[i][j] < maxR[i] && a[i][j] < maxC[j]) {
					return "NO";
				}
			}
		}
		return "YES";
	}

}
