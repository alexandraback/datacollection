/**
 * Created with IntelliJ IDEA.
 * User: brzezinsky
 * Date: 1/26/13
 * Time: 7:58 AM
 * To change this template use File | Settings | File Templates.
 */

import com.sun.servicetag.SystemEnvironment;

import java.io.*;
import java.util.*;

public class Hackercup extends Thread {
    public Hackercup(String inputFileName, String outputFileName) {
        try {
            if (inputFileName != null) {
                this.input = new BufferedReader(new FileReader(inputFileName));
            } else {
                this.input = new BufferedReader(new InputStreamReader(System.in));
            }
            if (outputFileName != null) {
                this.output = new PrintWriter(outputFileName);
            } else {
                this.output = new PrintWriter(System.out);
            }
            this.setPriority(Thread.MAX_PRIORITY);
        } catch (Throwable e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(666);
        }
    }

    private String doit() throws IOException {
        char [][]gr = new char[4][];
        for (int i = 0; i < 4; ++i) gr[i] = input.readLine().toCharArray();

        int tX = -1, tY = -1;
        boolean hasEmpty = false;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (gr[i][j] == 'T') {
                    tX = i;
                    tY = j;
                }
                hasEmpty |= gr[i][j] == '.';
            }
        }
        char types[] = {'X', 'O'};
        for (char C : types) {
            if (tX != -1) gr[tX][tY] = C;
            boolean won = false;
            for (int i = 0; i < 4; ++i) {
                boolean  okay = true;
                for (int j = 0; j < 4; ++j) okay &= gr[i][j] == C;
                if (okay) won = true;
                okay = true;
                for (int j = 0; j < 4; ++j) okay &= gr[j][i] == C;
                if (okay) won = true;

            }
            boolean okay = true;
            for (int i = 0; i < 4; ++i) okay &= gr[i][i] == C;
            if (okay) won = true;
            okay = true;
            for (int i = 0; i < 4; ++i) okay &= gr[i][3 - i] == C;
            if (okay) won = true;
            if (won) {
                return C + " won";
            }
        }
        if (hasEmpty) return "Game has not completed";
        else return "Draw";
    }


    private void solve() throws Throwable {
        int n = nextInt();
        for (int i = 1; i <= n; ++i) {
            output.printf("Case #%d: ", i);
            output.println(doit());
            if (i != n) input.readLine();
        }
    }

    public void run() {
        try {
            solve();
        } catch (Throwable e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(666);
        } finally {
            output.close();
        }
    }

    public static void main(String... args) {
       // new Hackercup(null, null).start();
        new Hackercup("/users/brzezinsky/IdeaProjects/contests/codeforces155/input.txt", "/users/brzezinsky/IdeaProjects/contests/codeforces155/output.txt").start();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    private String nextLine() throws IOException {
        return input.readLine();
    }


    private String next() throws IOException {
        while (tokens == null || !tokens.hasMoreTokens()) {
            tokens = new StringTokenizer(input.readLine());
        }
        return tokens.nextToken();
    }

    private StringTokenizer tokens;
    private BufferedReader input;
    private PrintWriter output;
}