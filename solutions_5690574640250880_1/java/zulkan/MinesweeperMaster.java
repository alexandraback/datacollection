/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.text.*;

public class MinesweeperMaster {

    static BufferedReader br;
    static Scanner sc;
    static PrintWriter out;

    public static void initA() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            sc = new Scanner(System.in);
            out = new PrintWriter(System.out);
        } catch (Exception e) {
        }
    }

    public static void initB() {
        try {
            String in = "d:\\MT.in";
            String of = "d:\\out.txt";
            br = new BufferedReader(new FileReader(in));
            sc = new Scanner(new FileReader(in));
            out = new PrintWriter(of);
        } catch (Exception e) {
        }
    }

    static boolean next_permutation(Integer[] p) {
        for (int a = p.length - 2; a >= 0; --a) {
            if (p[a] < p[a + 1]) {
                for (int b = p.length - 1;; --b) {
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public static String getString() {
        try {
            return br.readLine();
        } catch (Exception e) {
        }
        return "";
    }

    public static Integer getInt() {
        try {
            return Integer.parseInt(br.readLine());
        } catch (Exception e) {
        }
        return 0;
    }

    public static Integer[] getIntArr() {
        try {
            StringTokenizer temp = new StringTokenizer(br.readLine());
            int n = temp.countTokens();
            Integer temp2[] = new Integer[n];
            for (int i = 0; i < n; i++) {
                temp2[i] = Integer.parseInt(temp.nextToken());
            }
            return temp2;
        } catch (Exception e) {
        }
        return null;
    }

    public static Long[] getLongArr() {
        try {
            StringTokenizer temp = new StringTokenizer(br.readLine());
            int n = temp.countTokens();
            Long temp2[] = new Long[n];
            for (int i = 0; i < n; i++) {
                temp2[i] = Long.parseLong(temp.nextToken());
            }
            return temp2;
        } catch (Exception e) {
        }
        return null;
    }

    public static String[] getStringArr() {
        try {
            StringTokenizer temp = new StringTokenizer(br.readLine());
            int n = temp.countTokens();
            String temp2[] = new String[n];
            for (int i = 0; i < n; i++) {
                temp2[i] = (temp.nextToken());
            }
            return temp2;
        } catch (Exception e) {
        }
        return null;
    }

    public static void print(Object a) {
        out.println(a);
    }

    public static void print(String s, Object... a) {
        out.printf(s, a);
    }

    public static int nextInt() {
        return sc.nextInt();
    }

    public static double nextDouble() {
        return sc.nextDouble();
    }

    public static void main(String[] ar) {
        initB();
        MinesweeperMaster c = new MinesweeperMaster();
        c.solve();
        out.flush();
    }
    int r, c;
    char papan[][];
    char papan2[][];

    boolean bs(int a, int b) {
        if (a < 0 || b < 0 || a == r || b == c) {
            return true;
        }
        return papan[a][b] == '.';
    }

    void fill(int i, int j) {
        if (i < 0 || j < 0 || i == r || j == c || papan2[i][j] != '.') {
            return;
        }
        int v = getCount(i, j);
        papan2[i][j] = (char) (v + '0');
        if (v == 0) {
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) {
                        continue;
                    }
                    fill(i + k, j + l);

                }
            }
        }
    }

    boolean finalChecker() {
        papan2 = new char[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                papan2[i][j] = papan[i][j];
            }
        }
        fill(0, 0);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (papan2[i][j] == '.') {
                    return false;
                }
            }
        }
        return true;
    }

    int getCount(int i, int j) {
        int ct = 0;
        for (int k = -1; k <= 1; k++) {
            for (int l = -1; l <= 1; l++) {
                if (k == 0 && l == 0) {
                    continue;
                }
                if (!bs(i + k, j + l)) {
                    ct++;
                }
            }
        }
        return ct;
    }

    void solve(int R, int C, int M) {
        papan = new char[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                papan[i][j] = '.';
            }
        }
        r = R;
        c = C;
        int kanan = C, bawah = R;
        while (M > 0) {
            //print(bawah+" "+kanan+" "+M);
            if (M < kanan && M < bawah) {
                //print("HEHE");
                for (int i = bawah - 1; M > 0 && i > 1; M--, i--) {
                    papan[i][kanan - 1] = '*';
                }
                kanan--;
                for (int i = kanan - 1; M > 0 && i > 1; M--, i--) {
                    papan[bawah - 1][i] = '*';
                }
                bawah--;
            }
            if (kanan > bawah) {
                for (int i = bawah - 1; M > 0 && i >= 0; M--, i--) {
                    papan[i][kanan - 1] = '*';
                }
                kanan--;
            } else {
                for (int i = kanan - 1; M > 0 && i >= 0; M--, i--) {
                    papan[bawah - 1][i] = '*';
                }
                bawah--;
            }
        }
        if (!finalChecker()) {
            print("Impossible");
            /*
            for (int i = 0; i < R; i++) {
            print(new String(papan2[i]));
            }
             * 
             */


            return;
        }
        papan[0][0] = 'c';
        for (int i = 0; i < R; i++) {
            print(new String(papan[i]));
        }
    }

    void solve() {
        int tc = getInt();
        for (int kasus = 1; kasus <= tc; kasus++) {
            print("Case #%d:\n", kasus);
            Integer xx[] = getIntArr();
            solve(xx[0], xx[1], xx[2]);
        }
    }
}
