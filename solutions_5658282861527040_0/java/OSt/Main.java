package src;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;


public class Main {

    Scanner in;
    PrintWriter out;

    void solve() {
        in.useLocale(Locale.US);
        int nTests = in.nextInt();
        for (int test = 1; test <= nTests; test++) {
            solveOne(test);
        }
    }

    void solveOne(int test) {
        int a = in.nextInt();
        int b = in.nextInt();
        int k = in.nextInt();
        long cnt = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if ((i & j) < k) {
                    cnt++;
                }
            }
        }
        out.printf(Locale.US, "Case #" + test + ": " + cnt);
        out.println();
    }

    private boolean canReduct(String[] reducteds) {
        for (int i = 0; i < reducteds.length - 1; i++) {
            for (int j = i + 1; j < reducteds.length; j++) {
                if (!reducteds[i].equals(reducteds[j])) {
                    return false;
                }
            }
        }
        return true;
    }

    void run() {
        try {
            in = new Scanner(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } catch (IOException e) {
            throw new Error(e);
        }
        try {
            solve();
        } finally {
            out.close();
            ;
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }

}
