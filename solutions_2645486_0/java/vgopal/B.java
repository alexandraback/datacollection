package Round1A;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
    public static String filename = "B-small-attempt0 (1)";
    public static Scanner scanner;
    public static PrintWriter writer;
    public static void main(String[] args) throws Exception {
        scanner = new Scanner(new File(filename + ".in"));
        writer = new PrintWriter(filename + ".out");
        int iterations = scanner.nextInt();
        scanner.nextLine();
        for (int iter = 1; iter <= iterations; iter++) {
            print("Case #" + iter + ": ");
            solve();
            flush();
        }
    }
    
    public static void solve() {
        int E = scanner.nextInt();
        int R = scanner.nextInt();
        int N = scanner.nextInt();
        int[] activities = new int[N];
        for (int i = 0; i < N; i++) {
            activities[i] = scanner.nextInt();
        }
        
        int[][] dp  = new int[N][E+1];
        for (int i = 0; i <= E; i++) {
            dp[0][i] = activities[0] * (E-i);
        }
        
        for (int i = 1; i < activities.length; i++) {
            int best = -1;
            for (int j = E; j >= E-R; j--) {
                best = Math.max(best, dp[i-1][j]);
            }
            dp[i][E] = best;
            for(int j = E-1; j>=0; j--) {
                dp[i][j] = Math.max(dp[i][j+1] + activities[i], dp[i-1][Math.max(j-R,0)]);
            }
        }
        int best = -1;
        for (int j = 0; j <= E; j++) {
            best = Math.max(best, dp[N-1][j]);
        }
        println(""+best);
    }
    
    public static void print(String string) {
        System.out.print(string);
        writer.print(string);
    }
    
    public static void println(String string) {
        System.out.println(string);
        writer.println(string);
    }
    
    public static void flush() {
        System.out.flush();
        writer.flush();
    }
}
