
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author  tasyrkin
 * @since   2014/04/12
 */
public class PartElf {

    public static void main(final String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Integer t = Integer.parseInt(br.readLine());
        int init = t;
        while (t-- > 0) {
            String[] ps = br.readLine().split("/");
            long p = Long.parseLong(ps[0]);
            long q = Long.parseLong(ps[1]);

            long gcd = gcd(p, q);
            p = p / gcd;
            q = q / gcd;

            int i = 0;
            boolean possible = false;
            for (; i < 41; i++) {
                if (p >= q && isPow2(q)) {
                    if (2 * q >= p) {
                        possible = true;
                    }

                    break;
                }

                p = 2 * p;
                gcd = gcd(p, q);
                p = p / gcd;
                q = q / gcd;

            }

            if (i == 0) {
                i = 1;
            }

            String res = possible ? i + "" : "impossible";
            System.out.println("Case #" + (init - t) + ": " + res);
        }

    }

    private static boolean isPow2(long q) {
        if (q == 1) {
            return true;
        }
        while (q > 0 && q % 2 == 0) {
            q = q / 2;
            if (q == 1) {
                return true;
            }
        }

        return false;
    }

    public static long gcd(final long p, final long q) {
        if (p < q) {
            gcd(q, p);
        }

        if (q == 0) {
            return p;
        }

        return gcd(q, p % q);

    }

}
