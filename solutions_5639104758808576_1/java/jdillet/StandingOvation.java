import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class StandingOvation {

    private void processInput() throws IOException {
        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int testCase = 1; testCase <= T; testCase++) {
            int s = in.nextInt();
            String str = in.next();

            solve(testCase, s, str);
        }

        in.close();
    }

    public void solve(int testCase, int s, String str) {
        int res = 0;
        int sum = 0;

        for (int i = 0; i <= s; i++) {
            int curr = str.charAt(i) - '0';
            sum += curr;
            if (sum < i + 1) {
                res++;
                sum++;
            }
        }

        System.out.printf(Locale.ENGLISH, "Case #%d: %d\n", testCase, res);
    }

    public static void main(String[] args) throws Exception {
        StandingOvation main = new StandingOvation();
        main.processInput();
    }
}
