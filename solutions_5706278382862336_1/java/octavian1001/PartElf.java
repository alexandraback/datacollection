package ro.hasna.codejam;

import java.io.*;

public class PartElf {

    public static boolean isPowerOfTwo(long x) {
        while (((x % 2) == 0) && x > 1)
            x /= 2;
        return (x == 1);
    }

    public static long cmmdc(long a, long b) {
        long r;
        do {
            r = a % b;
            a = b;
            b = r;
        } while (r != 0);
        return a;
    }

    public static void main(String[] args) throws IOException {
//        BufferedReader reader = new BufferedReader(new FileReader("in.txt"));
        BufferedReader reader = new BufferedReader(new FileReader("A-large.in"));
        BufferedWriter writer = new BufferedWriter(new PrintWriter("A-large.out"));
//        BufferedWriter writer = new BufferedWriter(new PrintWriter("out.txt"));
        int t = Integer.parseInt(reader.readLine());

        for (int i = 0; i < t; i++) {
            String[] a = reader.readLine().split("/");
            long p = Long.parseLong(a[0]);
            long q = Long.parseLong(a[1]);
            long c = cmmdc(p, q);
            p = p / c;
            q = q / c;
            writer.append("Case #");
            writer.append((i + 1) + ": ");

            int r = 0;
            while (((q % 2) == 0) && q > 1) {
                if (q > p) {
                    r++;
                }
                q /= 2;
            }

            if (q != 1) {
                writer.append("impossible");
            } else {
                writer.append("" + r);
            }

            writer.append("\r\n");
            writer.flush();
        }

        writer.close();
        reader.close();
    }

}
