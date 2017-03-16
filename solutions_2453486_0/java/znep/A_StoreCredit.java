package contests.Qualification2013;

import contests.Util;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import contests.Util;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class A_StoreCredit extends Util {
    private static final int SIZE = 4;

    public static void main(String args[]) throws IOException {
        String inputFileName = "src/contests/Qualification2013/A-sample.in";
        if (args.length == 1) inputFileName = args[0];

        BufferedReader in = new BufferedReader(new FileReader(inputFileName));

        int numTestCases = Integer.parseInt(in.readLine());
        debug("Processing " + numTestCases + " test cases");
        for (int testCase = 1; testCase <= numTestCases; testCase = testCase + 1) {
            debug("Starting case " + testCase);

            char[][] matrix = new char[SIZE][];
            for (int i = 0; i < SIZE; i++) {
                String line = in.readLine();
                matrix[i] = line.toCharArray();
                debug("got line " + Arrays.toString(matrix[i]));
            }
            in.readLine(); // ignore

            boolean xWon = false, oWon = false, complete = true;

            // columns
            for (int i = 0; i < SIZE; i++) {
                boolean xlWon = true, olWon = true;
                for (int j = 0; j < SIZE; j++) {
                    char c = matrix[i][j];

                    if (c == '.') complete = false;
                    if (c != 'X' && c != 'T') xlWon = false;
                    if (c != 'O' && c != 'T') olWon = false;
                }
                xWon = xWon || xlWon;
                oWon = oWon || olWon;
            }

            // rows
            for (int i = 0; i < SIZE; i++) {
                boolean xlWon = true, olWon = true;
                for (int j = 0; j < SIZE; j++) {
                    char c = matrix[j][i];

                    if (c == '.') complete = false;
                    if (c != 'X' && c != 'T') xlWon = false;
                    if (c != 'O' && c != 'T') olWon = false;

                }
                xWon = xWon || xlWon;
                oWon = oWon || olWon;
            }

            // diag l to r
            {
                boolean xlWon = true, olWon = true;
                for (int i = 0; i < SIZE; i++) {
                    char c = matrix[i][i];

                    if (c == '.') complete = false;
                    if (c != 'X' && c != 'T') xlWon = false;
                    if (c != 'O' && c != 'T') olWon = false;

                }
                xWon = xWon || xlWon;
                oWon = oWon || olWon;
            }

            // diag r to l
            {
                boolean xlWon = true, olWon = true;
                for (int i = 0; i < SIZE; i++) {
                    char c = matrix[i][SIZE-i-1];

                    if (c == '.') complete = false;
                    if (c != 'X' && c != 'T') xlWon = false;
                    if (c != 'O' && c != 'T') olWon = false;
                }
                xWon = xWon || xlWon;
                oWon = oWon || olWon;
            }


            String strOut;
            if (xWon) {
                strOut = "X won";
            } else if (oWon) {
                strOut = ("O won");
            } else if (complete) {
                strOut = ("Draw");
            } else {
                strOut = ("Game has not completed");
            }
            System.out.println("Case #" + testCase + ": " + strOut);




        }
    }

}

