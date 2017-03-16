/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.demister.gcj;

import java.util.*;
import java.io.*;

/**
 *
 * @author rock
 */
public class Consonants {

    public Consonants() {
    }

    private boolean isConsonant(char c) {
        return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
    }

    public long getNValue(char[] name, int n) {
        long reval = 0l;
        long last = 0;
        long current = -1;
        for (int i = 0; i < name.length; i++) {
            char c = name[i];
            if (this.isConsonant(c)) {
                if (current < 0) {
                    current = i;
                }
                    if (current >= 0 && (i - current + 1) == n) {
                        reval += (current - last + 1) * (name.length - i);
                        last = current + 1;
                        if (n == 1) {
                            current = -1;
                        } else {
                            current++;
                        }
                    }
            } else {
                current = -1;
            }
        }
        return reval;
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileReader("in.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
        Consonants dealer = new Consonants();

        int numOfTests = in.nextInt();

        for (int i = 0; i < numOfTests; i++) {
            out.printf("Case #%d: ", i + 1);

            // Todo
            String name = in.next();
            int n = in.nextInt();

            out.print(dealer.getNValue(name.toCharArray(), n));

            out.println();
            out.flush();
        }

        in.close();
        out.close();
    }
}
