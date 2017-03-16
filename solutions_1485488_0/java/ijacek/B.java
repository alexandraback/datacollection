package R1B;

import java.io.*;
import java.util.*;

public class B {

	static int[] dx = {-1, 0, 1, 0,};
	static int[] dy = {0, 1, 0, -1,};

	static class Cell {

		int C;
		int F;
		boolean f;
		double t = Double.MAX_VALUE;

		public Cell(int C) {
			this.C = C;
		}

		boolean sp() {
			return C >= F;
		}

		void up(double dt) {
			if ( dt < t )
				t = dt;
		}

		boolean set() {
			return t < Double.MAX_VALUE;
		}
	}

	static class Coor {

		int x;
		int y;

		public Coor(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static boolean check(int x, int y) {
		if ( x < 0 )
			return false;
		if ( y < 0 )
			return false;
		if ( x >= N )
			return false;
		if ( y >= M )
			return false;
		return true;
	}

	static void add(Coor c, Set<Coor> t) {
		for (int i = 0; i < 4; i++) {
			int nx = c.x + dx[i];
			int ny = c.y + dy[i];
			if ( !check(nx, ny) )
				continue;
			if ( C[nx][ny].f )
				continue;
			t.add(new Coor(nx, ny));
		}
	}

	static double go(int sx, int sy, Coor d) {
		Cell sc = C[sx][sy];
		Cell dc = get(d);
		if ( !dc.sp() )
			return -1;
		if ( sc.C < dc.F )
			return -1;
		if ( sc.F > dc.C )
			return -1;

		double t = sc.t;
		double h = H - 10 * t;
		if ( (dc.C - h) >= 0.0 )
			return t;
		return (H - dc.C) / 10.0;
	}

	private static void update(Coor c) {
		for (int i = 0; i < 4; i++) {
			int nx = c.x + dx[i];
			int ny = c.y + dy[i];
			if ( !check(nx, ny) )
				continue;
			if ( !C[nx][ny].f )
				continue;
			double d = go(nx, ny, c);
			if ( d < 0.0 )
				continue;
			double tran = 0;
			if ( d > 0.0 ) {
				tran = 1;
				double h = H - 10 * d;
				if ( (h - C[nx][ny].F) < 20 )
					tran = 10;
			}
			get(c).up(d + tran);
		}
	}

	static Cell get(Coor c) {
		return C[c.x][c.y];
	}
	static int N;
	static int M;
	static int H;
	static Cell C[][];

	private static void solve(int TC) {
		H = ni();
		N = ni();
		M = ni();
		C = new Cell[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				C[i][j] = new Cell(ni() - 50);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				C[i][j].F = ni();
			}
		}

		C[0][0].f = true;
		C[0][0].t = 0;
		Set<Coor> todo = new HashSet<Coor>();
		add(new Coor(0, 0), todo);
		boolean rem;
		do {
			rem = false;
			double min = Double.MAX_VALUE;
			Coor minc = null;
			for (Coor co : todo) {
				update(co);
				if ( get(co).t < min ) {
					min = get(co).t;
					minc = co;
				}
			}
			if ( minc != null ) {
				todo.remove(minc);
				rem = true;
				get(minc).f = true;
				add(minc, todo);
			}
		} while (rem);

		out.println(String.format("Case #%d: %.6f", TC, C[N - 1][M - 1].t));
	}
	private static Scanner sc;
	private static PrintStream out;

	public static void main(String[] args) throws FileNotFoundException, IOException {
		Locale.setDefault(Locale.ENGLISH);

		String file = "tst/R1B/B.sm";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		int TC = ni();
		for (int i = 1; i <= TC; i++) {
			solve(i);
		}
	}

	private static int ni() {
		return sc.nextInt();
	}
}
