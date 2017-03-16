
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author  tasyrkin
 * @since   2014/04/12
 */
public class NewLotteryGame {

    public static void main(final String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Integer t = Integer.parseInt(br.readLine());
        int init = t;
        while (t-- > 0) {
            String[] ps = br.readLine().split("\\s+");
            int A = Integer.parseInt(ps[0]);
            int B = Integer.parseInt(ps[1]);
            int K = Integer.parseInt(ps[2]);

            int cnt = 0;
            int doubles = 0;
            for (int i = 0; i < A; i++) {
                for (int j = 0; j < B; j++) {
                    int bit = (i & j);
                    if (bit < K) {

                        // System.out.println("i=" + i + ", j=" + j);
                        if (i == j) {
                            doubles++;
                        }

                        cnt++;
                    }

                }
            }

            System.out.println("Case #" + (init - t) + ": " + (cnt));
        }

    }

}
