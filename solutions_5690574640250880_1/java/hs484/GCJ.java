package gcj.Qual2014C;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class GCJ {

	public static void tr(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	public static void main(String[] args) throws Throwable {
		String pkg = new Object(){}.getClass().getEnclosingClass().getPackage().getName().replace('.', '/');
		String dir = "src/" + pkg;

		String filename = "";

//		if (true) { filename = "sample.in"; }
//		if (true) { filename = "C-small-attempt1.in"; }
		if (true) { filename = "C-large.in"; }

		Scanner sc = null;
		try {
			sc = new Scanner(new File(dir + "/" + filename));
		} catch (FileNotFoundException e) {
			tr(e.getMessage());
			return;
		}
		PrintWriter fout = new PrintWriter(new File(dir + "/" + filename + ".res"));

		GCJ obj = new GCJ();
		int TNO = sc.nextInt();
		for (int tno = 0; tno < TNO; tno++) {
			fout.write(String.format("Case #%d:\n", (tno + 1)));
			obj.solve(sc, fout);
			fout.flush();
		}
		fout.flush();
		fout.close();
	}

	void solve(Scanner sc, PrintWriter fout) {
		int R = sc.nextInt();
		int C = sc.nextInt();
		int M = sc.nextInt();
		int S = R * C - M;

		char[][] map = new char[R][C];
		fill(map, '*');

		if (S <= 0) {
			map = null;
		} else if (S == 1) {
			map[0][0] = 'c';
		} else if (R == 1) {
			for (int j = 0; j < S; j++) {
				map[0][j] = '.';
			}
			map[0][0] = 'c';
		} else if (C == 1) {
			for (int i = 0; i < S; i++) {
				map[i][0] = '.';
			}
			map[0][0] = 'c';
		} else if (M == 0) {
			fill(map, '.');
			map[0][0] = 'c';
		} else if (S <= 3 || S == 5 || S == 7) {
			map = null;
		} else if (S % 2 == 1 && (R == 2 || C == 2)) {
			map = null;
		} else {
			map[0][0] = 'c';
			map[0][1] = map[1][0] = map[1][1] = '.';
			S -= 4;
			if (S >= 2 && C >= 3) {
				S -= 2;
				map[0][2] = '.';
				map[1][2] = '.';
			}
			if (S >= 2 && R >= 3) {
				S -= 2;
				map[2][0] = '.';
				map[2][1] = '.';
			}
			for (int j = 3; j < C && S >= 2; j++) {
				S -= 2;
				map[0][j] = '.';
				map[1][j] = '.';
			}
			for (int i = 3; i < R && S >= 2; i++) {
				S -= 2;
				map[i][0] = '.';
				map[i][1] = '.';
			}
			for (int i = 2; i < R && S > 0; i++) {
				for (int j = 2; j < C && S > 0; j++) {
					map[i][j] = '.';
					S--;
				}
			}
		}

		if (map == null) {
			fout.write("Impossible\n");
		} else {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					fout.write(map[i][j]);
				}
				fout.write("\n");
			}
		}
	}
	void fill(char[][] map, char ch) {
		for (int i = 0; i < map.length; i++) Arrays.fill(map[i], ch);
	}
}
