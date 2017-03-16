package gcj2013.r1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class B {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/gcj2013/r1a/in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/gcj2013/r1a/B.out")));

        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++) {
            String[] line = in.readLine().split(" ");
            int E = Integer.parseInt(line[0]);
            int R = Integer.parseInt(line[1]);
            int N = Integer.parseInt(line[2]);
            int[] v = new int[N];
            int[][] sortedV = new int[N][2];
            int[][] reverseV = new int[N][2];
            line = in.readLine().split(" ");

            if (R > E) {
                R = E;
            }

            for (int j = 0; j < N; j++) {
                v[j] = Integer.parseInt(line[j]);
                sortedV[j][0] = j;
                sortedV[j][1] = v[j];
                reverseV[j][0] = j;
                reverseV[j][1] = v[j];
            }

            Arrays.sort(reverseV, new Comparator<int[]>() {
                @Override
                public int compare(int[] a, int[] b) {
                    return b[1] - a[1];
                }
            });

            double[] energy = new double[N];
            for (int j = 0; j < N; j++) {
                energy[j] = E;
            }

            double[] energyUse = new double[N];

            for (int j = 0; j < N; j++) {
                double use = energy[reverseV[j][0]];
                int pos = reverseV[j][0];
                for (int k = pos + 1; k < N; k++) {
                    if (energyUse[k] != 0) {
                        use = Math.min(use, use - energyUse[k] + R * (k - pos));
                    }
                }
                if (use > 0) {
                    energyUse[pos] = use;
                    energy[pos] -= use;
                    double curr = energy[pos];
                    for (int k = pos + 1; k < N; k++) {
                        curr += R;
                        energy[k] = Math.min(energy[k], curr);
                    }
                }

            }

            int gain = 0;
            for (int j = 0; j < N; j++) {
                gain += v[j] * energyUse[j];
            }

            out.println("Case #" + (i + 1) + ": " + gain);

        }

        out.close();
    }
}
