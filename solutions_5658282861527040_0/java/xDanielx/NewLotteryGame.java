import java.util.Scanner;

public class NewLotteryGame {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numTestCases = sc.nextInt();
        for (int testCase = 1; testCase <= numTestCases; ++testCase) {
            System.out.printf("Case #%d: %s\n", testCase,
                    solve(sc.nextInt(), sc.nextInt(), sc.nextInt()));
        }
    }

    static long solve(int maxA, int maxB, int maxWinner) {
        long total = 0;
        for (int a = 0; a < maxA; ++a)
            for (int b = 0; b < maxB; ++b)
                if ((a & b) < maxWinner)
                    ++total;
        return total;
    }
}
