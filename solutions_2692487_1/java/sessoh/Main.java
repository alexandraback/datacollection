import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(new File("A.in")));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("A.out"))));

			int T = Integer.parseInt(br.readLine());
			String[] param;
			for (int i = 0; i < T; i++) {
				param = br.readLine().split(" ");
				int A = Integer.parseInt(param[0]);
				int N = Integer.parseInt(param[1]);
				int[] M = new int[N];
				param = br.readLine().split(" ");
				for (int j = 0; j < N; j++) M[j] = Integer.parseInt(param[j]);
				pw.println("Case #"+(i+1)+": "+analyze(A, N, M));
			}
			
			pw.close();
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
			return;
		}
	}
	
	private static int analyze(int A, int N, int[] M) {
		if (A == 1) return N;

		int[] x = new int[N];
		int s = A;
		Arrays.sort(M);
		for (int i = 0; i < N; i++) {
			while(s <= M[i]) {
				x[i]++;
				s += s-1;
			}
			s += M[i];
		}
		int c = 0;
		int p = N;
		for (int i = N-1; i >= 0; i--) {
			c += x[i];
			if (c > N-i) p = i;
		}
		c = 0;
		for (int i = 0; i < p; i++) c += x[i];
		return c + N - p;
	}
}
