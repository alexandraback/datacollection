import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class DancingWithTheGooglers {
    private PrintWriter out;
    private Scanner in;

    private void init() {
    }

    private void solve() {
        int N = in.nextInt();
        int S = in.nextInt();
        int p = in.nextInt();

        int r = 0;
        for (int i = 0; i < N; i++) {
            int best = in.nextInt();
            int part = best / 3;
            int rest = best - part * 3;
            // rest = 0,1,2 part=4
            // 0: 4 4 4->4 3 5; 4 (+1)
            // 1: 4 4 5->3 5 5; 5 (0)
            // 2: 4 5 5->4 4 6; 5 (+1)
            // part=0: +0
            // 0: 0 0 0->0 0 0; 0 (+0)
            // 1: 0 0 1->0 0 1; 1 (+0)
            // 2: 0 1 1->0 0 2; 1 (+1)
            // part=1: +0
            // 0: 1 1 1->1 0 2; 1 (+1)
            // 1: 1 1 2->1 1 2; 2 (+0)
            // 2: 1 2 2->1 1 3; 2 (+1)
            int max = part + (rest == 0 ? 0 : 1);
            int add = rest == 1 ? 0 : 1;
            if (part == 0) {
                add = rest == 2 ? 1 : 0;
            }
            if (S >= 1 && add == 1 && max + 1 == p) {
                S--;
                max += add;
            }
            if (max >= p) {
                r++;
            }
        }
        out.println(r);
    }

    private void runTests() {
        init();

        int T = Integer.parseInt(in.nextLine());
        for (int i = 0; i < T; i++) {
            out.print("Case #" + (i + 1) + ": ");
            solve();
        }
    }

    private void run() {
        try {
            runTests();
        } finally {
            close();
        }
    }

    private void close() {
        out.close();
        in.close();
    }

    public DancingWithTheGooglers() throws FileNotFoundException {
        this.in = new Scanner(new File("B-small-attempt2.in"));
        this.out = new PrintWriter(new File("B-small-attempt2.out"));
    }

    public static void main(String[] args) throws FileNotFoundException {
        new DancingWithTheGooglers().run();
    }
}
