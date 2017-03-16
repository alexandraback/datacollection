package com.nwollmann.codejam.year_2016.round1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by Nicholas on 4/30/2016.
 */
public class CloseMatch {

    static final boolean CONSOLE_MODE = false;
    static String fileName = "B-small-attempt0";

    static File in, out;
    static PrintWriter writer;
    static Scanner reader;

    public static void main(String[] args) throws Exception{
        if(CONSOLE_MODE) {
            writer = new PrintWriter(System.out);
            reader = new Scanner(System.in);
        } else {
            in = new File("C:/Codejam/in/" + fileName + ".in");
            out = new File("C:/Codejam/result.out");
            writer = new PrintWriter(new FileOutputStream(out));
            reader = new Scanner(new FileInputStream(in));
        }

        solve();

        writer.close();
        reader.close();
    }

    public static void solve() throws Exception{

        int cases = reader.nextInt();

        for(int i = 1; i <= cases; i++) {
            writer.println("Case #" + i + ": " + solveCase());
        }

    }

    public static String solveCase() throws Exception{

        String c = reader.next();
        String j = reader.next();

        int state = 0;
        int cOut = 0;
        int jOut = 0;

        cChar = c.toCharArray();
        jChar = j.toCharArray();

        recursive(0, 0, 0);

        return passback[0] + " " + passback[1];

    }

    static char[] cChar;
    static char[] jChar;
    static int[] passback = new int[2];

    public static void recursive(int cPre, int jPre, int index) throws Exception{
        int[] toReturn = new int[2];
        if(index == cChar.length) {
            passback[0] = cPre;
            passback[1] = jPre;
            return;
        } else {
            int state;
            if(cPre > jPre) state = 1;
            else if(jPre > cPre) state = -1;
            else state = 0;
            if(cChar[index] == '?' && jChar[index] == '?') {
                if(state == 0) {
                    //0 0, 0 1, or 1 0
                    int[] best = new int[2];
                    int difference = 0;
                    //0 0
                    recursive(cPre * 10, jPre * 10, index + 1);
                    best[0] = passback[0];
                    best[1] = passback[1];
                    difference = Math.abs(best[0] - best[1]);
                    //1 0
                    recursive(cPre * 10 + 1, jPre * 10, index + 1);
                    if(Math.abs(passback[0] - passback[1]) < difference) {
                        best[0] = passback[0];
                        best[1] = passback[1];
                        difference = Math.abs(best[0] - best[1]);
                    }
                    //0 1
                    recursive(cPre * 10 + 1, jPre * 10, index + 1);
                    if(Math.abs(passback[0] - passback[1]) < difference) {
                        best[0] = passback[0];
                        best[1] = passback[1];
                    }
                    passback[0] = best[0];
                    passback[1] = best[1];
                } else if(state == 1) {
                    cPre *= 10;
                    jPre *= 10;
                    jPre += 9;
                    recursive(cPre, jPre, index + 1);
                } else if(state == -1) {
                    jPre *= 10;
                    cPre *= 10;
                    cPre += 9;
                    recursive(cPre, jPre, index + 1);
                }
            } else if (cChar[index] == '?') {
                int jval = Integer.parseInt(jChar[index] + "");
                if(state == 0) {
                    jPre = jPre * 10 + jval;
                    //j - 1, j, j+1
                    int[] best = new int[2];
                    int difference = 0;
                    //j - 1
                    recursive(cPre * 10 + jval - 1, jPre, index + 1);
                    best[0] = passback[0];
                    best[1] = passback[1];
                    difference = Math.abs(best[0] - best[1]);
                    //j
                    recursive(cPre * 10 + jval, jPre, index + 1);
                    if(Math.abs(passback[0] - passback[1]) < difference) {
                        best[0] = passback[0];
                        best[1] = passback[1];
                        difference = Math.abs(best[0] - best[1]);
                    }
                    //j + 1
                    recursive(cPre * 10 + jval + 1, jPre, index + 1);
                    if(Math.abs(passback[0] - passback[1]) < difference) {
                        best[0] = passback[0];
                        best[1] = passback[1];
                    }
                    passback[0] = best[0];
                    passback[1] = best[1];
                    return;
                } else if (state == 1) {
                    cPre *= 10;
                } else if (state == -1) {
                    cPre *= 10;
                    cPre += 9;
                }

                jPre *= 10;
                jPre += jval;
                recursive(cPre, jPre, index + 1);
            } else if (jChar[index] == '?') {
                int cval = Integer.parseInt(cChar[index] + "");
                if(state == 0) {
                    cPre = cPre * 10 + cval;
                    //j - 1, j, j+1
                    int[] best = new int[2];
                    int difference = 0;
                    //j - 1
                    recursive(jPre * 10 + cval - 1, cPre, index + 1);
                    best[0] = passback[0];
                    best[1] = passback[1];
                    difference = Math.abs(best[0] - best[1]);
                    //j
                    recursive(jPre * 10 + cval, cPre, index + 1);
                    if(Math.abs(passback[0] - passback[1]) < difference) {
                        best[0] = passback[0];
                        best[1] = passback[1];
                        difference = Math.abs(best[0] - best[1]);
                    }
                    //j + 1
                    recursive(jPre * 10 + cval + 1, cPre, index + 1);
                    if(Math.abs(passback[0] - passback[1]) < difference) {
                        best[0] = passback[0];
                        best[1] = passback[1];
                    }
                    passback[0] = best[0];
                    passback[1] = best[1];
                    return;
                } else if (state == -1) {
                    jPre *= 10;
                } else if (state == 1) {
                    jPre *= 10;
                    jPre += 9;
                }

                cPre *= 10;
                cPre += cval;
                recursive(cPre, jPre, index + 1);
            } else {
                cPre *= 10;
                cPre += Integer.parseInt(cChar[index] + "");
                jPre *= 10;
                jPre += Integer.parseInt(jChar[index] + "");
                recursive(cPre, jPre, index + 1);
            }
        }
    }





    class pair {
        int location;
        int value;
    }

}
