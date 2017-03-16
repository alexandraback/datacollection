package google.codejam2013.round1b;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class GarbledEmail {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

    GarbledEmail() throws IOException {
        reader = new BufferedReader(new FileReader("C-small-attempt0.in"));
        writer = new PrintWriter(new FileWriter("C-small-attempt0.out"));
    }

    int[] readInts() throws IOException {
        String line = reader.readLine();
        String []s = line.split(" ");
        int[] ret = new int[s.length];
        for(int i = 0; i < s.length; i++) {
            ret[i] = Integer.parseInt(s[i]);
        }
        return ret;
    }

    int[] tt = null;
    int ti = 0;
    int readInt() throws IOException {
        if(tt == null || ti == tt.length) {
            tt = readInts();
            ti = 0;
        }
        return tt[ti++];
    }

    void solveTest(int test) throws IOException {
        writer.printf("Case #%d:", test);
        char[] s = reader.readLine().toCharArray();
        int n = s.length;
        int[][] dp = new int[n + 1][5];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < 5; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[0][4] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 5; j++) {
                if(dp[i][j] == Integer.MAX_VALUE) continue;
                for(char[] word: dict) {
                    if(word.length + i > n) continue;
                    int p = i - j - 1;
                    int r = 0;
                    for(int k = 0; k < word.length; k++) {
                        if(word[k] != s[i + k]) {
                            if(i + k - p < 5) {
                                r = Integer.MAX_VALUE;
                                break;
                            }
                            else {
                                r++;
                                p = i + k;
                            }
                        }
                    }
                    if(r != Integer.MAX_VALUE) {
                        int i2 = i + word.length;
                        int j2 = i2 - p - 1;
                        j2 = Math.min(j2, 4);
                        dp[i2][j2] = Math.min(dp[i2][j2], dp[i][j] + r);
                    }
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < 5; i++) {
            ans = Math.min(ans, dp[s.length][i]);
        }
        writer.println(" " + ans);
    }

    List<char[]> dict = new ArrayList<char[]>();

    void solve() throws IOException {
        BufferedReader dictReader = new BufferedReader(new FileReader("garbled_email_dictionary.txt"));
        while(true) {
            String s = dictReader.readLine();
            if(s == null) break;
            dict.add(s.toCharArray());
        }

        int t = readInt();
        for(int i = 1; i <= t; i++) {
            solveTest(i);
        }
        writer.flush();
    }

    public static void main(String[] args) throws IOException {
        new GarbledEmail().solve();
    }
}
