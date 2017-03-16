import java.io.*;
import java.util.StringTokenizer;

public class ProblemA {

    public static void main(String[] args) throws Exception {
        new ProblemA();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "A-small-attempt0";

    public ProblemA() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    private void solve() throws Exception {
        int t = nextInt();
        label:
        for (int it = 0; it < t; ++it) {
            out.print("Case #" + (it + 1) + ": ");
            char[][] a = new char[4][];
            for (int i = 0; i < 4; ++i) {
                a[i] = in.readLine().toCharArray();
            }
            in.readLine();
            boolean isX = false, isO = false, isDot = false;
            boolean filled = true;
            for (int i = 0; i < 4; ++i) {
                isX = isO = isDot = false;
                for (int j = 0; j < 4; ++j) {
                    switch (a[i][j]) {
                        case 'X':
                            isX = true;
                            break;
                        case 'O':
                            isO = true;
                            break;
                        case '.':
                            isDot = true;
                            break;
                    }
                }
                if (isX && !isO && !isDot) {
                    out.println("X won");
                    continue label;
                }
                if (!isX && isO && !isDot) {
                    out.println("O won");
                    continue label;
                }
                if (isDot) {
                    filled = false;
                }
            }
            for (int i = 0; i < 4; ++i) {
                isX = isO = isDot = false;
                for (int j = 0; j < 4; ++j) {
                    switch (a[j][i]) {
                        case 'X':
                            isX = true;
                            break;
                        case 'O':
                            isO = true;
                            break;
                        case '.':
                            isDot = true;
                            break;
                    }
                }
                if (isX && !isO && !isDot) {
                    out.println("X won");
                    continue label;
                }
                if (!isX && isO && !isDot) {
                    out.println("O won");
                    continue label;
                }
                if (isDot) {
                    filled = false;
                }
            }
            isX = isO = isDot = false;
            for (int i = 0; i < 4; ++i) {
                switch (a[i][i]) {
                    case 'X':
                        isX = true;
                        break;
                    case 'O':
                        isO = true;
                        break;
                    case '.':
                        isDot = true;
                        break;
                }
            }
            if (isX && !isO && !isDot) {
                out.println("X won");
                continue label;
            }
            if (!isX && isO && !isDot) {
                out.println("O won");
                continue label;
            }
            if (isDot) {
                filled = false;
            }
            isX = isO = isDot = false;
            for (int i = 0; i < 4; ++i) {
                switch (a[i][3 - i]) {
                    case 'X':
                        isX = true;
                        break;
                    case 'O':
                        isO = true;
                        break;
                    case '.':
                        isDot = true;
                        break;
                }
            }
            if (isX && !isO && !isDot) {
                out.println("X won");
                continue label;
            }
            if (!isX && isO && !isDot) {
                out.println("O won");
                continue label;
            }
            if (isDot) {
                filled = false;
            }
            if (filled) {
                out.println("Draw");
            } else {
                out.println("Game has not completed");
            }

        }
    }


    private void init() throws FileNotFoundException {
        if (fileName.equals("#Console")) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else if (fileName.equals("#IOtxt")) {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } else {
            in = new BufferedReader(new FileReader(fileName + ".in"));
            out = new PrintWriter(fileName + ".out");
        }
    }


    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }


    private String nextToken() throws IOException {
        while (!tok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            tok = new StringTokenizer(s);
        }
        return tok.nextToken();
    }

}
            