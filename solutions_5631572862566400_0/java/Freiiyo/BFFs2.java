package com.nwollmann.codejam.year_2016.round1a;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by Nicholas on 4/15/2016.
 */
public class BFFs2 {

    static final boolean CONSOLE_MODE = false;
    static String fileName = "C-small-attempt1";

    static File in, out;
    static PrintWriter writer;
    static Scanner reader;

    static HashMap<Integer, Integer> bffs;
    static HashMap<Integer, List<Integer>> bffsReversed;

    static HashSet<Integer> used;
    static HashMap<Integer, Integer> whenHit;

    static ArrayList<int[]> pairLoops;

    static int loopCurrent = 0;

    public static void main(String[] args) throws Exception{
        if(CONSOLE_MODE) {
            writer = new PrintWriter(System.out);
            reader = new Scanner(System.in);
        } else {
            in = new File("C:/Codejam/in/" + fileName + ".in");
            out = new File("C:/Codejam/result.out");
            writer = new PrintWriter(new FileOutputStream(out));
            reader = new Scanner(new FileInputStream(in));
        }

        solve();

        writer.close();
        reader.close();
    }

    public static void solve(){

        int cases = reader.nextInt();

        System.out.println("Cases: " + cases);

        for(int i = 1; i <= cases; i++) {
            System.out.println("On case " + i);
            writer.println("Case #" + i + ": " + solveCase());
        }

    }

    public static int solveCase(){

        int n = reader.nextInt();

        bffs = new HashMap<>();
        bffsReversed = new HashMap<>();

        for(int i = 1; i <= n; i++) {
            int bff = reader.nextInt();
            bffs.put(i, bff);
            List<Integer> reversals = bffsReversed.getOrDefault(bff, new ArrayList<>());
            reversals.add(i);
            bffsReversed.put(bff, reversals);
        }

        pairLoops = new ArrayList<>();

        int max = largestLoop(n);

        int maxPair = 0;

        //detect pairs
        for(int i = 1; i <= n; i++) {
            int bff = bffs.get(i);
            if(bff > i && bffs.get(bff) == i) {
                int[] pair = new int[2];
                pair[0] = i;
                pair[1] = bff;
                pairLoops.add(pair);
            }
        }

        for(int[] pair : pairLoops) {
            used = new HashSet<>();
            used.add(pair[0]);
            used.add(pair[1]);
            List<Integer> list = bffsReversed.get(pair[0]);
            list.remove((Integer) pair[1]);
            bffsReversed.put(pair[0], list);
            list = bffsReversed.get(pair[1]);
            list.remove((Integer) pair[0]);
            bffsReversed.put(pair[1], list);
            maxPair += reversePath(pair[0]) + reversePath(pair[1]);
        }

        return Math.max(max, maxPair + 2);
    }

    public static int reversePath(int n) {
        List<Integer> paths = bffsReversed.get(n);
        int count = 0;

        while(paths != null && paths.size() > 0) {
            count++;
            if(paths.size() == 1) {
                if (!used.add(paths.get(0))) return 0;
                paths = bffsReversed.get(paths.get(0));
            } else {
                int max = 0;
                for(int i = 0; i < paths.size(); i++) {
                    if(used.add(paths.get(i)))
                        max = Math.max(max, reversePath(paths.get(i)));
                }
                count += max;
                return count;
            }
        }

        return count;
    }


    public static int largestLoop(int n) {

        used = new HashSet<>();

        int max = 0;

        for(int i = 0; i < n; i++) {
            whenHit = new HashMap<>();
            loopCurrent = 0;
            int result = checkForLoopFrom(i);
            /*if(max <= 2 && result == 2) {
                int[] pair = new int[2];
                Set<Integer> keys = whenHit.keySet();
                Iterator<Integer> iterator = keys.iterator();
                pair[0] = iterator.next();
                pair[1] = iterator.next();
                pairLoops.add(pair);
            } */
            max = Math.max(max, result);
        }

        return max;
    }

    public static int checkForLoopFrom(int current) {
        if(used.contains(current))
            return 0;
        while(true) {
            loopCurrent++;
            int next = bffs.getOrDefault(current, -1);
            if(next == -1) return 0;
            else if(!used.add(next)) {
                return (loopCurrent) - whenHit.getOrDefault(next, loopCurrent);
            } else {
                whenHit.put(next, loopCurrent);
            }
            current = next;
        }
    }
}
