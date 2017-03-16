/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;
import java.math.*;
import java.io.*;

/**
 *
 * @author bgamlath
 */
public class Round1Q1 {

    /**
     * @param args the command line arguments
     */
    static PrintStream out;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        BufferedReader in = new BufferedReader(new FileReader("input.txt"));
        out = new PrintStream("output.txt");
        int n = Integer.parseInt(in.readLine());
        for (int i = 1; i <= n; i++) {
            out.print("Case #" + i + ":");
            proc(in.readLine());
        }
        out.close();
    }

    static String proc(String input) {
        String[] t = input.split(" ");

        int n = Integer.parseInt(t[0]);
        double[] m = new double[n];

        double X = 0.0;

        for (int i = 1; i < t.length; i++) {
            m[i - 1] = Double.parseDouble(t[i]);
            X += m[i - 1];
        }
        double sum = 2 * X;
        int rem = n;
        double target = 0.0;
        boolean changed = true;
        while (changed) {
            changed = false;
            target = sum / rem;
            for (int i = 0; i < m.length; i++) {
                if (m[i] > target) {
                    changed = true;
                    
                    sum -= m[i];
                    m[i] = -1;
                    rem--;
                }
            }
        }
        String s = "";
        double z;
        for (int i = 0; i < n; i++) {
            if (m[i] >= -0.5) {
                z = (target - m[i]) * 100.0 / X;
            } else {
                z = 0.0;
            }
            out.printf(" %.6f", z);
        }
        out.println();
        return "";
    }
}
