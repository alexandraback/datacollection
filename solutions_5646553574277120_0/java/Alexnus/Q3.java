package com.nus.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.TreeSet;

public class Q3 {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new FileReader(new File(args[0])));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File(args[1]))));
        int iterationsNum = Integer.parseInt(br.readLine());


        for (int i = 0; i < iterationsNum; ++i) {
            String[] cdv = br.readLine().split("\\s+");
            Long C = Long.parseLong(cdv[0]);
            Integer D = Integer.parseInt(cdv[1]);
            Integer V = Integer.parseInt(cdv[2]);



            TreeSet<Integer> existing = new TreeSet<Integer>();
            String[] denominationsString = br.readLine().split("\\s+");
            TreeSet<Integer> canBeRemoved = new TreeSet<>();

            for (int j = 0; j < D; ++j) {
                int d = Integer.parseInt(denominationsString[j]);
                if (d > V) {
                    canBeRemoved.add(d);
                    continue;
                }
                existing.add(d);
            }

            int missing = -1;
            int totalReplaced = -1;
            do {
                totalReplaced += 1;
                missing = missingCalc(existing, V);
                if (missing != 0) {
                    existing.add(missing);
                }
            } while (missing != 0);


            // int time = new Double(Math.ceil(Math.log(max) / Math.log(2)) + 1).intValue();
            bw.write("Case #" + (i + 1) + ": " + totalReplaced + "\n");
        }

        br.close();
        bw.close();
    }

    static int missingCalc(TreeSet<Integer> existing, int V) {
        boolean[] Varr = new boolean[V + 1];

        for (int d : existing) {
            for (int k = V - d; k >= 0; k--) {
                if (Varr[k] == true) {
                    Varr[k + d] = true;
                }
            }
            Varr[d] = true;
        }

        for (int j = 1; j < V + 1; ++j) {
            if (!Varr[j]) {
                return j;
            }
        }
        return 0;
    }
}
