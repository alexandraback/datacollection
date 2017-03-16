package gcj2013Q;

import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run(new Scanner(System.in));
	}

	void run(Scanner sc) {
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}

	void solve(Scanner sc, int case_num) {
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] map = new int[n][m];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		int[] row = new int[n];
		for(int i = 0; i < n; i++) {
			int max = 0;
			for(int j = 0; j < m; j++) {
				if(max < map[i][j]) max = map[i][j];
			}
			row[i] = max;
		}
		int[] column = new int[m];
		for(int i = 0; i < m; i++) {
			int max = 0;
			for(int j = 0; j < n; j++) {
				if(max < map[j][i]) max = map[j][i];
			}
			column[i] = max;
		}

		boolean res = true;
		a:for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(row[i] != map[i][j] && column[j] != map[i][j]) {
					res = false;
					break a;
				}
			}
		}
		
		System.out.printf("Case #%d: %s\n", case_num, res ? "YES": "NO");
	}
}
