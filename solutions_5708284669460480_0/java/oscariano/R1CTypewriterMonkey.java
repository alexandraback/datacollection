/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package r1ctypewritermonkey;

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
public class R1CTypewriterMonkey {

    private static int count(char[] letras, char[] palabra) {
        int count = 0;
        for (int i = 0; i + palabra.length <= letras.length; i++) {
            boolean valido = true;
            for (int j = 0; j < palabra.length; j++) {
                if (letras[i + j] != palabra[j]) {
                    valido = false;
                    break;
                }
            }
            if (valido)
                count++;
        }
        return count;
    }
    private static double solve(BufferedReader reader) throws Exception {
        String linea = reader.readLine();
        String[] pedazos = linea.split(" ");
        int K = Integer.parseInt(pedazos[0]);
        int L = Integer.parseInt(pedazos[1]);
        int S = Integer.parseInt(pedazos[2]);
        char[] keyboard = reader.readLine().toCharArray();
        char[] goal = reader.readLine().toCharArray();
        int[] countKeyboard = new int[26];
        Arrays.fill(countKeyboard, 0);
        for (int i = 0; i < K; i++) {
            countKeyboard[keyboard[i] - 'A']++;
        }
        for (int i = 0; i < L; i++) {
            if (countKeyboard[goal[i] - 'A'] == 0)
                return 0;
        }
        
        
        int rolling = L;
        for (int i = 1; i < L; i++) {
            boolean valido = true;
            for (int j = 0; i + j < L; j++) {
                if (goal[j] != goal[i + j]) {
                    valido = false;
                    break;
                }
            }
            if (valido) {
                rolling = i;
                break;
            }
        }
        int expected = 1 + ((S - L) / rolling);
        
        int[] posiciones = new int[S];
        Arrays.fill(posiciones, 0);
        char[] cadena = new char[S];
        Arrays.fill(cadena, keyboard[0]);
        int[] bananas = new int[S + 1];
        Arrays.fill(bananas, 0);
        int total = 0;
        while (true) {
            int count = count(cadena, goal);
            total++;
            bananas[count]++;
            boolean cambiado = false;
            for (int i = 0; i < S && !cambiado; i++) {
                posiciones[i]++;
                if (posiciones[i] >= K) {
                    posiciones[i] = 0;
                } else {
                    cambiado = true;
                }
                cadena[i] = keyboard[posiciones[i]];
            }
            if (!cambiado)
                break;
        }
        double dar = 0;
        int max = 0;
        for (int i = 1; i < bananas.length; i++) {
            dar += (double)(i * bananas[i]) / total;
            if (bananas[i] > 0)
                max = i;
        }
        
        return max - dar;
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
