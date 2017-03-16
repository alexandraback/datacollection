package com.andymur.codejam.cj2014.round1;

import java.io.*;

/**
 * Created by andymur on 5/3/14.
 */
public class Lottery {

    public static String IN_NAME = "lottery.in";
    public static String OUT_NAME = "lottery.out";

    public static int A = 0;
    public static int B = 0;
    public static int K = 0;
    private static int testCasesNum;

    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(IN_NAME)));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUT_NAME)));

        testCasesNum = readInt(reader);

        for (int i = 0; i < testCasesNum; i++) {
            readTestCase(reader);

            int result = solveTestCase();

            writer.write(String.format("Case #%d: %d", i + 1, result));

            if (i < testCasesNum - 1)
                writer.newLine();
        }

        reader.close();
        writer.close();
    }

    private static int solveTestCase() {
        int counter = 0;

        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if ((i & j) < K) {
                    counter++;
                }
            }
        }

        return counter;
    }

    private static int solveLargeTestCase() {
        return 0;
    }

    private static void readTestCase(BufferedReader reader) throws IOException {
        String line = reader.readLine();
        String[] args = line.split(" ");

        A = Integer.valueOf(args[0]);
        B = Integer.valueOf(args[1]);
        K = Integer.valueOf(args[2]);
    }

    private static int readInt(BufferedReader reader) throws IOException {
        return Integer.parseInt(reader.readLine().trim());
    }
}
