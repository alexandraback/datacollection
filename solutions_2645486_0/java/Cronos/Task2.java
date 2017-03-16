package codejam.y2013.r1a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

import static java.lang.Math.max;
import static java.lang.Math.min;

/**
 * @author Cronos
 */
public class Task2 {

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        int E = input.nextInt();
        int R = input.nextInt();
        int N = input.nextInt();
        int[] v = new int[N];
        for (int i = 0; i < N; i++) {
            v[i] = input.nextInt();
        }
        return  "" + rec(E, E, R, v, 0, 0);
    }

    private static int rec(int currentEnergy, int maxEnergy, int R, int[] v, int step, int tv) {
        if (step >= v.length) return tv;
        currentEnergy += R;
        currentEnergy = min(currentEnergy, maxEnergy);
        int res = tv;
        for (int i = 0; i <= currentEnergy; i++) {
            res = max(res, rec(currentEnergy - i, maxEnergy, R, v, step + 1, tv + (v[step] * i)));
        }
        return res;
    }
}
