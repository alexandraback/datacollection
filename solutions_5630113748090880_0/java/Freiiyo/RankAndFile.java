package com.nwollmann.codejam.year_2016.round1a;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by Nicholas on 4/15/2016.
 */
public class RankAndFile {

    static final boolean CONSOLE_MODE = false;
    static String fileName = "B-small-attempt0";

    static File in, out;
    static PrintWriter writer;
    static Scanner reader;

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
            List<Integer> result = solveCase();
            writer.print("Case #" + i + ": ");
            for(int j : result)
                writer.print(j + " ");
            writer.println();
        }

    }

    public static List<Integer> solveCase(){
        int n = reader.nextInt();

        HashMap<Integer, Integer> set = new HashMap<>();

        int inputs = n * (2 * n - 1);

        for(int i = 0; i < inputs; i++) {
            int in = reader.nextInt();
            set.put(in, set.getOrDefault(in, 0) + 1);
        }

        ArrayList<Integer> result = new ArrayList<>();

        for(Integer i : set.keySet()) {
            if(set.get(i) % 2 != 0)
                result.add(i);
        }

        Collections.sort(result);

        return result;
    }

}
