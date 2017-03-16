import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class CSmall {
    private int[][] candidates = {
            {5,5,5},{5,5,4},{5,5,3},{5,5,2},
            {5,4,4},{5,4,3},{5,4,2},
            {5,3,3},{5,3,2},
            {5,2,2},
            {4,4,4},{4,4,3},{4,4,2},
            {4,3,3},{4,3,2},
            {4,2,2},
            {3,3,3},{3,3,2},
            {3,2,2},
            {2,2,2},
    };

    public String solve(int[] P) {
        Arrays.sort(P);
        for (int[] candidate : candidates) {
            boolean possible = true;
            for (int t : P) {
                for (int n : candidate) {
                    if (t % n == 0) t /= n;
                }
                if (t != 1) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                String res = "";
                for (int n : candidate) {
                    res += n;
                }
                return res;
            }
        }
        return "";
    }

    public static void main(String[] args) {
        try {
            int T;
            BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

            T = Integer.parseInt(input.readLine());
            for (int i = 0; i < T; i++) {
                String[] str = input.readLine().split(" ");
                if (str.length != 4) throw new RuntimeException();
                int R = Integer.parseInt(str[0]);
                int N = Integer.parseInt(str[1]);
                int M = Integer.parseInt(str[2]);
                int K = Integer.parseInt(str[3]);
                System.out.println("Case #" + (i + 1) + ":");
                for (int j = 0; j < R; j++) {
                    str = input.readLine().split(" ");
                    if (str.length != K) throw new RuntimeException();
                    int[] p = new int[K];
                    for (int k = 0; k < K; k++) {
                        p[k] = Integer.parseInt(str[k]);
                    }
                    System.out.println(new CSmall().solve(p));
                }
            }
            if (input.readLine() != null) throw new RuntimeException();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
