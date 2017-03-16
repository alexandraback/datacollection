package round1c;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by tomas on 11.05.14.
 */
public class B {

    private static final long MOD = 1000000007;
    static String[] trains;

    public static void main(String[] argv) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            int N = sc.nextInt();
            sc.nextLine();
            trains = new String[N];
            for (int j = 0; j < N; j++) {
                trains[j] = sc.next();
            }

            boolean[] used = new boolean[N];
            c = new int[26];
            long res = perm(0, used, "");
            System.out.println("Case #" + i + ": " + res);
        }
    }

    public static long perm(int d, boolean[] u, String acc) {
        if (d >= trains.length) {
            return check(acc) ? 1 : 0;
        }

        long count = 0;
        for (int i = 0; i < trains.length; i++) {
            if (!u[i]) {
                u[i] = true;
                count += perm(d+1, u, acc + trains[i]);
                count %= MOD;
                u[i] = false;
            }
        }
        return count;
    }

    static int[] c;
    public static boolean check(String acc) {
        Arrays.fill(c, 0);
        char prev = 0;
        for (int i = 0; i < acc.length(); i++) {
            char curr = acc.charAt(i);
            if (curr != prev) {
                if (c[curr-'a'] > 0) {
                    return false;
                }
            }
            c[curr-'a']++;
            prev = curr;
        }
        return true;
    }
}
