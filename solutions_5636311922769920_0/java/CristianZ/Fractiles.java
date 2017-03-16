package com.cristizmf.googlecodejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by crist on 4/9/2016.
 * <p/>
 * https://code.google.com/codejam/contest/6254486
 */
public class Fractiles {

    private static void generateSolution() {
        int n = 7;
        int transform = 1;
        for (int i = (int) (Math.pow(2, n) - 1); i >= 0; i--) {
            String b2 = Integer.toString(i, 2);
            StringBuilder stringBuilder = new StringBuilder(b2);
            while (stringBuilder.length() != n) {
                stringBuilder.insert(0, "0");
            }
            for (int j = 0; j < transform; j++) {
                StringBuilder newStr = new StringBuilder();
                for (int k = 0; k < stringBuilder.length(); k++) {
                    if (stringBuilder.charAt(k) == '1') {
                        for (int z = 0; z < stringBuilder.length(); z++) {
                            newStr.append("1");
                        }
                    } else {
                        newStr.append(stringBuilder);
                    }
                }
                stringBuilder = newStr;
            }
            String s = stringBuilder.toString();
            s = s.replace("1", "G");
            s = s.replace("0", "L");
            System.out.println(s);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        final int INPUT_FILE_NUMBER = 2;
        Scanner scanner = new Scanner(new File("C:\\dev\\Projects\\algorithms\\TestCases\\GoogleCodeJam\\Fractiles\\input" + INPUT_FILE_NUMBER + ".txt"));
        PrintWriter printWriter = new PrintWriter(new File("C:\\dev\\Projects\\algorithms\\TestCases\\GoogleCodeJam\\Fractiles\\output" + INPUT_FILE_NUMBER + ".txt"));
        int tc = scanner.nextInt();

        for (int t = 0; t < tc; t++) {
            int k = scanner.nextInt();
            int c = scanner.nextInt();
            int s = scanner.nextInt();

            printWriter.print("Case #" + (t + 1) + ": ");
            for (int i = 1; i <= k; i++) {
                printWriter.print(i + (i != k ? " " : ""));
            }
            printWriter.println();

        }
        printWriter.flush();
        printWriter.close();
    }
}
