/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Qualifier2012;

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
import java.util.List;
import java.util.Map;
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
        FileInputStream fis = new FileInputStream("src\\Qualifier2012\\tez");
        DataInputStream dis = new DataInputStream(fis);
        BufferedReader br = new BufferedReader(new InputStreamReader(dis));

        FileInputStream fis2 = new FileInputStream("src\\Qualifier2012\\A-small-attempt0.in");
        DataInputStream dis2 = new DataInputStream(fis2);
        BufferedReader br2 = new BufferedReader(new InputStreamReader(dis2));

        FileWriter fw = new FileWriter("src\\Qualifier2012\\output.out");
        BufferedWriter out = new BufferedWriter(fw);

        Map<Character, Character> mapping = new TreeMap<Character, Character>();
        mapping.put('q', 'z');
        mapping.put('e', 'o');
        mapping.put('y', 'a');
        mapping.put('z', 'q');
        String[] sol = {
            "our language is impossible to understand",
            "there are twenty six factorial possibilities",
            "so it is okay if you want to just give up"};
        int caseCount = 0;
        caseCount = Integer.parseInt(br.readLine());
        for (int i = 0; i < caseCount; i++) {
            String line = br.readLine();
            for (int y = 0; y < line.length(); y++) {
                mapping.put(line.charAt(y), sol[i].charAt(y));
            }
        }

        caseCount = Integer.parseInt(br2.readLine());
        String[] finalSol = new String[caseCount];
        for (int i = 0; i < caseCount; i++) {
            StringBuilder sb = new StringBuilder();
            String line = br2.readLine();
            for (int y = 0; y < line.length(); y++) {
                sb.append(mapping.get(line.charAt(y)));
            }
            finalSol[i] = sb.toString();
            out.write("Case #" + (i+1) + ": " + finalSol[i] + "\n");
        }
        System.out.println(mapping);
        out.close();
        br.close();
    }

    private static void doit(BufferedWriter out, int casec, int[] v1, int[] v2) throws IOException {
        Arrays.sort(v1);
        Arrays.sort(v2);

        long res = 0;
        for (int i = 0; i < v1.length; i++) {
            long a = v1[i];
            long b = v2[v1.length - i - 1];
            res += a * b;
        }
        out.write("Case #" + casec + ": " + res + "\n");
    }
}
