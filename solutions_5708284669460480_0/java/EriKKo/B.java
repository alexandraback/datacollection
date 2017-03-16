import java.io.*;
import java.util.*;

public class B {
	
	static int K, L, S;
	static int[] count;
	static char[] target;
	static double[][] e;
	static int[][] best;
	static int[] backup;
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st;
		
		int T = Integer.parseInt(in.readLine());
		for (int test = 1; test <= T; test++) {
			st = new StringTokenizer(in.readLine());
			K = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());
			S = Integer.parseInt(st.nextToken());
			count = new int[26];
			for (char c : in.readLine().toCharArray()) {
				count[c-'A']++;
			}
			target = in.readLine().toCharArray();
			e = new double[S+1][L];
			best = new int[S+1][L];
			for (int i = 0; i <= S; i++) {
				Arrays.fill(best[i], -1);
			}
			for (int i = 0; i < L; i++) {
				best[S][i] = 0;
				e[S][i] = 0;
			}
			backup = new int[L+1];
			for (int i = 2; i <= L; i++) {
				for (int j = i-1; j > 0; j--) {
					boolean good = true;
					for (int k = 0; k < j; k++) {
						if (target[k] != target[i-j+k]) {
							good = false;
							break;
						}
					}
					if (good) {
						backup[i] = j;
						break;
					}
				}
			}
			solve(0, 0);
			out.println("Case #" + test + ": " + (best[0][0] - e[0][0]));
		}
		
		in.close();
		out.close();
	}
	
	static void solve(int pos1, int pos2) {
		if (best[pos1][pos2] != -1) return;
		boolean[] used = new boolean[26];
		best[pos1][pos2] = 0;
		e[pos1][pos2] = 0;
		int left = K;
		int pos22 = pos2;
		double p1 = 1;
		while (true) {
			int c = target[pos22] - 'A';
			if (count[c] > 0) {
				int npos2 = pos22+1;
				int nres = 0;
				if (npos2 == L) {
					npos2 = backup[npos2];
					nres++;
				}
				solve(pos1+1, npos2);
				best[pos1][pos2] = Math.max(best[pos1][pos2], nres + best[pos1+1][npos2]);
				if (!used[c]) {
					double p = ((double)count[c]) / left;
					e[pos1][pos2] += p1*p*(nres + e[pos1+1][npos2]);
					used[c] = true;
					left -= count[c];
					p1 *= 1-p;
				}
			}
			if (pos22 == 0) break;
			pos22 = backup[pos22];
		}
		solve(pos1+1, 0);
		best[pos1][pos2] = Math.max(best[pos1][pos2], best[pos1+1][0]);
		e[pos1][pos2] += e[pos1+1][0] * left / K;
//		System.err.println("Pos (" + pos1 + "," + pos2 + "): " + e[pos1][pos2]);
	}
}
