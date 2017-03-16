/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Qualifier2012.b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

/**
 *
 * @author Ant Ongun Kefeli
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileInputStream fis = new FileInputStream("src\\Qualifier2012\\b\\B-large.in");
        Scanner sc = new Scanner(fis);

        FileWriter fw = new FileWriter("src\\Qualifier2012\\b\\output.out");
        BufferedWriter out = new BufferedWriter(fw);

        int caseCount = 0;
        caseCount = sc.nextInt();
        for (int i = 0; i < caseCount; i++) {
            int numberOfGoogler = sc.nextInt();
            int[] googlers = new int[numberOfGoogler];
            int numberOfSurprising = sc.nextInt();
            int limit = sc.nextInt();
            for (int j = 0; j < numberOfGoogler; j++) {
                googlers[j] = sc.nextInt();
            }

            doit(out, i + 1, googlers, numberOfSurprising, limit);

        }

        out.close();
        sc.close();
    }

    private static void doit(BufferedWriter out, int casec, int googlers[], int numberOfSurprising, int limit) throws IOException {

        int res = 0;
        int surp = 0;
        for (int i = 0; i < googlers.length; i++) {
            int j1;
            int dancer = googlers[i];
            if (dancer % 3 == 0) {
                j1 = dancer / 3;
                if (j1 <= 10 && j1 >= limit) {
                    res++;
                } else if (j1 == limit - 1 && j1 >= 1 && surp < numberOfSurprising) {
                    res++;
                    surp++;
                }
            } else if (dancer % 3 == 1) {
                j1 = dancer / 3 + 1;
                if (j1 <= 10 && j1 >= limit) {
                    res++;
                }
            } else if (dancer % 3 == 2) {
                j1 = dancer / 3 + 1;
                if (j1 <= 10 && j1 >= limit) {
                    res++;
                } else if (j1 == limit - 1 && surp < numberOfSurprising) {
                    res++;
                    surp++;
                }
            }

        }

        out.write(
                "Case #" + casec + ": " + res + "\n");
    }
}
