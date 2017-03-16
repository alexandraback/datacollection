package com.polarnick.codejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Polyarnyi Nikolay
 */
public class ProblemA {

    private void solve() throws IOException {
        int t = (int) nextLong();
        for (int i = 1; i <= t; i++) {
            long p = nextLong();
            long q = nextLong();
            long qPow = 0;
            long tmpQ = q;
            while (tmpQ % 2 == 0) {
                tmpQ /= 2;
                qPow++;
            }
            if (p % tmpQ != 0) {
                out.println("Case #" + i + ": impossible");
                continue;
            }
            p /= tmpQ;
            q /= tmpQ;
            if (!possible(0, qPow)) {
                out.println("Case #" + i + ": impossible");
                continue;
            }
            out.println("Case #" + i + ": " + getRes(0, p, q, qPow));
        }
    }

    private int getRes(int gen, long p, long q, long qPow) {
        if (gen == 40) {
            if (q != p && p != 0) {
                throw new IllegalStateException();
            }
            return 40;
        }
        if (2 * p >= q) {
            return gen + 1;
        }
        return getRes(gen + 1, p, q / 2, qPow - 1);
    }

    private boolean possible(int gen, long qPow) {
        return qPow <= (40 - gen);
    }

    private static final String filename = ProblemA.class.getSimpleName();

    public static void main(String[] args) throws IOException {
        ProblemA solution = new ProblemA();
        solution.solve();
        solution.close();
    }

    BufferedReader in;
    PrintWriter out;
    String curLine = null;
    StringTokenizer tok = null;

    public ProblemA() throws IOException {
        in = new BufferedReader(new FileReader(filename + ".in"));
        out = new PrintWriter(filename + ".out");
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextWord());
    }

    private String nextWord() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            curLine = in.readLine();
            if (curLine == null) {
                return null;
            }
            tok = new StringTokenizer(curLine, "/");
        }
        return tok.nextToken();
    }

    private void close() throws IOException {
        in.close();
        out.close();
    }


}
