import java.io.*;
import java.util.*;
import java.math.*;

public class B {
    public static void main(String[] args) { 
        PrintWriter out = new PrintWriter(System.out);

        Application application = new Application();
        application.solve(System.in, out);

        out.close();
    }
}


class Application {
    public void solve(InputStream in, PrintWriter out) {
        Scanner scanner = new Scanner(in);

        int T = scanner.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = scanner.nextInt();
            int M = 0;
            int A[] = new int[N];

            for (int i = 0; i < N; i++) {
                A[i] = scanner.nextInt();
                if (A[i] > M) { M = A[i]; }
            }

            int minCost = M;
            for (int x = 1; x <= M; x++) {
                int totalWait = 0;
                for (int i = 0; i < N; i++) {
                    int wait = (int) (Math.ceil((A[i] * 1.0f) / x)) - 1;
                    totalWait += wait;
                }

                int totalCost = x + totalWait;
                if (totalCost < minCost) {
                    minCost = totalCost;
                }
            }

            System.out.println("Case #" + t + ": " + minCost);
        }
    }
}
