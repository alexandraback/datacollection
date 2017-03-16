package qualificationRound;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class P4 {
	public static String[] map;
	public static int x = 0, y = 0;

	public static int calGCD(int n, int m) {
		if (m == 0)
			return n;
		if (n == 0)
			return m;
		if (m < n) {
			int tmp = m;
			m = n;
			n = tmp;
		}
		while (n != 0) {
			int tmp = m % n;
			m = n;
			n = tmp;
		}
		return m;
	}

	public static boolean check(double unit_x, double unit_y, int step) {
		boolean ret = false;
		double start_x = x - 0.5, start_y = y - 0.5;
		double tmp_x = start_x, tmp_y = start_y;
		for (int i = 1; i <= step; ++i) {
			tmp_x += unit_x;
			tmp_y += unit_y;
			if (Math.abs(tmp_x - start_x) < 1E-9
					&& Math.abs(tmp_y - start_y) < 1E-9) {
				if (i == step)
					return true;
				else
					return false;
			}

			int int_x = (int) Math.round(tmp_x);
			int int_y = (int) Math.round(tmp_y);

			if (Math.abs(tmp_x - int_x) < 1E-9
					&& Math.abs(tmp_y - int_y) < 1E-9) {
				if (unit_x > 0)
					int_x = int_x + 1;
				if (unit_y > 0)
					int_y = int_y + 1;
				if (map[int_x].charAt(int_y) == '#') {
					if (map[int_x - (int) Math.signum(unit_x)].charAt(int_y) == '#'
							&& map[int_x].charAt(int_y
									- (int) Math.signum(unit_y)) == '#') {
						unit_x = -unit_x;
						unit_y = -unit_y;
					} else if (map[int_x - (int) Math.signum(unit_x)]
							.charAt(int_y) == '#') {
						unit_y = -unit_y;
					} else if (map[int_x].charAt(int_y
							- (int) Math.signum(unit_y)) == '#') {
						unit_x = -unit_x;
					} else {
						return false;
					}
				}
			} else if (Math.abs(tmp_x - int_x) < 1E-9) {
				if (unit_x > 0)
					int_x = int_x + 1;
				int_y = (int) Math.ceil(tmp_y);
				if (map[int_x].charAt(int_y) == '#')
					unit_x = -unit_x;
			} else if (Math.abs(tmp_y - int_y) < 1E-9) {
				if (unit_y > 0)
					int_y = int_y + 1;
				int_x = (int) Math.ceil(tmp_x);
				if (map[int_x].charAt(int_y) == '#')
					unit_y = -unit_y;
			}
		}

		return ret;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("D-large.in"));
		FileWriter fw = new FileWriter("out.txt");
		int t = Integer.parseInt(br.readLine());
		for (int c = 1; c <= t; ++c) {
			args = br.readLine().split(" ");
			int h = Integer.parseInt(args[0]);
			int w = Integer.parseInt(args[1]);
			int d = Integer.parseInt(args[2]);
			int ans = 0;
			map = new String[h];
			for (int j = 0; j < h; ++j) {
				map[j] = br.readLine();
				if (map[j].indexOf('X') != -1) {
					x = j;
					y = map[j].indexOf('X');
				}
			}

			for (int i = x - d; i <= x + d; ++i) {
				for (int j = y - d; j <= y + d; ++j) {
					int dx = x - i, dy = y - j;
					if (dx * dx + dy * dy > d * d || (dx == 0 && dy == 0))
						continue;

					double unit_x, unit_y;
					int gcd = calGCD(Math.abs(dx), Math.abs(dy));
					int step;
					if (dx != 0 && dy != 0)
						step = 2 * Math.abs(dx) * Math.abs(dy) /gcd;
					else if (dx == 0) {
						step = 2 * Math.abs(dy);
					} else {
						step = 2 * Math.abs(dx);
					}

					unit_x = (double) dx / step;
					unit_y = (double) dy / step;

					if (check(unit_x, unit_y, step))
						ans++;
				}
			}
			fw.append("Case #" + c + ": " + ans + "\n");
			System.out.println("Case #" + c + ": " + ans);
		}
		br.close();
		fw.close();
	}
}
