import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class R1CA {

    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {

            String s1 = in.next();
            String[] s2 = s1.split("/");
            int P = Integer.parseInt(s2[0]);
            int Q = Integer.parseInt(s2[1]);

            int p = P;
            int q = Q;
            int n = 0;
            while(p < q) {
                if(q % 2 != 0)
                    break;
                n++;
                q = q >> 1;
            }

            while(q % 2 == 0) {
                q = q >> 1;
            }
            if(p % q != 0) {
                System.out.format("Case #%d: %s\n", t, "impossible");
            } else {
                System.out.format("Case #%d: %d\n", t, n);
            }
        }
    }

}
