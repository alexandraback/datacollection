package ro.hasna.codejam;

import java.io.*;

public class Enclosure {

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
        BufferedReader reader = new BufferedReader(new FileReader("C-small-attempt0.in"));
        BufferedWriter writer = new BufferedWriter(new PrintWriter("out.txt"));
        int t = Integer.parseInt(reader.readLine());

        for (int i = 0; i < t; i++) {
            String a[] = reader.readLine().split(" ");
            int n = Integer.parseInt(a[0]);
            int m = Integer.parseInt(a[1]);
            int k = Integer.parseInt(a[2]);

            int r;
            if (k == n * m) {
                r = n * 2 + m * 2 - 4;
            } else if (n < 3 || m < 3 || (k < n && k < m)) {
                r = k;
            } else {
                if (n < m) {
                    int cat = k / n;
                    int rest = k % n;
                    if (cat <= 2 || n + rest > k) {
                        r = k;
                    } else {
                        r = n + rest;
                    }
                } else {
                    int cat = k / m;
                    int rest = k % m;
                    if (cat <= 2 || m + rest > k) {
                        r = k;
                    } else {
                        r = m + rest;
                    }
                }

            }
            writer.append("Case #");
            writer.append((i + 1) + ": ");


            writer.append("" + r);

            writer.append("\r\n");
            writer.flush();
        }

        writer.close();
        reader.close();
    }

}
