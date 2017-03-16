import java.io.*;
import java.util.*;
import java.math.*;

public class A {
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
        scanner.nextLine();
        for (int t = 1; t <= T; t++) {
            String[] tokens = scanner.nextLine().split(" ");
            int N = Integer.parseInt(tokens[0]);
            int S[] = new int[N+5];
            for (int i = 0; i <= N; i++) {
                S[i] = Integer.parseInt(tokens[1].charAt(i) + "");
            }

            int A[] = new int[N+5];
            A[0] = 0;
            for (int i = 1; i <= N; i++) {
                A[i] = A[i-1] + S[i-1];
            }

            int M = 0;
            for (int i = 0; i <= N; i++) {
                if (A[i] < i) {
                    int D = i - A[i];
                    if (D > M) { M = D; }
                }
            }
            System.out.println("Case #" + t + ": " + M);
        }
    }
}
