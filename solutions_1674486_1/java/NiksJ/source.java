import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main1 {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		int n;// no of test cases
		BufferedReader bufferedReader = new BufferedReader(
				new InputStreamReader(new FileInputStream(new File(args[0]))));
		BufferedWriter bufferedWriter = new BufferedWriter(
				new OutputStreamWriter(new FileOutputStream(new File(args[1]))));
		n = Integer.parseInt(bufferedReader.readLine());
		for (int i = 0; i < n; i++) {
			int N = Integer.parseInt(bufferedReader.readLine());
			boolean[][] graph = new boolean[N][N];
			for (int k = 0; k < N; k++) {
				for (int j = 0; j < N; j++) {
					graph[k][j] = false;
				}
			}
			for (int k = 0; k < N; k++) {
				String string = bufferedReader.readLine();
				String[] split = string.split(" ");
				for (int j = 1; j < split.length; j++) {
					int classNo = Integer.parseInt(split[j]);
					graph[k][classNo - 1] = true;
				}
			}
			boolean diamondExists = false;
			// Transitive closure
			outer: for (int q = 0; q < N; q++) {
				for (int p = 0; p < N; p++) {
					for (int r = 0; r < N; r++) {
						boolean initial = graph[p][r];
						boolean another = graph[p][q] && graph[q][r];
						graph[p][r] = graph[p][r]
								|| (graph[p][q] && graph[q][r]);
						if (initial && another) {
							diamondExists = true;
							break outer;
						}
					}
				}
			}
			bufferedWriter.write("Case #" + (i + 1) + ": "
					+ ((diamondExists) ? "Yes" : "No") + "\n");
			bufferedWriter.flush();
		}
		bufferedReader.close();
		bufferedWriter.close();
	}
}

