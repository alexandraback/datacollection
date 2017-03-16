/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam2012;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;

/**
 *
 * @author Rumal
 */
public class QB {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        TreeSet<Integer> 
//        for (int i = 0; i <= 10; i++) {
//            for (int j = Math.max(i-1,0); j < 10 && j<=i+1 ; j++) {
//                for (int k = Math.max(i-1,0); k < 10 && k<=i+1 ; k++) {
//                    
//                }
//            }
//        }
//        
        
        
        
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            int ans = 0;
            int N = sc.nextInt();
            int S = sc.nextInt();
            int p = sc.nextInt();
            int[] gg = new int[N];
            for (int i = 0; i < N; i++) {
                gg[i] = sc.nextInt();
            }
            Arrays.sort(gg);
            //System.out.println(Arrays.toString(gg));
            int minSc = (2) * (p - 1) + p;
            int minSp = (2) * (p - 2) + p;
            minSc = Math.max(minSc, 0);
            minSp = Math.max(minSp, 2);
            //System.out.println(minSc+" "+minSp);
            for (int i : gg) {
                if (i >= minSc) {
                    //System.out.println(i);
                    ans++;
                    continue;
                }
                if (i >= minSp && S-- > 0) {
                    //System.out.println("*"+i);
                    ans++;
                    continue;
                }
                //System.out.println(i);
            }


            System.out.println("Case #" + t + ": " + ans);
        }
    }
}
