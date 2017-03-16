import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class DijkstraBF {

    private void processInput() throws IOException {
        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int testCase = 1; testCase <= T; testCase++) {
            int L = in.nextInt();
            int X = in.nextInt();
            String str = in.next();

            solve(testCase, L, X, str);
        }

        in.close();
    }

    int[][] op = {{0, 1, 2, 3},
                  {1, 0, 3, 2},
                  {2, 3, 0, 1},
                  {3, 2, 1, 0}};
    int[][] sign = {{1, 1, 1, 1},
                    {1, -1, 1, -1},
                    {1, -1, -1, 1},
                    {1, 1, -1, -1}};
    public void solve(int testCase, int L, int X, String str) {

        String res = "NO";
        int val = 0;
        int s = 1;
        int exp = 1;
        String idx = "1ijk";
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < str.length(); j++) {
                int next = idx.indexOf(str.charAt(j));
                s *= sign[val][next];
                val = op[val][next];
                if (s == 1 && val == exp && exp < 4) {
                    exp++;
                    val = 0;
                }
            }
        }

        if (val == 0 && s == 1 && exp == 4) {
            res = "YES";
        }
        System.out.printf(Locale.ENGLISH, "Case #%d: %s\n", testCase, res);
    }

    public static void main(String[] args) throws Exception {
        DijkstraBF main = new DijkstraBF();
        main.processInput();
    }
}
