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
import java.util.Arrays;

/**
 *
 * @author osdroid
 */
public class QDeceitfulWar {
    
    private static String solve(BufferedReader reader) throws Exception {
        String line = reader.readLine();
        int numBlocks = Integer.parseInt(line);
        line = reader.readLine();
        String[] pieces = line.split(" ");
        double[] player1 = new double[numBlocks];
        for (int i = 0; i < numBlocks; i++)
            player1[i] = Double.parseDouble(pieces[i]);
        line = reader.readLine();
        pieces = line.split(" ");
        double[] player2 = new double[numBlocks];
        for (int i = 0; i < numBlocks; i++)
            player2[i] = Double.parseDouble(pieces[i]);
        Arrays.sort(player1);
        Arrays.sort(player2);
        int score1 = 0;
        int score2 = 0;
        int position1L = 0;
        int position1H = numBlocks - 1;
        int position2L = 0;
        int position2H = numBlocks - 1;
        
        for (int i = numBlocks - 1; i >= 0; i--) {
            if (player1[position1H] > player2[position2H]) {
                score2++;
                position2L++;
            } else {
                position2H--;
            }
            position1H--;
        }
        
        position1L = 0;
        position1H = numBlocks - 1;
        position2L = 0;
        position2H = numBlocks - 1;
        
        for (int i = numBlocks - 1; i >= 0; i--) {
            if (player2[position2H] > player1[position1H]) {
                position2H--;
                position1L++;
            } else {
                if (player1[position1L] > player2[position2L]) {
                    position2L++;
                    position1L++;
                    score1++;
                } else {
                    position2H--;
                    position1L++;
                }
            }
        }
        
        

        return String.format("%d %d", score1, score2);
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
