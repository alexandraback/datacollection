/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

/**
 *
 * @author Paris
 */
public class task4 {

    public static void main(String[] args) throws FileNotFoundException, IOException {

        BufferedReader in = new BufferedReader(new FileReader("D-small-attempt0.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
        int T = Integer.parseInt(in.readLine());

        for (int i = 0; i < T; i++) {
            String[] data = in.readLine().split(" ");
            int K = Integer.parseInt(data[0]);
            int C = Integer.parseInt(data[1]);
            int S = Integer.parseInt(data[2]);

            out.append("Case #" + (i + 1) + ": ");

            if (S >= K - 1 && C > 1) {
                if (K == 1) {
                    out.append("1");
                } else {
                    for (int m = 1; m < K; m++) {
                        out.append((m+1) + " ");
                    }
                }
            } else if (C == 1) {
                if (S == K) {
                    for (int m = 0; m < K; m++) {
                       out.append((m+1) + " ");
                    }
                } else {
                    out.append("IMPOSSIBLE");
                }
            }

            out.append("\n");

        }
        out.close();

    }

}
