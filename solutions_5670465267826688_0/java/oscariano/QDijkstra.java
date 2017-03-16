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
import java.util.Iterator;
import java.util.ListIterator;

/**
 *
 * @author osdroid
 */
public class QDijkstra {
    
    private static boolean[][] sign = {
        {false, false, false, false},
        {false, true, false, true},
        {false, true, true, false},
        {false, false, true, true}
    };
    private static int[][] mult = {
        {0, 1, 2, 3},
        {1, 0, 3, 2},
        {2, 3, 0, 1},
        {3, 2, 1, 0}
    };

    
    private static String solve(BufferedReader reader) throws Exception {
        String linea = reader.readLine();
        String[] pedazos = linea.split(" ");
        int times = Integer.parseInt(pedazos[1]);
        linea = reader.readLine();
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < times; i++) {
            builder.append(linea);
        }
        String texto = builder.toString();
        ArrayList<Integer> posI = new ArrayList<>();
        ArrayList<Integer> posK = new ArrayList<>();
        boolean negativo = false;
        int actual = 0;
        for (int i = 0; i < texto.length(); i++) {
            int nuevo = texto.charAt(i) - 'i' + 1;
            if (sign[actual][nuevo])
                negativo = !negativo;
            actual = mult[actual][nuevo];
            if (!negativo && actual == 1)
                posI.add(i + 1);
        }
        
        negativo = false;
        actual = 0;
        for (int i = texto.length() - 1; i >= 0; i--) {
            int nuevo = texto.charAt(i) - 'i' + 1;
            if (sign[nuevo][actual])
                negativo = !negativo;
            actual = mult[nuevo][actual];
            if (!negativo && actual == 3)
                posK.add(i);
        }
        
        boolean posible = false;
        if (posI.size() == 0 || posK.size() == 0)
            return "NO";
        Iterator itI = posI.iterator();
        while (itI.hasNext()) {
            ListIterator itK = posK.listIterator(posK.size());
            int ini = (int)itI.next();
            int fin = (int)itK.previous();
            negativo = false;
            actual = 0;
            int pos = ini;
            for (; pos < fin; pos++) {
                int nuevo = texto.charAt(pos) - 'i' + 1;
                if (sign[actual][nuevo])
                    negativo = !negativo;
                actual = mult[actual][nuevo];
            }
            if (!negativo && actual == 2)
                return "YES";
            while (itK.hasPrevious()) {
                fin = (int)itK.previous();
                for (; pos < fin; pos++) {
                    int nuevo = texto.charAt(pos) - 'i' + 1;
                    if (sign[actual][nuevo])
                        negativo = !negativo;
                    actual = mult[actual][nuevo];
                }
                if (!negativo && actual == 2)
                    return "YES";
            }
        }
        return "NO";
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
