import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.AbstractCollection;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Erik Odenman
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("tideintideout.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TideInTideOut solver = new TideInTideOut();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TideInTideOut {

    static int[] dr = {0, 1, 0, -1};
    static int[] dc = {1, 0, -1, 0};

    static int H, N, M;
    static int[][] F, C;
    static long[][] lowest;
    static final long INF = 10000000000L;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
        H = in.getInt();
        N = in.getInt();
        M = in.getInt();
        C = new int[N][M];
        F = new int[N][M];
        for (int i = 0; i < N; i++) {
            in.readIntArrays(C[i]);
        }
        for (int i = 0; i < N; i++) {
            in.readIntArrays(F[i]);
        }
        lowest = new long[N][M];
        for (int i = 0; i < N; i++) {
            Arrays.fill(lowest[i], INF);
        }
        PriorityQueue<State> q = new PriorityQueue<State>();
        q.add(new State(0, 0, 0));
        lowest[0][0] = 0;
        double res = 0;
        while (!q.isEmpty()) {
            State st = q.poll();
            int r = st.r;
            int c = st.c;
            long t = st.t;
            if (t > lowest[r][c]) continue;
            if (r == N-1 && c == M-1) {
                res = t;
                res /= 10;
                break;
            }
            int Ccurr = C[r][c];
            int Fcurr = F[r][c];
            long water = H - t;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (!onMap(nr, nc)) continue;
                int Cnext = C[nr][nc];
                int Fnext = F[nr][nc];
                if (Fcurr > Cnext - 50 || Fnext > Cnext - 50 || Fnext > Ccurr - 50) continue;
                long wait = Math.max(0, water - Cnext + 50);
                long nt = t + wait;
                if (nt > 0) {
                    if (H - nt >= Fcurr + 20) {
                        nt += 10;
                    } else {
                        nt += 100;
                    }
                }
                if (lowest[nr][nc] > nt) {
                    lowest[nr][nc] = nt;
                    q.add(new State(nr, nc, nt));
                }
            }
        }
        out.println("Case #"+testNumber+": "+res);
	}

    static boolean onMap(int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < M;
    }

    static class State implements Comparable<State> {
        int r, c;
        long t;
        public State(int rr, int cc, long tt) {
            r = rr; c = cc; t = tt;
        }
        public int compareTo(State st) {
            if (lowest[st.r][st.c] <= lowest[r][c]) return 1;
            return -1;
        }
    }
}

class InputReader {
    private BufferedReader in;
    private StringTokenizer st;
    String token;

    public InputReader(InputStream inStream) {
        in = new BufferedReader(new InputStreamReader(inStream));
    }

    public int getInt() {
        return Integer.parseInt(next());
    }

    public String next() {
        String res = peekToken();
        token = null;
        return res;
    }

    public String peekToken() {
        if (token != null) return token;
        while (st == null || !st.hasMoreTokens()) {
            String line = null;
            try {
                line = in.readLine();
            } catch (IOException e) {
                throw new RuntimeException("No more tokens was found");
            }
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return token = st.nextToken();
    }

    public void readIntArrays(int[]... arrays) {
        for (int i = 0; i < arrays.length; i++) {
            for (int j = 0; j < arrays[i].length; j++) {
                arrays[i][j] = getInt();
            }
        }
    }
}

class OutputWriter  {

    PrintWriter out;

    public OutputWriter(OutputStream outStream) {
        out = new PrintWriter(outStream);
    }

    public OutputWriter(Writer writer) {
        out = new PrintWriter(writer);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) out.print(' ');
            out.print(objects[i]);
        }
    }

    public void println(Object... objects) {
        print(objects);
        out.println();
    }

    public void close() {
        out.close();
    }
}

