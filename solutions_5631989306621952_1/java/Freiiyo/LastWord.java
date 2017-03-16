package com.nwollmann.codejam.year_2016.round1a;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by Nicholas on 4/15/2016.
 */
public class LastWord {

    static final boolean CONSOLE_MODE = false;
    static String fileName = "A-large";

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

    public static void solve(){

        int cases = reader.nextInt();

        for(int i = 1; i <= cases; i++) {
            writer.println("Case #" + i + ": " + solveCase());
        }

    }

    public static String solveCase(){
        String in = reader.next();

        String build = in.substring(0, 1);

        for(int i = 1; i < in.length(); i++) {
            char c = in.charAt(i);
            if(c < build.charAt(0))
                build = build + c;
            else
                build = c + build;
        }

        return build;
    }

}
