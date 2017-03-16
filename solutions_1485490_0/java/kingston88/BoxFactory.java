import java.util.*;
import java.io.*;

public class BoxFactory {

    class Testcase {
        long ans;

        public Testcase() {
        }

        public Testcase(int seed) {
            Random rnd = new Random(seed);
        }

        int N, M;
        long[] boxes;
        long[] toys;

        public void loadInput(Scanner sc) {
            N = sc.nextInt();
            M = sc.nextInt();
            boxes = new long[2 * N];
            toys = new long[2 * M];
            for (int i = 0; i < 2* N; i++) {
                boxes[i] = sc.nextLong();
            }
            for (int i = 0; i < 2 * M; i++) {
                toys[i] = sc.nextLong();
            }
        }

        public void solveSlow() {
        }

        public void solveFast() {
            long[][] dp = new long[N + 1][M + 1];
            for (int i = 0; i <= N; i++) {
                dp[i][0] = 0;
            }
            for (int j = 0; j <= M; j++) {
                dp[0][j] = 0;
            }
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    if (boxes[2*(i - 1) + 1] == toys[2 * (j - 1) + 1]) { // if the types are equal
                        dp[i][j] = Math.max(Math.max(dp[i - 1][j - 1] + Math.min(boxes[2 * (i - 1)], toys[2 * (j - 1)]), dp[i - 1][j]), dp[i][j - 1]) ;
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                    
                }
            }
            ans = dp[N][M];
        }

        public void printSelf(PrintWriter pw) {
            pw.println(ans);
        }

        public boolean sameAnswers(Testcase other) {
            return false;
        }
    }

    final String AFTER_CASE = " ";

    public void go() throws Exception {

        Scanner sc = new Scanner(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));

        int caseCnt = sc.nextInt();

        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("solving case " + caseNum);

            Testcase tc = new Testcase();

            tc.loadInput(sc);
            tc.solveFast();

            pw.print("Case #" + (caseNum + 1) + ":");
            pw.print(AFTER_CASE);

            tc.printSelf(pw);
        }

        pw.flush();
        pw.close();
        sc.close();
    }

    public void stresstest() {
        int it = 0;
        Random rnd = new Random();
        while (true) {
            it++;
            if (it % 1000 == 0)
                System.out.println(it + " iterations");

            int seed = rnd.nextInt();

            Testcase tc1 = new Testcase(seed);
            tc1.solveFast();

            Testcase tc2 = new Testcase(seed);
            tc2.solveSlow();

            if (!tc1.sameAnswers(tc2)) {
                System.out.println("ERROR: it failed");
                System.exit(0);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        new BoxFactory().go();
    }
}
