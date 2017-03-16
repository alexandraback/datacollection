package com.cristizmf.googlecodejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by crist on 4/9/2016.
 * https://code.google.com/codejam/contest/6254486/
 */
public class RevengeOfThePancakes {

    public static void main(String[] args) throws FileNotFoundException {
        final int INPUT_FILE_NUMBER = 2;
        Scanner scanner = new Scanner(new File("C:\\dev\\Projects\\algorithms\\TestCases\\GoogleCodeJam\\RevengeOfThePancakes\\input" + INPUT_FILE_NUMBER + ".txt"));
        PrintWriter printWriter = new PrintWriter(new File("C:\\dev\\Projects\\algorithms\\TestCases\\GoogleCodeJam\\RevengeOfThePancakes\\output" + INPUT_FILE_NUMBER + ".txt"));
        int tc = Integer.parseInt(scanner.nextLine());
        for (int t = 0; t < tc; t++) {
            String pancake = scanner.nextLine();
            int swaps = 0;
            for (int i = pancake.length() - 1; i >= 0; i--) {
                if ((pancake.charAt(i) == '-' && (swaps % 2 == 0)) || (pancake.charAt(i) == '+' && (swaps % 2 == 1))) {
                    swaps++;
                }
            }
//            System.out.println(swaps);
            printWriter.println("Case #" + (t + 1) +": " +swaps);
        }
        printWriter.flush();
        printWriter.close();
    }
}
