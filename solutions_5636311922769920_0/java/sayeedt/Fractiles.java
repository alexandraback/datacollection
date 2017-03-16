package fractiles;

import java.io.*;
import java.util.*;

/**
 * Created by Sayeed on 4/9/2016.
 */
public class Fractiles {
    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new FileReader("D-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("D-small-attempt0.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        int K, C, S;
        long[] positions;

        for (int caseNum = 1; caseNum <= T; caseNum++) {
            st = new StringTokenizer(br.readLine());
            K = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            S = Integer.parseInt(st.nextToken());

            positions = solvePositions(K, C, S);

            pw.print("Case #" + caseNum + ":");

            if (positions.length == 0) {
                pw.println(" IMPOSSIBLE");
            } else if (positions.length > 0) {
                for (long p : positions) {
                    pw.print(" " + p);
                }
                pw.println();
            }
        }

        br.close();
        pw.close();
    }

    public static long[] solvePositions(int K, int C, int Smax) {
        if (Smax * C < K) {
            return new long[0];
        }

        int S = (K-1)/C + 1;
        long[] positions = new long[S];

        long[] powTable = new long[C];
        powTable[0] = (long) 1;
        for (int exp = 1; exp < C; exp++) {
            powTable[exp] = powTable[exp-1] * ((long) K);
        }

        for (int i = 0; i < positions.length - 1; i++) {
            long pos = 0;
            for (int j = 0; j < C; j++) {
                pos += (C * i + j) * powTable[j];
            }
            positions[i] = pos + 1;
        }

        int lastBlockSize = (K - C*(S-1));
        long pos = 0;
        for (int j = 0; j < lastBlockSize; j++) {
            pos += (C * (S-1) + j) * pow((long) K, j);
        }
        positions[S-1] = pos + 1;

        return positions;
    }

    public static long pow(long base, int exp) {
        if (exp == 0) {
            return (long) 1;
        } else if (exp == 1) {
            return base;
        } else if (exp > 1) {
            long a = pow(base, exp/2);
            a *= a;
            if ((exp % 2) == 1) {
                a *= base;
            }
            return a;
        } else {
            throw new IllegalArgumentException("Negative exponent");
        }
    }
}
