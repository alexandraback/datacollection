package com.seulgi.sample.service;

import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

class Solve {
    int W;

}

public class Board {

    private static int solve(int available, int W) {
        if(available == W) return W;

        int res = available / W;
        if(available % W != 0) res += 1;
        return res + W - 1;

    }
    public static void main(String[] args) throws Exception {

        List<String> file = Files.readAllLines(Paths.get("input.in"), StandardCharsets.UTF_8);
        PrintWriter writer = new PrintWriter("output.out");

        int lineNum = 0;
        int T = Integer.parseInt(file.get(lineNum++));

        for (int cid = 1; cid <= T; cid++) {
            String[] targets = file.get(lineNum++).split(" ");
            int R = Integer.parseInt(targets[0]);
            int C = Integer.parseInt(targets[1]);
            int W = Integer.parseInt(targets[2]);

            int res = solve(C, W);
            writer.println(String.format("Case #%d: %d", cid, res));
        }

        writer.close();
    }
}
