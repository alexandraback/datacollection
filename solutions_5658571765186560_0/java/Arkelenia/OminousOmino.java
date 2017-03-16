/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ominousomino;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author Sammy Guergachi <sguergachi at gmail.com>
 */
public class OminousOmino {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        File inputFile = new File("smallInput.txt");
        FileReader reader = null;
        BufferedReader bufferedReader = null;

        File outputFile = new File("smallOutput.txt");

        try {
            reader = new FileReader(inputFile);
            bufferedReader = new BufferedReader(reader);
            String line = bufferedReader.readLine();

            int pos = 1;
            
            while ((line = bufferedReader.readLine()) != null) {
                String[] numbers = line.split(" ");
                Integer X = Integer.parseInt(numbers[0]);
                Integer R = Integer.parseInt(numbers[1]);
                Integer C = Integer.parseInt(numbers[2]);

                if ((R * C) % X != 0) {
                    System.out.println("Case #" + pos + ": RICHARD");
                } else if (R < X && C < X) {
                    System.out.println("Case #" + pos + ": RICHARD");
                } else if (R >= X && C < ((X + 1) / 2)) {
                    System.out.println("Case #" + pos + ": RICHARD");
                } else if (R < ((X + 1) / 2) && C >= X) {
                    System.out.println("Case #" + pos + ": RICHARD");
                } else if (R >= X && X % 2 == 0 && C == X / 2 && C > 1) {
                    System.out.println("Case #" + pos + ": RICHARD");
                } else if (R == X / 2 && X % 2 == 0 && C >= X && R > 1) {
                    System.out.println("Case #" + pos + ": RICHARD");
                } else {
                    System.out.println("Case #" + pos + ": GABRIEL");
                }
                pos++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (reader != null) {
                    reader.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    
}
