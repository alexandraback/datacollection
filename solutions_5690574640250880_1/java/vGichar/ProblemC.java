package magictrick;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemC {

    public static int R;
    public static int C;
    public static int M;
    public static int F;

    public static char mat[][];

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File f = new File("problemC.in");
        File f2 = new File("ProblemCSolve.out");
        Scanner sc = new Scanner(f);
        FileWriter fw = new FileWriter(f2);

        int T = sc.nextInt();

        for (int i = 0; i < T; i++) {
            R = sc.nextInt();
            C = sc.nextInt();
            M = sc.nextInt();
            F = (R * C) - M;
            mat = new char[R][C];

            boolean posible = hasSolution();

            fw.append("Case #" + (i + 1) + ":\n");
            //System.out.println("Case #" + (i + 1) + "\tR:" + R + " C:" + C + " M:" + M + " F:" + F);
            if (posible) {

                populate();
                //print();

                for (int j = 0; j < R; j++) {
                    for (int k = 0; k < C; k++) {
                        fw.append(mat[j][k]);
                    }
                    fw.append("\n");
                }
            } else {
                fw.append("Impossible\n");
                //System.out.println("Impossible");
            }
            //System.out.println("");
        }
        fw.close();
    }

    public static boolean hasSolution() {
        if (F == 1) {
            return true;
        }
        if (R == 1 || C == 1) {
            return true;
        }

        if (R == 2 || C == 2) {
            if (F >= 4 && F % 2 == 0) {
                return true;
            }
            return false;
        }

        if (R > 2 && C > 2) {
            if (F == 4 || F == 6 || F >= 8) {
                return true;
            }
        }

        return false;
    }

    public static void populate() {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                mat[i][j] = '.';
            }
        }

        if (M == 0) {
            mat[0][0] = 'c';
            return;
        }

        if (F == 1) {
            for (int i = 0; i < R && M > 0; i++) {
                for (int j = 0; j < C && M > 0; j++) {
                    mat[i][j] = '*';
                }
            }
            mat[0][0] = 'c';
        }
        if (R == 1 || C == 1) {
            for (int i = 0; i < R && M > 0; i++) {
                for (int j = 0; j < C && M > 0; j++) {
                    mat[i][j] = '*';
                    M--;
                }
            }
            mat[R - 1][C - 1] = 'c';
        }

        if (R == 2 || C == 2) {
            if (F >= 4 && F % 2 == 0) {
                if (R == 2) {
                    for (int i = 0; i < M / 2; i++) {
                        mat[0][i] = '*';
                        mat[1][i] = '*';
                    }
                } else if (C == 2) {
                    for (int i = 0; i < M / 2; i++) {
                        mat[i][0] = '*';
                        mat[i][1] = '*';
                    }
                }
                mat[R - 1][C - 1] = 'c';
            }
        }

        if (R > 2 && C > 2) {
            if (F == 4 || F == 6 || F >= 8) {
                int r = R - 2;
                int c = C - 2;
                int m = M;
                for (int i = 0; i < r && m > 0; i++) {
                    for (int j = 0; j < c && m > 0; j++) {
                        m--;
                        mat[i][j] = '*';
                    }
                }
                if (m % 2 == 1 && F > 8 && m > 0) {
                    mat[r - 1][c - 1] = '.';
                    m++;
                }
                for (int i = 0; i < r - 1 && m > 0; i++) {
                    m -= 2;
                    mat[i][C - 1] = '*';
                    mat[i][C - 2] = '*';
                }
                for (int i = 0; i < c - 1 && m > 0; i++) {
                    m -= 2;
                    mat[R - 1][i] = '*';
                    mat[R - 2][i] = '*';
                }

                if (m > 0) {
                    m -= 2;
                    mat[R - 3][C - 1] = '*';
                    mat[R - 3][C - 2] = '*';
                }

                if (m > 0) {
                    m -= 2;
                    mat[R - 1][C - 3] = '*';
                    mat[R - 2][C - 3] = '*';
                }
                mat[R - 1][C - 1] = 'c';
            }
        }
    }

    public static void print() {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                System.out.print(mat[j][k] + " ");
            }
            System.out.println("");
        }
    }
}
