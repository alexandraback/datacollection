package gcj;

import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: svasilinets
 * Date: 04.05.13
 * Time: 20:08
 */
public class Osmos {


    public static int solve(int a, int[] m) {
        if (a == 1) {
            return m.length;
        }
        Arrays.sort(m);
        long curSize = a;
        int j = 0;
        int best = m.length;
        int steps = 0;
        while (true) {
            while (curSize <= m[j]) {
                curSize += (curSize - 1);
                steps++;
            }
            while (m[j] < curSize) {
                curSize += m[j];
                j++;
                if (j == m.length) {
                    return Math.min(best, steps);
                }
            }
            best = Math.min(steps + (m.length - j) , best);
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new FileInputStream("a4.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("ans.txt"));
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int a = sc.nextInt();
            int n = sc.nextInt();
            int[] m = new int[n];
            for (int j = 0; j < n; j++) {
                m[j] = sc.nextInt();
            }

            writer.write("Case #" + (i + 1) + ": " + solve(a, m));

            writer.newLine();
        }
        writer.close();

    }

}
