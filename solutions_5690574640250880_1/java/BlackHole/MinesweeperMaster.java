package Qualification.C;

import java.io.*;
import java.util.*;
import java.math.*;

/**
 * Created by mtian on 4/12/14.
 */
public class MinesweeperMaster {


    public void solve(ContestReader cr, PrintWriter pw) throws Exception {
        int R = cr.nextInt();
        int C = cr.nextInt();
        int M = cr.nextInt();
        boolean inverted = false;
        if (R < C) {
            int t = R;
            R = C;
            C = t;
            inverted = true;
        }

        char[][] mine = new char[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                mine[i][j] = '*';
            }
        }

        int open = R * C - M;
        boolean success = true;

        if (open <= 0) {
            success = false;
        } else if (open == 1) {
            success = true;
        } else if (C == 1) {
            int rowOpened = open / C;
            for (int i = 0; i < rowOpened; i++) {
                mine[i][0] = '.';
            }
            success = true;
        } else if (C == 2) {
            int rowOpened = open / C;
            if (rowOpened >= 2 && open % 2 == 0) {
                for (int i = 0; i < rowOpened; i++) {
                    mine[i][0] = '.';
                    mine[i][1] = '.';
                }
                success = true;
            } else {
                success = false;
            }
        } else if (open == 2 || open == 3 || open == 5 || open == 7) {
            success = false;
        } else if (open == 4 || open == 6) {
            int colOpened = open / 2;
            for (int j = 0; j < colOpened; j++) {
                mine[0][j] = '.';
                mine[1][j] = '.';
            }
            success = true;
        } else if (open >= 8 && open <= C * 3) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    mine[i][j] = '.';
                }
            }
            mine[2][0] = '.';
            mine[2][1] = '.';

            int moreOpen = open - 8;
            int moreCol = Math.min(moreOpen / 2, C - 3);
            int moreThirdRow = moreOpen - 2 * moreCol;
            for (int j = 3; j < 3 + moreCol; j++) {
                mine[0][j] = '.';
                mine[1][j] = '.';
            }
            for (int j = 2; j < 2 + moreThirdRow; j++) {
                mine[2][j] = '.';
            }
            success = true;
        } else {
            int fullRowNum = open / C;
            int lastRowCol = open - fullRowNum * C;
            assert fullRowNum >= 3;
            if (lastRowCol != 1) {
                for (int i = 0; i < fullRowNum; i++) {
                    for (int j = 0; j < C; j++) {
                        mine[i][j] = '.';
                    }
                }
                for (int j = 0; j < lastRowCol; j++) {
                    mine[fullRowNum][j] = '.';
                }
            } else {
                fullRowNum -= 1;
                lastRowCol += 1;
                for (int i = 0; i < fullRowNum; i++) {
                    for (int j = 0; j < C; j++) {
                        mine[i][j] = '.';
                    }
                }
                for (int j = 0; j < C - 1; j++) {
                    mine[fullRowNum][j] = '.';
                }
                mine[fullRowNum + 1][0] = '.';
                mine[fullRowNum + 1][1] = '.';
            }
            success = true;
        }

        if (success) {
            mine[0][0] = 'c';
            pw.println();
            if (inverted) {
                for (int i = 0; i < C; i++) {
                    for (int j = 0; j < R; j++) {
                        pw.print(mine[j][i]);
                    }
                    pw.println();
                }
            } else {

                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        pw.print(mine[i][j]);
                    }
                    pw.println();
                }
            }
        } else {
            pw.println();
            pw.println("Impossible");
        }
    }

    public static void main(String[] args) throws Exception {
        ContestReader cr = new ContestReader(new FileInputStream("C-large.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("C-large.out"));
        MinesweeperMaster solver = new MinesweeperMaster();
        int T = cr.nextInt();
        for (int caseNum = 1; caseNum <= T; caseNum++) {
            System.out.println("Processing test case " + caseNum);
            pw.print("Case #" + caseNum + ": ");
            solver.solve(cr, pw);
        }
        pw.flush();
        pw.close();
    }
}

class ContestReader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    public ContestReader(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    public String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}