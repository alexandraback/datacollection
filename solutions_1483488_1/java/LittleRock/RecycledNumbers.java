/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package com.falidae;


import java.util.*;
import java.io.*;

/**
 *
 * @author LittleRock
 */
public class RecycledNumbers {

    public RecycledNumbers() {
    }

    public void init() {

    }
    
    public long solve(int a, int b) {
        Set<Integer> valid = new HashSet<Integer>();
        long reval = 0l;
        for (int i = a; i <= b; i++) {
            String digits = Integer.toString(i);
            char last = digits.charAt(0);
            boolean allSame = true;
            for (int j = 1; j < digits.length(); j++) {
                if (digits.charAt(j) != last) {
                    allSame = false;
                }
            }
            if (allSame) {
                continue;
            }
            int pow10a = 1;
            int pow10b = (int)Math.pow(10, digits.length());
            valid.clear();
            
            for (int j = 1; j < digits.length(); j++) {
                pow10a *= 10;
                pow10b /= 10;
                int front = i / pow10a;
                int back = i % pow10a;
                int shifted = back * pow10b + front;
//                System.out.println("front " + front + ", back " + back);
//                System.out.println("shifted " + shifted);
                if (Integer.toString(shifted).length() == digits.length() && shifted <= b && shifted > i) {
                    valid.add(shifted);
                }
            }
//            if (valid.size() > 0) {
//                System.out.println(i + " cycle valid " + valid.size());
//            }
            
            reval += valid.size();
        }
        return reval;
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("in.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
        RecycledNumbers solver = new RecycledNumbers();

        int testCount = in.nextInt();
        for (int i = 0; i < testCount; i++) {
            solver.init();
            printIndex(i, out);
            out.print(solver.solve(in.nextInt(), in.nextInt()));
            out.println();
        }

        in.close();
        out.flush();
        out.close();
    }

    private static void printIndex(int i, PrintWriter out) {
        out.printf("Case #%d: ", i + 1);
    }
}