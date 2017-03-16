/*
 * This file is public domain
 */
package net.boreeas.gcj;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.Arrays;

/**
 *
 * @author malte
 */
public class Main {

    static long casenum = 1;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {

        BufferedReader reader =
                       new BufferedReader(new InputStreamReader(new FileInputStream("in")));

        String in = reader.readLine();
        while ((in = reader.readLine()) != null) {
            if (in.trim().isEmpty()) {
                continue;
            }

            String[] parts = in.split(" ");
            String name = parts[0];
            int n = Integer.parseInt(parts[1]);

            solveName(name, n);
        }
    }

    static void solveName(String name, int n) {

        boolean[] subs = new boolean[name.length()];
        long subCount = 0;

        for (int i = n; i <= name.length(); i++) {

            int begin = 0;
            int end = i;

            while (end <= name.length()) {

                if (subs[begin]) {
                    subCount++;
                } else {
                    int max = 0;
                    int count = 0;

                    for (int idx = begin; idx < end; idx++) {
                        if (name.charAt(idx) == 'a' || name.charAt(idx) == 'e'
                            || name.charAt(idx) == 'i' || name.charAt(idx) == 'o'
                            || name.charAt(idx) == 'u') {
                            count = 0;
                        } else {
                            count++;
                            if (count > max) {
                                max = count;
                            }
                        }
                    }
                    if (max >= n) {
                        subCount++;
                        subs[begin] = true;
                    } else {
                        subs[begin] = false;
                    }
                }

                begin++;
                end++;
            }
        }

        printCase(subCount);
    }

    static void printCase(long solution) {
        System.out.println("Case #" + casenum + ": " + solution);
        casenum++;
    }
}