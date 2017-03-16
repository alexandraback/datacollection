/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package brattleship;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author martin
 */
public class Brattleship {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        String fileName;
        if (args.length < 1) {
            fileName = "/home/martin/GCJ/2015_1C/A/MyTest.txt";
        } else {
            fileName = args[0];
        }
        BufferedReader br = new BufferedReader(new FileReader(fileName));
        String line = br.readLine(); // Number of test cases
        int n = Integer.parseInt(line);
        for (int i = 0; i < n; i++) {
            String y = getPlay(br);
            System.out.println("Case #" + (i + 1) + ": "+y);
            //System.out.printf("Case #%d: %.8f %.8f\n", i+1, y.d, y.t);
        }
    }

    private static String getPlay(BufferedReader br) throws IOException {
        String line = br.readLine();
        Scanner s = new Scanner(line);
        int R = s.nextInt();
        int C = s.nextInt();
        int W = s.nextInt();
        
        int nc = C/W;
        int unknownEnd = 0;
        if ((C%W > 0)  && W > 1) {
            unknownEnd = 1;
        }
        return Integer.toString(R*nc+(W-1+unknownEnd));
    }
    
}
