import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Created with IntelliJ IDEA.
 * User: gouravr
 * Date: 5/11/14
 * Time: 2:49 PM
 */
public class A {
    static final String NP = "impossible";
    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    public static void main(String[] args) throws Exception {
        int T;
        long P, Q;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine().trim());
        int index = 0;
        while (T-- > 0) {
            index++;
            System.out.print(String.format("Case #%d: ", index));
            String[] splitted = br.readLine().trim().split("/");
            P = Long.valueOf(splitted[0]);
            Q = Long.valueOf(splitted[1]);

            long TG = gcd(P, Q);
            P /= TG;
            Q /= TG;
            if ((Q & (Q - 1)) != 0) {
                System.out.print(NP + "\n");
            } else {
                long N = 2;
                int gen = 1;
                while (true) {
                    long G = gcd(N, Q);
                    long L = N / G * Q;
                    long num = P * L / Q - L / N;
                    if (num >= 0) {
                        break;
                    }
                    gen++;
                    N *= 2;
                }
                System.out.print(gen + "\n");
            }
        }

    }
}
