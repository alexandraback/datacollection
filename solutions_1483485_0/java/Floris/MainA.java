/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam.qual_2012;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author floris
 */
public class MainA {

    static char[] mapping = new char[256];
    
    public static void main(String[] args) throws Exception {
        buildMapping(" ", " ");
        buildMapping("qz", "zq");
        buildMapping("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
        buildMapping("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
        buildMapping("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
//        printMapping();

        String f = "/home/floris/dev/java/Test/src/codejam/qual_2012/A-small-attempt0.in";
        Scanner sc = new Scanner(new File(f));
        System.setOut(new PrintStream(new File(f+".out")));
        int T = sc.nextInt();
        sc.nextLine();
        for (int i=1; T-- > 0; i++) {
            System.out.printf("Case #%d: %s%n", i, performMapping(sc.nextLine()));
        }
    }

    private static void buildMapping(String string, String string0) {
        for (int i = 0; i < string.length(); i++) {
            if (mapping[string.charAt(i)] != 0 && mapping[string.charAt(i)] != string0.charAt(i)) {
                System.out.println("Problem mapping "+string.charAt(i)+" to " + string0.charAt(i));
                System.out.println("  "+string);
                System.out.println("  "+string0);
            } else {
                mapping[string.charAt(i)] = string0.charAt(i);
            }
        }
    }
    private static void printMapping() {
        for (int i = 'a'; i <= 'z'; i++) {
            System.out.print((char)i);
        }
        System.out.println();
        for (int i = 'a'; i <= 'z'; i++) {
            if (mapping[i] != 0) {
                System.out.print((char)mapping[i]);
            } else {
                System.out.print('-');
            }
        }
        System.out.println();
    }
    private static String performMapping(String s) {
        StringBuilder sb = new StringBuilder(s.length());
        for (int i = 0; i < s.length(); i++) {
            sb.append(mapping[s.charAt(i)]);
        }
        return sb.toString();
    }

}
