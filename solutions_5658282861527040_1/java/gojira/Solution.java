import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Solution {
    public static void main(String args[]) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new File("output"));
        //PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();
        int i, j, k;
        for (int curTest = 1; curTest <= T; curTest++) {
            int a = in.nextInt();
            int b = in.nextInt();
            k = in.nextInt();
            out.println("Case #" + curTest + ": " + get(a - 1, b - 1, k - 1));
        }
        in.close();
        out.close();
    }

    static long get(int a, int b, int k) {
        long ret = 0;
        long[][][][] dp = new long[40][2][2][2]; // dp[i][aa][bb][kk] = how many pairs of i-bit numbers exist
        // such that [first number <= first i bits of a <=> aa], [second number <= first i bits of b <=> bb],
        // [their AND <= first i bits of k <=> kk]; rightmost bit is bit 1
        dp[0][0][0][0] = 1;
        for (int i = 0; i < dp.length - 1; i++) {
            for (int aa = 0; aa < 2; aa++) {
                for (int bb = 0; bb < 2; bb++) {
                    for (int kk = 0; kk < 2; kk++) {
                        if (dp[i][aa][bb][kk] == 0) {
                            continue;
                        }
                        //System.out.println(i + " " + aa + bb + kk + " " + dp[i][aa][bb][kk]);
                        // look at (i+1)st bit
                        for (int bitA = 0; bitA < 2; bitA++) {
                            for (int bitB = 0; bitB < 2; bitB++) {
                                int newAA = getNew(bitA, getBit(a, i), aa);
                                int newBB = getNew(bitB, getBit(b, i), bb);
                                int newKK = getNew(bitA & bitB, getBit(k, i), kk);
                                dp[i + 1][newAA][newBB][newKK] += dp[i][aa][bb][kk];
                            }
                        }
                    }
                }
            }
        }
        //System.out.println(dp[dp.length - 1][0][0][0]);
        //System.out.println(dp[dp.length - 1][0][0][1]);
        return dp[dp.length - 1][0][0][0];
    }

    static int getNew(int newBit, int bitInNumber, int prev) {
        return (newBit == 1 && bitInNumber == 0 || newBit == bitInNumber && prev == 1) ? 1 : 0;
    }

    static int getBit(int x, int bit) {
        return (x & (1L << bit)) > 0 ? 1 : 0;
    }
}