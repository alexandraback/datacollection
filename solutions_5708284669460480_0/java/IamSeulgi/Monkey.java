package com.seulgi.sample.service;

import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;


class Solve {
    int maxBanana = 0;
    List<Integer> needed = new ArrayList<>();
    String keyboard;
    String target;
    int repeat;


    public Solve(String keyboard, String target, int repeat) {
        this.keyboard = keyboard;
        this.target = target;
        this.repeat = repeat;
    }

    public double solve() {
        generate("", repeat);

        int diff = 0;
        for(int cur : needed) {
            diff += maxBanana - cur;
        }

//        System.out.println(maxBanana);
//        System.out.println(diff);
//        System.out.println(needed.size());
//        System.out.println("=================");
        return ((double) diff) / ((double)needed.size());
    }

    public void generate(String currentWord, int typeNeeded) {
        if (typeNeeded == 0) {
//            System.out.println(currentWord);
            int res = howMany(currentWord);
//            System.out.println(res);
            needed.add(res);
            maxBanana = Math.max(maxBanana, res);
        } else {
            for (char ch : keyboard.toCharArray()) {
                generate(currentWord + ch, typeNeeded - 1);
            }
        }
    }

    public int howMany(String result) {
        int N = target.length();
        int res = 0;
        for (int i = 0; (i + N - 1) < result.length(); i++) {
//            System.out.println(result.substring(i, i + N));
            if (result.substring(i, i + N).equals(target)) {
                res++;
            }
        }
//        System.out.println("############# :  " + res);
        return res;
    }
}

public class Monkey {

    public static void main(String[] args) throws Exception {

        List<String> file = Files.readAllLines(Paths.get("input.in"), StandardCharsets.UTF_8);
        PrintWriter writer = new PrintWriter("output.out");

        int lineNum = 0;
        int T = Integer.parseInt(file.get(lineNum++));

        for (int cid = 1; cid <= T; cid++) {
            String[] targets = file.get(lineNum++).split(" ");
            int K = Integer.parseInt(targets[0]); // number of keys == word.length()
            int L = Integer.parseInt(targets[1]); // Length of target word == target.length()
            int S = Integer.parseInt(targets[2]); // Number of times the monkey will type

            String word = file.get(lineNum++);
            String target = file.get(lineNum++);

            Solve solve = new Solve(word, target, S);
            double res = solve.solve();
            writer.println(String.format("Case #%d: %f", cid, res));
        }

        writer.close();
    }
}
