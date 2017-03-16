import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class G_1 {

    public static void main(String[] args) throws Exception {
        G_1 instance = new G_1();
        instance.func();
    }

    PrintWriter bw;

    public void func() throws Exception {
        bw = new PrintWriter(new FileWriter("1.txt"));
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        next_i: for (int i = 0; i < T; i++) {
            int N = scan.nextInt();
            int[] s = new int[N];
            int[] s_o = new int[N];
            int X = 0;
            for (int j = 0; j < N; ++j) {
                s[j] = scan.nextInt();
                s_o[j] = s[j];
                X += s[j];
            }
            Arrays.sort(s);
            for (int j = 0; j < N; ++j) {
                int sub_sum = 0;
                for (int k = 0; k <= j; ++k) {
                    sub_sum += s[k];
                }
                double avg = (sub_sum + X) * 1.0 / (j + 1);
                if (j == N - 1 || avg <= s[j + 1]) {
                    print(String.format("Case #%d:", (i + 1)));
                    for (int m = 0; m < N; ++m) {
                        if (s_o[m] > avg) {
                            print(String.format(" %f", 0.0));
                        } else {
                            double key = 100 * (avg - s_o[m]) * 1.0 / X;
                            print(String.format(" %f", key < 0 ? 0 : key));

                        }
                    }
                    print("\n");
                    continue next_i;
                }
            }

            /*
             * double avg = 2.0 * X / N; int count = N; for (int j = 0; j < N; ++j) { if (s[j] > avg) { count--; } } print(String.format("Case #%d:",
             * (i + 1))); for (int j = 0; j < N; ++j) { }
             */
            // System.out.println(String.format("Case #%d: %d", (i + 1), 1));
            // bw.write(String.format("Case #%d: %d\n", (i + 1), 1));
        }
        bw.flush();
        bw.close();
    }

    void print(String s) {
        System.out.print(s);
        bw.write(s);
    }
}
