import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class NewLotteryGame {
    private static final String inputName = "e:/downloads/B-small-attempt0.in";
    private static final String outputName = "C:/workspaces/algo/GCJ/src/prolemB.out";

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new FileReader(inputName));
        // Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new FileWriter(outputName));
        int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            int K = sc.nextInt();
            int res = solve(A, B, K);
            String str = String.format("Case #%s: %s\n", t + 1, res);
            bw.write(str);
            System.out.print(str);
        }
        bw.close();
    }

    private static int solve(int A, int B, int K) {
        int res = 0;
        for (int a = 0; a < A; a++) {
            for (int b = 0; b < B; b++) {
                int t = a & b;
                if (t < K) {
                    res++;
                }
            }
        }
        return res;
    }

}
