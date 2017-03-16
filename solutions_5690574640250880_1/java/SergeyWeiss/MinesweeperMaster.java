package com.google.codejam2014.qual;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class MinesweeperMaster {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    MinesweeperMaster() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
    }

    String next() throws IOException {
        while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
            stringTokenizer = new StringTokenizer(reader.readLine());
        }
        return stringTokenizer.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    void solveTestCase(int testNumber) throws IOException {
        writer.printf("Case #%d:\n", testNumber);
        int r = nextInt(), c = nextInt(), m = nextInt();
        int n = r * c - m;
        String impossible = "Impossible";
        char click = 'c';
        char[][] ans = new char[r][c];
        if(r == 1) {
            Arrays.fill(ans[0], '.');
            Arrays.fill(ans[0], 0, m, '*');
            ans[0][c - 1] = click;
        } else if(c == 1) {
            for(int i = 0; i < r; i++) ans[i][0] = '.';
            for(int i = 0; i < m; i++) ans[i][0] = '*';
            ans[r - 1][0] = click;
        } else if(n == 1) {
            for(int i = 0; i < r; i++) {
                Arrays.fill(ans[i], '*');
            }
            ans[0][0] = click;
        } else if(n <= 3) {
            writer.println(impossible);
            return;
        }
        else if(r == 2) {
            if(m % 2 == 1) {
                writer.println(impossible);
                return;
            } else {
                for(int i = 0; i < r; i++) Arrays.fill(ans[i], '.');
                for(int i = 0; i < r; i++) Arrays.fill(ans[i], 0, m / 2, '*');
                ans[0][c - 1] = click;
            }
        }
        else if(c == 2) {
            if(m % 2 == 1) {
                writer.println(impossible);
                return;
            } else {
                for(int i = 0; i < r; i++) Arrays.fill(ans[i], '.');
                for(int i = 0; i < m / 2; i++) Arrays.fill(ans[i], '*');
                ans[r - 1][0] = click;
            }
        } else {
            for(int i = 0; i < r; i++) Arrays.fill(ans[i], '*');
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    ans[i][j] = '.';
                }
            }
            n -= 4;
            ans[0][0] = click;
            int rr = 2, cc = 2;
            while((rr < r || cc < c) && n > 1) {
                if(rr < r) {
                    for(int i = 0; i < 2; i++) ans[rr][i] = '.';
                    n-= 2;
                    rr++;
                }
                if(cc < c && n > 1) {
                    for(int i = 0; i < 2; i++) ans[i][cc] = '.';
                    n -= 2;
                    cc++;
                }
            }
            for(int i = 2; n > 0 && i < rr; i++) {
                for(int j = 2; n > 0 && j < cc; j++) {
                    ans[i][j] = '.';
                    n--;
                }
            }
            if(n > 0) {
                writer.println(impossible);
                return;
            }
        }
        for(int i = 0; i < r; i++) {
            writer.println(ans[i]);
        }
    }

    void solve() throws IOException {
        int testsNumber = nextInt();
        for(int i = 1; i <= testsNumber; i++) {
            solveTestCase(i);
        }
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        new MinesweeperMaster().solve();
    }
}
