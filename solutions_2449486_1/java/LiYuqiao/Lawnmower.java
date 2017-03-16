import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Lawnmower {
	boolean check(int[][] pattern, int N, int M) {
		int[] maxR = new int[N];
		int[] maxC = new int[M];
		Arrays.fill(maxR, 0);
		Arrays.fill(maxC, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (pattern[i][j] > maxR[i]) {
					maxR[i] = pattern[i][j];
				}
			}
		}
		for (int j = 0; j < M; j++) {
			for (int i = 0; i < N; i++) {
				if (pattern[i][j] > maxC[j]) {
					maxC[j] = pattern[i][j];
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (pattern[i][j] < maxR[i] && pattern[i][j] < maxC[j])
					return false;
			}
		}
		return true;
	}

	public static void main(String[] args) throws Exception {
		Lawnmower lm = new Lawnmower();
		BufferedReader reader = new BufferedReader(new FileReader("B-large.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("out.txt"));
		int T = Integer.parseInt(reader.readLine());
		int k = 1;
		while (k <= T) {
			String line = reader.readLine();
			StringTokenizer st = new StringTokenizer(line);
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int [][]patterns=new int[N][M];
			for(int i=0;i<N;i++){
				line=reader.readLine();
				st=new StringTokenizer(line);
				for(int j=0;j<M;j++){
					patterns[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			writer.write("Case #"+k+": ");
			if(lm.check(patterns, N, M))writer.write("YES");
			else writer.write("NO");
			writer.newLine();
			k++;
		}
		reader.close();
		writer.close();
	}
}
