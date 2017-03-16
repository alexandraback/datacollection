import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(new File("B.in")));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("B.out"))));

			String[] message = { "", "YES", "NO" };
			int T = Integer.parseInt(br.readLine());
			for (int i = 0; i < T; i++) {
				String[] param = br.readLine().split(" ");
				int N = Integer.parseInt(param[0]);
				int M = Integer.parseInt(param[1]);
				int[][] map = new int[N][M];
				for (int j = 0; j < N; j++) {
					param = br.readLine().split(" ");
					for (int k = 0; k < M; k++) {
						map[j][k] = Integer.parseInt(param[k]);
					}
				}
				pw.println("Case #" + (i+1) + ": " + message[analyze(N, M, map)]);
			}
			
			pw.close();
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
			return;
		}
	}
	
	private static int analyze(int N, int M, int[][] map) {
		int[] yoko = new int[N];
		int[] tate = new int[M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				yoko[i] = Math.max(yoko[i], map[i][j]);
				tate[j] = Math.max(tate[j], map[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if ((yoko[i] > map[i][j])&&(tate[j] > map[i][j])) return 2;
			}
		}
		return 1;
	}
}
