package prob3;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by lvitor on 30/04/16.
 */
public class Main {
    int J, P, K, S;
    int[][][] combs;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("src/prob3/in1.in"));
        PrintWriter out = new PrintWriter("src/prob3/out1.txt");
        Main m = new Main();
        int T = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= T; i++) {
            m.J = in.nextInt();
            m.P = in.nextInt();
            m.S = in.nextInt();
            m.K = in.nextInt();
            m.solve(out, i);
        }
        out.close();
    }

    public String solve(PrintWriter out, int t) {
        combs = new int[J][P][S];
        int count;
        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s < S; s++) {
                    combs[j][p][s] = 0;
                }
            }
        }
        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s < S; s++) {
                    combs[j][p][s] = 1;
                    if (!isValid(j, p, s)) {
                        combs[j][p][s] = 0;
                    }
//                    printSol();
                }
            }
        }


        count = 0;
        String string_out = "";
        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s < S; s++) {
                    if (combs[j][p][s] == 1) {
                        string_out += (j + 1) + " " + (p + 1) + " " + (s + 1) + "\n";
                        count++;
                    }
                }
            }
        }

        out.write("Case #" + t + ": " + count + "\n");
        out.write(string_out);
        return null;
    }

    void printSol() {
        System.out.println("printing sol");
        for (int j1 = 0; j1 < J; j1++) {
            for (int p1 = 0; p1 < P; p1++) {
                for (int s = 0; s < S; s++) {
                    if (combs[j1][p1][s] == 1) {
                        System.out.println((j1 + 1) + " " + (p1 + 1) + " " + (s + 1));
//                                count++;
                    }
                }
            }
        }
        System.out.println();
    }

    boolean isValid(int j, int p, int s) {
        int count = 0;
        for (int c = 0; c < S; c++) {
            if (combs[j][p][c] == 1) {
                count++;
                if (count > K) {
                    return false;
                }
            }
        }

        count = 0;
        for (int a = 0; a < J; a++) {
            if (combs[a][p][s] == 1) {
                count++;
                if (count > K) {
                    return false;
                }
            }
        }

        count = 0;
        for (int b = 0; b < P; b++) {
            if (combs[j][b][s] == 1) {
                count++;
                if (count > K) {
                    return false;
                }
            }
        }


        return true;
    }
}
