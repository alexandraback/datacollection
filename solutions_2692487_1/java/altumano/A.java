package com.google.codejam;

import java.io.File;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

// Libraries used: http://commons.apache.org/lang/, http://commons.apache.org/collections/, https://code.google.com/p/guava-libraries/
public class A {
    private static int caseNumber;

    private static String solve(Scanner scanner) {
        long A = scanner.nextLong();
        int N = scanner.nextInt();
        int[] m = new int[N];
        for (int i = 0; i < N; i++) {
            m[i] = scanner.nextInt();
        }
        debug("A=" + A + ", N=" + N + ", m=" + Arrays.toString(m));
        Arrays.sort(m);
        debug("sorted m=" + Arrays.toString(m));

        long stepsNeeded = solve(A, m);

        debug("A=" + A);
        return String.valueOf(stepsNeeded);
    }

    private static long solve(long initialA, int[] m) {
        long A = initialA;
        long stepsNeeded = 0;
        for (int i = 0; i < m.length; i++) {
            if (m[i] < A) {
                A += m[i];
                continue;
            }

            // if we cannot add a mote, just do delete
            if (A - 1 == 0) {
                stepsNeeded++;
                continue;
            }

            // if adding a mote helps with the next node, add it
            //            if (A + (A - 1) > m[i]) {
            //                stepsNeeded++;
            //                A += A - 1;
            //                A += m[i];
            //                continue;
            //            }

            // first option: add motes until we can swallow the next one
            long A1 = A;
            long stepsNeeded1 = stepsNeeded;
            do {
                // add mote (A1 - 1)
                A1 += A1 - 1;
                stepsNeeded1++;
            } while (m[i] >= A1);
            A1 += m[i];
            stepsNeeded1 += solve(A1, Arrays.copyOfRange(m, i + 1, m.length));

            // second option: delete next mote
            long A2 = A;
            long stepsNeeded2 = stepsNeeded;
            stepsNeeded2++;
            stepsNeeded2 += solve(A2, Arrays.copyOfRange(m, i + 1, m.length));

            if (stepsNeeded1 < stepsNeeded2) {
                stepsNeeded = stepsNeeded1;
                A = A1;
            } else {
                stepsNeeded = stepsNeeded2;
                A = A2;
            }
            break;
        }
        return stepsNeeded;
    }

    public static void main(String[] args) throws Exception {
        if (args.length != 1) {
            throw new IllegalArgumentException("Wrong run parameters: " + Arrays.deepToString(args));
        }
        File inputFile = new File(args[0]);
        String outputFileName = inputFile.getParent() + File.separator + inputFile.getName().replace(".in", ".out");
        PrintStream out = new PrintStream(outputFileName);

        Scanner scanner = new Scanner(inputFile);
        scanner.useLocale(Locale.US);
        int numberOfCases = Integer.valueOf(scanner.nextLine());
        debug(numberOfCases + " cases");

        long startTime = System.currentTimeMillis();
        for (caseNumber = 1; caseNumber <= numberOfCases; caseNumber++) {
            debug("Case #" + caseNumber);
            String result = solve(scanner);
            String resultString = "Case #" + caseNumber + ": " + result;
            out.println(resultString);
            debug("Solution for " + resultString);
            debug("");
        }
        long time = System.currentTimeMillis() - startTime;
        debug("Time: " + time + " ms (" + time / numberOfCases + " ms / case)");

        scanner.close();
        out.close();
    }

    private static void debug(String text) {
        System.out.println(text);
    }
}
