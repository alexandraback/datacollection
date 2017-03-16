package com.google.codejam;

import java.io.File;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

import org.apache.commons.lang.ArrayUtils;

//Libraries used: http://commons.apache.org/lang/, http://commons.apache.org/collections/, https://code.google.com/p/guava-libraries/
public class B {
    private static boolean debugAllowed = true;

    private static String solve(int caseNumber, Scanner scanner) {
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int[][] a = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                a[i][j] = scanner.nextInt();
            }
        }
        debug(Arrays.deepToString(a));

        int[] maxInRow = new int[N];
        for (int i = 0; i < N; i++) {
            maxInRow[i] = 0;
            for (int j = 0; j < M; j++) {
                if (a[i][j] > maxInRow[i]) {
                    maxInRow[i] = a[i][j];
                }
            }
        }
        debug("maxInRow: " + ArrayUtils.toString(maxInRow));

        int[] maxInCol = new int[M];
        for (int j = 0; j < M; j++) {
            maxInCol[j] = 0;
            for (int i = 0; i < N; i++) {
                if (a[i][j] > maxInCol[j]) {
                    maxInCol[j] = a[i][j];
                }
            }
        }
        debug("maxInCol: " + ArrayUtils.toString(maxInCol));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int current = a[i][j];
                if (current < maxInRow[i] && current < maxInCol[j]) {
                    return "NO";
                }
            }
        }

        return "YES";
    }

    public static void main(String[] args) throws Exception {
        if (args.length != 1) {
            throw new IllegalArgumentException("Wrong run parameters: " + Arrays.deepToString(args));
        }
        File inputFile = new File(args[0]);
        String outputFileName = inputFile.getParent() + File.separator + inputFile.getName().replace(".in", ".out");
        PrintStream out = new PrintStream(outputFileName);

        Scanner scanner = new Scanner(inputFile);
        int numberOfCases = Integer.valueOf(scanner.nextLine());
        debug(numberOfCases + " cases");

        long startTime = System.currentTimeMillis();
        for (int caseNumber = 1; caseNumber <= numberOfCases; caseNumber++) {
            // Parsing the file
            debug("Case #" + caseNumber);

            // Now solving

            String result = solve(caseNumber, scanner);
            String resultString = "Case #" + caseNumber + ": " + result;
            out.println(resultString);
            debug("Solution for " + resultString);

            debug("");
        }
        long time = System.currentTimeMillis() - startTime;
        debug("Time: " + time + " ms (" + time / numberOfCases + " ms / case)");

        out.close();
    }

    private static void debug(String text) {
        if (debugAllowed) {
            System.out.println(text);
        }
    }
}
