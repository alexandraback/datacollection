package PracitceProject;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by Sahil on 16/04/16.
 */
public class CharSort {
    public static void main(String[] args) throws IOException {
        {
            String fileAddr = "/users/sahil/Desktop/filename.txt";
            Scanner scanner = new Scanner(System.in).useDelimiter(System.getProperty("line.separator"));
            int numTestcases = scanner.nextInt();
            File file = new File(fileAddr);
            if (!file.exists()) {
                file.createNewFile();
            }
            FileWriter fw = new FileWriter(file.getAbsoluteFile());
            BufferedWriter bw = new BufferedWriter(fw);
            for (int j = 0; j < numTestcases; j++) {
                String letters = scanner.next();
                char[] lettChar = letters.toCharArray();
                String test = "";
                int left = 0;
                for (int k = 0; k < lettChar.length; k++) {
                    if ((int) lettChar[k] >= left) {
                        test = lettChar[k] + test;
                        left = (int) lettChar[k];
                    } else {
                        test = test + lettChar[k];
                    }

                }
                test="Case #" + (j+1) + ": " + test;
                bw.write(test);
                bw.newLine();

            }
            bw.close();
            scanner.close();
        }
    }
}
