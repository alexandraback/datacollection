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
public class R1CBrattleship {
    
    private static int solve(BufferedReader reader) throws Exception {
        String linea = reader.readLine();
        String[] pedazos = linea.split(" ");
        int R = Integer.parseInt(pedazos[0]);
        int C = Integer.parseInt(pedazos[1]);
        int W = Integer.parseInt(pedazos[2]);
        if (W == 1)
            return R * C;

        int perRow = C / W;
        int total = perRow * R;
        if (C % W != 0)
            total++;
        total += W - 1;
        return total;
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
