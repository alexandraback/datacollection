package com.mavtushenko.Gcj1b;

import java.io.*;

public class TaskA {

    private static int remove(int count[], char c, String s) {
        int res = count[c - 'A'];
        for (char cs : s.toCharArray())
            count[cs - 'A'] -= res;
        return res;
    }

    public static void main(String[] args) {
        String fileName = "A-small-attempt0.in";
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {

            try (BufferedWriter bw = new BufferedWriter(new FileWriter(fileName + ".out"))) {
                int tests = Integer.valueOf(br.readLine());
                final int num = 28;
                int count[] = new int[num];
                int res[] = new int[10];
                for (int test = 1; test <= tests; ++test) {
                    String s = br.readLine();
                    for (int i = 0; i < num; ++i)
                        count[i] = 0;
                    for (int i = 0; i < 10; ++i)
                        res[i] = 0;
                    for (char c : s.toCharArray()) {
                        count[c - 'A']++;
                    }
                    res[0] = remove(count, 'Z', "ZERO");
                    res[2] = remove(count, 'W', "TWO");
                    res[8] = remove(count, 'G', "EIGHT");
                    res[6] = remove(count, 'X', "SIX");
                    res[4] = remove(count, 'U', "FOUR");
                    res[3] = remove(count, 'H', "THREE");
                    res[5] = remove(count, 'F', "FIVE");
                    res[7] = remove(count, 'V', "SEVEN");
                    res[1] = remove(count, 'O', "ONE");
                    res[9] = remove(count, 'E', "NINE");

                    bw.write("Case #" + test + ": ");
                    for (int i = 0; i < 10; ++i) {
                        while (res[i] != 0) {
                            bw.write("" + i);
                            --res[i];
                        }
                    }
                    bw.write("\n");
                }
                bw.close();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
