package com.nus.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Map.Entry;

import com.nus.codejam.utils.IntegerHistogram;

public class InfiniteHouseOfPancakes {

    public static void main(String[] args) throws NumberFormatException, IOException {
        long start = System.currentTimeMillis();
        BufferedReader br = new BufferedReader(new FileReader(new File(args[0])));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File(args[1]))));
        int iterationsNum = Integer.parseInt(br.readLine());


        for (int i = 0; i < iterationsNum; ++i) {
            int platesNum = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split("\\s+");

            IntegerHistogram<Integer> sortedPlates = new IntegerHistogram<Integer>();
            for (int plate = 0; plate < platesNum; ++plate) {
                sortedPlates.inc(Integer.parseInt(line[plate]));
            }

            // from min to max
            int min = sortedPlates.max();
            boolean feasible = true;
            for (int time = 1; time <= sortedPlates.lastKey(); ++time) {
                int extraTime = 0;
                for (Entry<Integer, Integer> plateEntry : sortedPlates.tailMap(time).entrySet()) {
                    int repetitions = plateEntry.getValue();
                    double devision = plateEntry.getKey() / (time * 1.0);

                    extraTime += repetitions * (new Double(Math.ceil(devision)).intValue() - 1);
                }
                min = Math.min(min, time + extraTime);
            }

            // int time = new Double(Math.ceil(Math.log(max) / Math.log(2)) + 1).intValue();
            bw.write("Case #" + (i + 1) + ": " + min + "\n");
        }

        br.close();
        bw.close();

        System.out.println("Time: " + (System.currentTimeMillis() - start) / 1000);
    }
}
