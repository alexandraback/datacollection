package r1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by fatminmin on 5/8/16.
 */
public class B {
//    Scanner sc = new Scanner(System.in);
//    PrintWriter pw = new PrintWriter(System.out);
    Scanner sc = new Scanner(new File("r1c_tc/B-small-attempt0.in"));
    PrintWriter pw = new PrintWriter("r1c_tc/B-small-attempt0.out");
    public B() throws FileNotFoundException {
    }

    private void fill(int idx, int[][] arr) {
        for(int i = 0; i < arr.length; i++) {
            Arrays.fill(arr[i], 0);
            for(int j = i + 1; j < arr[i].length; j++) {
                if((idx & 1) > 0) arr[i][j] = 1;
                idx >>= 1;
            }
        }
    }
    private int getWays(int[][] arr) {
        int[] dp = new int[arr.length];
        dp[arr.length - 1] = 1;
        for(int i = arr.length - 2; i >= 0; i--) {
            for(int j = i + 1; j < arr[i].length; j++) {
                if(arr[i][j] == 1) dp[i] += dp[j];
            }
        }
        return dp[0];
    }

    private void solve() {
        int b = sc.nextInt(), m = sc.nextInt();
        int tmp = (b * b - b) / 2;
        int[][] arr = new int[b][b];
        boolean find =false;
        for(int i = 0; i < (1 << tmp); i++) {
            fill(i, arr);
            if(getWays(arr) == m) {
                find = true;
                break;
            }
        }
        if(find) {
            pw.println("POSSIBLE");
            for(int i = 0; i < b; i++) {
                for(int j = 0; j < b; j++) {
                    pw.print(arr[i][j]);
                }
                pw.println("");
            }
        } else {
            pw.println("IMPOSSIBLE");
        }

    }

    public void run() {
        int t = sc.nextInt();
        for(int cs = 1; cs <= t; cs++) {
            pw.print(String.format("Case #%d: ", cs));
            solve();
        }
        pw.flush();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new B().run();
    }
}
