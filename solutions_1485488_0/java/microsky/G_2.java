import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class G_2 {

    public static void main(String[] args) throws Exception {
        G_2 instance = new G_2();
        instance.func();
    }

    PrintWriter bw;
    int[][] f, c;
    double[][] t;
    final int dn[] = { -1, 0, 1, 0 }, dm[] = { 0, 1, 0, -1 };

    void mov(int n, int m, double time) {
        // System.out.println(n + " " + m);
        if (t[n][m] != -1 && t[n][m] <= time) {
            return;
        }
        if (t[n][m] == -1 || t[n][m] > time) {
            t[n][m] = time;
        }
        if (n == N - 1 && m == M - 1) {
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int n2 = n + dn[i];
            int m2 = m + dm[i];
            if (n2 < 0 || m2 < 0 || n2 >= N || m2 >= M) {
                continue;
            } else {
                double water = H - 10 * time;
                if (c[n2][m2] - f[n2][m2] >= 50 && c[n][m] - f[n2][m2] >= 50 && c[n2][m2] - f[n][m] >= 50 && c[n][m] - f[n][m] >= 50) {
                    if (c[n2][m2] - water >= 50) {
                        if (water - f[n][m] >= 20 && water - f[n2][m2] >= 20) {
                            mov(n2, m2, time == 0 ? 0 : time + 1);
                        } else {
                            mov(n2, m2, time == 0 ? 0 : time + 10);
                        }
                    } else if (water <= f[n2][m2] && water <= f[n2][m2]) {

                        System.out.println("************************************************");
                        // mov(n2, m2, time == 0 ? 0 : time + 10);
                    } else {
                        // double a = water - (c[n][m] - 50);
                        double b = water - (c[n2][m2] - 50);
                        // System.out.println(a + "-" + b);
                        double deta = b / 10.0;
                        double new_water = H - 10 * (time + deta);
                        if (new_water - f[n][m] >= 20 && new_water - f[n2][m2] >= 20) {
                            mov(n2, m2, (time + deta == 0) ? 0 : time + deta + 1);
                        } else {
                            mov(n2, m2, (time + deta == 0) ? 0 : time + deta + 10);
                        }
                    }
                } else {
                    // System.out.println("************************************************");

                    // no way
                }
            }
        }
    }

    int H, N, M;

    public void func() throws Exception {
        bw = new PrintWriter(new FileWriter("1.txt"));
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int i = 0; i < T; i++) {
            H = scan.nextInt();
            N = scan.nextInt();
            M = scan.nextInt();
            f = new int[N][M];
            c = new int[N][M];
            t = new double[N][M];
            for (int n = 0; n < N; ++n) {
                for (int m = 0; m < M; ++m) {
                    c[n][m] = scan.nextInt();
                }
            }
            for (int n = 0; n < N; ++n) {
                for (int m = 0; m < M; ++m) {
                    f[n][m] = scan.nextInt();
                    t[n][m] = -1;
                }
            }
            // t[0][0] = 0;
            mov(0, 0, 0);

            print(String.format("Case #%d: %f\n", (i + 1), t[N - 1][M - 1]));
        }
        bw.flush();
        bw.close();
    }

    void print(String s) {
        System.out.print(s);
        bw.write(s);
    }
}
