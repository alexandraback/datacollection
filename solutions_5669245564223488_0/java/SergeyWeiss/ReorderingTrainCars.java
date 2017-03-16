package com.google.codejam2014.round1c;

import java.io.*;
import java.util.List;
import java.util.StringTokenizer;

public class ReorderingTrainCars {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    ReorderingTrainCars() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
    }

    String next() throws IOException {
        while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
            stringTokenizer = new StringTokenizer(reader.readLine());
        }
        return stringTokenizer.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    int rec(String[] input, String current, int mask, int n) {
        if(n == input.length) {
//            writer.println("check");
//            writer.flush();
            for(char c = 'a'; c <= 'z'; c++) {
                boolean met = false;
                for(int i = 0; i < current.length(); i++) {
                    if(i > 0 && current.charAt(i) == current.charAt(i - 1)) {
                        continue;
                    }
                    if(current.charAt(i) == c) {
                        if(met) return 0;
                        met = true;
                    }
                }
            }
            return 1;
        }
        int ans = 0;
        for(int i = 0; i < input.length; i++) {
            if(((mask >> i) & 1) == 0) {
                ans += rec(input, current + input[i], mask + (1 << i), n + 1);
            }
        }
        return ans;
    }

    int naive(String[] input) {
        return rec(input, "", 0, 0);
    }

    void solveTestCase(int testNumber) throws IOException {
        writer.printf("Case #%d: ", testNumber);
        int n = nextInt();
        char[][] pref = new char[26][];
        char[][] suf = new char[26][];
        int[] whole = new int[26];
        int[] inside = new int[26];
        boolean bad = false;
        String[] input = new String[n];
        for(int k = 0; k < n; k++) {
            input[k] = next();
            char[] s = input[k].toCharArray();
            for(int i = 1; i < s.length - 1; i++) {
                if(s[i] == s[i - 1]) continue;
                boolean prefix = true;
                for(int j = 0; j < i; j++) {
                    if(s[j] != s[i]) prefix = false;
                }
                boolean suffix = true;
                for(int j = i + 1; j < s.length; j++) {
                    if(s[j] != s[i]) suffix = false;
                }
                if(!prefix && !suffix) {
                    inside[s[i] - 'a']++;
                }
            }
            if(whole(s)) {
                whole[s[0] - 'a']++;
            } else {
                if(pref[s[0] - 'a'] != null) {
                    bad = true;
                }
                pref[s[0] - 'a'] = s;
                if(suf[s[s.length - 1] - 'a'] != null) {
                    bad = true;
                }
                suf[s[s.length - 1] - 'a'] = s;
            }
        }
//        writer.print(naive(input) + " ");
        if(bad) {
            writer.println(0);
            return;
        }
        for(int i = 0; i < 26; i++) {
            if(inside[i] > 1) {
                writer.println(0);
                return;
            }
            if(inside[i] == 1 && (pref[i] != null || suf[i] != null || whole[i] > 0)) {
                writer.println(0);
                return;
            }
        }
        int[] f = new int[n + 1];
        f[0] = 1;
        for(int i = 1; i <= n; i++) {
            f[i] = product(f[i - 1], i);
        }
        int ans = 1;
        for(int i = 0; i < 26; i++) {
            ans = product(ans, f[whole[i]]);
        }
        int components = 0;
        for(int i = 0; i < 26; i++) {
            if(whole[i] > 0 && pref[i] == null && suf[i] == null) {
                components++;
            }
        }
        boolean[] used = new boolean[26];
        for(int i = 0; i < 26; i++) {
            if(used[i]) continue;
            if(pref[i] == null) {
                used[i] = true;
                continue;
            }
            if(suf[i] != null) {
                continue;
            }
            components++;
            int a = i;
            while(pref[a] != null) {
                used[a] = true;
                a = pref[a][pref[a].length - 1] - 'a';
            }
        }
        for(int i = 0; i < 26; i++) {
            if(!used[i]) {
                writer.println(0);
                return;
            }
        }
        ans = product(ans, f[components]);
        writer.println(ans);
    }

    final int mod = 1000 * 1000 * 1000 + 7;

    int sum(int x, int y) {
        x += y;
        return x >= mod ? x - mod : x;
    }

    int product(int x, int y) {
        return (int)(1L * x * y % mod);
    }

    boolean whole(char[] s) {
        for(int i = 1; i < s.length; i++) {
            if(s[i] != s[i - 1]) return false;
        }
        return true;
    }

    void solve() throws IOException {
        int testsNumber = nextInt();
        for(int i = 1; i <= testsNumber; i++) {
            solveTestCase(i);
            writer.flush();
        }
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        new ReorderingTrainCars().solve();
    }
}
