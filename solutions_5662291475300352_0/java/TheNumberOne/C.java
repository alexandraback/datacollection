package rounds.round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class C {

    int[][] input;

    static Scanner in;
    static PrintStream out;

    public static void main(String[] args) throws FileNotFoundException {
        out = new PrintStream("out.txt");
        in = new Scanner(new File(args[0]));

        int N = in.nextInt();
        in.nextLine();

        for (int i = 0; i < N; i++) {
            runTestCase(i + 1);
        }
    }

    private static void runTestCase(int id) {
        int N = in.nextInt();
        int[][] input = new int[N][];
        for (int i = 0; i < N; i++) {
            int D = in.nextInt();
            int H = in.nextInt();
            int M = in.nextInt();
            input[i] = new int[]{D, H, M};
        }
        int s = new C(input).solve();
        out.printf("Case #%d: %d\n", id, s);
    }

    public C(int[][] input) {
        this.input = input;
    }

    int solve() {
        int hikers = 0;
        for (int[] a : input) {
            hikers += a[1];
        }
        int[][] speeds = new int[hikers][];
        int i = 0;
        for (int[] a : input){
            for (int j = 0; j < a[1]; j++){
                speeds[i++] = new int[]{a[0], a[2] + j};
            }
        }
        if (hikers == 1){
            return 0;
        }
        Arrays.sort(speeds, Comparator.comparingInt((int[] a) -> a[1]).reversed());
        if (speeds[0][1] == speeds[1][1]){
            return 0;
        }
        double time0 = (360.0 - speeds[0][0]) / (360.0 / speeds[0][1]);
        double time1 = (360.0 - speeds[1][0]) / (360.0 / speeds[1][1]);
        if (time0 < time1 + speeds[1][1]){
            return 0;
        } else {
            return 1;
        }
    }

}