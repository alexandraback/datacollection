package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String... args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.println("Case #" + i + ": " + go(s));
        }
    }

    static String go(Scanner s) {
        char[] arr = s.next().toCharArray();
        char[] map = new char[26];

        for (char c : arr) {
            map[c - 'A']++;
        }

        String[] ns = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

        char[][] z = new char[10][];

        char[] out = new char[10];

        for (int i = 0; i < ns.length; i++) {
            char[] x = ns[i].toCharArray();
            char[] o = new char[26];
            for (char c : x) {
                o[c - 'A']++;
            }
            z[i] = o;
        }

        int[] order = {0, 2, 8, 6, 7, 5, 4, 3, 9, 1};

        for (int i : order) {
            char[] a = z[i];
            while (hasChars(map, a)) {
                remove(map, a);
                out[i]++;
            }
        }

        StringBuilder outBuild = new StringBuilder();

        for (int i = 0; i < ns.length; i++) {
            while (out[i] > 0) {
                out[i]--;
                outBuild.append(i);
            }
        }

        return outBuild.toString();
    }

    private static void remove(char[] map, char[] a) {
        for (int i = 0; i < a.length; i++) {
            map[i] -= a[i];
        }
    }

    private static boolean hasChars(char[] map, char[] a) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] > 0) {
                if (map[i] < a[i]) {
                    return false;
                }
            }
        }
        return true;
    }

}
