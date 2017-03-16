package diamondinheritance;

import java.util.Arrays;

import template.Template;

public class DiamondInheritance extends Template {
	public static void main(String[] args) throws Exception {
		init("src/diamondinheritance/A-large");
		int lines = readInt();
		for (int i = 1; i <= lines; i++) {

			boolean result = false;
			int n = readInt();
			int[][] m = new int[n][];
			int[][] t = new int[n][n];
			for (int j = 0; j < n; j++) {
				int[] l = readIntArray();
				m[j] = new int[l[0]];
				for (int k = 0; k < m[j].length; k++) {
					m[j][k] = l[k + 1] - 1;
					t[j][m[j][k]]++;
				}
			}

			// boolean changed = false;
			// a: do {
			// toString(t);
			// changed = false;
			// for (int x = 0; x < n; x++) {
			// for (int y = 0; y < n; y++) {
			// if (x != y)
			// for (int z = 0; z < n; z++) {
			// if (z != x && z != y)
			// if (t[x][y] > 0 && t[y][z] > 0) {
			// t[x][z]++;
			// if (t[x][z] == 1)
			// changed = true;
			// if (t[x][z] > 1) {
			// result = true;
			// break a;
			// }
			// }
			// }
			// }
			// }
			// } while (changed);

			result = find(m);
			write("Case #" + i + ": " + (result ? "Yes" : "No"));
		}
	}

	public static boolean find(int start, int[][] m, int[] found) {
		for (int i = 0; i < m[start].length; i++) {
			found[m[start][i]]++;
			if (found[m[start][i]] > 1)
				return true;
			if (find(m[start][i], m, found))
				return true;
		}
		return false;
	}

	public static boolean find(int[][] t) {
		for (int i = 0; i < t.length; i++) {
			if (find(i, t, new int[t.length]))
				return true;
		}
		return false;
	}

	public static void toString(int[][] t) {
		for (int i = 0; i < t.length; i++)
			System.out.println(Arrays.toString(t[i]));
		System.out.println();
	}
}
