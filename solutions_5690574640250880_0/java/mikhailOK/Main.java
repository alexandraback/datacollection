import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("c.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		C solver = new C();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class C {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int rows = in.nextInt();
        int cols = in.nextInt();
        int mines = in.nextInt();
        out.println("Case #" + testNumber + ":");
        char[][] answer = solveStupid(rows, cols, mines);
        if (answer == null) {
            out.println("Impossible");
        } else {
            for (char[] row: answer) {
                out.println(row);
            }
        }

    }

    char[][] solveStupid(int rows, int cols, int mines) {
        int all = rows * cols;

        int[][] graph = new int[rows * cols][];
        int[] temp = new int[20];
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                int cnt = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    int nx = x + dx;
                    if (nx < 0 || nx >= rows) {
                        continue;
                    }
                    for (int dy = -1; dy <= 1; dy++) {
                        int ny = y + dy;
                        if (ny < 0 || ny >= cols) {
                            continue;
                        }
                        temp[cnt++] = nx * cols + ny;
                    }
                }
                graph[x * cols + y] = Arrays.copyOf(temp, cnt);
            }
        }

        int[] ans = new int[rows * cols];

        for (int mask = 0; mask < 1 << all; mask++) {
            if (Integer.bitCount(mask) != mines) {
                continue;
            }
            for (int i = 0; i < rows * cols; i++) {
                ans[i] = (mask & (1 << i)) != 0 ? MINE : FREE;
            }
            if (isGood(graph, ans)) {
                char[][] ok = new char[rows][cols];
                boolean hadStart = false;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        int id = i * cols + j;
                        switch (ans[id]) {
                            case MINE:
                                ok[i][j] = '*';
                                break;
                            case FREE:
                                ok[i][j] = !hadStart ? 'c' : '.';
                                hadStart = true;
                                break;
                            case NEXT_TO_MINE:
                                ok[i][j] = mines == rows * cols - 1 ? 'c' : '.';
                                break;
                            default:
                                throw new AssertionError();
                        }
                    }
                }
                return ok;
            }
        }
        return null;
    }

    static final int FREE = 0, MINE = 1, NEXT_TO_MINE = 2;

    private boolean isGood(int[][] graph, int[] ans) {
        int n = ans.length;
        int minesCount = 0;
        for (int i = 0; i < n; i++) {
            if (ans[i] == MINE) {
                ++minesCount;
                for (int j : graph[i]) {
                    if (ans[j] == FREE) {
                        ans[j] = NEXT_TO_MINE;
                    }
                }
            }
        }
        if (minesCount >= n - 1) {
            return true;
        }
        int[] queue = new int[n];
        boolean[] was = new boolean[n];
        for (int start = 0; start < n; start++) {
            if (ans[start] != FREE) {
                continue;
            }
            int qh = 0, qt = 0;
            queue[qt++] = start;
            was[start] = true;
            while (qh < qt) {
                int u = queue[qh++];
                if (ans[u] == NEXT_TO_MINE) {
                    continue;
                }
                for (int v: graph[u]) {
                    if (ans[v] != MINE && !was[v]) {
                        was[v] = true;
                        queue[qt++] = v;
                    }
                }
            }
            return qt == n - minesCount;
        }
        return false;
    }
}

class InputReader {
    BufferedReader br;
    StringTokenizer st;

    public InputReader(InputStream stream) {
        br = new BufferedReader(new InputStreamReader(stream));
    }

    public String next() {
        return nextToken();
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            String line = null;
            try {
                line = br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

}

