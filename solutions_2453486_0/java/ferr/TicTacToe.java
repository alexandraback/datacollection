import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public final class TicTacToe implements Runnable {

    String conv(String str) {
        char[] arr = str.toCharArray();
        Arrays.sort(arr);
        String str2 = new String(arr);
        return str2;
    }

    public void solveCase(int n) throws IOException{
        char[][] tbl = new char[4][];
        int qtyEmpty = 0;
        for (int i = 0; i < 4; ++i) {
            tbl[i] = in.readLine().toCharArray();
            for (int j = 0; j < 4; ++j)
                qtyEmpty += tbl[i][j] == '.' ? 1 : 0;
        }
        in.readLine();
        Set<String> set = new HashSet<String>();
        set.add(conv("" + tbl[0][0] + tbl[1][1] + tbl[2][2] + tbl[3][3]));
        set.add(conv("" + tbl[0][3] + tbl[1][2] + tbl[2][1] + tbl[3][0]));
        for (int i = 0; i < 4; ++i) {
            String s1 = "";
            String s2 = "";
            for (int j = 0; j < 4; ++j) {
                s1 += tbl[i][j];
                s2 += tbl[j][i];
            }
            set.add(conv(s1));
            set.add(conv(s2));
        }
        pw.printf("Case #%d: ", n);
        if (set.contains("TXXX") || set.contains("XXXX")) {
            pw.print("X won");
        } else if (set.contains("OOOT") || set.contains("OOOO")) {
            pw.print("O won");
        } else if (qtyEmpty > 0) {
            pw.print("Game has not completed");
        } else {
            pw.print("Draw");
        }
        pw.println();
    }

    public void solve() throws IOException {
        int T = nextInt();
        for (int i = 0; i < T; ++i) {
            solveCase(i + 1);
        }
    }

    public static void main(String[] args) {
        new TicTacToe().run();
    }

    static final String filename = "A";
    static final boolean fromConsole = true;

    public void run() {
        try {
            if (!fromConsole) {
                in = new BufferedReader(new FileReader(filename + ".in"));
                pw = new PrintWriter(filename + ".out");
            } else {
                in = new BufferedReader(new InputStreamReader(System.in));
                pw = new PrintWriter(System.out);
            }
            st = new StringTokenizer("");
            solve();
            pw.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    private StringTokenizer st;
    private BufferedReader in;
    private PrintWriter pw;

    boolean hasNext() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return false;
            }
            st = new StringTokenizer(line);
        }
        return st.hasMoreTokens();
    }

    String next() throws IOException {
		return hasNext() ? st.nextToken() : null;
	}

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
}