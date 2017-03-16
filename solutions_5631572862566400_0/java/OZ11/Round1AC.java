/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package round1ac;

import java.util.*;
import java.io.*;

/**
 *
 * @author DUC
 */
public class Round1AC {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        File file = new File("D:/C-small-attempt1 (1).in");
        try {
            Scanner input = new Scanner(file);
            int T = input.nextInt();
            for (int n = 0; n < T; n++) {
                int N = input.nextInt();
                Vector<Integer> v = new Vector<Integer>();
                v.setSize(N + 1);
                for (int i = 1; i <= N; i++) {
                    v.set(i, 0);
                }
                for (int i = 1; i <= N; i++) {
                    v.set(i, input.nextInt());
                }
                int max = 0;
                for (int i = 1; i <= N; i++) {
                    int count = 0;
                    int start = i;
                    String str = "";
                    boolean temp = true;
                    while (temp) {
                        str += v.get(start);
                        int cur = start;
                        if (v.get(start) != -1) {
                            start = v.get(start);
                            v.set(cur, -1);
                        } else {
                            temp = false;
                        }
                    }
                    if (max < str.length()) {
                        max = str.length();
                    }
                }
                System.out.printf("Case #" + (n + 1) + ": " + (max - 2) + "\n");
            }
            input.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

}
