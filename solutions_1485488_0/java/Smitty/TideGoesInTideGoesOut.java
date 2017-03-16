import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.io.*;

public final class TideGoesInTideGoesOut {

	private final static String FILE_IN = TideGoesInTideGoesOut.class
			.getSimpleName() + ".in";
	private final static String FILE_OUT = TideGoesInTideGoesOut.class
			.getSimpleName() + ".out";

	public static final void main(final String[] args) throws Exception {
		final Scanner in = new Scanner(new File(FILE_IN));
		final PrintWriter out = new PrintWriter(FILE_OUT);
		final int testCnt = in.nextInt();
		for (int caseNum = 1; caseNum <= testCnt; ++caseNum) {

			final int h = in.nextInt();
			final int n = in.nextInt();
			final int m = in.nextInt();

			final int[][] c = new int[n][m];
			final int[][] f = new int[n][m];

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					c[i][j] = in.nextInt();
				}
			}

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					f[i][j] = in.nextInt();
				}
			}

			final int[][] d = new int[n][m];
			for (int i = 0; i < n; ++i) {
				Arrays.fill(d[i], Integer.MAX_VALUE);
			}

			d[0][0] = 0;
			final TreeSet<Record> heap = new TreeSet<TideGoesInTideGoesOut.Record>();
			heap.add(new Record(0, 0, 0));

			final int[] dx = { 0, 1, 0, -1 };
			final int[] dy = { 1, 0, -1, 0 };

			while (!heap.isEmpty()) {
				final Record r = heap.first();
				heap.remove(r);
				
//				System.out.println(String.format("%d-%d = %d", r.x, r.y, r.t));

				for (int q = 0; q < 4; ++q) {
					if (r.x + dx[q] >= 0 && r.x + dx[q] < n) {
						if (r.y + dy[q] >= 0 && r.y + dy[q] < m) {

							final int nx = r.x + dx[q];
							final int ny = r.y + dy[q];

							if (c[nx][ny] - f[nx][ny] < 50) {
								continue;
							}

							int waitTime = computeWaitTime(f[r.x][r.y], c[r.x][r.y], f[nx][ny], c[nx][ny], r.t, h);
							
							if (waitTime < 0){
								continue;
							}
							
							int arriveTime = r.t + waitTime;

							if (arriveTime != 0){
								if (h - arriveTime >= f[r.x][r.y] + 20){
									arriveTime += 10;
								}
								else {
									arriveTime += 100;
								}								
							}
							

							if (arriveTime < d[nx][ny]){
								
//								System.out.println(String.format("%d-%d -> %d-%d = %d", r.x ,r.y, nx, ny, arriveTime));
								
								heap.remove(new Record(nx, ny, d[nx][ny]));
								d[nx][ny] = arriveTime;
								heap.add(new Record(nx,ny, d[nx][ny]));
							}
						}
					}
				}
			}
			double result = d[n - 1][m - 1] / 10.0;
			out.println(String.format("Case #%d: %.1f", caseNum, result));
		}
		in.close();
		out.close();
	}

	private static final int computeWaitTime(int f0, int c0, int f1, int c1,
			int time, int h) {

		if (time >= h){
			if (canMove(f0, c0, f1, c1, 0)){
				return 0;
			}
			else {
				return -1;
			}
		}
		
		if (Math.min(c0, c1) - Math.max(f0, f1) < 50) {
			return -1;
		}

		int l = 0;
		int r = h - time;

		while (r - l > 1) {
			final int c = (l + r) / 2;
			if (canMove(f0, c0, f1, c1, c)) {
				l = c;
			} else {
				r = c;
			}
		}

		if (! canMove(f0, c0, f1, c1, l)) {
			return -1;
		}

		while (l + 1 <= h - time && canMove(f0, c0, f1, c1, l + 1)) {
			++l;
		}

		return h - time - l;
	}

	private static final boolean canMove(int f0, int c0, int f1, int c1, int h) {

		c0 = Math.max(c0, h);
		f0 = Math.max(f0, h);
		c1 = Math.max(c1, h);
		f1 = Math.max(f1, h);

		if (c0 - f0 < 50) {
			return false;
		}
		if (c1 - f1 < 50) {
			return false;
		}

		return f0 + 50 <= c1;
	}

	private static final class Record implements Comparable<Record> {

		int x, y, t;

		public Record(int x, int y, int t) {
			super();
			this.x = x;
			this.y = y;
			this.t = t;
		}

		@Override
		public int compareTo(Record o) {

			if (t != o.t) {
				return t - o.t;
			}
			if (x != o.x) {
				return x - o.x;
			}

			return y - o.y;
		}
	}
}
