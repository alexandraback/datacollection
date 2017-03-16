import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        String input = "Input.in";
        String smallAttempt0 = "C-small-attempt0.in";
        String smallAttempt1 = "C-small-attempt1.in";
        String smallAttempt2 = "C-small-attempt2.in";
        String largeAttempt = "C-large.in";

        String output = "Output.out";

        Scanner in = new Scanner(new FileReader(smallAttempt0));
        PrintWriter out = new PrintWriter(new FileWriter(output));

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
        int n = in.nextInt();
        int[] x = new int[n];
        for (int i = 0; i < n; ++i)
            x[i] = in.nextInt();

        out.println("Case #" + testNumber + ":");
        Sum[] s = new Sum[1 << n];
        s[0] = new Sum(0, -1);
        for (int i = 1; i < (1 << n); ++i) {
            s[i] = new Sum(i, 0);
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) == 0) continue;
                s[i].sum += x[j];
            }
        }
        Arrays.sort(s, new Comparator<Sum>() {
            public int compare(Sum o1, Sum o2) {
                return o1.sum - o2.sum;
            }
        });

        int first = -1, second = -1;
        for (int i = 1; i < (1 << n); ++i) {
            if (s[i].sum == s[i - 1].sum) {
                first = s[i].subset;
                second = s[i - 1].subset;
                break;
            }
        }
        if (first == -1 || second == -1) {
            out.println("Impossible");
        }
        else {
            int and = first & second;
            and = ~and;
            first &= and;
            second &= and;
            for (int i = 0; i < n; ++i) {
                if ((first & (1 << i)) == 0) continue;
                out.print(x[i] + " ");
            }
            out.println();
            for (int i = 0; i < n; ++i) {
                if ((second & (1 << i)) == 0) continue;
                out.print(x[i] + " ");
            }
            out.println();
        }
    }

    public class Sum {
        int subset;
        int sum;

        public Sum(int subset, int sum) {
            this.subset = subset;
            this.sum = sum;
        }
    }
}
