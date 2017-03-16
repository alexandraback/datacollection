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
			BufferedReader br = new BufferedReader(new FileReader(new File("D.in")));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("D.out"))));

			int T = Integer.parseInt(br.readLine());
			for (int i = 0; i < T; i++) {
				String[] param = br.readLine().split(" ");
				int K = Integer.parseInt(param[0]);
				int N = Integer.parseInt(param[1]);
				pw.flush();
				System.out.println(" "+i+":"+K+" "+N);
				int[] FK = new int[K];
				param = br.readLine().split(" ");
				for (int j = 0; j < K; j++) FK[j] = Integer.parseInt(param[j])-1;
				int[] RK = new int[N];
				int[][] GK = new int[N][];
				for (int j = 0; j < N; j++) {
					param = br.readLine().split(" ");
					RK[j] = Integer.parseInt(param[0])-1;
					int kn = Integer.parseInt(param[1]);
					GK[j] = new int[kn];
					for (int k = 0; k < kn; k++) GK[j][k] = Integer.parseInt(param[k+2])-1;
				}
				int[] answer = analyze(K, N, FK, RK, GK);
				pw.print("Case #"+(i+1)+":");
				if (answer == null) pw.println(" IMPOSSIBLE");
				else {
					for (int j = 0; j < answer.length; j++) pw.print(" "+(answer[j]+1));
					pw.println();
				}
			}
			
			pw.close();
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
			return;
		}
	}
	
	private static int[] analyze(int K, int N, int[] FK, int[] RK, int[][] GK) {

		int[] keycheck = new int[200];
		for (int i = 0; i < K; i++) keycheck[FK[i]]++;
		for (int i = 0; i < N; i++) {
			keycheck[RK[i]]--;
			for (int j = 0; j < GK[i].length; j++) keycheck[GK[i][j]]++;
		}
		for (int i = 0; i < keycheck.length; i++) if (keycheck[i] < 0) return null;
		
		int[][] keychest = new int[200][400];
		int[] keycount = new int[200];
		for (int i = 0; i < N; i++) keychest[RK[i]][keycount[RK[i]]++] = i;
		boolean[] pass = new boolean[N];
		int[] path = new int[N];
		int pathbottom = 0;
		for (int i = 0; i < FK.length; i++) {
			for (int j = 0; j < keycount[FK[i]]; j++) {
				if (!pass[keychest[FK[i]][j]]) {
					pass[keychest[FK[i]][j]] = true;
					path[pathbottom++] = keychest[FK[i]][j];
				}
			}
		}
		int pathtop = 0;
		while (pathtop < pathbottom) {
			int n = path[pathtop++];
			for (int i = 0; i < GK[n].length; i++) {
				for (int j = 0; j < keycount[GK[n][i]]; j++) {
					if (!pass[keychest[GK[n][i]][j]]) {
						pass[keychest[GK[n][i]][j]] = true;
						path[pathbottom++] = keychest[GK[n][i]][j];
					}
				}
			}
		}
		if (pathtop < N) return null;
		
		
		int[] keyring = new int[200];
		for (int i = 0; i < FK.length; i++) keyring[FK[i]]++;
		int[] answer = new int[N];
		boolean[] open = new boolean[N];
		int depth = 0;
		int now;
		while (depth >= 0) {
			now = answer[depth];
			if (now >= N) {
				int[] remainkey = new int[200];
				int remainkeycount = 0;
				for (int i = 0; i < N; i++) {
					if (!open[i]) { remainkey[RK[i]]++; remainkeycount++; }
				}
				while (true) {
					depth--;
					if (depth < 0) return null;
					now = answer[depth];
					open[now] = false;
					keyring[RK[now]]++;
					for (int i = 0; i < GK[now].length; i++) keyring[GK[now][i]]--;
					if (remainkey[RK[now]] > 0) {
						remainkey[RK[now]]--;
						remainkeycount--;
//						if (remainkeycount == 0) break;
						break;
					}
				}
				answer[depth]++;
			} else {
				if (!open[now] && keyring[RK[now]] > 0) {
					open[now] = true;
					keyring[RK[now]]--;
					for (int i = 0; i < GK[now].length; i++) keyring[GK[now][i]]++;
					depth++;
					if (depth == N) return answer;
					answer[depth] = 0;
				} else {
					answer[depth]++;
				}
			}
		}
		
		return null;
	}
}
