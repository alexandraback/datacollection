import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class B {

	int MX = 3000;
	int[] memo = new int[100000];

	public class Level {
		int s1;
		int s2;
		int cnt;
		public Level(String l) {
			String[] it = l.split("\\s+");
			s1 = Integer.parseInt(it[0]);
			s2 = Integer.parseInt(it[1]);
			cnt = 0;
		}
	}

	public int DFS(Level[] lv, int p) {
		int m = 0;
		for (int i=0; i<lv.length; i++) {
			m *= 3;
			m += lv[i].cnt;
		}
		if (memo[m] >= 0) {
			return memo[m];
		}
		int best = MX;
		boolean perfect = true;
		for (int i=0; i<lv.length; i++) {
			if (lv[i].cnt != 2) {
				perfect = false;
			}
			if (lv[i].s2 <= p) {
				if (lv[i].cnt < 2) {
					int oldCnt = lv[i].cnt;
					lv[i].cnt = 2;
					best = Math.min(best, 1 + DFS(lv, p+2-oldCnt));
					lv[i].cnt = oldCnt;
				}
			} else if (lv[i].s1 <= p) {
				if (lv[i].cnt < 1) {
					int oldCnt = lv[i].cnt;
					lv[i].cnt = 1;
					best = Math.min(best, 1 + DFS(lv, p+1-oldCnt));
					lv[i].cnt = oldCnt;
				}
			}
		}
		if (perfect) {
			best = 0;
		}
		return memo[m] = best;
	}

	public String solve(Level[] lv) {
		Arrays.fill(memo, -1);
		int cnt = DFS(lv, 0);
		if (cnt >= MX) {
			return "Too Bad\n";
		}
		return Integer.toString(cnt) + "\n";
	}

	////////////////////////////////////////
	// read input
	////////////////////////////////////////
	public String runInput(BufferedReader br) throws IOException {
		String[] items = br.readLine().trim().split("\\s+");
		int N = Integer.parseInt(items[0]);
		Level[] lv = new Level[N];
		for (int i=0; i<N; i++) {
			lv[i] = new Level(br.readLine().trim());
		}
		return solve(lv);
	}

	////////////////////////////////////////
	// main
	////////////////////////////////////////
	public static void main(String[] args) {
		B b = new B();
		try {
			b.parseFile("B-sample");
			b.parseFile("B-small-attempt1");
			//b.parseFile("B-large");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	////////////////////////////////////////
	// library
	////////////////////////////////////////
	public void parseFile(String filePrefix) throws IOException {
		String fileIn = filePrefix + ".in";
		String fileOut = filePrefix + ".out";

		BufferedReader br = new BufferedReader(new FileReader(fileIn));
		BufferedWriter bw = new BufferedWriter(new FileWriter(fileOut));

		int n = Integer.parseInt(br.readLine());
		for (int i=1; i<=n; i++) {
			String ret = "Case #" + i + ": ";
			ret += runInput(br);
			System.out.print(ret);
			bw.write(ret);
		}
		br.close();
		bw.close();
	}

}
