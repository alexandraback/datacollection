package com.google.code.jam.third;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * @author: nava
 * @date: 04.05.13
 */
public class ProblemASolver implements ProblemSolver {
    public String getResult(Input input) {
        List<Long> bitArray = getBitArray(input.name);
        return String.valueOf(calculateNSub(bitArray, input.n));
    }

    private long calculateNSub(List<Long> bits, long n) {
        long rang = 0;
        long start = 1;
        if (bits.get(bits.size() - 1) < n) {
           return 0;
        }
        for (int i = 0; i < bits.size(); i++) {
            for (int j = i+1; j < bits.size(); j++) {
                if (bits.get(j-1) == bits.get(j)) {
                    i = j;
                }
                    if (bits.get(j) - bits.get(i) == n) {
                        long k = i + 1 - start;
                        long m = bits.size() - 1 - j;
                        rang+= (k+1)*(m);
                        start = i + 2;
                        j = bits.size();
                    }
            }
        }
        return rang;
    }

    private List getBitArray(String name) {
        List<Long> bits = new ArrayList<Long>();
        long summ = 0;
        bits.add(summ);
        for (char ch: name.toCharArray()) {
            if (!isVowel(ch)) {
                summ++;
            }
            bits.add(summ);
        }
        bits.add(summ);
        return bits;
    }

    private boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'o' ||ch == 'u' ||ch == 'e' ||ch == 'i');
    }
}
