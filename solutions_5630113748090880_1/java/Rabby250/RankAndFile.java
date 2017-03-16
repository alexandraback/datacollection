package com.rabby250.codejam;

import java.util.ArrayList;
import java.util.List;

public class RankAndFile {
    public static List<Integer> solve(
            final List<List<Integer>> grid) {
        final int[] counts = new int[4501];
        for (List<Integer> row : grid) {
            for (Integer i : row) {
                counts[i]++;
            }
        }
        final List<Integer> result = new ArrayList<>();
        for (int i = 1; i < counts.length; i++) {
            if ((counts[i] & 1) != 0) {
                result.add(i);
            }
        }
        return result;
    }
}
