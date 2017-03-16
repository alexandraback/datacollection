import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class BDanceScores {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("bsmall.in"));
        //Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter("bsmall.out");
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            int N = in.nextInt(), S = in.nextInt(), p = in.nextInt();
            int bigScores = 0, okScores = 0;
            for (int i = 0; i < N; ++i) {
                int sumScore = in.nextInt();
                int bestScore = (sumScore + 2) / 3;
                if (bestScore >= p) {
                    bigScores++;
                } else if (bestScore == p-1 && sumScore >= 2 && sumScore <= 28 && (sumScore % 3 != 1)) {
                    okScores++;
                }
            }
            int result = Math.min(okScores, S) + bigScores;
            out.println("Case #" + t + ": " + result);
        }
        out.close();
    }
}
