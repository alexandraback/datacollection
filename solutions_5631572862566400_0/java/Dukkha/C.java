import java.io.*;
import java.util.*;

public class C {
	static class Kid {
		ArrayList<Kid> list = new ArrayList<>();
		boolean visited = false;
		Kid bff = null;
		int ibff = -1;
		int cnt = 1;
		void path() {
			visited = true;
			for (Kid k : list)
				if (!k.visited && !(k.bff == this && this.bff == k)) {
					k.path();
					cnt = Math.max(cnt, k.cnt + 1);
				}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			Kid[] kk = new Kid[n];
			for (int i = 0; i < n; i++)
				kk[i] = new Kid();
			for (int i = 0; i < n; i++) {
				int j = Integer.parseInt(st.nextToken()) - 1;
				kk[i].bff = kk[j];
				kk[i].ibff = j;
				kk[j].list.add(kk[i]);
			}
			int[] max1 = new int[n];
			int[] cycle = new int[n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)
					kk[j].visited = false;
				kk[i].visited = true;
				cycle[i] = 1;
				Kid l;
				for (l = kk[i].bff; !l.visited; l = l.bff) {
					l.visited = true;
					cycle[i]++;
				}
				if (l != kk[i])
					cycle[i] = 0;
				for (int j = 0; j < n; j++) {
					kk[j].visited = false;
					kk[j].cnt = 1;
				}
				kk[i].path();
				max1[i] = 0;
				for (Kid k : kk[i].list)
					if (!(k == kk[i].bff && k.bff == kk[i]) && max1[i] < k.cnt)
						max1[i] = k.cnt;
			}
			int max = 0;
			for (int i = 0; i < n; i++) {
				if (cycle[i] > 0) {
					int cnt = cycle[i] + max1[i];
					if (max < cnt)
						max = cnt;
				}
			}
			for (int i = 0; i < n; i++) {
				if (kk[i].bff.bff == kk[i]) {
					int cnt = 2 + max1[kk[i].ibff] + max1[i];
					if (max < cnt)
						max = cnt;
				}
			}
			pw.println("Case #" + t + ": " + max);
		}
		pw.close();
	}
}
