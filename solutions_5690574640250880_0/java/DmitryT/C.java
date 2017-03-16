import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * by dt on 4/11/14, 9:34 PM
 */
public class C {
    public static void main(String[] args) throws FileNotFoundException {
//        Scanner sc = new Scanner(System.in);
        Scanner sc = new Scanner(new File("./GCJ14qual/C-small-attempt1.in"));
        PrintWriter pw = new PrintWriter(new File("./GCJ14qual/C-small-attempt1.out"));
        PrintWriter pwdf = new PrintWriter(new File("./GCJ14qual/C-small-attempt1-debug.txt"));
//        PrintWriter pw = new PrintWriter(System.out);
//        PrintWriter pwdf = new PrintWriter(System.out);

        PrintWriter pwd = new PrintWriter(System.out);

        int t = sc.nextInt();
        for (int j = 1; j <= t; j ++) {
            int r = sc.nextInt(), c = sc.nextInt(), mo = sc.nextInt(), m = mo, cr = 0, cc = 0;
            char[][] f = new char[r][c];
            f[r-1][c-1] = 'c';
            while (m >= Math.max(r - cr, c - cc) && r - cr > 3 && c - cc > 3) {
                if (r - cr > c - cc) {
                    fillCol(f, r, cr, cc, Integer.MAX_VALUE);
                    m -= r - cr;
                    cc ++;
                } else {
                    fillRow(f, c, cr, cc, Integer.MAX_VALUE);
                    m -= c - cc;
                    cr ++;
                }
            }

            while (m >= Math.min(r - cr, c - cc) && (r - cr > 2 || c - cc > 2)) {
                if (r - cr > c - cc) {
                    fillRow(f, c, cr, cc, Integer.MAX_VALUE);
                    m -= c - cc;
                    cr ++;
                } else {
                    fillCol(f, r, cr, cc, Integer.MAX_VALUE);
                    m -= r - cr;
                    cc ++;
                }
            }

            // N.B. easier check using mod exists, still need to verify cases there though
            // leftover mines
            boolean possible = true;
            if (m > 0) {
                if (Math.min(r - cr, c - cc) == 1) {
                    fillRow(f, c, cr, cc, m);
                    possible = true;
                } else if (Math.min(r - cr, c - cc) == 2 && m != 3) {
                    possible = false;
                } else if (Math.max(r - cr, c - cc) == 3 && m > 1) {
                    possible = false;
                } else {
                    int maxFree = Math.max(r - cr, c - cc) - m;
                    int m1 = maxFree > 1 ? m : m - 1, m2 = maxFree > 1 ? 0 : 1;
                    if (r - cr < c - cc) {
                        fillRow(f, c, cr, cc, m1);
                        fillRow(f, c, cr + 1, cc, m2);
                    } else {
                        // more rows -- place leftovers into rightmost column, starting top. place 1 in opposite corner
                        fillCol(f, r, cr, cc, m1);
                        fillCol(f, r, cr, cc + 1, m2);
                    }
                }
            }

            pwd.println("Case #" + j + ":");
            pw.println("Case #" + j + ":");
            if (!possible) {
                pwd.println("Impossible");
                pw.println("Impossible");
                pwdf.println("Impossible? : 1 " + r + " " + c + " " + mo);
            } else {
                pf(pwd, f);
                pf(pw, f);
            }
        }

        sc.close();
        pw.close();
        pwd.close();
        pwdf.close();
    }

    private static void pf(PrintWriter pwd, char[][] f) {
        for (char[] row : f) {
            String s = "";
            for (char p : row) {
                s += (p == '*' || p == 'c' ? p : '.');
            }
            pwd.println(s);
        }
        pwd.println();
        pwd.flush();
    }

    private static void fillRow(char[][] f, int c, int cr, int cc, int lim) {
        for (int i = cc, cnt = 0; i < c && cnt < lim; i ++, cnt ++) {
            f[cr][i] = '*';
        }
    }

    private static void fillCol(char[][] f, int r, int cr, int cc, int lim) {
        for (int i = cr, cnt = 0; i < r && cnt < lim; i ++, cnt ++) {
            f[i][cc] = '*';
        }
    }
}
