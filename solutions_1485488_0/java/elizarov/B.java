package round1B;

import java.io.*;
import java.util.*;

/**
 * @author Roman Elizarov
 */
public class B {
	private static final int INF = Integer.MAX_VALUE / 2;

	public static void main(String[] args) throws IOException {
		new B().go();
	}

	Scanner in;
	PrintWriter out;

	private void go() throws IOException  {
		in = new Scanner(new File("src\\round1B\\b.in"));
		out = new PrintWriter(new File("src\\round1B\\b.out"));
		int t = in.nextInt();
		for (int tn = 1; tn <= t; tn++) {
			readCase();
			out.println("Case #" + tn + ": " + solveCase());
		}
		in.close();
		out.close();
	}

	int h0;
	int n;
	int m;
	int[][] a;
	int[][] b;

	void readCase() {
		h0 = in.nextInt();
		n = in.nextInt();
		m = in.nextInt();
		alloc();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = in.nextInt();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				b[i][j] = in.nextInt();
	}

	void alloc() {
		a = new int[n][m];
		b = new int[n][m];
	}

	static final int[] DX = new int[] { 1, 0, -1,  0 };
	static final int[] DY = new int[] { 0, 1,  0, -1 };

	boolean[][][] ok;
	int h1;
	int nm;
	int nm10;
	int nm100;

	boolean[] v;
	int[][] tBest;
	boolean[][] f;
	TreeSet<Dist> ss = new TreeSet<Dist>();

	double solveCase() {
		ok = new boolean[n][m][4];
		h1 = h0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				h1 = Math.min(h1, a[i][j] - 50);
				h1 = Math.min(h1, b[i][j] + 20 - 1);
				for (int k = 0; k < 4; k++) {
					int i2 = i + DX[k];
					int j2 = j + DY[k];
					ok[i][j][k] = i2 >= 0 && i2 < n && j2 >= 0 && j2 < m &&
						b[i][j] <= a[i2][j2] - 50 &&
						b[i2][j2] <= a[i2][j2] - 50 &&
						b[i2][j2] <= a[i][j] - 50;
				}
			}
		nm = n * m;
		nm10 = 10 * nm;
		nm100 = 100 * nm;
		int tMax = h0 - h1;
		v = new boolean[nm * (tMax + 101)];
		init(0, 0);
		int t = 0;
		while (t <= tMax) {
			int h = h0 - t;
			int p = t * nm;
			if (v[nm - 1 + p])
				return t / 10.0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					if (v[p]) {
						v[p + nm] = true;
						int d = h >= b[i][j] + 20 ? nm10 : nm100;
						for (int k = 0; k < 4; k++)
							if (ok[i][j][k]) {
								int i2 = i + DX[k];
								int j2 = j + DY[k];
								if (h <= a[i2][j2] - 50)
									v[p + d + DX[k] * m + DY[k]] = true;
							}
					}
					p++;
				}
			t++;
		}
		tBest = new int[n][m];
		for (int[] ar : tBest)
			Arrays.fill(ar, INF);
		for (t = tMax; t <= tMax + 100; t++) {
			int p = t * nm;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					if (v[p] && tBest[i][j] == INF)
						tBest[i][j] = t;
					p++;
				}
		}
		ss.clear();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ss.add(new Dist(i, j, tBest[i][j]));
		f = new boolean[n][m];
		while (!f[n - 1][m - 1]) {
			Dist head = ss.first();
			ss.remove(head);
			assert head.t < INF;
			int i = head.i;
			int j = head.j;
			f[i][j] = true;
			int tNext = head.t + 100;
			for (int k = 0; k < 4; k++)
				if (ok[i][j][k]) {
					int i2 = i + DX[k];
					int j2 = j + DY[k];
					if (tNext < tBest[i2][j2]) {
						ss.remove(new Dist(i2, j2, tBest[i2][j2]));
						tBest[i2][j2] = tNext;
						ss.add(new Dist(i2, j2, tNext));
					}
				}
		}
		return tBest[n - 1][m - 1] / 10.0;
	}

	private void init(int i, int j) {
		if (v[i * m + j])
			return;
		v[i * m + j] = true;
		for (int k = 0; k < 4; k++) {
			if (ok[i][j][k]) {
				int i2 = i + DX[k];
				int j2 = j + DY[k];
				if (h0 <= a[i2][j2] - 50)
					init(i2, j2);
			}
		}
	}

	static class Dist implements Comparable<Dist> {
		int i;
		int j;
		int t;

		Dist(int i, int j, int t) {
			this.i = i;
			this.j = j;
			this.t = t;
		}

		public int compareTo(Dist o) {
			int d = t - o.t;
			if (d != 0)
				return d;
			d = i - o.i;
			if (d != 0)
				return d;
			return j - o.j;
		}

		@Override
		public boolean equals(Object o) {
			if (this == o)
				return true;
			if (!(o instanceof Dist))
				return false;

			Dist dist = (Dist)o;

			if (i != dist.i)
				return false;
			if (j != dist.j)
				return false;
			if (t != dist.t)
				return false;

			return true;
		}

		@Override
		public int hashCode() {
			int result = i;
			result = 31 * result + j;
			result = 31 * result + t;
			return result;
		}
	}
}
