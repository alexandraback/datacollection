/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package round1ab;

import java.util.*;
import java.io.*;

/**
 *
 * @author DUC
 */
public class Round1AB {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        File file = new File("D:/B-small-attempt0.in");
        try {
            Scanner input = new Scanner(file);
            int T = input.nextInt();

            for (int n = 0; n < T; n++) {
                Vector<Integer> v = new Vector<Integer>();
                v.setSize(2501);
                for (int i = 1; i <= 2500; i++) {
                    v.set(i, 0);
                }
                int N = input.nextInt();
                for (int i=0;i<2*N-1;i++){
                    for (int j=0;j<N;j++){
                        int a = input.nextInt();
                    int k = v.get(a) + 1;
                    v.set(a, k);
                    }
                }
//                while (input.hasNext()) {
//                    int a = input.nextInt();
//                    int k = v.get(a) + 1;
//                    v.set(a, k);
//                }
//                Vector<Integer> k = new Vector<Integer>();

                System.out.printf("Case #" + (n + 1) + ": ");
                for (int i = 1; i <= 2500; i++) {
                    if (v.get(i) % 2 != 0) {
//                        k.add(i);
                        System.out.printf(i + " ");
                    }
                }
                System.out.printf("\n");

//                + result + "\n");
            }

            input.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }

}
