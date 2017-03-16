import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class B {

	int MX = 3000;

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
		// try greedy
		// done?
		boolean perfect = true;
		for (int i=0; i<lv.length; i++) {
			if (lv[i].cnt != 2) {
				perfect = false;
				break;
			}
		}
		if (perfect) {
			return 0;
		}
		// try s2 first
		for (int i=0; i<lv.length; i++) {
			if (lv[i].cnt != 2) {
				if (p >= lv[i].s2) {
					int oldCnt = lv[i].cnt;
					lv[i].cnt = 2;
					return 1 + DFS(lv, p+2-oldCnt);
				}
			}
		}
		// no s2, try s1 with the highest s2
		int best = -1;
		for (int i=0; i<lv.length; i++) {
			if (lv[i].cnt == 0) {
				if (p >= lv[i].s1) {
					if (best == -1) {
						best = i;
					} else {
						if (lv[i].s2 > lv[best].s2) {
							best = i;
						}
					}
				}
			}
		}
		if (best == -1) {
			return MX;
		}
		lv[best].cnt = 1;
		return 1 + DFS(lv, p+1);
	}

	public String solve(Level[] lv) {
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
			b.parseFile("B-large");
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
