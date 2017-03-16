import gcj.GCJ;

import java.util.Scanner;

public class Treasure {

    static final String imp = "IMPOSSIBLE";

    int n;

    int[] initKeys;

    int[] chestTypes;

    int[][] chestKeys;

    int nn;

    byte[] memo;

    int[] path;

    public Treasure(int n, int[] initKeys, int[] chestTypes, int[][] chestKeys) {
        this.n = n;
        nn = 1 << n;
        this.initKeys = initKeys;
        this.chestTypes = chestTypes;
        this.chestKeys = chestKeys;
    }

    public String compute() {
        memo = new byte[nn];
        path = new int[n];
        if (compute(0, initKeys) > 0) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(path[i] + 1);
                sb.append(' ');
            }
            return sb.toString().trim();
        } else {
            return imp;
        }
    }

    public byte compute(int mask, int[] curKeys) {
        if (memo[mask] != 0) {
            return memo[mask];
        }
        if (mask == nn - 1) {
            memo[mask] = 1;
            return 1;
        }
        memo[mask] = -1;
        int pos = Integer.bitCount(mask);
        for (int i = 0; i < n; i++) {
            int ii = 1 << i;
            if ((mask & ii) == 0 && curKeys[chestTypes[i]] > 0) {
                path[pos] = i;
                curKeys[chestTypes[i]]--;
                for (int x = 0; x < chestKeys[i].length; x++) {
                    curKeys[chestKeys[i][x]]++;
                }
                memo[mask] = compute(mask | ii, curKeys);
                if (memo[mask] > 0) {
                    return memo[mask];
                }
                curKeys[chestTypes[i]]++;
                for (int x = 0; x < chestKeys[i].length; x++) {
                    curKeys[chestKeys[i][x]]--;
                }
            }
        }
        return memo[mask];
    }

    public static void main(String[] args) {
        Scanner s = GCJ.createScanner('D', false, 0);
        int t = s.nextInt();
        for (int i = 1; i <= t; i++) {
            int k = s.nextInt();
            int n = s.nextInt();
            int[] initKeys = new int[201];
            for (int j = 0; j < k; j++) {
                initKeys[s.nextInt()]++;
            }
            int[] chestTypes = new int[n];
            int[][] chestKeys = new int[n][];
            for (int j = 0; j < n; j++) {
                chestTypes[j] = s.nextInt();
                int kj = s.nextInt();
                chestKeys[j] = new int[kj];
                for (int jj = 0; jj < kj; jj++) {
                    chestKeys[j][jj] = s.nextInt();
                }
            }
            Treasure tr = new Treasure(n, initKeys, chestTypes, chestKeys);
            GCJ.out(i, tr.compute());
        }
    }

}
