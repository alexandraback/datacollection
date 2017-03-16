
import java.util.*;

public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        for (int t = 1; t <= T; ++t) {
            int n = in.nextInt();
            in.nextLine();
            String[] s = new String[n];
            for (int i = 0; i < n; ++i) {
                s[i] = in.nextLine();
            }

            int res = 0;

            for (int mask = 0; mask < (1 << n); ++mask) {
                Set<String> c1 = new HashSet<>();
                Set<String> c2 = new HashSet<>();
                Set<String> wh = new HashSet<>();
                for (int i = 0; i < n; ++i) {
                    if ((mask & (1 << i)) == 0) continue;

                    String[] sc = s[i].trim().split("\\s+");
                    c1.add(sc[0].trim());
                    c2.add(sc[1].trim());
                    wh.add(s[i]);
                }

                boolean ok = true;
                boolean[] taken = new boolean[n];
                for (int j = 0; j < n - Integer.bitCount(mask) && ok; ++j) {
                    boolean found = false;
                    for (int i = 0; i < n && !found; ++i) {
                        if ((mask & (1 << i)) != 0 || taken[i]) continue;
                        String[] sc = s[i].trim().split("\\s+");
                        if (c1.contains(sc[0]) && c2.contains(sc[1]) && !wh.contains(s[i])) {
                            c1.add(sc[0].trim());
                            c2.add(sc[1].trim());
                            wh.add(s[i]);
                            found = true;
                            taken[i] = true;
                        }
                    }

                    if (!found) ok = false;
                }

                if (ok) {
                    res = Math.max(res, n - Integer.bitCount(mask));
                }
            }

            System.out.println("Case #" + t + ": " + res);
        }
    }
}
