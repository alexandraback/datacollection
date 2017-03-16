package com.google.codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * User: svasilinets
 * Date: 14.04.12
 * Time: 9:40
 */
public class QualA {

    static void generateSubt() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        String[] inputs = new String[n];
        String[] outputs = new String[n];

        for (int i = 0; i < n; i++) {
            inputs[i] = reader.readLine();
        }

        for (int i = 0; i < n; i++) {
            outputs[i] = reader.readLine().substring(9);
        }

        char[] alph = new char[26];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < inputs[i].length(); j++) {
                if (Character.isWhitespace(inputs[i].charAt(j))) {
                    continue;
                }
                char ch = alph[inputs[i].charAt(j) - 'a'];
                if (ch != 0 && ch != outputs[i].charAt(j)) {
                    System.out.println("wrong idea!!!");
                    return;
                }
                alph[inputs[i].charAt(j) - 'a'] = outputs[i].charAt(j);
            }
        }

        System.out.println(Arrays.toString(alph));
        for (int i = 0; i < 26; i++) {
            if (alph[i] == 0) {
                System.out.println("" + (char) (i + 'a'));
            }
        }

    }


    public static void main(String[] args) throws IOException {

        char[] sub = new char[]{'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r',
                'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        for (int i = 1;   i <= n; i++) {
            String s = reader.readLine();
            System.out.print("Case #" + i + ": ");
            StringBuilder builder = new StringBuilder();
            for (int j = 0; j < s.length(); j++) {
                if (!Character.isWhitespace(s.charAt(j))) {
                    builder.append(sub[s.charAt(j) - 'a']);
                }else{
                    builder.append(' ');
                }
            }
            System.out.println(builder);
        }


    }
}
