import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Formatter;
import java.util.Scanner;
import java.util.Stack;

public class A {

	int T;
	int t = 1;
	String[] out;

	public A() throws FileNotFoundException {
		Scanner sc = new Scanner(new File("A-small-attempt1.in"));
		T = sc.nextInt();
		sc.nextLine();
		out = new String[T];
		int[][] s = null;
		while (sc.hasNext()) {
			int N = sc.nextInt();
			s = new int[N][];

			for (int i = 0; i < N; i++) {
				int M = sc.nextInt();
				s[i] = new int[M];
				for (int j = 0; j < s[i].length; j++) {
					s[i][j] = sc.nextInt();
				}
			}

			calc(s);

			t++;
		}

		PrintWriter pw = new PrintWriter(new File("outA.txt"));
		for (String a : out) {
			pw.println(a);
		}
		pw.close();
	}

	private void calc(int[][] s) {

		boolean yes = false;
		for (int i = 0; i < s.length && !yes; i++) {
			int[] ex = new int[s.length];
			DPS(s, i, ex);
			for (int e : ex) {
				if (e >= 2) {
					yes = true;
				}
			}
		}
		if (yes) {
			out[t - 1] = "Case #" + t + ": Yes";
		} else {
			out[t - 1] = "Case #" + t + ": No";
		}

	}

	private void DPS(int[][] s, int a, int[] ex) {
		Stack<Integer> S = new Stack<Integer>();
		boolean[] vis = new boolean[s.length];
		S.push(a);
		while (!S.isEmpty()) {
			int u = S.pop();
			if (!vis[u]) {
				vis[u] = true;
				for (int i = 0; i < s[u].length; i++) {
					// each unvisited neighbour w of u
					ex[s[u][i] - 1]++;
					S.push(s[u][i] - 1);
				}
			}
		}
	}

	public void calcOut() {

	}

	public static void main(String[] args) {
		try {
			new A();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
