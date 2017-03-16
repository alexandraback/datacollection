package r1_20122506;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class PA {
	static Scanner sc = new Scanner(new BufferedInputStream(System.in));
	static PrintWriter pw = new PrintWriter(
			new BufferedOutputStream(System.out));

	static int n;
	static int[][] edges;
	static boolean[] ck;
	static boolean result;

	public static void main(String[] args) {
		int test = sc.nextInt();
		for (int t = 1; t <= test; t++) {
			n = sc.nextInt();
			edges = new int[n][];
			getInput();
			ck = new boolean[n];
			result = false;
			for (int i = 0; i < n; i++) {
				ck = new boolean[n];
//				if (!ck[i])
					_try(i);
				if (result)
					break;
			}
			pw.println("Case #" + t + ": " + (result ? "Yes" : "No"));
		}
		pw.flush();
	}

	static void getInput() {
		for (int i = 0; i < n; i++) {
			int m = sc.nextInt();
			edges[i] = new int[m + 1];
			edges[i][0] = m;
			for (int j = 1; j <= m; j++)
				edges[i][j] = sc.nextInt() - 1;
		}
	}

	static void _try(int v) {
		if (result)
			return;
		for (int i = 1; i <= edges[v][0]; i++) {
			int u = edges[v][i];
			if (ck[u]) {
				result = true;
				break;
			}
			ck[u] = true;
			_try(u);
		}
	}
}
