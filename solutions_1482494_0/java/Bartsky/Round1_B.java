/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package round1_b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Formatter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Bart
 */
public class Round1_B {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String file = "B-small-attempt4";
        Formatter formatter = null;
        Scanner scanner;
        try {
            scanner = new Scanner(new FileInputStream(file + ".in"));

            formatter = new Formatter(new File(file + ".out"));

            int numberOfCases = scanner.nextInt();
            System.out.println("Number of cases: " + numberOfCases);

            for (int caseNr = 0; caseNr < numberOfCases; caseNr++) {
                int nLevels = scanner.nextInt();
                int starsToEarn = nLevels * 2;
                int nTurns = 0;
                int[] oneStar = new int[nLevels];
                int[] twoStars = new int[nLevels];

                for (int i = 0; i < nLevels; i++) {
                    oneStar[i] = scanner.nextInt();
                    twoStars[i] = scanner.nextInt();
                }
                insertionSort(twoStars, oneStar);


                int starsEarned = 0;
                boolean running = true;
                nTurns = 0;
                // 2 star that is 0?
                while (running && starsEarned < starsToEarn) {
                    int pos = getPos(twoStars, starsEarned);
                    if (pos >= 0) {
                        if (oneStar[pos] == Integer.MAX_VALUE) {
                            starsEarned++;
                        } else {
                            starsEarned += 2;
                            oneStar[pos] = Integer.MAX_VALUE;
                        }
                        twoStars[pos] = Integer.MAX_VALUE;

                    } else {
                        pos = getFirst(oneStar, starsEarned);
                        if (pos >= 0) {
                            starsEarned++;
                            oneStar[pos] = Integer.MAX_VALUE;

                        } else {
                            running = false;
                        }
                    }
                    nTurns++;
                }

                if (starsEarned == starsToEarn) {
                    System.out.printf("Case #%d: %d%n", caseNr + 1, nTurns);;
                    formatter.format("Case #%d: %d%n", caseNr + 1, nTurns);
                } else {
                    System.out.printf("Case #%d: Too Bad%n", caseNr + 1);;
                    formatter.format("Case #%d: Too Bad%n", caseNr + 1);
                }

            }
        } catch (FileNotFoundException ex) {
            System.err.println(ex.getMessage());
        }
        formatter.close();
    }

    public static int getPos(int[] array, int value) {
        int pos = -1;
        int i = 0;
        while (pos < 0 && i < array.length) {
            if (array[i] <= value) {
                pos = i;
            }

            i++;
        }
        return pos;
    }
    
    public static int getFirst(int[] array, int value){
        int pos = -1;
        int i=array.length-1;
       
        while(pos<0 && i>=0){
            if(array[i] <= value)
                pos = i;
            i--;
        }
        
        return pos;
    }

    public static void insertionSort(int[] arr1, int[] arr2) {
        int i, j, newValue, newValue2;
        for (i = 1; i < arr1.length; i++) {
            newValue = arr1[i];
            newValue2 = arr2[i];
            j = i;
            while (j > 0 && arr1[j - 1] > newValue) {
                arr1[j] = arr1[j - 1];
                arr2[j] = arr2[j - 1];
                j--;
            }
            arr1[j] = newValue;
            arr2[j] = newValue2;
        }
    }
}
