package qr2014C;

import java.util.*;
import java.io.*;

import static java.lang.System.*;
import static java.lang.Math.*;

public class Main {

//	Scanner sc = new Scanner(in);
	Scanner sc; 
	
	void run() {
		try {
			sc = new Scanner(new File("/Users/ryo/Documents/procon/C-small-attempt1.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int t = sc.nextInt();
		for (int z = 1; z <= t; z++) {
			int r = sc.nextInt(), c = sc.nextInt(), m = sc.nextInt();
			char[][] map = new char[r][c];
			int s = r * c;
			if (s - m == 1) {
				for (int i = 0; i < r; i++)
					for (int j = 0; j < c; j++)
						map[i][j] = '*';
				map[r-1][c-1] = 'c';
			} else if (r == 1) {
				Arrays.fill(map[0], '.');
				for (int i = 0; i < m; i++) map[0][i] = '*';
				map[r-1][c-1] = 'c';
			} else if (c == 1) {
				for (int i = 0; i < r; i++) map[i][0] = '.';
				for (int i = 0; i < m; i++) map[i][0] = '*';
				map[r-1][c-1] = 'c';
			} else if (s-m == 2 || s-m==3 || s-m== 5 || s-m==7) {
				out.printf("Case #%d:\nImpossible\n", z);
				continue;
			} else if (r == 2) {
				if ((s-m)%2 == 1) {
					out.printf("Case #%d:\nImpossible\n", z);
					continue;
				}
				for (int i = 0; i < r; i++)
					Arrays.fill(map[i], '.');
				int index = 0;
				while (m > 0) {
					map[0][index] = '*';
					map[1][index] = '*';
					m -= 2;
					index++;
				}
			} else if (c == 2) {
				if ((s-m)%2 == 1) {
					out.printf("Case #%d:\nImpossible\n", z);
					continue;
				}
				for (int i = 0; i < r; i++)
					Arrays.fill(map[i], '.');
				int index = 0;
				while (m > 0) {
					map[index][0] = '*';
					map[index][1] = '*';
					m -= 2;
					index++;
				}
			} else {
				for (int i = 0; i < r; i++)
					Arrays.fill(map[i], '.');
				int x = 0, y = 0;
				if (r < c) {
					I:for (int i = 0; c-i > r; i++) {
						for (int j = 0; j < r; j++) {
							map[j][i] = '*';
							m--;
							if (m == 0) {
								if (j == r-2) {
									map[j][i] = '.';
									map[0][i+1] = '*';
								}
								break I;
							}
						}
					}
					x = 0;
					y = c-r;
				} else if (c < r) {
					I:for (int i = 0; r-i > c; i++) {
						for (int j = 0; j < c; j++) {
							map[i][j] = '*';
							m--;
							if (m == 0) {
								if (j == c-2) {
									map[i][j] = '.';
									map[i+1][0] = '*';
								}
								break I;
							}
						}
					}
					x = r-c;
					y = 0;
				}
				if (m > 0) {
					I:for (int i = min(r, c); i >= 0; i--) {
						for (int j = 0; j < i; j++) {
							map[x+j][y] = '*';
							m--;
							if (m == 0) {
								if (x+j == r-2) {
									map[x+j][y] = '.';
									map[x][y+1] = '*';
								}
								break I;
							}
						}
						for (int j = 1; j < i; j++) {
							map[x][y+j] = '*';
							m--;
							if (m == 0) {
								if (y+j == c-2) {
									map[x][y+j] = '.';
									map[x+1][y+1] = '*';
								}
								break I;
							}
						}
						x++;
						y++;
					}
				}
			}
			map[r-1][c-1] = 'c';
			out.printf("Case #%d:\n", z);
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					out.print(map[i][j]);
				}
				out.println();
			}
		}
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}