package codejam.y2013.r1b;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

/**
 * 
 */
public class Problem1 {
    
    private static int a;
    private static int n;
    private static int[] motes;

    public static void main(String[] args) throws IOException {
//        String name = "1.in.txt";
//        String name = "A-small-attempt0.in.txt";
        String name = "A-small-attempt1.in.txt";
        String path = "/Users/octavian/codejam2/" + name;
        Scanner scanner = new Scanner(new File(path));
        BufferedWriter writer = new BufferedWriter(new FileWriter(new File(path.replace(".in.", ".out."))));
        
        int T = scanner.nextInt();
        for (int c = 0; c < T; c++) {
            a = scanner.nextInt();
            n = scanner.nextInt();
            motes = new int[n];
            for (int i = 0; i < n; i++) {
                motes[i] = scanner.nextInt();
            }
            int minr = n;
            Arrays.sort(motes);
            for (int i = 0; i <= n; i++) {
                minr = Math.min(minr, solve(i));
            }
            writer.write("Case #" + (c + 1) + ": " + (minr) + "\n");
        }
        scanner.close();
        writer.close();
        System.out.println("finished");
    }

    private static int solve(int k) {
        int op = 0;
        int ca = a;
        for (int i = 0; i < k; i++) {
            while (ca <= motes[i]) {
                ca += (ca - 1);
                op++;
                if (ca <= 1) {
                    return n;
                }
            }
            ca += motes[i];
        }
        return op + (n - k);
    }
}
