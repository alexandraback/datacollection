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
public class QCookieClicker {

    private static double solve(BufferedReader reader) throws Exception {
        String line = reader.readLine();
        String[] pieces = line.split(" ");
        double required = Double.parseDouble(pieces[0]);
        double added = Double.parseDouble(pieces[1]);
        double win = Double.parseDouble(pieces[2]);
        double time = 0;
        double speed = 2;
        while (true) {
            double currTime = required / speed;
            double remaining1 = win / speed;
            speed += added;
            double remaining2 = currTime + (win / speed);
            if (remaining1 < remaining2) {
                return time + remaining1;
            } else {
                time += currTime;
            }
        }
        
    }
    private static void solve(String filename) throws Exception {
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(new FileInputStream(filename + ".in")));
        PrintStream writer = new PrintStream(new File(filename + ".out"));
        int numCases = Integer.parseInt(reader.readLine());
        for (int i = 0; i < numCases; i++) {
            writer.println(String.format("Case #%d: %.7f", i + 1, solve(reader)));
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
