import java.io.File;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ProblemB {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("B-small.in"));
		PrintStream out = new PrintStream("B-small.out");
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int N = in.nextInt();
			int[][] slips = new int[2*N-1][N];
			for (int slip = 0; slip < 2*N-1; slip++) {
				for (int i = 0; i < N; i++) {
					slips[slip][i] = in.nextInt();
				}
			}
			int[] res = solve(slips);
			out.printf("Case #%d:", caseNum);
			for (int i : res) {
				out.printf(" %d", i);
			}
			out.println();
		}
	}
	
	private static int[] solve(int[][] slips) {
		int N = slips[0].length;
		for (int i = 0; i < slips.length; i++) {
			int[] res = pick(slips, 1 << i, new int[N][], slips[i], 0, 0);
			if (res == null) {
				res = pick(slips, 1 << i, new int[N][], slips[i], 1, 0);
			}
			if (res != null) {
				return res;
			}
		}
		return null;
	}
	
	private static int[] pick(int[][] slips, int used, int[][] cur, int[] slip, int pos, int index) {
		int N = slips[0].length;
		if (index == N) {
			Set<Integer> unknown = new HashSet<>();
			for (int column = 0; column < N; column++) {
				if (column == pos) continue;
				boolean found = false;
				for (int i = 0; i < slips.length; i++) {
					if ((used & (1 << i)) != 0) continue;
					boolean valid = true;
					for (int j = 0; j < N; j++) {
						if (cur[j][column] != slips[i][j]) {
							valid = false;
							break;
						}
					}
					if (valid) {
						used = used | (1 << i);
						found = true;
						break;
					}
				}
				if (!found) {
					unknown.add(column);
				}
			}
			if (unknown.size() > 1) return null;
			int column = unknown.iterator().next();
			int[] res = new int[N];
			for (int i = 0; i < N; i++) {
				res[i] = cur[i][column];
			}
			return res;
		}
		
		for (int i = 0; i < slips.length; i++) {
			if ((used & (1 << i)) != 0) continue;
			if (slip[index] != slips[i][pos]) continue;
			cur[index] = slips[i];
			int[] res = pick(slips, used | (1 << i), cur, slip, pos, index + 1);
			if (res != null) {
				return res;
			}
		}
		
		return null;
	}
}
