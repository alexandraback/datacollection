package minesweeperMaster;

import deceitfulWar.DeceitfulWar;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Locale;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class MinesweeperMaster {

    static boolean[][] map = new boolean[50][50];

    private static boolean isValid(int R, int C, int M) {
        int A = R * C;
        if (A == M + 1)
            return true;
        if (R == 1 || C == 1)
            return A >= M + 2;
        if (A < M + 4)
            return false;
        if (R == 2 || C == 2)
            return M % 2 == 0;
        return A - M != 5 && A - M != 7;
    }

    public static void main(String[] args) {
        try {
            Scanner s = new Scanner(new BufferedReader(new FileReader("C-large.in")));
            Writer w = new BufferedWriter(new FileWriter("C-large.out"));

            s.useLocale(Locale.US);

            int T = s.nextInt();
            for (int t = 0; t < T; ++t) {
                int R, C, M;
                R = s.nextInt();
                C = s.nextInt();
                M = s.nextInt();
                w.write("Case #" + (t + 1) + ":\n");

                int actR = R;
                int actC = C;

                R = Math.min(actR, actC);
                C = Math.max(actR, actC);

                if (!isValid(R, C, M)) {
                    w.write("Impossible\n");
                    continue;
                }

                for (int y = 0; y < R; ++y)
                    for (int x = 0; x < C; ++x)
                        map[y][x] = false;

                if (R * C == M + 1)
                    for (int y = 0; y < R; ++y)
                        for (int x = 0; x < C; ++x)
                            map[y][x] = true;
                else if (R == 1)
                    for (int m = 0; m < M; ++m)
                        map[0][m] = true;
                else if (R == 2) {
        //            System.out.println("Case " + (t + 1) + ": R == 2");
                    for (int m = 0; m < M; m += 2) {
                        map[0][m / 2] = true;
                        map[1][m / 2] = true;
                    }
                }
/*                else if (R == 3 && C == 3 && M == 2) {
                    map[2][0] = true;
                    map[0][2] = true;
                }*/ else {
                    for (int y = 0; y < R - 2 && y * (C - 2) < M; ++y)
                        for (int x = 0; x < C - 2 && y * (C - 2) + x < M; ++x)
                            map[y][x] = true;
                    if (M > (R - 2) * (C - 2)) {
                        int remaining = M - (R - 2) * (C - 2);
                        for (int y = 0; y < R - 3 && remaining > 0; ++y) {
                            map[y][C - 2] = true;
                            map[y][C - 1] = true;
                            remaining -= 2;
                        }
                        for (int x = 0; x < C - 3 && remaining > 0; ++x) {
                            map[R - 2][x] = true;
                            map[R - 1][x] = true;
                            remaining -= 2;
                        }
                        if (remaining == -1)
                            map[R - 3][C - 3] = false;
                        if (remaining > 0 && R >= 3) {
                            map[R - 3][C - 2] = true;
                            map[R - 3][C - 1] = true;
                            remaining -= 2;
                        }
                        if (remaining > 0 && C >= 3) {
                            map[R - 2][C - 3] = true;
                            map[R - 1][C - 3] = true;
                        }
                    }
                }

                if (R == actR)
                    for (int y = 0; y < R; ++y) {
                        for (int x = 0; x < C && (y < R - 1 || x < C - 1); ++x)
                            if (map[y][x])
                                w.write('*');
                            else
                                w.write('.');
                        if (y < R - 1)
                            w.write("\n");
                    }
                else
                    for (int y = 0; y < C; ++y) {
                        for (int x = 0; x < R && (y < C - 1 || x < R - 1); ++x)
                            if (map[x][y])
                                w.write('*');
                            else
                                w.write('.');
                        if (y < C - 1)
                            w.write("\n");
                    }
                w.write("c\n");
            }
            w.flush();
            w.close();
            s.close();
        } catch (IOException ex) {
            Logger.getLogger(DeceitfulWar.class
                    .getName()).log(Level.SEVERE, null, ex);
        }
    }
}