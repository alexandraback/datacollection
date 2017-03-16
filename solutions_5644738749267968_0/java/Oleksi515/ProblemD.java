import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemD {
    static int T;
    static int N;
    static double[] NAOMI;
    static double[] KEN;

    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(new FileReader("ProblemD.txt"));
        FileWriter fileWriter = new FileWriter("ProblemD.out");
        BufferedWriter bw = new BufferedWriter(fileWriter);

        T = scanner.nextInt();
        for (int testNumber = 1; testNumber <= T; ++testNumber) {
            N = scanner.nextInt();
            NAOMI = new double[N];
            KEN = new double[N];
            for (int i = 0; i < N; ++i) {
                NAOMI[i] = scanner.nextDouble();
            }
            for (int i = 0; i < N; ++i) {
                KEN[i] = scanner.nextDouble();
            }
            Arrays.sort(NAOMI);
            Arrays.sort(KEN);

            bw.write("Case #" + testNumber + ": " + calculateDeceitfulWar() + " " + calculateWar());
            bw.newLine();
        }
        bw.close();
    }

    private static int calculateDeceitfulWar() {
        int result = 0;
        int minKenIndex = 0;
        for (int i = 0; i < N; ++i) {
            if (NAOMI[i] > KEN[minKenIndex]) {
                ++result;
                ++minKenIndex;
            }
        }
        return result;
    }

    private static int calculateWar() {
        int result = 0;
        int maxKenIndex = N - 1;
        for (int i = N - 1; i >= 0; --i) {
            if (NAOMI[i] > KEN[maxKenIndex]) {
                ++result;
            } else {
                --maxKenIndex;
            }
        }
        return result;
    }
}
