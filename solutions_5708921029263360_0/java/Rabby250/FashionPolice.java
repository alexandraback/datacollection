package com.rabby250.codejam;

import java.util.ArrayList;
import java.util.List;

public class FashionPolice {
    public static List<String> solve(int J, int P, int S, int K) {
        int maxDays3 = J * P * S;
        int maxDays2 = J * P * K;
        final List<String> result = new ArrayList<>();
        if (maxDays3 < maxDays2) {
            for (int j = 1; j <= J; j++) {
                for (int p = 1; p <= P; p++) {
                    for (int s = 1; s <= S; s++) {
                        result.add("" + j + ' ' + p + ' ' + s);
                    }
                }
            }
            return result;
        }
        for (int k = 1; k <= K; k++) {
            for (int j = 1; j <= J; j++) {
                for (int p = 1; p <= P; p++) {
                    result.add("" + j + ' ' + p + ' ' + p);
                }
            }
        }
        return result;
    }
}
