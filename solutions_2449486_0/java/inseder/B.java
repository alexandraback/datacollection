package jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class B {

	public static void main(String[] args) throws Exception {
		f1();
	}

	public static void f1() throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("b.in"),
				1024 * 1024 * 2);
		BufferedWriter bw = new BufferedWriter(new FileWriter("b.out"),
				1024 * 1024 * 2);

		int t = Integer.parseInt(br.readLine());
		int count = 1;
		StringBuilder sb = new StringBuilder();

		while (count <= t) {
			int values[] = readArrayLine(br.readLine(), 2);
			int n = values[0];
			int m = values[1];
			if (n == 1 || m == 1) {
				sb.append("Case #" + count + ": YES\n");
				for (int i = 0; i < n; i++) {
					readArrayLine(br.readLine(), m);
				}
			} else {
				int[][] mat = new int[n][m];
				for (int i = 0; i < n; i++) {
					mat[i] = readArrayLine(br.readLine(), m);
				}
				int[][] maxLeft2Right = new int[n][m];
				int[][] maxRight2Left = new int[n][m];
				int[][] maxUp2Down = new int[n][m];
				int[][] maxDown2Up = new int[n][m];
				for (int i = 0; i < n; i++) {
					maxLeft2Right[i][m - 1] = mat[i][m - 1];
					for (int j = m - 2; j >= 0; j--) {
						maxLeft2Right[i][j] = Math.max(maxLeft2Right[i][j + 1],
								mat[i][j]);
					}
					maxRight2Left[i][0] = mat[i][0];
					for (int j = 1; j < m; j++) {
						maxRight2Left[i][j] = Math.max(maxRight2Left[i][j - 1],
								mat[i][j]);
					}
				}

				for (int j = 0; j < m; j++) {
					maxUp2Down[n - 1][j] = mat[n - 1][j];
					for (int i = n - 2; i >= 0; i--) {
						maxUp2Down[i][j] = Math.max(maxUp2Down[i + 1][j],
								mat[i][j]);
					}
					maxDown2Up[0][j] = mat[0][j];
					for (int i = 1; i < n; i++) {
						maxDown2Up[i][j] = Math.max(maxDown2Up[i - 1][j],
								mat[i][j]);
					}
				}
				boolean impos = false;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						// road
						if ((mat[i][j] < maxLeft2Right[i][j] || mat[i][j] < maxRight2Left[i][j])
								&& (mat[i][j] < maxUp2Down[i][j] || mat[i][j] < maxDown2Up[i][j])) {
							impos = true;
							break;
						}
					}
					if (impos) {
						break;
					}
				}
				sb.append("Case #" + count + ": " + (impos ? "NO" : "YES")
						+ "\n");
			}
			count++;
		}
		System.out.print(sb.toString());
		bw.write(sb.toString());
		bw.close();
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
