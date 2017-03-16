import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class MinesweeperMaster {

	static {
		try {
			String input = "C-large.in";
			System.setIn(new FileInputStream(input));
			String output = input.substring(0, input.lastIndexOf('.')) + ".out";
			System.setOut(new PrintStream(new FileOutputStream(output), true));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(0);
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		char map[][] = new char[52][52];
		int r, c, m, w, x, i, j, rp, cp, xp, off;
		boolean possible;
		for (int T = input.nextInt(), t = 1; t <= T; t++) {
			r = input.nextInt();
			c = input.nextInt();
			m = w = input.nextInt();
			x = r * c - m;
			for (i = 0; i < map.length; i++)
				Arrays.fill(map[i], '.');
			if (r == 1 || c == 1 || x == 1 || m == 0) {
				for (i = 1; i <= r; i++)
					for (j = 1; j <= c && w-- > 0; j++)
						map[i][j] = '*';
				map[r][c] = 'c';
				possible = true;
			} else if (r == 2 || c == 2) {
				if ((r != 2 || c != 2) && (x % 2 == 0 && x > 2)) {
					if (r == 2 && x > 2) {
						for (j = 1; j <= c; j++)
							for (i = 1; i <= r && w-- > 0; i++)
								map[i][j] = '*';
						map[r][c] = 'c';
					} else if (c == 2 && x > 2) {
						for (i = 1; i <= r; i++)
							for (j = 1; j <= c && w-- > 0; j++)
								map[i][j] = '*';
						map[r][c] = 'c';
					}
					possible = true;
				} else {
					possible = false;
				}
			} else if (x < 4 || x == 5 || x == 7) {
				possible = false;
			} else {
				rp = cp = 0;
				search: for (rp = 2; rp <= r; rp++)
					for (cp = 2; cp <= c; cp++)
						if (x == rp * cp)
							break search;
				if (x == rp * cp) {
					for (i = 1; i <= r; i++)
						for (j = 1; j <= c; j++)
							if (i <= r - rp || j <= c - cp)
								map[i][j] = '*';
					map[r][c] = 'c';
					possible = true;
				} else {
					search: for (rp = r - 2; rp >= 1; rp--)
						for (cp = c - 2; cp >= 1; cp--)
							if (m == rp * cp)
								break search;
					if (m == rp * cp) {
						for (i = 1; i <= r; i++)
							for (j = 1; j <= c; j++)
								if (i <= rp && j <= cp)
									map[i][j] = '*';
						map[r][c] = 'c';
						possible = true;
					} else if (x >= 2 * c && (m % c) <= c - 2) {
						for (i = 1; i <= r && w >= c; w -= c, i++)
							Arrays.fill(map[i], '*');
						for (j = 1; j <= w; j++)
							map[i][j] = '*';
						map[r][c] = 'c';
						possible = true;
					} else if (x >= 2 * r && (m % r) <= r - 2) {
						for (j = 1; j <= c && w >= r; w -= r, j++)
							for (i = 1; i <= r; i++)
								map[i][j] = '*';
						for (i = 1; i <= w; i++)
							map[i][j] = '*';
						map[r][c] = 'c';
						possible = true;
					} else {
						off = 0;
						possible = false;
						while (!possible && ++off <= r - 2) {
							xp = x + off;
							search: for (rp = r; rp >= 2 + off; rp--)
								for (cp = c; cp >= 4; cp--)
									if (xp == rp * cp)
										break search;
							if (xp == rp * cp && rp >= 2 + off && cp >= 4) {
								for (i = 1; i <= r; i++)
									for (j = 1; j <= c; j++)
										if (i <= r - rp || j <= c - cp)
											map[i][j] = '*';
								for (i = r - rp + 1; off > 0; i++, off--)
									map[i][c] = '*';
								map[r][c] = 'c';
								possible = true;
							} else {
								off = 1;
								int mp = m + off;
								search: for (rp = r - 2; rp >= 1; rp--)
									for (cp = c - 2; cp >= 1; cp--)
										if (mp == rp * cp)
											break search;
								if (mp == rp * cp) {
									for (i = 1; i <= r; i++)
										for (j = 1; j <= c; j++)
											if (i <= rp && j <= cp)
												map[i][j] = '*';
									for (i = rp; off > 0; i--, off--)
										map[i][cp] = '.';
									map[r][c] = 'c';
									possible = true;
								} else {
									possible = false;
								}
							}
						}
					}
				}
			}
			System.out.printf("Case #%d:\n", t);
			if (possible) {
				for (i = 1; i <= r; System.out.println(), i++)
					for (j = 1; j <= c; j++) {
						System.out.print(map[i][j]);
						if (map[i][j] == '*')
							m--;
					}
				if (m != 0)
					System.out.println("Illegal");
			} else {
				System.out.println("Impossible");
				// System.out.printf("%d * %d - %d = %d\n", r, c, m, x);
				// for (i = 0; i < r; i++, System.out.println())
				// for (j = 0; j < c; j++)
				// System.out.print(m-- > 0 ? '*' : '.');
			}
		}
		input.close();
	}
}
