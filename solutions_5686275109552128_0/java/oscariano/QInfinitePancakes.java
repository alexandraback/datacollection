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
import java.util.Collections;
import java.util.PriorityQueue;

/**
 *
 * @author osdroid
 */
public class QInfinitePancakes {

    
    
    private static int solve(BufferedReader reader) throws Exception {
        String linea = reader.readLine();
        linea = reader.readLine();
        String[] pedazos = linea.split(" ");
        PriorityQueue<Integer> heap = new PriorityQueue<>(pedazos.length, 
                Collections.reverseOrder());
        for (int i = 0; i < pedazos.length; i++) {
            heap.add(Integer.parseInt(pedazos[i]));
        }
        int min = heap.peek();
        int maxCuts = min;
        int count = 0;
        for (int i = 0; i < maxCuts; i++) {
            count++;
            int valor = heap.poll();
            int mitad = valor / 2;
            heap.add(mitad);
            heap.add(valor - mitad);
            int tentativo = heap.peek() + count;
            if (tentativo < min)
                min = tentativo;
        }
        
        return min;
    }
    
    private static void solve(String filename) throws Exception {
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(new FileInputStream(filename + ".in")));
        PrintStream writer = new PrintStream(new File(filename + ".out"));
        int numCases = Integer.parseInt(reader.readLine());
        for (int i = 0; i < numCases; i++) {
            writer.println(String.format("Case #%d: %d", i + 1, solve(reader)));
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
