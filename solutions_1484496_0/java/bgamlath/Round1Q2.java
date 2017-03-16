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
public class Round1Q2 {

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
            out.println("Case #" + i + ":" );
            proc(in.readLine());
        }
    }

    static String proc(String input) {
        String[] t = input.split(" ");
        long[] m = new long[20];
        for (int i = 0; i < 20; i++) {
            m[i] = Long.parseLong(t[i + 1]);
        }
        int lim = (int) Math.pow(2, 20);
        HashMap<Long, Integer> temp = new HashMap<Long, Integer>();

        for (int i = 0; i < lim; i++) {
            long z = getsum(i, m);
            if (temp.containsKey(z)) {
                out.println(get(temp.get(z), m));
                out.println(get(i, m));
                return "";
            }else{
                temp.put(z, i);
            }
        }
        out.println("Impossible");
        return "";
    }

    static String get(int i, long[] m) {
        String s = "";
        for (int j = 0; j < 20; j++) {
            if (i % 2 == 1) {
                s += " " + m[j];
            }
            i /= 2;
        }
        return s.substring(1);
    }

    static long getsum(int i, long[] m) {
        long sum = 0;
        for (int j = 0; j < 20; j++) {
            if (i % 2 == 1) {
                sum += m[j];
            }
            i /= 2;
        }
        return sum;
    }
}
