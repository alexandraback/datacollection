/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package numbers;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Serban
 */
public class Input {

    PrintWriter out;

    public Input(String fileName) {
        //C-large-practice.in
        try {
            out = new PrintWriter(new File("result.txt"));
            Scanner scan = new Scanner(new File(fileName));
            int T = scan.nextInt();
            scan.nextLine();
            for (int i = 0; i < T; i++) {
                int A = scan.nextInt();
                int B = scan.nextInt();
                solve(A, B, digits(A), i);
            }
            out.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private void solve(int A, int B, int digits, int testCase) {
        out.print("Case #" + (testCase + 1) + ": ");
        int nr = 0;
        int n = (int) Math.pow(10, digits);

        if (A >= 10) {
            for (int i = A; i < n; i++) {
                int m = reverse(i, digits);
                while (m != i) {
                    if (i < m && m <= B) {
                        nr++;
                    }
                    m = reverse(m, digits);
                }
            }
        }
        System.out.println(nr);
        out.print(nr);
        out.println();
        out.flush();
    }

    private int digits(int nr) {
        int digits = 0;
        while (nr > 0) {
            nr /= 10;
            digits++;
        }
        return digits;
    }

    private int reverse(int nr, int digits) {
        int last = 0;
        while (last == 0) {
            last = nr % 10;
            nr = nr / 10;
        }
        nr = last * (int) Math.pow(10, digits - 1) + nr;
        return nr;
    }
}
