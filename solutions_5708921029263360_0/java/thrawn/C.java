package de.shadowhunt.codejam.c4314486;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class C {

    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }

    public static void solve(final InputStream in, final PrintStream out) throws Exception {
        final BufferedReader br = new BufferedReader(new InputStreamReader(in));
        final int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            String[] line = br.readLine().split(" ");
            final int J = Integer.parseInt(line[0]);
            final int P = Integer.parseInt(line[1]);
            final int S = Integer.parseInt(line[2]);
            final int K = Integer.parseInt(line[3]);

            final String[] all = new String[J*P*S];
            
            final int[][] js = new int[J][S];
            final int[][] jp = new int[J][P];
            final int[][] ps = new int[P][S];

            int count = 0;
            for (int j = 0; j < J; j++) {
                for (int p = 0; p < P; p++) {
                    for (int s = 0; s < S; s++) {
                        if ((js[j][s] >= K) || (jp[j][p] >= K) || (ps[p][s] >= K)) {
                            continue;
                        }

                        js[j][s]++;
                        jp[j][p]++;
                        ps[p][s]++;

                        all[count++] = (j + 1) + " " + (p + 1) + " " + (s + 1);
                    }
                }
            }
            out.println("Case #" + i + ": " + count);
            for (int c = 0; c < count; c++) {
                out.println(all[c]);
            }
        }
    }
}
