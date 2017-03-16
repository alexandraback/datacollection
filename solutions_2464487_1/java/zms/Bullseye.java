package com.meituan.tests.topcoder.jam2013;

import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Bullseye {

    public long cal(long r, long t) {
        if (!cal(r, t, 0)) {
            return 0;
        }
        if (!cal(r, t, 1)) {
            return 1;
        }
        long min = 0;
        long max = t + 1;
        while (min < max) {
            long mid = (min + max) / 2;
            if (cal(r, t, mid)) {
                min = mid;
            } else {
                max = mid;
            }
            if ((max - min) == 1) {
                return min + 1;
            }
        }
        throw new RuntimeException("why?");
    }

    public boolean cal(long r, long t, long k) {
        return t * 1.0 / (2 * r + 2 * k + 1) / (k + 1) >= 1;
    }

    public static void main(String[] args) throws Exception {
        Bullseye test = new Bullseye();
        //test.test();
        File file = new File("/Users/zms/Downloads/A-large.in");
        System.out.println(file.exists());
        try (Scanner scanner = new Scanner(new FileReader(file))) {
            File out = new File(file.getParentFile(), "d.dat");
            try (PrintWriter writer = new PrintWriter(out)) {
                int count = scanner.nextInt();
                for (int i = 0; i < count; i++) {
                    writer.printf("Case #%d: %d\n", i + 1, test.cal(scanner.nextLong(), scanner.nextLong()));
                }
                writer.flush();
            }
        }
    }

}
