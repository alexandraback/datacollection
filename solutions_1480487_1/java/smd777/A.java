package gcj2012.r1b;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 *
 * @author Scott DellaTorre
 */
public class A {

    public static void main(String[] args) throws IOException {
        try (BufferedReader in = new BufferedReader(new FileReader("src/gcj2012/r1b/in"));
                PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/gcj2012/r1b/A.out")));) {

            int T = Integer.parseInt(in.readLine());
            for (int i = 0; i < T; i++) {
                StringTokenizer st = new StringTokenizer(in.readLine());
                int N = Integer.parseInt(st.nextToken());
                int[] s = new int[N];
                int X = 0;
                for (int j = 0; j < N; j++) {
                    s[j] = Integer.parseInt(st.nextToken());
                    X += s[j];
                }

                double maximumMinimum = 0;
                double[] tempS = new double[N];
                for (int j = 0; j < N; j++) {
                    tempS[j] = s[j];
                }
                double tempX = X;
                Arrays.sort(tempS);
                for (int j = 0; j < N - 1; j++) {
                    double diff = (tempS[j + 1] - tempS[j]) * (j + 1);
                    if (diff >= tempX) {
                        tempS[j] += tempX / (j + 1);
                        tempX = 0;
                        maximumMinimum = tempS[j];
                        break;
                    } else {
                        tempS[j] += diff / (j + 1);
                        tempX -= diff;
                        maximumMinimum = tempS[j];
                    }
                }
                if (tempX > 0) {
                    maximumMinimum += tempX / N;
                }

                out.print("Case #" + (i + 1) + ": ");
                for (int j = 0; j < N; j++) {
                    if (s[j] > maximumMinimum) {
                        out.print(0);
                    } else {
                        out.print((maximumMinimum - s[j]) / X * 100);
                    }
                    if (j < N - 1) {
                        out.print(" ");
                    }
                }
                out.println();

            }

        }
    }
}
