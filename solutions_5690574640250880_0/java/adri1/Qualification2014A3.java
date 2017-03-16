package question;

import java.text.DecimalFormat;

import utils.FileTools;

public class Qualification2014A3 {
	public static void main(String[] args) {
		try {
			FileTools ft = new FileTools("C-small-attempt0.in");
			int T = Integer.parseInt(ft.in.readLine());
			String line;

			for (int i = 0; i < T; i++) {
				line = ft.in.readLine();
				String[] l = line.split(" ");
				int r = Integer.parseInt(l[0]);
				int c = Integer.parseInt(l[1]);
				int m = Integer.parseInt(l[2]);
				int a1 = 0;
				int a2 = 0;
				if (r < c) {
					a1 = r;
					a2 = c;
				} else {
					a1 = c;
					a2 = r;
				}
				boolean possible = false;
				int blank = r * c - m;
				if (blank == 1) {
					possible = true;
				} else {
					if (a1 == 1) {
						possible = true;
					} else {
						if (blank <= a1 * 2 + 1) {
							if (blank < 9) {// 无法在中心启动
								if (blank >= 4 && (blank - 4) % 2 == 0) {
									possible = true;
								}
							} else {
								possible = true;
							}
						} else {
							if (a1 == 2) {
								if (blank % 2 == 0) {
									possible = true;
								}
							} else {
								possible = true;
							}
						}
					}
				}
				ft.out.write("Case #" + (i + 1) + ":");
				ft.out.newLine();
				System.out.println("Case #" + (i + 1) + ":");
				if (possible) {
					char[][] res = new char[r][c];
					for (int y = 1; y <= r; y++) {
						for (int x = 1; x <= c; x++) {
							if (a1 == c) {
								res[y - 1][x - 1] = setRes(a1, a2, x, y, blank);
							} else {
								res[y - 1][x - 1] = setRes(a1, a2, y, x, blank);
							}
						}
					}
					for (int y = 0; y < r; y++) {
						ft.out.write(new String(res[y]));
						ft.out.newLine();
						System.out.println(new String(res[y]));
					}
				} else {
					ft.out.write("Impossible");
					ft.out.newLine();
					System.out.println("Impossible");
				}
			}

			ft.out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static Character setRes(int a1, int a2, int x, int y, int blank) {
		if (x == 1 && y == 1) {
			return 'c';
		}
		if (blank == 1) {
			return '*';
		}
		if (a1 == 1) {
			if (y <= blank) {
				return '.';
			} else {
				return '*';
			}
		}
		if (blank > 2 * a1 + 1) {
			if ((blank - 1) % a1 == 0) {
				if ((y - 1) * a1 + x <= blank+1&&((y - 1) * a1 + x!=blank-1)) {
					return '.';
				} else {
					return '*';
				}
			} else {
				if ((y - 1) * a1 + x <= blank) {
					return '.';
				} else {
					return '*';
				}
			}
		}
		if (blank % 2 == 0) {// 无法出现奇数解
			if (y <= 2 && x <= blank / 2) {
				return '.';
			} else {
				return '*';
			}
		} else {
			if (y <= 2 && x <= (blank - 3) / 2) {
				return '.';
			} else if (y == 3 && x <= 3) {
				return '.';
			} else {
				return '*';
			}
		}
	}
}
