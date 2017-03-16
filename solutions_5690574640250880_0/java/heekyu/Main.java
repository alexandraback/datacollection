/**
 * Created by heekyu on 2014. 4. 12..
 */
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;
import java.io.InputStream;

public class Main {

    public static void main(String[] args) throws Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        Qual_C solver = new Qual_C();
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            solver.solve(i+1, in, out);
        }
        out.close();
    }
}

class Qual_C {
    public void solve(int testNumber, InputReader in, PrintWriter out) throws Exception {
        out.println("Case #" + testNumber + ":");
        R = in.nextInt();
        C = in.nextInt();
        int M = in.nextInt();
        int safe = R*C - M;

        boolean[][] map = new boolean[R][C];
        if (M == 0) {
            for (int i = 0; i < R; i++) Arrays.fill(map[i], true);
            printMap(map, out);
            return;
        }
        if (R == 1) {
            out.print('c');
            for (int i = 0; i < safe-1; i++) {
                out.print(".");
            }
            for (int i = 0; i < M; i++) {
                out.print('*');
            }
            out.println();
            return;
        } else if (C == 1) {
            out.println('c');
            for (int i = 0; i < safe-1; i++) {
                out.println(".");
            }
            for (int i = 0; i < M; i++) {
                out.println('*');
            }
            return;
        }

        if (safe == 1) {
            map[0][0] = true;
            printMap(map, out);
            return;
        } else if (safe <= 3 || safe == 5 || safe == 7) {
            out.println("Impossible");
            return;
        } else if ((R == 2 || C == 2) && safe % 2 == 1) {
            out.println("Impossible");
            return;
        }

        if (safe <= 2*R+1) {
            int r = 0;
            while (safe >= 2) {
                if (safe == 3) break;
                map[r][0] = true;
                map[r][1] = true;
                r++;
                safe -= 2;
            }
            for (int i = 0; i < safe; i++) {
                map[i][2] = true;
            }
            printMap(map, out);
            return;
        } else if (safe <= 2*C+1) {
            int c = 0;
            while (safe >= 2) {
                if (safe == 3) break;
                map[0][c] = true;
                map[1][c] = true;
                c++;
                safe -= 2;
            }
            for (int i = 0; i < safe; i++) {
                map[2][i] = true;
            }
            printMap(map, out);
            return;
        }

        if (R > C) {
            int fillrow = safe / C - 1;
            for (int i = 0; i < fillrow; i++) {
                for (int j = 0; j < C; j++) map[i][j] = true;
            }
            if (safe % C == 1) {
                for (int j = 0; j < C-1; j++) map[fillrow][j] = true;
                for (int j = 0; j < 2; j++) map[fillrow+1][j] = true;
            } else {
                for (int j = 0; j < C; j++) map[fillrow][j] = true;
                for (int j = 0; j < safe%C; j++) map[fillrow+1][j] = true;
            }
        } else {
            int fillcol = safe / R - 1;
            for (int j = 0; j < fillcol; j++) {
                for (int i = 0; i < R; i++) map[i][j] = true;
            }
            if (safe % R == 1) {
                for (int i = 0; i < R-1; i++) map[i][fillcol] = true;
                for (int i = 0; i < 2; i++) map[i][fillcol+1] = true;
            } else {
                for (int i = 0; i < R; i++) map[i][fillcol] = true;
                for (int i = 0; i < safe % R; i++) map[i][fillcol+1] = true;
            }
        }
        printMap(map, out);
    }

    int R;
    int C;
    private void printMap(boolean[][] map, PrintWriter out) {
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < R; i++) {
            sb.setLength(0);
            for (int j = 0; j < C; j++) {
                if (i == 0 && j == 0) {
                    sb.append('c');
                    continue;
                }
                sb.append(map[i][j] ? '.':'*');
            }
            out.println(sb.toString());
        }
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}
