
import javafx.beans.binding.StringBinding;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ":\n" + new C().solve(in);
            out.print(s);
//            System.out.print(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int r = in.nextInt();
        int c = in.nextInt();
        int m = in.nextInt();
        char[][] a = new char[r][c];
        for (char[] chars : a) {
            Arrays.fill(chars, '*');
        }
        int d = r * c - m;
        if (r == 1 || c == 1) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    int z = (i + 1) * (j + 1);
                    if (z <= m) {
                        a[i][j] = '*';
                    } else if (z == r * c) {
                        a[i][j] = 'c';
                    } else {
                        a[i][j] = '.';
                    }
                }
            }
        } else if (d == 2 || d == 3 || d == 5 || d == 7) {
            return "Impossible\n";
        } else {
            for (char[] chars : a) {
                Arrays.fill(chars, '*');
            }
            a[0][0] = 'c';
            int dd = 1;
            int n = Math.max(r, c);
            boolean ok = dd == d;
            if (!ok) {
                outer:
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        for (int ii = i - 1; ii <= i + 1; ii++) {
                            for (int jj = j - 1; jj <= j + 1; jj++) {
                                if (ii >= 0 && ii < r && jj >= 0 && jj < c && a[ii][jj] == '*') {
                                    dd++;
                                    a[ii][jj] = '.';
                                }
                            }
                        }
                        if (dd == d) {
                            ok = true;
                            break outer;
                        }
                        if (dd > d) {
                            break outer;
                        }
                        for (int ii = j - 1; ii <= j + 1; ii++) {
                            for (int jj = i - 1; jj <= i + 1; jj++) {
                                if (ii >= 0 && ii < r && jj >= 0 && jj < c && a[ii][jj] == '*') {
                                    dd++;
                                    a[ii][jj] = '.';
                                }
                            }
                        }
                        if (dd == d) {
                            ok = true;
                            break outer;
                        }
                        if (dd > d) {
                            break outer;
                        }
                    }
                }
            }
            if (!ok) {
                for (char[] chars : a) {
                    Arrays.fill(chars, '*');
                }
                a[0][0] = 'c';
                dd = 1;
                for (int ii = 0; ii <= 2; ii++) {
                    for (int jj = 0; jj <= 2; jj++) {
                        if (ii >= 0 && ii < r && jj >= 0 && jj < c && a[ii][jj] == '*') {
                            dd++;
                            a[ii][jj] = '.';
                        }
                    }
                }
                outer:
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        for (int ii = i - 1; ii <= i + 1; ii++) {
                            for (int jj = j - 1; jj <= j + 1; jj++) {
                                if (ii >= 0 && ii < r && jj >= 0 && jj < c && a[ii][jj] == '*') {
                                    dd++;
                                    a[ii][jj] = '.';
                                }
                            }
                        }
                        if (dd == d) {
                            ok = true;
                            break outer;
                        }
                        if (dd > d) {
                            break outer;
                        }
                        for (int ii = j - 1; ii <= j + 1; ii++) {
                            for (int jj = i - 1; jj <= i + 1; jj++) {
                                if (ii >= 0 && ii < r && jj >= 0 && jj < c && a[ii][jj] == '*') {
                                    dd++;
                                    a[ii][jj] = '.';
                                }
                            }
                        }
                        if (dd == d) {
                            ok = true;
                            break outer;
                        }
                        if (dd > d) {
                            break outer;
                        }
                    }
                }
            }
            if (!ok) {
                System.err.println(r + " " + c + " " + m + " " + d);
                return "Impossible\n";
            }
        }
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < r; i++) {
            res.append(String.valueOf(a[i])).append("\n");
        }
        return res.toString();
    }
}