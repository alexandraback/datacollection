import java.io.*;
import java.util.StringTokenizer;

/**
 * User: Oleksiy Pylypenko
 * Date: 1/6/13
 * Time: 1:46 PM
 */
public class Y13QA {
    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer tok;

    private String r(int row, String ...arr) {
        StringBuilder builder = new StringBuilder(arr.length);
        for (String s : arr) {
            builder.append(s.charAt(row));
        }
        return builder.toString();
    }

    private String d(int start, int inc, String ...arr) {
        StringBuilder builder = new StringBuilder(arr.length);
        for (String s : arr) {
            builder.append(s.charAt(start));
            start += inc;
        }
        return builder.toString();
    }

    private boolean isWon(char x, String str) {
        int t = 0, nx = 0;
        for (char c : str.toCharArray()) {
            if (c == 'T') t++;
            if (c == x) nx++;
        }

        return nx == 4 || (nx == 3 && t == 1);
    }

    private void solveTest() throws IOException {
        String a = readLine();
        String b = readLine();
        String c = readLine();
        String d = readLine();
        readLine();

        String e = r(0, a, b, c, d);
        String f = r(1, a, b, c, d);
        String g = r(2, a, b, c, d);
        String h = r(3, a, b, c, d);

        String i = d(0, 1, a, b, c, d);
        String j = d(3, -1, a, b, c, d);

        String arr[] = {a, b, c, d, e, f, g, h, i, j};
        boolean draw = true;
        for (String s : arr) {
            if (isWon('O', s)) {
                out.println("O won");
                return;
            }
            if (isWon('X', s)) {
                out.println("X won");
                return;
            }
            if (s.contains(".")) {
                draw = false;
            }
        }
        if (draw) {
            out.println("Draw");
        } else {
            out.println("Game has not completed");
        }
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
        new Y13QA().exec();
    }

    private void exec() {
        try {
            System.setIn(new FileInputStream(getClass().getName() + ".in"));
        } catch (FileNotFoundException e) {
            System.out.println(e);
            System.exit(1);
        }
        try {
            System.setOut(new PrintStream(new FileOutputStream(getClass().getName() + ".out")));
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }

        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out, true);

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
    }

}
