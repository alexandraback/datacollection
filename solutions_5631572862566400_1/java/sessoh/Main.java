import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("C.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("C.out"))));

		int T = Integer.parseInt(br.readLine());
		
		for (int t = 0; t < T; t++) {
			int N = Integer.parseInt(br.readLine());
			String[] str = br.readLine().split(" ");
			int[] F = new int[N];
			int[][] chain = new int[N][N];
			HashSet<Integer>[] prev = new HashSet[N];
			for (int i = 0; i < N; i++) {
				F[i] = Integer.parseInt(str[i])-1;
				prev[i] = new HashSet<Integer>();
			}
			int answer1 = 0;
			for (int i = 0; i < N; i++) {
				boolean[] used = new boolean[N];
				int o = i;
				int count = 0;
				while (!used[o]) {
					count++;
					used[o] = true;
					int n = F[o];
					prev[n].add(o);
					chain[n][o] = Math.max(chain[n][o], count); 
					o = n;
				}
				if (o == i) answer1 = Math.max(answer1, count);
			}
			int answer2 = 0;
			for (int i = 0; i < N; i++) {
				int j = F[i];
				if (i == F[j]) {
					int counti = 0;
					for(int o : prev[i]) {
						if (o != j) counti = Math.max(counti, chain[i][o]);
					}
					int countj = 0;
					for(int o : prev[j]) {
						if (o != i) countj = Math.max(countj, chain[j][o]);
					}
					answer2 += counti + countj + 2;
				}
			}
			
			pw.println("Case #"+(t+1)+": "+Math.max(answer1, answer2/2));
			pw.flush();
		}
		
		pw.close();
		br.close();
	}
}
