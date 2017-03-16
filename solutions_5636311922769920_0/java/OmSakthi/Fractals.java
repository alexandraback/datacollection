/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fractals;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 *
 * @author user
 */
public class Fractals {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        //variable initialization

        String strLine, output;

//Read in a file and process one line at a time
        FileReader singleFile = new FileReader("E:\\GoogleCodeJam\\input4.txt");
        BufferedReader reader = new BufferedReader(singleFile);
        FileWriter outFile = new FileWriter("E:\\GoogleCodeJam\\output4.txt");
        BufferedWriter writer = new BufferedWriter(outFile);

        strLine = reader.readLine();
        System.out.println("Input" + strLine);
        StringTokenizer st;
        int K, C, S;

        int count = Integer.parseInt(strLine);

        for (int j = 1; j <= count; j++) {
            strLine = reader.readLine();
            System.out.println("Input" + strLine);
            st = new StringTokenizer(strLine);
            K = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            S = Integer.parseInt(st.nextToken());

            if (S < (K / 2 + 1) || (C == 1 && K != S)) {
                output = "Case #" + j + ": IMPOSSIBLE";
                writer.write(output);
                writer.newLine();
                writer.flush();
                continue;
            }

            if (C == 1) {
                output = "Case #" + j + ":";
                for (int t = 1; t <= K; t++) {
                    output = output + " " + t;
                }
            } else if (K == 1) {
                output = "Case #" + j + ": 1";
            } else if (K == 2) {
                output = "Case #" + j + ": 2";
            }else if (K == 3) {
                output = "Case #" + j + ": 2 6";

            } else {
                int next, total = K/2 + 1;
                output = "Case #" + j + ": 2";
                
                for (int n = 2; n <= total; n++){
                    next = (n  * K) + (K - (n - 2));
                    output = output + " " + next;
                }
            }
            writer.write(output);
            writer.newLine();
            writer.flush();

        }

        writer.close();
    }
}
