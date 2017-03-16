package y2014.r1;

import java.io.*;
import java.util.Scanner;

public class PartElf {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new BufferedInputStream(new FileInputStream(
            //"/home/aurel/repos/cuteants/codejam/src/y2014/r1/A-test.in"
            "/home/aurel/repos/cuteants/codejam/src/y2014/r1/A-small-attempt1.in"
        )));
        BufferedWriter out = new BufferedWriter(new FileWriter(
            //"/home/aurel/repos/cuteants/codejam/src/y2014/r1/A-test.out"
            "/home/aurel/repos/cuteants/codejam/src/y2014/r1/A-small.out"
        ));

        int t = in.nextInt();
        for (int ti = 1; ti <= t; ti++) {
            String pq = in.next();
            long p = Long.parseLong(pq.split("/")[0]);
            long q = Long.parseLong(pq.split("/")[1]);

            long gcd = gcd(p, q);
            p /= gcd;
            q /= gcd;
            if (exp(q) == -1) {
                out.write(String.format("Case #%d: impossible", ti));
            } else {
                long gen = 0;
                while (p < q) {
                    q /= 2;
                    gen++;
                }
                out.write(String.format("Case #%d: %d", ti, gen));
            }

            out.newLine();
        }

        in.close();
        out.close();
    }

    private static long gcd(long a, long b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    private static long exp(long n) {
        int i = 0;
        while (n % 2 == 0) {
            n /= 2;
            i++;
        }
        return (n == 1) ? i : -1;
    }

}
