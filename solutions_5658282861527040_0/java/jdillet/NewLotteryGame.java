import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class NewLotteryGame {

    private void processInput() throws IOException {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        for (int testCase = 1; testCase <= T; testCase++) {
            int A = in.nextInt();
            int B = in.nextInt();
            int K = in.nextInt();

            long res = go(A, B, K);

            System.out.printf(Locale.ENGLISH, "Case #%d: %d\n", testCase, res);         
        }

        in.close();
    }

    private long go(int A, int B, int K) {
        long res = 0;
        
        for (int i = 0 ; i < A; i++) {
            for (int j = 0; j < B; j++) {
                
                if ((i & j) < K) {
                    res++;
                }
                
            }
        }
        
        
        return res;
    }

    public static void main(String[] args) throws Exception {
        NewLotteryGame main = new NewLotteryGame();
        main.processInput();
    }
}
