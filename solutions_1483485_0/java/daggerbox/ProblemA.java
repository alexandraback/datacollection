package com.forthgo.google.g2012r0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by Xan Gregg.
 * Date: 4/14/12
 */
public class ProblemA {
    public static void main(String[] args) {
        try {
            char[] map = new char[256];
            map[' '] = ' ';
            learn(map, "a zoo", "y qee");
            learn(map, "our language is impossible to understand", "ejp mysljylc kd kxveddknmc re jsicpdrysi");
            learn(map, "there are twenty six factorial possibilities", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
            learn(map, "so it is okay if you want to just give up", "de kr kd eoya kw aej tysr re ujdr lkgc jv");
            char missing = check(map);
            char[] imap = invert(map, missing);

            Scanner in = new Scanner(new File("A.in"));
            PrintWriter out = new PrintWriter(new FileWriter("A.out"));
            //PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                String s = in.nextLine();
                String t = translate(imap, s);
                //String t = solve(in, s);
                out.printf("Case #%d: %s%n", i + 1, t);
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    private static char[] invert(char[] map, char missing) {
        char[] imap = new char[256];
        imap[' '] = ' ';
        for (char c = 'a'; c <= 'z'; c++) {
            char b = map[c];
            if (b == 0)
                imap[missing] = c;
            else
                imap[b] = c;
        }
        return imap;
    }

    private static char check(char[] map) {
        int missing = 0;
        int u = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (map[c] == 0) {
                if (u > 0)
                    throw new RuntimeException();
                u++;
            }
            missing += c - map[c];
        }
        return (char) missing;
    }

    private static String translate(char[] map, String s) {
        StringBuilder t = new StringBuilder(s.length());
        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i);
            t.append(map[a]);
        }
        return t.toString();
    }


    private static void learn(char[] map, String s, String t) {
        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i);
            char b = t.charAt(i);
            if (map[a] != 0 && map[a] != b)
                throw new RuntimeException();
            map[a] = b;
        }
    }


}

