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
public class R1BCounterCulture {

    private static int reverse(int N) {
        int num = 0;
        while (N > 0) {
            num = num * 10 + (N % 10);
            N = N / 10;
        }
        return num;
    }
    private static int solve2(int N) {
        int numActual = 0;
        int count = 0;
        if (N == 10)
            return 10;
        while (numActual != N) {
            if (numActual <= 10) {
                numActual++;
                count++;
            }
            
            int mejor = -1;
            int suma = count;
            for (int i = 1; i <= 9; i++) {
                int temp = numActual + i;
                if (temp == N)
                    return count + i;
                if (temp > mejor) {
                    suma = count + i;
                    mejor = temp;
                }
                int temp2 = reverse(temp);
                if (temp2 > N)
                    continue;
                if (temp2 > mejor) {
                    suma = count + i + 1;
                    mejor = temp2;
                }
            }
            numActual = mejor;
            count = suma;
        }
        
        return count;
    }
    private static int solve(BufferedReader reader) throws Exception {
        String linea = reader.readLine();
        int N = Integer.parseInt(linea);
        int N1 = N - 1;
        if (N <= 20)
            return N;
        if (N <= 100) {
            return 11 + (N1 / 10) + (N1 % 10);
        }
        int digits = Integer.toString(N).length();
        int count = 29;
        int actual = 100;
        for (int i = 3; i < digits; i++) {
            count += actual + 9;
            actual *= 10;
        }
        
        count += (N1 / actual) + (N1 % actual);
        int otro = solve2(N);
        //if (otro != count)
        //    System.out.println("ouch " + N + ": " + otro + ", " + count);
        return otro;
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
