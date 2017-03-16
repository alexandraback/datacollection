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
import java.util.StringTokenizer;
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
        Scanner s = new Scanner(System.in);
//        int R = 100;
//        int[] cache = new int[R + 1];
//        for (int i = 1; i <= R; i++) {
//            if (i < 10) {
//                cache[i] = 0;
//                continue;
//            }
//            cache[i] = cache[i-1];
//            String h = (i + "");
//            int N = h.length();
//            System.out.println(i);
//            for (int j = 1; j < N; j++) {
//                int y = shift(i, j, N);
//                System.out.print(y+", ");
//                if (y <= R && i < y) {
//                    cache[i]++;
//                }
//            }
//            System.out.println(cache[i]);
//            
//        }
//        System.out.println(Arrays.toString(cache));
//        System.out.println(cache[R]);
//        System.out.println(cache[40]);
//        System.exit(0);
//
//
//
//
//








        int T = s.nextInt();
        for (int t = 1; t <= T; t++) {
            int A = s.nextInt();
            int B = s.nextInt();
            long count = 0;
            p:
            for (int i = A; i <= B; i++) {
                if (i < 10) {
                    continue;
                }
                String h = (i + "");
                int N = h.length();
//                for (int j = 1; j < N; j++) {
//                    if (h.charAt(j) < h.charAt(j - 1)) {
//                        continue p;
//                    }
//                }


                int c = 0;
                //System.out.println(i);
                TreeSet<Integer> st = new TreeSet<Integer>();
                for (int j = 1; j < N; j++) {
                    int y = shift(i, j, N);
                    st.add(y);
                    //  System.out.print(y+",");
                }
                for (int y : st) {
                    if (y <= B && i < y) {
                        count++;
                    }
                }

            }
            //System.out.println(chk);
            System.out.println("Case #" + t + ": " + count);
        }
    }

    private static int shift(int i, int j, int n) {
        String s = i + "";
        int N = s.length();
        if (n != N) {
            return -1;
        }
        int y = Integer.parseInt(s.substring(N - j) + s.substring(0, N - j));
        if ((y + "").length() != N) {
            return -1;
        }
        return y;
    }
}
