import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class B {
    private static final String tooBad = "Too Bad";

    public String solve(int N, int[] a, int[] b) {
        int res = 0;
        int nStars = 0;
        boolean[] completed = new boolean[N * 2];
        while (true) {
            int best = -1;
            int max = -1;
            for (int i = 0; i < N; i++) {
                if (!completed[i * 2 + 1] && b[i] <= nStars) {
                    best = i * 2 + 1;
                    break;
                }
                if (!completed[i * 2] && a[i] <= nStars && b[i] > max) {
                    best = i * 2;
                    max = b[i];
                }
            }
            if (best < 0) break;
            nStars++;
            res++;
            completed[best] = true;
            if (best % 2 == 1) {
                if (!completed[best - 1]) {
                    nStars++;
                    completed[best - 1] = true;
                }
            }
        }
        if (nStars < N * 2) return tooBad;
        return String.valueOf(res);
    }

    public static void main(String[] args) {
        try {
            int T;
            BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

            T = Integer.parseInt(input.readLine());
            for (int i = 0; i < T; i++) {
                int N = Integer.parseInt(input.readLine());
                int[] a = new int[N];
                int[] b = new int[N];
                for (int j = 0; j < N; j++) {
                    String[] str2 = input.readLine().split(" ");
                    if (str2.length != 2) throw new RuntimeException();
                    a[j] = Integer.parseInt(str2[0]);
                    b[j] = Integer.parseInt(str2[1]);
                }
                System.out.println("Case #" + (i + 1) + ": " + new B().solve(N, a, b));
            }
            if (input.readLine() != null) throw new RuntimeException();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
