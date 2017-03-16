/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lessmoney;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author martin
 */
public class LessMoney {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        String fileName;
        if (args.length < 1) {
            fileName = "/home/martin/GCJ/2015_1C/C/MyTest.txt";
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
        int C = s.nextInt();
        int D = s.nextInt();
        int V = s.nextInt();
        line = br.readLine();
        s = new Scanner(line);
        int[] dedoms = new int[D];
        for (int i = 0; i < D; i++) {
            dedoms[i] = s.nextInt();
        }
        
        int addD = 0;
        nextv: for (int v = 1; v <= V; v++) {
            int vv = v;
            for (int i = D-1; i >= 0; i--) {
                int d = dedoms[i];
                if (d == vv) {
                    continue nextv;
                }
                if (d > vv) {
                    continue;
                }
                // d < v
                vv = vv - d;
            }
            if (vv > 0) {
                int[] newDedoms = new int[D + 1];
                System.arraycopy(dedoms, 0, newDedoms, 0, D);
                newDedoms[D] = vv;
                dedoms = newDedoms;
                D++;
                addD++;
                Arrays.sort(dedoms);
            }
        }
        return Integer.toString(addD);
    }
}
