import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Treasure {
	
	private static int n;
	private static int[] init;
	private static int[] needs;
	private static int[][] contains;
	
	public static final void main(String[] params) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("Treasure.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("Treasure.out"));
		int count = Integer.parseInt(br.readLine().trim());
		for (int test = 0; test < count; test++) {
			String[] parts = br.readLine().split(" +");
			int k = Integer.parseInt(parts[0]);
			n = Integer.parseInt(parts[1]);
			init = new int[k];
			parts = br.readLine().split(" +");
			for (int i = 0; i < k; i++) init[i] = Integer.parseInt(parts[i]);
			needs = new int[n];
			contains = new int[n][];
			for (int i = 0; i < n; i++) {
				parts = br.readLine().split(" +");
				needs[i] = Integer.parseInt(parts[0]);
				contains[i] = new int[Integer.parseInt(parts[1])];
				for (int j = 0; j < contains[i].length; j++) {
					contains[i][j] = Integer.parseInt(parts[2 + j]);
				}
			}
			found = false;
			sol = new int[n];
			opened = new boolean[n];
			keyCount = new int[201];
			for (int key: init) keyCount[key]++;
			failed = new boolean[1<<n];
			rec(0, 0);
			bw.write("Case #" + (test+1) + ": " + (found ? ssol : "IMPOSSIBLE"));
			bw.newLine();
			System.out.println(test + 1);
			cnt = 0;
		}
		bw.close();
		br.close();
	}
	
	private static boolean found;
	private static int[] sol;
	private static String ssol;
	private static boolean[] opened;
	private static int[] keyCount;
	private static long cnt = 0;
	private static boolean[] failed;
	
	private static void rec(int k, int cfg) {
		if (found || failed[cfg]) return;
		cnt++;
		if (cnt % 100000 == 0) System.out.println(cnt);
		if (k == n) {
			found = true;
			ssol = "" + (sol[0] + 1);
			for (int i = 1; i < n; i++) ssol += " " + (sol[i] + 1);
		} else {
			for (int i = 0; i < n; i++) if (!opened[i] && keyCount[needs[i]] > 0) {
				keyCount[needs[i]]--;
				sol[k] = i;
				opened[i] = true;
				for (int key: contains[i]) {
					keyCount[key]++;
				}
				rec(k + 1, cfg | (1 << i));
				for (int key: contains[i]) {
					keyCount[key]--;
				}
				opened[i] = false;
				keyCount[needs[i]]++;
			}
			failed[cfg] = true;
		}
	}

}
