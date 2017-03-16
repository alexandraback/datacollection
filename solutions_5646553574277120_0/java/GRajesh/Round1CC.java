package com.fm;

import java.util.Arrays;
import java.util.Scanner;

public class Round1CC {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long t = sc.nextLong();

        int i = 1;
        int c, d, v;
        while (i <= t) {
            c = sc.nextInt();
            d = sc.nextInt();
            v = sc.nextInt();

            int arr[] = new int[d];

            for (int k = 0; k < d; k++) {
                arr[k] = sc.nextInt();
            }

            int count = 0;

            while (true) {
                int dp[][] = new int[d + 1][v + 1];
                for (int m = 1; m <= d; m++) {
                    for (int p = 1; p <= v; p++) {
                        if (p < arr[m - 1]) {
                            dp[m][p] = dp[m - 1][p];
                        } else {
                            if (dp[m - 1][p - arr[m - 1]] != 0 || arr[m - 1] == p) {
                                dp[m][p] = arr[m - 1] + dp[m - 1][p - arr[m - 1]];
                            }
                        }
                    }
                }

                boolean b = true;
                int z;
                for (z = 1; z <= v; z++) {
                    if (dp[d][z] != z) {
                        b = false;
                        break;
                    }
                }

                if (b) {
                    break;
                } else {
                    d = d + 1;
                    arr = Arrays.copyOf(arr, d);
                    arr[d - 1] = z;
                    Arrays.sort(arr);
                }
                count++;
            }

            System.out.println("Case #" + i + ": " + count);
            i++;
        }
    }
}
