package codejam.y2013.r1a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

/**
 * @author Cronos
 */
public class Task3 {

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
        int R = input.nextInt();
        int N = input.nextInt();
        int M = input.nextInt();
        int K = input.nextInt();
        StringBuilder result = new StringBuilder("\n");
        for (int i = 0; i < R; i++) {
            result.append(getResultInternal(N, M, K) + "\n");
        }
        return result.toString();
    }

    private static String getResultInternal(int N, int M, int K) {
        long[] products = new long[K];
        for (int i = 0; i < K; i++) {
            products[i] = input.nextLong();
        }
        Map<Integer, Integer> factors = new HashMap<Integer, Integer>();
        for (int i = 2; i <= 8; i++) {
            factors.put(i, 0);
        }
        for (int i = 0; i < K; i++) {
            Map<Integer, Integer> lf = new HashMap<Integer, Integer>();
            long p = products[i];
            while (p > 1) {
                for (int j = M; j >= 2; j--) {
                    if (p % j == 0) {
                        if (lf.get(j) == null) {
                            lf.put(j, 1);
                        } else {
                            lf.put(j, lf.get(j) + 1);
                        }
                        if (j == 8) {
                            if (lf.get(2) == null) {
                                lf.put(2, 4);
                            } else {
                                lf.put(2, factors.get(2) + 4);
                            }
                            if (lf.get(4) == null) {
                                lf.put(4, 2);
                            } else {
                                lf.put(4, factors.get(4) + 2);
                            }
                        }
                        if (j == 4) {
                            if (lf.get(2) == null) {
                                lf.put(2, 2);
                            } else {
                                lf.put(2, factors.get(2) + 2);
                            }
                        }
                        p /= j;
                        break;
                    }
                }
            }
            for (Map.Entry<Integer, Integer> entry : lf.entrySet()) {
                int old = factors.get(entry.getKey());
                if (entry.getValue() > old) factors.put(entry.getKey(), entry.getValue());
            }
        }

        StringBuilder result = new StringBuilder();
        if (factors.get(6) > 0) {
            result.append("6");
            factors.put(3, factors.get(3) - 1);
            factors.put(2, factors.get(2) - 1);
        } else if (factors.get(3) > 0) {
            result.append("3");
            factors.put(3, factors.get(3) - 1);
        }
        if (factors.get(5) > 0) {
            result.append("5");
            factors.put(5, factors.get(5) - 1);
        }
        if (factors.get(7) > 0) {
            result.append("7");
            factors.put(7, factors.get(7) - 1);
        }
        if (factors.get(8) > 0) {
            result.append("8");
            factors.put(8, factors.get(8) - 1);
            factors.put(4, factors.get(4) - 2);
            factors.put(2, factors.get(2) - 4);
        } else if (factors.get(4) > 0) {
            result.append("4");
            factors.put(4, factors.get(4) - 1);
            factors.put(2, factors.get(2) - 2);
        }
        if (result.length() >= N) return result.toString();
        for (int i = 2; i <= M; i++) {
            int count = factors.get(i);
            for (int j = 0; j < count; j++) {
                result.append(i);
                if (result.length() >= N) return result.toString();
            }
        }

        StringBuilder unknownResult = new StringBuilder();
        for (int i = 0; i < N; i++) {
            unknownResult.append("2");
        }
        return unknownResult.toString();
    }

}
