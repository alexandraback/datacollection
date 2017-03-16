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
public class SpeakingInTongues {

    private char[] mapto;
    private char[] mapfrom;
    
    public SpeakingInTongues() {
        mapto = new char['z' - 'a' + 1];
        mapfrom = new char['z' - 'a' + 1];
        
        this.parse("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
        this.parse("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
        this.parse("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
        
        mapto['z' - 'a'] = 'q';
        mapto['q' - 'a'] = 'z';
        mapfrom['z' - 'a'] = 'q';
        mapfrom['q' - 'a'] = 'z';
    }

    public void init() {
        
    }

    private void parse(String dest, String src) {
        int i = 0;
        for (char c : dest.toCharArray()) {
            if (c != ' ') {
                mapfrom[c - 'a'] = src.charAt(i);
                mapto[src.charAt(i) - 'a'] = c;
            }
            i++;
        }
    }
    
    public String solve(String dest) {
        StringBuilder reval = new StringBuilder(101);
        for (char c : dest.toCharArray()) {
            if (c != ' ') {
                reval.append(mapfrom[c - 'a']);
            } else {
                reval.append(' ');
            }
        }
        return reval.toString();
    }
    
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileReader("in.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
        SpeakingInTongues solver = new SpeakingInTongues();

        int testCount = in.nextInt();
        in.nextLine();
        for (int i = 0; i < testCount; i++) {
            solver.init();
            printIndex(i, out);
            out.print(solver.solve(in.nextLine()));
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