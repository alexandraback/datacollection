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
public class QStandingOvation {
    
    private static int solve(BufferedReader reader) throws Exception {
        String linea = reader.readLine();
        String[] pedazos = linea.split(" ");
        String cadena = pedazos[1];
        int suma = 0;
        int necesarios = 0;
        for (int i = 0; i < cadena.length(); i++) {
            int actual = cadena.charAt(i) - '0';
            if (suma < i) {
                int agregar = i - suma;
                necesarios += agregar;
                suma += agregar;
            }
            suma += actual;
        }
        return necesarios;
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
