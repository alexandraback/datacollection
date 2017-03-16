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

    private static int solve(int C, int W) {
        if(C == W) return W;

        int res = C / W;
        if(C % W != 0) res += 1;
        return res + W - 1;
    }

    private static int checkPerRow(int C, int W) {
        int res = C / W;
        if(C % W != 0) res += 1;
        return res;
    }

    private static int solveBig(int R, int C, int W) {
        int res = checkPerRow(C, W) * (R - 1);
        return res + solve(C, W);
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

            int res = solveBig(R, C, W);
            writer.println(String.format("Case #%d: %d", cid, res));
        }

        writer.close();
    }
}
