package com.google.codejam.ka;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Motes {

    private static int currMin = Integer.MAX_VALUE;

    public static void main(String args[]) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File(args[0]));
        PrintWriter writer = new PrintWriter(new FileOutputStream("motes.out"));
        try {
            int caseCnt = scanner.nextInt();
            for (int i = 0; i < caseCnt; i++) {
                int mote = scanner.nextInt();
                int moteCnt = scanner.nextInt();
                int motes[] = new int[moteCnt];
                for (int j = 0; j < moteCnt; j++) {
                    motes[j] = scanner.nextInt();
                }
                Arrays.sort(motes);
                currMin = Integer.MAX_VALUE;
                int moves = solve(mote, motes, 0, 0);
                // solve
                writer.println(String.format("Case #%d: %d", i + 1 , moves));
            }
        } finally {
            writer.close();
        }
    }

    public static int solve(int mote, int motes[], int cnt, int idx) {
        if (cnt >= currMin) {
            return cnt;
        }
        int currMote = mote;
        int i = idx;

        for (; i < motes.length && motes[i] < currMote; i++) {
            currMote += motes[i];
        }
        if (i == motes.length) {
            currMin = cnt;
            return cnt;
        } else {
            int withAdding = (currMote == 1 ? Integer.MAX_VALUE : solve(currMote + currMote - 1, motes, cnt + 1, i));
            int withDeleting = solve(currMote, motes, cnt + 1, i + 1);
            return Math.min(withAdding, withDeleting);
        }
    }
}
