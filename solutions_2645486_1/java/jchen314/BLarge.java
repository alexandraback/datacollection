import java.util.Arrays;
import java.util.Scanner;

public class BLarge {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            int E = sc.nextInt();
            int R = sc.nextInt();
            int N = sc.nextInt();
            long[] v = new long[N];

            if (R > E) {
                R = E;
            }

            for (int i = 0; i < N; i++) {
                v[i] = sc.nextInt();
            }

            long total = 0;
            long[] available = new long[N];
            long[] required = new long[N];
            Arrays.fill(available, E);
            for (int i = 0; i < N; i++) {
                int maxIndex = 0;
                for (int j = 0; j < N; j++) {
                    if (v[maxIndex] < v[j])
                        maxIndex = j;
                }
                long used = available[maxIndex] - required[maxIndex];
                if (used < 0)
                    used = 0;
                total += v[maxIndex] * used;
                required[maxIndex] += used;
                v[maxIndex] = 0;
                long amount = available[maxIndex] - used;
                for (int j = maxIndex; j < N; j++) {
                    available[j] = Math.min(amount + (j - maxIndex) * R, available[j]);
                }
                for (int j = maxIndex - 1; j >= 0; j--) {
                    required[j] = Math.max(required[maxIndex] - R * (maxIndex - j), required[j]);
                }
                // for (int j : available)
                // System.out.print(j);
                // System.out.print("\t");
                // for (int j : required)
                // System.out.print(j);
                // System.out.println();
            }

            System.out.println("Case #" + caseNum + ": " + total);
        }
    }
}
