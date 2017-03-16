import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.util.Arrays;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    int DX[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int DY[] = {0, 1, 1, 1, 0, -1, -1, -1};

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int r = in.nextInt();
        int c = in.nextInt();
        int m = in.nextInt();

        char[][] map = new char[r][c];
        for (char[] row : map) {
            Arrays.fill(row, '.');
        }
        out.printf("Case #%d:\n", testNumber);
        if (!search(map, 0, 0, m)) {
            out.println("Impossible");
        } else {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    out.print(map[i][j]);
                }
                out.println();
            }
        }
    }

    private boolean search(char[][] map, int i, int j, int m) {
        int r = map.length;
        int c = map[0].length;
        if (i == r) {
            return m == 0 && oneClick(map);
        }
        if (j == c) {
            return search(map, i + 1, 0, m);
        }
        if (m > (r - i - 1) * c + c - j - 1) {
            return false;
        }

        if (search(map, i, j + 1, m)) {
            return true;
        }
        if (m > 0) {
            map[i][j] = '*';
            if (search(map, i, j + 1, m - 1)) {
                return true;
            }
            map[i][j] = '.';
        }
        return false;
    }

    private boolean oneClick(char[][] map) {
        int r = map.length;
        int c = map[0].length;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (map[i][j] == '.') {
                    if (tryClick(map, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean tryClick(char[][] map, int i, int j) {
        int r = map.length;
        int c = map[0].length;
        boolean[][] revealed = new boolean[r][c];
        for (boolean[] row : revealed) {
            Arrays.fill(row, false);
        }

        revealed[i][j] = true;
        bloodFill(map, revealed, i, j);

        for (int x = 0; x < r; ++x) {
            for (int y = 0; y < c; ++y) {
                if (map[x][y] == '.' && !revealed[x][y]) {
                    return false;
                }
            }
        }
        map[i][j] = 'c';
        return true;
    }

    private void bloodFill(char[][] map, boolean[][] revealed, int i, int j) {
        int r = map.length;
        int c = map[0].length;

        int count = 0;
        for (int d = 0; d < DX.length; ++d) {
            int x = i + DX[d];
            int y = j + DY[d];
            if (0 <= x && x < r && 0 <= y && y < c && map[x][y] == '*') {
                ++count;
            }
        }
        if (count == 0) {
            for (int d = 0; d < DX.length; ++d) {
                int x = i + DX[d];
                int y = j + DY[d];
                if (0 <= x && x < r && 0 <= y && y < c && !revealed[x][y]) {
                    revealed[x][y] = true;
                    bloodFill(map, revealed, x, y);
                }
            }
        }
    }
}

