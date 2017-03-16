package com.elsa.battleship;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by elisabet on 2015-05-10.
 */
public class Battleship {


    public static void main(String[] args) {
        try {
            String path = args[0];
            Battleship m = new Battleship();
            List<String> result = m.readFile(path);
            String outPath = "/home/elisabet/temp.out";

            PrintWriter pw = new PrintWriter(outPath);
            for (String s : result) {
                pw.println(s);
            }
            pw.close();
        } catch (IOException e) {
            System.out.println("IOException: "+e.getMessage());
        }
    }
    private List<String> readFile(String path) throws IOException {
        FileReader fr = new FileReader(path);
        BufferedReader br = new BufferedReader(fr);
        List<String> result = new ArrayList<String>();

        int m = Integer.parseInt(br.readLine());

        for (int i = 1; i<=m; i++){
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.append("Case #"+i+": ");

            int[] t = readExample(br);
            int a = solve(t[0], t[1], t[2]);
            String str = ""+a;

            stringBuilder.append(str);
            result.add(stringBuilder.toString());
            System.out.println(stringBuilder);
        }
        return result;
    }


    private int[] readExample(BufferedReader br) throws IOException{
        String[] strings= br.readLine().split(" ");
        int[] ret = new int[strings.length];
        for (int i = 0; i < strings.length; i++) {
            ret[i] = Integer.parseInt(strings[i]);
        }
        return ret;
    }

    private int solve(int R, int C, int W) {
        System.out.println(R+" "+C+" "+W);
        if (W == C) return W+R-1;
        if (W == C+1) return W+R;
        int guess = 0;
        for (int i = 0; i < R; i++) {
            for (int j = W; j<=C; j+=W) {
                guess++;
            }
        }
        guess += C%W == 0 ? W-1: W;
        return guess;
    }
}
