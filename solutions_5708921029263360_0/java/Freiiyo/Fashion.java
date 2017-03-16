package com.nwollmann.codejam.year_2016.round1c;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by Nicholas on 5/8/2016.
 */
public class Fashion {

    static final boolean CONSOLE_MODE = false;
    static String fileName = "C-small-attempt2";

    static File in, out;
    static PrintWriter writer;
    static Scanner reader;

    static int k, j, p, s;
    static boolean printMe;

    static CompareSets compareSets = new CompareSets();

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

        for(int i = 1; i <= cases; i++) {
            List<int[]> result = solveCase();
            /*List<int[]> result2 = newSolution();
            if(result2.size() > result.size()) {
                result = result2;
                System.out.println("New solution better for case " + i);
            } else if(result2.size() < result.size()) {
                System.out.println("New solution worse for case " + i);
            } */
                writer.println("Case #" + i + ": " + result.size());
                for (int[] set : result) {
                    for (int j = 0; j < 3; j++) {
                        writer.print(set[j] + " ");
                    }
                    writer.println();
                }
            if(!testAnswer(result)) {
                System.out.println("ERROR on case " + i);
            }
        }

    }

    public static List<int[]> solveCase(){
        ArrayList<int[]> result = new ArrayList<>();

        j = reader.nextInt();
        p = reader.nextInt();
        s = reader.nextInt();
        k = reader.nextInt();

        ArrayList<int[]> possibilities = new ArrayList<>();

        HashMap<Integer, Integer> jp = new HashMap<>();
        HashMap<Integer, Integer> js = new HashMap<>();
        HashMap<Integer, Integer> ps = new HashMap<>();

        int count1, count2, count3;

        for(int ij = 1; ij <= j; ij++) {
            for(int ip = 1; ip <= p; ip++) {
                for(int is = 1; is <= s; is++) {
                    /*count1 = jp.getOrDefault(ij * 100 + ip, 0);
                    count2 = js.getOrDefault(ij * 100 + is, 0);
                    count3 = ps.getOrDefault(ip * 100 + is, 0);
                    if(count1 < k && count2 < k && count3 < k) {
                        jp.put(ij * 100 + ip, count1 + 1);
                        js.put(ij * 100 + is, count2 + 1);
                        ps.put(ip * 100 + is, count3 + 1);
                        int[] set = {ij, ip, is};
                        result.add(set);
                    } */
                    int[] poss = {ij, ip, is, 0};
                    possibilities.add(poss);
                }
            }
        }

        while(!possibilities.isEmpty()) {
            for (int[] poss : possibilities) {
                poss[3] = 0;
                for (int[] other : possibilities) {
                    if (other[0] == poss[0] && other[1] == poss[1])
                        poss[3]++;
                    if (other[0] == poss[0] && other[2] == poss[2])
                        poss[3]++;
                    if (other[1] == poss[1] && other[2] == poss[2])
                        poss[3]++;
                }
            }
            Collections.sort(possibilities, compareSets);
            int[] set = possibilities.remove(0);
            result.add(set);
            count1 = jp.getOrDefault(set[0] * 100 + set[1], 0);
            count2 = js.getOrDefault(set[0] * 100 + set[1], 0);
            count3 = ps.getOrDefault(set[0] * 100 + set[1], 0);
            jp.put(set[0] * 100 + set[1], count1 + 1);
            js.put(set[0] * 100 + set[2], count2 + 1);
            ps.put(set[1] * 100 + set[2], count3 + 1);

            if(count1 == k - 1 || count2 == k - 1 || count3 == k - 1) {
                Iterator<int[]> iterator = possibilities.iterator();
                while(iterator.hasNext()) {
                    int[] next = iterator.next();
                    if(count1 == k - 1 && next[0] == set[0] && next[1] == set[1]) {
                        iterator.remove();
                    } else if (count2 == k - 1 && next[0] == set[0] && next[2] == set[2]) {
                        iterator.remove();
                    } else if (count3 == k - 1 && next[1] == set[1] && next[2] == set[2]) {
                        iterator.remove();
                    }
                }
            }
        }

        return result;
    }

    public static List<int[]> newSolution() {
        HashMap<Integer, Integer> jp = new HashMap<>();
        HashMap<Integer, Integer> js = new HashMap<>();
        HashMap<Integer, Integer> ps = new HashMap<>();

        int count1, count2, count3;

        ArrayList<int[]> result = new ArrayList<>();

        for(int ij = 1; ij <= j; ij++) {
            for(int ip = 1; ip <= p; ip++) {
                for(int is = s; is > 0; is--) {
                    if(ij != ip || ip != is) {
                        count1 = jp.getOrDefault(ij * 100 + ip, 0);
                        count2 = js.getOrDefault(ij * 100 + is, 0);
                        count3 = ps.getOrDefault(ip * 100 + is, 0);
                        if (count1 < k && count2 < k && count3 < k) {
                            jp.put(ij * 100 + ip, count1 + 1);
                            js.put(ij * 100 + is, count2 + 1);
                            ps.put(ip * 100 + is, count3 + 1);
                            int[] set = {ij, ip, is};
                            result.add(set);
                        }
                    }
                }
            }
        }

        for(int i = 1; i <= j; i++) {
            count1 = jp.getOrDefault(i * 100 + i, 0);
            count2 = js.getOrDefault(i * 100 + i, 0);
            count3 = ps.getOrDefault(i * 100 + i, 0);
            if (count1 < k && count2 < k && count3 < k) {
                jp.put(i * 100 + i, count1 + 1);
                js.put(i * 100 + i, count2 + 1);
                ps.put(i * 100 + i, count3 + 1);
                int[] set = {i, i, i};
                result.add(set);
            }
        }

        return result;
    }

    public static boolean testAnswer(List<int[]> result) {
        HashMap<Integer, Integer> jp = new HashMap<>();
        HashMap<Integer, Integer> js = new HashMap<>();
        HashMap<Integer, Integer> ps = new HashMap<>();

        int count1, count2, count3;

        for(int[] set : result) {
            count1 = jp.getOrDefault(set[0] * 100 + set[1], 0);
            count2 = js.getOrDefault(set[0] * 100 + set[2], 0);
            count3 = ps.getOrDefault(set[1] * 100 + set[2], 0);
            if(count1 < k && count2 < k && count3 < k) {
                jp.put(set[0] * 100 + set[1], count1 + 1);
                js.put(set[0] * 100 + set[2], count2 + 1);
                ps.put(set[1] * 100 + set[2], count3 + 1);
            } else {
                return false;
            }
        }
        return true;
    }

    public static class CompareSets implements Comparator<int[]> {

        @Override
        public int compare(int[] o1, int[] o2) {
            return o1[3] - o2[3];
        }
    }
}
