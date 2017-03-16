package com.zms.gcj;

import java.io.*;
import java.util.Scanner;

/**
 * Created by zms on 14-5-4.
 */
public class NewLotteryGame {

    public static void main(String[] args) throws Exception {
        File folder = new File("C:\\Users\\zms\\Downloads");
        File input = new File(folder, "B-small-attempt0.in");
        File output = new File(folder, "B-small-attempt0.out");
        int[] cc = new int[200];
        try (Scanner scanner = new Scanner(new FileInputStream(input))) {
            try (PrintWriter writer = new PrintWriter(new FileOutputStream(output))) {
                int T = scanner.nextInt();
                for (int k = 1; k <= T; k++) {
                    int A = scanner.nextInt();
                    int B = scanner.nextInt();
                    int K = scanner.nextInt();
                    int t = 0;
                    for (int a = 0; a < A; a++) {
                        for (int b = 0; b < B; b++) {
                            int c = a & b;
                            if (c < K) {
                                t++;
                            }
                        }
                    }
                    writer.printf("Case #%d: %d\n", k, t);

                }
            }
        }
    }
}
