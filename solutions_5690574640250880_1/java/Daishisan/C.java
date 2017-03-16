import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class C {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numTests = in.nextInt();
		for (int test = 1; test <= numTests; ++test) {
			System.out.println("Case #" + test + ":");
			int r = in.nextInt();
			int c = in.nextInt();
			int m = in.nextInt();
			boolean possib = false;
			if (c == 1) {
				System.out.println('c');
				for (int i = 0; i < r - m - 1; ++i)
					System.out.println('.');
				for (int i = 0; i < m; ++i)
					System.out.println('*');
			} else if (r == 1) {
				System.out.print('c');
				for (int i = 0; i < c - m - 1; ++i)
					System.out.print('.');
				for (int i = 0; i < m; ++i)
					System.out.print('*');
				System.out.println();
			} else if (m == r*c - 1) {
				for (int i = 0; i < r; ++i) {
					for (int j = 0; j < c; ++j)
						System.out.print((i == 0 && j == 0) ? 'c' : '*');
					System.out.println();
				}
			} else {
				for (int i = 2; i <= r; ++i) {
					boolean[] seen = new boolean[r*c + 1];
					int[][] state = new int[r*c + 1][2];
					seen[2*i] = true;
					state[2*i][0] = -1;
					state[2*i][1] = i;
					for (int j = 2; j < c; ++j)
						for (int base = r*c; base >= 2*i; --base)
							for (int k = 2; k <= i; ++k)
								if (base + k <= r*c && seen[base] && !seen[base + k]) {
									seen[base + k] = true;
									state[base + k][0] = base;
									state[base + k][1] = k;
								}
					int desired = r*c - m; 
					if (seen[desired]) {
						possib = true;
						ArrayList<Integer> vals = new ArrayList<Integer>();
						int curr = desired;
						while (curr != -1) {
							vals.add(state[curr][1]);
							curr = state[curr][0];
						}
						vals.add(i);
						Collections.sort(vals);
						Collections.reverse(vals);
						char[][] ans = new char[r][c];
						for (int j = 0; j < r; ++j)
							for (int k = 0; k < c; ++k)
								ans[j][k] = '*';
						for (int k = 0; k < c; ++k)
							if (k < vals.size())
								for (int j = 0; j < vals.get(k); ++j)
									ans[j][k] = '.';
						ans[0][0] = 'c';
						for (int j = 0; j < r; ++j) {
							for (int k = 0; k < c; ++k)
								System.out.print(ans[j][k]);
							System.out.println();
						}
						break;
					}
				}
				if (!possib)
					System.out.println("Impossible");
			}
		}
	}

}
