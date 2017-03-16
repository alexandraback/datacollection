/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package round1aa;

import java.util.*;
import java.io.*;

/**
 *
 * @author DUC
 */
public class Round1AA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        File file = new File("D:/A-large.in");
        try {
            Scanner input = new Scanner(file);
            int T = input.nextInt();
            for (int n = 0; n < T; n++) {
                String str = input.next();
                String result = str.charAt(0) + "";
                for (int i = 1; i < str.length(); i++) {
                    if (str.charAt(i) >= result.charAt(0)) {
                        result = str.charAt(i) + result;
                    } else {
                        result = result + str.charAt(i);
                    }
                }
                System.out.printf("Case #" + (n + 1) + ": " + result + "\n");
            }
            input.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
