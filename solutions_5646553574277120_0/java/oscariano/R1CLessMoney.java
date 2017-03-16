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
import java.util.ArrayList;
import java.util.Arrays;

/**
 *
 * @author osdroid
 */
public class R1CLessMoney {

    private static int getFirst(boolean[] covered) {
        for (int i = 0; i < covered.length; i++)
            if (!covered[i])
                return i + 1;
        return 0;
    }
    private static int solve(BufferedReader reader) throws Exception {
        String linea = reader.readLine();
        String[] pedazos = linea.split(" ");
        int C = Integer.parseInt(pedazos[0]);
        int D = Integer.parseInt(pedazos[1]);
        int V = Integer.parseInt(pedazos[2]);
        linea = reader.readLine();
        pedazos = linea.split(" ");
        boolean[] covered = new boolean[V];
        Arrays.fill(covered, false);
        ArrayList<Integer> denoms = new ArrayList<>();
        for (int i = 0; i < D; i++) {
            denoms.add(Integer.parseInt(pedazos[i]));
        }
        boolean[] used = new boolean[denoms.size()];
        Arrays.fill(used, false);
        int sum = 0;
        while (true) {
            int pos = -1;
            for (int i = 0; i < used.length; i++) {
                if (used[i] == false) {
                    used[i] = true;
                    sum += denoms.get(i);
                    pos = i;
                    break;
                } else {
                    used[i] = false;
                    sum -= denoms.get(i);
                }
            }
            if (pos == -1)
                break;
            int val = sum - 1;
            if (val < V)
                covered[val] = true;
        }
        
        
        int count = 0;
        int min = 0;
        while((min = getFirst(covered)) != 0) {
            for (int i = V - 1; i >= 0; i--) {
                if (covered[i]) {
                    if (i + min < V) 
                        covered[i + min] = true;
                }
            }
            int val1 = min - 1;
            count++;
            if (val1 < V)
                covered[val1] = true;

        }
        
        
        return count;
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
