import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileReader("A-large.in"));
        PrintWriter out = new PrintWriter(new FileWriter("Output.out"));

        Task solver = new Task();
        int testCases = in.nextInt();
        for (int i = 1; i <= testCases; ++i)
            solver.solve(i, in, out);

        in.close();
        out.close();
    }
}

class Task {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int A = in.nextInt(), B = in.nextInt(), C = B - A;
        double[] probability = new double[A + 1];
        probability[0] = 1.0;
        for (int i = 1; i <= A; ++i)
            probability[i] = in.nextDouble();
        for (int i = 1; i <= A; ++i)
            probability[i] *= probability[i - 1];

        double res = B + 2;

        for (int i = 0; i <= A; ++i) {
            double p = probability[A - i], q = 1.0 - p;
            double e = p * (2 * i + C + 1) + q * (2 * i + B + C + 2);
            res = Math.min(res, e);
        }

        out.println("Case #" + testNumber + ": " + res);
    }
}
