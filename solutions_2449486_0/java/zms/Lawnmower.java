package com.meituan.tests.topcoder.jam2013;

import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Lawnmower {

    public boolean test(int[][] lines) {
        int n = lines.length;
        int m = lines[0].length;
        boolean ok = true;
        int p;
        out:
        for (int i = 0; i < n; i++) {
            int max = 0;
            for(int j=0;j<m;j++) {
                if (lines[i][j] > max) {
                    max = lines[i][j];
                }
            }
            for(int j=0;j<m;j++) {
                if (lines[i][j] < max) {
                    p=lines[i][j];
                    for (int k = 0; k < n; k++) {
                        if (lines[k][j] > p) {
                            ok = false;
                            break out;
                        }
                    }
                }
            }
        }
        if (ok) {
            out:
            for (int j = 0; j < m; j++) {
                int max = 0;
                for (int k = 0; k < n; k++) {
                    if (lines[k][j] > max) {
                        max = lines[k][j];
                    }
                }
                for (int i = 0; i < n; i++) {
                    if (lines[i][j] < max) {
                        p=lines[i][j];
                        for (int k = 0; k < m; k++) {
                            if (lines[i][k] > p) {
                                ok = false;
                                break out;
                            }
                        }
                    }
                }
            }
        }
        return ok;
    }

    public static void main(String[] args) throws Exception {
        Lawnmower test = new Lawnmower();
        File file = new File("/Users/zms/Downloads/B-small-attempt0.in");
        System.out.println(file.exists());
        try (Scanner scanner = new Scanner(new FileReader(file))) {
            File out = new File(file.getParentFile(), "a2.dat");
            try (PrintWriter writer = new PrintWriter(out)) {
                int count = scanner.nextInt();
                int[][] lines;
                for (int i = 0; i < count; i++) {
                    int n = scanner.nextByte();
                    int m = scanner.nextByte();
                    lines = new int[n][m];
                    for (int a = 0; a < n; a++) {
                        for (int b = 0; b < m; b++) {
                            lines[a][b] = scanner.nextInt();
                        }
                    }
                    writer.printf("Case #%d: %s\n", i + 1, test.test(lines) ? "YES" : "NO");
                }
                writer.flush();
            }
        }
    }

}
