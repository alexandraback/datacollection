/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj2012.qual;

import gcj2010.round2.*;
import gcj2009.*;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author scbit
 */
public class P1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        new P1().run();
    }
    PrintWriter pw;
    static HashMap<Character, Character> map = new HashMap<Character, Character>();

    static {
        map.put('y', 'a');
        map.put('e', 'o');
        map.put('q', 'z');

    }

    void run() throws Exception {
        String[] to = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
        String[] from = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};

        for (int i = 0; i < from.length; i++) {
            String t = to[i];
            String f = from[i];
            for (int index = 0; index < f.length(); index++) {
                char c1 = f.charAt(index);
                char c2 = t.charAt(index);
                Character r = map.put(c2, c1);
                if (r != null && r != c1) {
                    System.err.println(f + " @" + index);
                    System.err.println("map:" + c1 + " " + r);
                }
            }
        }
        if (map.size() == 26) {
            boolean[] hits = new boolean[128];
            for (int i = 0; i < 128; i++) {
                hits[i] = false;
            }
            char key = 0, value = 0;
            for (char c = 'a'; c <= 'z'; c++) {
                Character obj = map.get(c);
                if (obj == null) {
                    key = c;
                } else {
                    hits[(char) obj] = true;
                }
            }
            for (char c = 'a'; c <= 'z'; c++) {
                if (!hits[c]) {
                    value = c;
                    break;
                }
            }
            map.put(key, value);
        }
        if (map.size() != 27) {

            System.err.println("not 27!");
            System.err.println(map.size());
            System.err.println(map);
            return;
        }
        File infile = new File("A-small-attempt0.in");
        String outfile = "result";
        pw = new PrintWriter(outfile);
        int N = 0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        //N=Integer.parseInt(br.readLine());
        Scanner sc = new Scanner(infile);
        N = sc.nextInt();
        sc.nextLine();
        for (int case_i = 1; case_i <= N; case_i++) {
            StringBuilder result = new StringBuilder();
            String f1 = sc.nextLine();
            for (int i = 0; i < f1.length(); i++) {
                char c = f1.charAt(i);
                result.append(map.get(c));
            }
            pw.printf("Case #%d: %s\n", case_i, result.toString());
            System.out.printf("Case #%d: %s\n", case_i, result.toString());
        }
        pw.close();
    }
}
