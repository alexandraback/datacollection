/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package A;

import java.util.*;
import java.math.*;

/**
 *
 * @author .
 */
public class A {

    static String input1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi   rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd   de kr kd eoya kw aej tysr re ujdr lkgc jv   a zoo";
    static String output1 = "our language is impossible to understand   there are twenty six factorial possibilities   so it is okay if you want to just give up   y qee";

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = Integer.parseInt(in.nextLine());
        String G;

        HashMap<Character, Character> mapping = new HashMap<Character, Character>(26);

        for (int i = 0; i < input1.length(); i++) {
            if (!mapping.containsKey(input1.charAt(i))) {
                mapping.put(input1.charAt(i), output1.charAt(i));
            }
        }
        mapping.put('q', 'z');

//        for(char a: mapping.keySet()) {
//            pl(a + " " + mapping.get(a));
//        }
//        pl(mapping.size());


        for (int kase = 1; kase <= T; kase++) {
            G = in.nextLine();

            String out = new String();

            for (int i = 0; i < G.length(); i++) {
                out += mapping.get(G.charAt(i));
            }

            pl("Case #" + kase + ": " + out);
        }
    }

    public static void pf(String s, Object... o) {
        System.out.printf(s, o);
    }

    public static void pl(Object o) {
        System.out.println(o);
    }

    public static void pr(Object o) {
        System.out.print(o);
    }
}
