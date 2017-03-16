import com.sun.corba.se.spi.ior.MakeImmutable;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class TaskC {
    private static int N;
    private static int M;
    private static int K;
    private static int[] prod;
    private static int[] A;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numTests = in.nextInt();

        for (int testId = 1; testId <= numTests; ++testId) {
            System.out.println("Case #" + testId + ": ");

            int R = in.nextInt();
            N = in.nextInt();
            M = in.nextInt();
            K = in.nextInt();
            prod = new int[K];
            A = new int[N];
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < K; ++j) {
                    prod[j] = in.nextInt();
                }
                search(0, 2);
                for (int j = 0;j < N; ++j) {
                    System.out.print(A[j]);
                }
                System.out.println();
            }
        }
    }

    private static boolean search(int depth, int last) {
        if (depth == N) {
            return check();
        }
        for (int i = last; i <= M; ++i) {
            A[depth] = i;
            if (search(depth + 1, i)) {
                return true;
            }
            A[depth] = 0;
        }
        return false;
    }

    private static boolean check() {
        List<Integer> res = new ArrayList<Integer>();
        res.add(1);
        for (int i = 0; i < N; ++i) {
            List<Integer> newRes = new ArrayList<Integer>();
            for (int j = 0; j < res.size(); ++j) {
                int k = res.get(j) * A[i];
                if (!newRes.contains(k)) newRes.add(k);
            }
            for (int j = 0; j < newRes.size(); ++j) {
                int k = newRes.get(j);
                if (!res.contains(k)) res.add(k);
            }
        }
        for (int i =0; i < K; ++i) {
            if (!res.contains(prod[i])) return false;
        }
        return true;
    }
}
