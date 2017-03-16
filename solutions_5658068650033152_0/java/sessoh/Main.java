import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("C.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("C.out"))));

		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			String[] str = br.readLine().split(" ");
			int N = Integer.parseInt(str[0]);
			int M = Integer.parseInt(str[1]);
			int K = Integer.parseInt(str[2]);
			pw.println("Case #"+(t+1)+": "+analyze(N, M, K));
			pw.flush();
		}

		pw.close();
		br.close();
	}
	
	private static int analyze(final int N, final int M, final int K) {
		int best = Integer.MAX_VALUE;
		for (int i = 0; i < (1<<(N*M)); i++) {
			int score = 0;
			for (int j = 0; j < N*M; j++) if ((i&(1<<j)) != 0) score++;
			if (score != K) continue;
			for (int y = 1; y < N-1; y++) for (int x = 1; x < M-1; x++) {
				if ((i&(1<<(y*M+x)))!=0 && (i&(1<<(y*M+x-1)))!=0 && (i&(1<<(y*M+x+1)))!=0 && (i&(1<<((y-1)*M+x)))!=0 && (i&(1<<((y+1)*M+x)))!=0) score--; 
			}
			if (best > score) best = score;
		}
		return best;
	}
	
}
