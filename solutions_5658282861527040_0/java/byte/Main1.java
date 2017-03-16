import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Created with IntelliJ IDEA.
 * User: gouravr
 * Date: 5/3/14
 * Time: 10:23 PM
 */
public class Main1 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T, A, B, K;
        T = Integer.parseInt(br.readLine().trim());

        int index = 0;
        while (T-- > 0) {
            index++;
            System.out.print(String.format("Case #%d: ", index));
            String[] splitted = br.readLine().split(" ");

            A = Integer.parseInt(splitted[0]);
            B = Integer.parseInt(splitted[1]);
            K = Integer.parseInt(splitted[2]);

            int count = 0;
            for (int i = 0; i < A; ++i) {
                for (int j = 0; j < B; ++j) {
                    if ( (i & j) < K)
                        count++;
                }
            }
            System.out.print(count);
            System.out.print("\n");
        }
    }
}
