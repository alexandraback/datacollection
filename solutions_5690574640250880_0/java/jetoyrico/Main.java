import java.util.Scanner;
import java.io.IOException;
import java.util.Arrays;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Collection;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("tc/C-small-attempt0.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("tc/output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		C solver = new C();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class C {
	public void solve(int testNumber, Scanner in, PrintWriter out) {
		out.print(String.format("Case #%d:\n", testNumber));
		int R = in.nextInt();
		int C = in.nextInt();
		int M = in.nextInt();
		int S = R * C - M;
		if (M == 0) {
			char[][] map = new char[R][C];
			for (int i = 0; i < map.length; ++i) Arrays.fill(map[i], '.');
			map[0][0] = 'c';
			IOUtils.printTable(out, map);
			return;
		}
		if (S == 1) {
			char[][] map = new char[R][C];
			for (int i = 0; i < map.length; ++i) Arrays.fill(map[i], '*');
			map[0][0] = 'c';
			IOUtils.printTable(out, map);
			return;
		}
		if (R == 1 || C == 1) {
			char[][] map = new char[R][C];
			int s = 0;
			for (int i = 0; i < R; ++i)
				for (int j = 0; j < C; ++j)
					if (s++ < S) map[i][j] = '.';
					else map[i][j] = '*';
			map[0][0] = 'c';
			IOUtils.printTable(out, map);
			return;
		}
		// R >= 2 && C >= 2
		if (S == 2 || S == 3 || S == 5 || S == 7) {
			out.println("Impossible");
			return;
		}
		if (R == 2 || C == 2) {
			if (S % 2 == 1) {
				out.println("Impossible");
				return;
			} else {
				char[][] map = new char[R][C];
				int s = 0;
				if (R == 2) {
					for (int j = 0; j < C; ++j) {
						if (j < S / 2) map[0][j] = map[1][j] = '.';
						else map[0][j] = map[1][j] = '*';
					}
				} else {
					for (int i = 0; i < R; ++i) {
						if (i < S / 2) map[i][0] = map[i][1] = '.';
						else map[i][0] = map[i][1] = '*';
					}
				}
				map[0][0] = 'c';
				IOUtils.printTable(out, map);
				return;
			}
		}
		// R >= 3 && C >= 3
		if (S < 9) { // 4,6,8
			char[][] map = new char[R][C];
			for (int i = 0; i < map.length; ++i) Arrays.fill(map[i], '*');
			for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) map[i][j] = '.';
			if (S >= 6) map[0][2] = map[1][2] = '.';
			if (S >= 8) map[2][0] = map[2][1] = '.';
			map[0][0] = 'c';
			IOUtils.printTable(out, map);
			return;
		} else {
			char[][] map = new char[R][C];
			for (int i = 0; i < map.length; ++i) Arrays.fill(map[i], '*');
			if (S % 2 == 1) {
				for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) map[i][j] = '.';
				int s = 9;
				for (int i = 3; i < R; ++i) if (s < S) { map[i][0] = map[i][1] = '.'; s += 2; }
				for (int j = 3; j < C; ++j) if (s < S) { map[0][j] = map[1][j] = '.'; s += 2; }
				for (int i = 2; i < R; ++i)
					for (int j = 2; j < C; ++j)
						if (map[i][j] != '.' && s < S) {
							map[i][j] = '.';
							s++;
						}
			} else {
				int s = 0;
				for (int i = 0; i < R; ++i) if (s < S) { map[i][0] = map[i][1] = '.'; s += 2; }
				for (int j = 2; j < C; ++j) if (s < S) { map[0][j] = map[1][j] = '.'; s += 2; }
				for (int i = 2; i < R; ++i)
					for (int j = 2; j < C; ++j)
						if (s++ < S) {
							map[i][j] = '.';
						}
			}
			map[0][0] = 'c';
			IOUtils.printTable(out, map);
			return;
		}
	}

}

class IOUtils {

	public static void printTable(PrintWriter out, char[][] table) {
		for (char[] row : table)
			out.println(new String(row));
	}
}

