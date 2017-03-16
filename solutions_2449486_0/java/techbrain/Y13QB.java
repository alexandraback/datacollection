import java.io.*;
import java.util.*;

/**
 * User: Oleksiy Pylypenko
 * Date: 1/6/13
 * Time: 1:46 PM
 */
public class Y13QB {
    private static final int STAR = 200;

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer tok;

    private void solveTest() throws IOException {
        nextLine();
        int n =  readInt(), m = readInt();

        int a[][] = new int[n][m];

        int []positions = new int[n * m];
        int ptr = 0;
        for (int j = 0; j < n; j++) {
            nextLine();
            for (int i = 0; i < m; i++) {
                int v = readInt();
                a[j][i] = v;
                positions[ptr++] = v * 10000 + i * 100 + j;
            }
        }

        Arrays.sort(positions);

        for (int pos : positions) {
            int v = pos / 10000;
            int i = (pos / 100) % 100;
            int j = pos % 100;

            if (a[j][i] == STAR) continue;

            boolean fill1 = true;
            for (int k = 0; k < n; k++) {
                int v1 = a[k][i];
                if (v1 != STAR && v1 != v) {
                    fill1 = false;
                    break;
                }
            }
            boolean fill2 = true;
            for (int k = 0; k < m; k++) {
                int v2 = a[j][k];
                if (v2 != STAR && v2 != v) {
                    fill2 = false;
                    break;
                }
            }
            if (!fill1 && !fill2) {
                out.println("NO");
                return;
            }
            if (fill1) {
                for (int k = 0; k < n; k++) {
                    a[k][i] = STAR;
                }
            }
            if (fill2) {
                for (int k = 0; k < m; k++) {
                    a[j][k] = STAR;
                }
            }
        }
        out.println("YES");
    }

    private void solve() throws IOException {
        nextLine();
        int nt = readInt();
        for (int t = 1; t <= nt; t++) {
            out.print("Case #" + t + ": ");
            solveTest();
        }
    }

    private String readLine() throws IOException {return in.readLine();}
    private void nextLine() throws IOException {tok = new StringTokenizer(in.readLine());}

    private String read() {return tok.nextToken();}
    private int readInt() {return Integer.parseInt(tok.nextToken());}
    private long readLong() {return Long.parseLong(tok.nextToken());}
    private double readDouble() {return Double.parseDouble(tok.nextToken());}

    public static void main(String[] args) throws IOException {
        new Y13QB().exec();
    }

    private void exec() {
        try {
            in = new BufferedReader(new FileReader(getInFile()));
            out = new PrintWriter(new FileWriter(getOutFile()), true);
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }

        try {
            solve();
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        } finally {
            out.close();
            try {
                in.close();
            } catch (IOException e) {
                System.out.println(e);
                System.exit(1);
            }
        }
        try {
            FileInputStream input = new FileInputStream(getOutFile());
            byte []buf = new byte[1024];
            int r;
            while ((r = input.read(buf)) != -1) {
                System.out.write(buf, 0, r);
            }
            input.close();
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }
    }

    private String getOutFile() {
        return getClass().getName() + ".out";
    }

    private String getInFile() {
        return getClass().getName() + ".in";
    }

    static class Gen {
        public static void main(String[] args) throws FileNotFoundException {
            PrintWriter pw = new PrintWriter(new Y13QB().getInFile());
            pw.println(1);
            pw.println("100 100");
            Random rnd = new Random(123);
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    if (j != 0) pw.print(' ');
                    pw.print(rnd.nextInt(100) + 1);
                }
                pw.println();
            }
            pw.flush();
        }
    }
    static class Gen2 {
        public static void main(String[] args) throws IOException {
            PrintWriter pw = new PrintWriter(new Y13QB().getInFile());
            pw.println(1);
            pw.println("100 100");
            Random rnd = new Random(123);
            int a[][] = new int[100][100];
            for (int i = 0; i < 100; i++)
            Arrays.fill(a[i], 100);
            for (int l = 0; l < 10000; l++) {
                boolean v = rnd.nextBoolean();
                int vv = rnd.nextInt(100) + 1;
                int p = rnd.nextInt(100);
                if (v) {
                    for (int i = 0; i < 100; i++) a[i][p] = Math.min(vv, a[i][p]);
                } else {
                    for (int i = 0; i < 100; i++) a[p][i] = Math.min(vv, a[p][i]);
                }
            }
            a[50][50] = 1;
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    if (j != 0) pw.print(' ');
                    pw.printf("%4d", a[i][j]);
                }
                pw.println();
            }
            pw.close();
            Y13QB.main(args);
        }
    }
}
