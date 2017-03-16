/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.podervisual.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

/**
 *
 * @author osdroid
 */
public class QOminousOmino {
    private static final String RICHARD = "RICHARD";
    private static final String GABRIEL = "GABRIEL";

    private static String solve(BufferedReader reader) throws Exception {
        String linea = reader.readLine();
        String[] pedazos = linea.split(" ");
        int X = Integer.parseInt(pedazos[0]);
        int R = Integer.parseInt(pedazos[1]);
        int C = Integer.parseInt(pedazos[2]);
        if (X == 1)
            return GABRIEL;
        int mult = R * C;
        if (mult % X != 0)
            return RICHARD;
        if (X == 3 && (R == 1 || C == 1))
            return RICHARD;
        if (X == 4 && (R < 3 || C < 3))
            return RICHARD;
        return GABRIEL;
    }

    private static void solve(String filename) throws Exception {
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(new FileInputStream(filename + ".in")));
        PrintStream writer = new PrintStream(new File(filename + ".out"));
        int numCases = Integer.parseInt(reader.readLine());
        for (int i = 0; i < numCases; i++) {
            writer.println(String.format("Case #%d: %s", i + 1, solve(reader)));
        }
        writer.close();
    }
    
    public static void main(String[] args) throws Exception {
        System.out.println("File?: ");
        BufferedReader lector = new BufferedReader(
                new InputStreamReader(System.in));
        String filename = lector.readLine();
        solve(filename);
    }
}
