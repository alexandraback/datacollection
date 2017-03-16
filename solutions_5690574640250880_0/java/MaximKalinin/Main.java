import java.io.StreamTokenizer;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.Collection;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		TokenizerReader in = new TokenizerReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    final static int MINE = 42;

    int[][] map;
    boolean[][] visited;

    public void solve(int testNumber, TokenizerReader in, PrintWriter out) {
        out.println("Case #" + testNumber + ":");
        int R = in.nextInt(), C = in.nextInt(), M = in.nextInt();

        if (M == R * C - 1) {
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j)
                    out.print(i == 0 && j == 0 ? 'c' : '*');
                out.println();
            }
            return;
        }


        map = new int[R][C];

        for (long mask = 0; mask < 1L << (R * C); ++mask)
            if (Long.bitCount(mask) == M) {
                fillMap(R, C, mask);
                countNeighbors();
                outer:
                for (int i = 0; i < R; ++i)
                    for (int j = 0; j < C; ++j)
                        if (map[i][j] == 0) {
                            visited = new boolean[R][C];
                            dfs(i, j);
                            break outer;
                        }
                if (check()) {
                    printMap(out);
                    return;
                }
            }

        out.println("Impossible");
    }

    private boolean check() {
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[i].length; j++) {
                if (map[i][j] == 0 && !visited[i][j])
                    return false;
                else if (map[i][j] != MINE && map[i][j] > 0) {
                    boolean hasNeighbor0 = false;
                    for (Pair<Integer> cell : BoardUtil.getSideAndAngleNeighbors(i, j, map.length, map[i].length)) {
                        int i1 = cell.first, j1 = cell.second;
                        if (map[i1][j1] == 0) {
                            hasNeighbor0 = true;
                            break;
                        }
                    }
                    if (!hasNeighbor0)
                        return false;
                }
            }
        }
        return true;
    }

    private void dfs(int i, int j) {
        if (i < 0 || i >= map.length || j < 0 || j >= map[i].length)
            return;
        if (map[i][j] != 0 || visited[i][j])
            return;
        visited[i][j] = true;
        for (Pair<Integer> cell : BoardUtil.getSideAndAngleNeighbors(i, j, map.length, map[i].length))
            dfs(cell.first, cell.second);
    }

    private void countNeighbors() {
        for (int i = 0; i < map.length; ++i)
            for (int j = 0; j < map[i].length; ++j)
                if (map[i][j] == MINE)
                    for (Pair<Integer> cell : BoardUtil.getSideAndAngleNeighbors(i, j, map.length, map[i].length)) {
                        int i1 = cell.first, j1 = cell.second;
                        if (map[i1][j1] != MINE)
                            ++map[i1][j1];
                    }
    }

    private void printMap(PrintWriter out) {
        boolean clicked = false;
        for (int[] ii : map) {
            for (int i : ii) {
                if (i == MINE)
                    out.print('*');
                else if (i > 0 || clicked)
                    out.print('.');
                else {
                    clicked = true;
                    out.print('c');
                }
            }
            out.println();
        }

    }

    private void fillMap(int r, int c, long mask) {
        for (int i = 0, b = 0; i < r; ++i)
            for (int j = 0; j < c; ++j, ++b)
                map[i][j] = (mask & 1L << b) > 0 ? MINE : 0;
    }
}

class TokenizerReader extends StreamTokenizer {
    public TokenizerReader(InputStream in) {
        super(new BufferedReader(new InputStreamReader(in)));
        defaultConfig();
    }

    public String nextString() {
        try {
            nextToken();
        } catch (IOException e) {
            throw new RuntimeException("nextString: exception in line " + lineno(), e);
        }
        return sval;
    }

    public String next() {
        return nextString();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public void defaultConfig() {
        resetSyntax();
        wordChars(33, 126);
        whitespaceChars(0, ' ');
    }

}

class Pair<T> {
    public final T first, second;

    public Pair(T first, T second) {
        this.first = first;
        this.second = second;
    }

    public int hashCode() {
        return first.hashCode() * 31013 + second.hashCode();
    }

    public boolean equals(Object obj) {
        Pair<T> p = (Pair<T>) obj;
        return first.equals(p.first) && second.equals(p.second);
    }
}

class BoardUtil {
    public static Collection<Pair<Integer>> getSideAndAngleNeighbors(int r, int c, int R, int C) {
        Collection<Pair<Integer>> result = new ArrayList<>();
        for (int di = -1; di <= 1; ++di)
            for (int dj = -1; dj <= 1; ++dj)
                if (di != 0 || dj != 0) {
                    int i = r + di;
                    int j = c + dj;
                    if (i >= 0 && i < R && j >= 0 && j < C)
                        result.add(new Pair<>(i, j));
                }
        return result;
    }
}

