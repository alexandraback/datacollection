package codejam.dance;

public class DanceSolver {

	public DanceSolver() {
	}

	public String solve(String line) {

		String[] ss = line.split(" ");

		int n = Integer.parseInt(ss[0]);
		int s = Integer.parseInt(ss[1]);
		int p = Integer.parseInt(ss[2]);

		int yes = 0, no = 0, surpPoss = 0;
		for (int i = 0; i < n; i++) {
			int t = Integer.parseInt(ss[3 + i]);
			if (t >= p + 2 * Math.max(p - 1, 0)) {
				yes++;
			}
			else if (t >= p + 2 * Math.max(p - 2, 0)) {
				surpPoss++;
			}
			else {
				no++;
			}
		}

		int ans = yes + Math.min(s, surpPoss);
		return "" + ans;
	}
}
