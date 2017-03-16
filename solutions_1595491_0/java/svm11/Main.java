import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new FileWriter("DancingWithTheGooglers-Small.out"));

        DancingWithTheGooglers solver = new DancingWithTheGooglers();
        int testCases = in.nextInt();
        for (int i = 1; i <= testCases; ++i) {
            solver.solve(i, in, out);
        }

        in.close();
        out.close();
    }
}

class DancingWithTheGooglers {
    int MAX_SCORE = 31;
    int[] bestScoreSurprising = new int[MAX_SCORE];
    int[] bestScoreNotSurprising = new int[MAX_SCORE];

    public DancingWithTheGooglers() {
        Arrays.fill(bestScoreSurprising, -1);
        Arrays.fill(bestScoreNotSurprising, -1);
        for (int i = 0; i <= 10; ++i) {
            for (int j = 0; j <= 10; ++j) {
                for (int k = 0; k <= 10; ++k) {
                    if (Math.abs(i - j) > 2 || Math.abs(j - k) > 2 || Math.abs(k - i) > 2) continue;
                    if (Math.abs(i - j) == 2 || Math.abs(j - k) == 2 || Math.abs(k - i) == 2) {
                        int sum = i + j + k;
                        int score = Math.max(i, Math.max(j, k));
                        bestScoreSurprising[sum] = Math.max(bestScoreSurprising[sum], score);
                    }
                    else {
                        int sum = i + j + k;
                        int score = Math.max(i, Math.max(j, k));
                        bestScoreNotSurprising[sum] = Math.max(bestScoreNotSurprising[sum], score);
                    }
                }
            }
        }
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int N = in.nextInt();
        int S = in.nextInt();
        int P = in.nextInt();
        int[] t = new int[N];
        for (int i = 0; i < N; ++i)
            t[i] = in.nextInt();

        int res = 0;
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, z = 0;
        for (int score : t) {
            if (bestScoreSurprising[score] == -1) {
                if (bestScoreNotSurprising[score] >= P) {
                    ++a;
                }
                else {
                    ++c;
                }
            }
            else if (bestScoreNotSurprising[score] == -1) {
                if (bestScoreSurprising[score] >= P) {
                    ++b;
                }
                else {
                    ++d;
                }
            }

            if (bestScoreSurprising[score] >= P) {
                if (bestScoreNotSurprising[score] >= P) {
                    ++h;
                }
                else {
                    ++f;
                }
            }
            else if (0 <= bestScoreSurprising[score] && bestScoreSurprising[score] < P) {
                if (bestScoreNotSurprising[score] >= P) {
                    ++g;
                }
                else {
                    ++e;
                }
            }
        }

        z = Math.min(S, b + d);
        S -= z;
        res += a + b;
        z = Math.min(S, f);
        S -= z;
        res += z;
        z = Math.min(S, e + h);
        S -= z;
        res += g + h - S;

        out.println("Case #" + testNumber + ": " + res);
    }
}
