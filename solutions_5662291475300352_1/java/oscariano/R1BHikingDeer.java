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
        ArrayList<Hiker> temp = new ArrayList<Hiker>();
        for (int i = 0; i < lines; i++) {
            linea = reader.readLine();
            String[] pedazos = linea.split(" ");
            int currStart = Integer.parseInt(pedazos[0]);
            int currNum = Integer.parseInt(pedazos[1]);
            int currTime = Integer.parseInt(pedazos[2]);
            for (int j = 0; j < currNum; j++) {
                temp.add(new Hiker(currStart, currTime + j));
            }
        }

        Hiker[] hikers = new Hiker[temp.size()];
        for (int i = 0; i < temp.size(); i++) {
            hikers[i] = temp.get(i);
        }
        Arrays.sort(hikers);
        int numHikers = hikers.length;
        
        if (hikers[numHikers - 1].timeToFinish < hikers[0].timeToFinish + hikers[0].time)
            return 0;
        
        int cost[] = new int[numHikers];
        Arrays.fill(cost, 0);
        for (int i = numHikers - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (hikers[i].timeToFinish < hikers[j].timeToFinish + hikers[j].time)
                    continue;
                double left = hikers[i].timeToFinish - hikers[j].timeToFinish;
                double rounds = left / hikers[j].time;
                cost[i] += rounds;
            }
        }
        int max = numHikers;
        if (cost[numHikers - 1] < max)
            max = cost[numHikers - 1];
        
        for (int i = numHikers -1; i >= 0; i--) {
            int j = i - 1;
            while (j >= 0 && hikers[j].timeToFinish == hikers[i].timeToFinish) {
                j--;
            }
            i = j + 1;
            if (i <= 0)
                break;
            int tot = (numHikers - i) + cost[i - 1];
            if (tot < max)
                max = tot;
        }
        
        return max;
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
