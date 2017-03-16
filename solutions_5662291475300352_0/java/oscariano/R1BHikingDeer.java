/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.podervisual.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;

/**
 *
 * @author osdroid
 */
public class R1BHikingDeer {

    private static class Hiker implements Comparable<Hiker>{
        public int start;
        public int time;
        public double timeToFinish;
        public Hiker(int start, int time) {
            this.start = start;
            this.time = time;
            timeToFinish = (360.0 - start) / 360.0 * time;
        }

        @Override
        public int compareTo(Hiker o) {
            if (this.timeToFinish > o.timeToFinish)
                return 1;
            if (this.timeToFinish < o.timeToFinish)
                return -1;
            return 0;
        }
    }
    private static int solve(BufferedReader reader) throws Exception {
        String linea = reader.readLine();
        int lines = Integer.parseInt(linea);
        ArrayList<Hiker> hikers = new ArrayList<Hiker>();
        for (int i = 0; i < lines; i++) {
            linea = reader.readLine();
            String[] pedazos = linea.split(" ");
            int currStart = Integer.parseInt(pedazos[0]);
            int currNum = Integer.parseInt(pedazos[1]);
            int currTime = Integer.parseInt(pedazos[2]);
            for (int j = 0; j < currNum; j++) {
                hikers.add(new Hiker(currStart, currTime + j));
            }
        }

        Hiker[] ordered = new Hiker[hikers.size()];
        for (int i = 0; i < hikers.size(); i++) {
            ordered[i] = hikers.get(i);
        }
        Arrays.sort(ordered);
        if (ordered[1].timeToFinish < ordered[0].timeToFinish + ordered[0].time)
            return 0;
        

        return 1;
    }

    private static void solve(String filename) throws Exception {
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(new FileInputStream(filename + ".in")));
        PrintStream writer = new PrintStream(new File(filename + ".out"));
        int numCases = Integer.parseInt(reader.readLine());
        for (int i = 0; i < numCases; i++) {
            writer.println(String.format("Case #%d: %d", i + 1, solve(reader)));
        }
        writer.close();
    }
    
    public static void main(String[] args) throws Exception {
        System.out.println("File?: ");
        BufferedReader lector = new BufferedReader(
                new InputStreamReader(System.in));
        String filename = lector.readLine();
        solve(filename);
    }
    
}
