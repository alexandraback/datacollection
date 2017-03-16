import java.util.*;

public class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();

		for (int caseNum = 1;  caseNum <= t; caseNum++) {
			int c = sc.nextInt();
			int d = sc.nextInt();
			int v = sc.nextInt();

			int vCount = 0;
			int dCount = d;
			boolean[] ds = new boolean[v + 1];
			boolean[] vs = new boolean[v + 1];
			vs[0] = true;
			for (int i = 0; i < d; i++) {
				int nextD = sc.nextInt();
				ds[nextD] = true;
				for (int j = v - nextD; j >= 0; j--) {
					if (vs[j] && !vs[j + nextD]) {
						vs[j + nextD] = true;
						vCount += 1;
					}
				}
			}

			for (int i = 0; i < v + 1 - d; i++) {
				if (solve(v, ds, dCount, vs, vCount, 0, i)) {
					System.out.printf("Case #%d: %d\n", caseNum, i);
					break;
				}
			}
		}
	}

	public static boolean solve(int v, boolean[] ds, int dCount, boolean[] vs, int vCount, int lastNewD, int limit) {
		if (limit == 0) {
			if (vCount == v) {
				return true;
			}
			else {
				return false;
			}
		}
		for (int i = lastNewD + 1; i < v + 1; i++) {
			boolean[] dsCopy = Arrays.copyOf(ds, ds.length);
			int dCountCopy = dCount;
			boolean[] vsCopy = Arrays.copyOf(vs, vs.length);
			int vCountCopy = vCount;

			if (!dsCopy[i]) {
				boolean isHelpful = false;
				for (int j = v - i; j >= 0; j--) {
					if (vsCopy[j] && !vsCopy[j + i]) {
						vsCopy[j + i] = true;
						vCountCopy += 1;
						isHelpful = true;
					}
				}
				if (isHelpful) {
					dsCopy[i] = true;
					if (solve(v, dsCopy, dCountCopy, vsCopy, vCountCopy, i, limit - 1)) {
						return true;
					}
				}
			}
		}

		return false;
	}
}
