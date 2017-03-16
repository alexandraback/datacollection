import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class DiamondInheritance {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();

        for (int tc = 1; tc <= T; tc++) {
            int N = input.nextInt();
            ArrayList<ArrayList<Integer>> Mi = new ArrayList<ArrayList<Integer>>();
            Mi.add(new ArrayList<Integer>());
            for (int n = 1; n <= N; n++) {
                int M = input.nextInt();
                ArrayList<Integer> m = new ArrayList<Integer>();

                for (int i = 0; i < M; i++) {
                    m.add(input.nextInt());
                }

                Mi.add(m);
            }

            boolean diamond = false;
            for (int n = N; n > 0; n--) {
                HashSet<Integer> sM = new HashSet<Integer>();

                ArrayList<Integer> S = new ArrayList<Integer>(Mi.get(n));
                while (!S.isEmpty()) {
                    Integer s = S.remove(0);
                    if (sM.contains(s)) {
                        diamond = true;
                        break;
                    }
                    sM.add(s);

                    S.addAll(Mi.get(s));
                }
                if (diamond) break;
            }

            System.out.format("Case #%d: %s\n", tc, diamond ? "Yes" : "No");
        }

    }
}
