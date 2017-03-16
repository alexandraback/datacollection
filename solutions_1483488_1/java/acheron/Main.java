/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Qualifier2012.c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

/**
 *
 * @author Ant Ongun Kefeli
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileInputStream fis = new FileInputStream("src\\Qualifier2012\\c\\C-large.in");
        Scanner sc = new Scanner(fis);

        FileWriter fw = new FileWriter("src\\Qualifier2012\\c\\output.out");
        BufferedWriter out = new BufferedWriter(fw);

        int caseCount = 0;
        caseCount = sc.nextInt();
        for (int i = 0; i < caseCount; i++) {
            long smallLimit = sc.nextLong();
            long bigLimit = sc.nextLong();

            doit(out, i + 1, smallLimit, bigLimit);

        }

        out.close();
        sc.close();
    }

    private static void doit(BufferedWriter out, int casec, long smallLimit, long bigLimit) throws IOException {

        long res = 0;
        if (bigLimit < 21) {
            res = 0;
        } else {
            int digits = (int) Math.log10(smallLimit) + 1;
            Map<Long, List<Long>> map = new HashMap();
            for (long i = smallLimit; i <= bigLimit; i++) {
                for (int j = 1; j <= digits - 1; j++) {
                    String str = Long.toString(i);
                    StringBuilder sb = new StringBuilder();
                    sb.append(str.substring(str.length() - j, str.length()));
                    sb.append(str.substring(0, str.length() - j));

                    long cr = Long.parseLong(sb.toString());
                    if (cr >= smallLimit && cr <= bigLimit) {

                        long sm = i;
                        long big = cr;
                        if (i == cr) {
                            continue;
                        }
                        if (cr < i) {
                            sm = cr;
                            big = i;
                        }
                        if (map.containsKey(sm) && map.get(sm).contains(big)) {
                            continue;
                        }
                        if (map.get(sm) == null) {
                            List<Long> list = new ArrayList<Long>();
                            list.add(big);
                            map.put(sm, list);
                        } else {
                            List<Long> list = map.get(sm);
                            list.add(big);
                            map.put(sm, list);
                        }
                        res++;
                    }
                }
            }
        }
        out.write(
                "Case #" + casec + ": " + res + "\n");

    }
}
