package zad1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Formatter;
import java.util.Scanner;

/**
 *
 * @author Milen
 */
public class Zad1 {

    static int a = 0;
    static int[] arr;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.in"));
        Formatter out = new Formatter(new File("output.txt"));

        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            a = in.nextInt();
            int n = in.nextInt();
            arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextInt();
            }
            Arrays.sort(arr);
            int steps = n;
            if(a > 1){
                steps = func(0);
            }

            out.format("Case #%d: %d\n", test+1,steps);
        }


        out.close();
    }

    static int growSteps(int goal) {
        if (a > goal) {
            return 0;
        }
        a += (a - 1);
        return 1 + growSteps(goal);
    }

    static int func(int level) {
        if (level == arr.length) {
            return 0;
        }
        int count = 0;
        if (arr[level] < a) {
            a += arr[level];
            count = func(level + 1);
            a -= arr[level];
            return count;
        } else {
            int olda = a;
            int steps = growSteps(arr[level]);
            if (steps >= arr.length - level) {
                count += arr.length - level;
                a = olda;
                return count;
            }

            count += steps;
            a += arr[level];
            count += func(level + 1);
            a = olda;
            if (count >= arr.length - level) {
                return arr.length - level;
            } else {
                return count;
            }
        }
    }
}
