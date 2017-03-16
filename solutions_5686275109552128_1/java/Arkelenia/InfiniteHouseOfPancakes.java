/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package infinitehouseofpancakes;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author Sammy Guergachi <sguergachi at gmail.com>
 */
public class InfiniteHouseOfPancakes {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        File inputFile = new File("largeInput.txt");
        FileReader reader = null;
        BufferedReader bufferedReader = null;

        File outputFile = new File("largeOutput.txt");

        try {
            reader = new FileReader(inputFile);
            bufferedReader = new BufferedReader(reader);
            String line = bufferedReader.readLine();

            int pos = 1;
            
            while ((line = bufferedReader.readLine()) != null) {
                ArrayList<Integer> array = new ArrayList<>();
                line = bufferedReader.readLine();
                for (String num : line.split(" ")) {
                    array.add(Integer.parseInt(num));
                }
                
                // Get maximum element
                Integer maxElement = 0;
                for (Integer element : array) {
                    if (maxElement < element) {
                        maxElement = element;
                    }
                }

                Integer minNeeded = maxElement;
                for (int i = 1; i <= maxElement; ++i) {
                    int sum = 0;
                    int max = 0;
                    for (Integer element : array) {
                        int nb = ((int)(element + i - 1) / i);
                        int maxValue = ((int)(element + nb - 1) / nb);
                        sum += nb - 1;
                        if (max < maxValue) {
                            max = maxValue;
                        }
                    }
                    if (minNeeded > sum + max) {
                        minNeeded = sum + max;
                    }
                }

                System.out.println("Case #" + pos + ": " + minNeeded);
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
