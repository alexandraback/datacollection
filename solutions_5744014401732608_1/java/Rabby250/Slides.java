package com.rabby250.codejam;

import java.util.ArrayList;
import java.util.List;

public class Slides {
    public static List<String> solve(int B, long M) {
        long max = 1L << (B - 2);
        if (M < 1 || M > max) {
            return null;
        }
        final List<String> result = new ArrayList<>(B);
        long remove = max - M;
        final StringBuilder sb = new StringBuilder(B);
        sb.append('0');
        for (int i = 1; i < B - 1; i++) {
            sb.append((remove & (1L << (B - i - 2))) == 0 ? '1' : '0');
        }
        sb.append('1');
        result.add(sb.toString());
        for (int i = 1; i < B; i++) {
            sb.setLength(0);
            for (int j = 0; j <= i; j++) {
                sb.append('0');
            }
            for (int j = i + 1; j < B; j++) {
                sb.append('1');
            }
            result.add(sb.toString());
        }
        return result;
    }
}
