package gcj2014.round1C;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by khabat95 on 11/05/14.
 */
public class c {

    public static String alg(long n, long m, long k) {
        long res = 0;
        long min = Math.min(n, m);
        long max = Math.max(n, m);
        if (min == 2 || min == 1) {
            res = k;
        } else if (k == n*m) {
            res = 2*m + 2*(n - 2);
        } else if ((n*m - k) < Math.min(n, m)) {
            long rest = (n * m) - k;
            if (rest > (min - 2)) {
                res = 2*min - 2 + 2*(max -2);
            } else {
                res = 2*m + 2*(n - 2) - 1;
            }
        } else {
            long rows = 0;
            if (k % min == 0) {
                rows = k/min - 1;
            } else {
                rows = k/min;
            }
            long rest = k - (rows * min);
            if (rows == 0) {
                res = k;
            } else {
                if (rest > (min - 2)) {
                    res = 2*rows + 2*(min -2);
                } else {
                    res = min + 2*(rows-1) + min -2;
                }
            }
            while (min > 3) {
                min--;
                rows = 0;
                if (k % min == 0) {
                    rows = k/min - 1;
                } else {
                    rows = k/min;
                }
                rest = k - (rows * min);
                long sup = 0;
                if (rest > min -2) {
                    sup = 2;
                }
                if (rows+sup > max) {
                    if (rest > min) {
                        break;
                    } else if (rows + 1 > max) {
                        break;
                    } else {
                        res = Math.min(res, 2*rows + 2*(min -2));
                    }
                } else if (rows == 0) {
                    res = Math.min(res, k);
                } else {
                    if (rest > (min - 2)) {
                        res = Math.min(res, 2*rows + 2*(min -2));
                    } else {
                        res = Math.min(res, min + 2*(rows-1) + min -2);
                    }
                }
            }
        }
        return String.valueOf(res);
    }

    public static void main(String args[]) {
        try {
            Scanner sc = new Scanner(new FileReader("/home/khabat95/gcj2014/round1C/c1.in"));
            PrintWriter pw = new PrintWriter("/home/khabat95/gcj2014/round1C/c1.out");

            int T = sc.nextInt();
            for (int i = 0; i < T; i++) {
                long n = sc.nextLong();
                long m = sc.nextLong();
                long k = sc.nextLong();
                System.out.println("Test case " + (i + 1) + "...");
                pw.println("Case #" + (i + 1) + ": " + alg(n, m, k));
            }

            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
