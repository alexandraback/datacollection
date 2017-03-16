package com.mavtushenko.Gcj1b;

import java.io.*;

public class TaskB {
    private static void fillEqual(char c[], char j[], int start, int finish) {
        for (int i = start; i < finish; ++i) {
            if (c[i] != '?' && j[i] != '?')
                continue;
            char num = '0';
            if (c[i] != '?')
                num = c[i];
            if (j[i] != '?')
                num = j[i];
            c[i] = num;
            j[i] = num;
        }

    }

    private static boolean can(char c[], char j[], int cur) {
        boolean can = false;
        for (int i = cur; i >= 0; --i) {
            if (c[i] == j[i] && c[i] != '?')
                break;
            if (c[i] == '9' || j[i] == '0')
                continue;
            can = true;
            break;
        }
        return can;
    }

    public static void main(String[] args) {
        String fileName = "B-small-attempt3.in";
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {

            try (BufferedWriter bw = new BufferedWriter(new FileWriter(fileName + ".out"))) {
                int tests = Integer.valueOf(br.readLine());
                for (int test = 1; test <= tests; ++test) {
                    String s[] = br.readLine().split(" ");
                    char cc[] = s[0].toCharArray();
                    char jj[] = s[1].toCharArray();
                    char c[] = cc;
                    char j[] = jj;
                    int max = c.length;
                    int cur = 0;
                    while (cur < max && (c[cur] == '?' || j[cur] == '?' || c[cur] == j[cur]))
                        ++cur;
                    if (cur == max)
                        fillEqual(c, j, 0, max);
                    else {
                        int tmp = cur;
                        if (c[cur] < j[cur]) {
                            char t[] = c;
                            c = j;
                            j = t;
                        }
                        if (Math.abs(c[cur] - j[cur]) == 5) {
                            boolean finish = false;
                            while (cur > 0) {
                                --cur;
                                if (c[cur] != '?' && j[cur] != '?') {
                                    finish = true;
                                } else if (c[cur] == '?' && j[cur] == '?') {
                                    finish = true;
                                    c[cur] = '0';
                                    j[cur] = '0';
                                    if (c[tmp] < j[tmp]) {
                                        char t[] = c;
                                        c = j;
                                        j = t;
                                    }
                                } else if (j[cur] == '?') {
                                    j[cur] = (char) (c[cur]);
                                    finish = true;
                                } else if (c[cur] == '?') {
                                    if (j[cur] != '0') {
                                        c[cur] = (char) (j[cur] - 1);
                                        char t[] = c;
                                        c = j;
                                        j = t;
                                    } else
                                        c[cur] = '0';
                                    finish = true;
                                }
                                if (finish) {
                                    fillEqual(c, j, 0, cur);
                                    break;
                                }
                            }
                        } else {
                            if (c[cur] - j[cur] > 5 && can(c, j, cur)) {
                                while (cur > 0) {
                                    --cur;
                                    if (c[cur] == '?' && j[cur] == '0')
                                        c[cur] = '9';
                                    else if (c[cur] == '9' && j[cur] == '?')
                                        j[cur] = '0';
                                    else {
                                        if (c[cur] == '?' && j[cur] == '?') {
                                            c[cur] = '0';
                                            j[cur] = '1';
                                        } else if (c[cur] == '?') {
                                            c[cur] = (char) (j[cur] - 1);
                                        } else {
                                            j[cur] = (char) (c[cur] + 1);
                                        }
                                        break;
                                    }
                                }
                                fillEqual(c, j, 0, cur);
                                char t[] = c;
                                c = j;
                                j = t;
                            } else {
                                fillEqual(c, j, 0, cur);
                            }
                        }
                        for (cur = tmp + 1; cur < max; ++cur) {
                            if (c[cur] != '?' && j[cur] != '?')
                                continue;
                            if (c[cur] == '?')
                                c[cur] = '0';
                            if (j[cur] == '?')
                                j[cur] = '9';
                        }
                    }
                    bw.write("Case #" + test + ": " + new String(cc) + " " + new String(jj) + "\n");
                }
                bw.close();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
