import java.util.*;

public class CB {
    public static Double links = 0.0;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Integer T = in.nextInt();
        for (Integer _i = 0; _i < T; _i++) {
            Long B = in.nextLong();
            Long M = in.nextLong();
            Double max_ways = recurs(B - 1);
            Boolean possible = max_ways >= M;
            if (!possible) {
                System.out.println("Case #" + String.valueOf(_i + 1) + ": IMPOSSIBLE");
                continue;
            }
            Long test = B - 2;
            while (test >= 0 && recurs(test) > M) {
//                System.out.println(1 + recurs(test));
                test--;
            }
//            System.out.println(test);

            Map<Long, Map<Long, Integer>> adj = new HashMap<>();

            for (long k = 0; k < B; k++) {
                Map<Long, Integer> tmp = new HashMap<>();
                for (long kk = 0; kk < B; kk++) {
                    tmp.put(kk, 0);
                }
                adj.put(k, tmp);
            }
            for (long k = 0; k < test; k++) {
                for (long j = k + 1; j < test; j++) {
                    adj.get(k).put(j, 1);
                }
                adj.get(k).put(B - 1, 1);
            }
//            System.out.println(adj);
            // Links we still need to make
//            System.out.println(test);
            links = M - recurs(test);
//            System.out.println(links);
            if (links > 0.0) {
                adj.get(test).put(B - 1, 1);
                if (test != 0) {
                    adj.get(Long.valueOf("0")).put(test, 1);
                }
                links--;
            }
            long start = test - 1;

//            System.out.println(adj);
//            System.out.println(links);
            while (links > 0.0) {
//                System.out.println(links);
                if (links - Math.pow(2, start - 1) >= 0.0) {
                    adj.get(start).put(test, 1);
                    links -= Math.pow(2, start - 1);
                }
                start--;
//                System.out.println(adj);
//                System.out.println(links);
            }
//            System.out.println(links);
            System.out.println("Case #" + String.valueOf(_i + 1) + ": POSSIBLE");
            for (Long adjRowKey = Long.valueOf("0"); adjRowKey <B; adjRowKey++) {
                String out = "";
                for (Long adjColKey = Long.valueOf("0"); adjColKey < B; adjColKey++) {
                    out += String.valueOf(adj.get(adjRowKey).get(adjColKey));
                }
                System.out.println(out);
            }
//            System.out.println(adj);
//            System.out.println("Case #" + String.valueOf(_i + 1) + ": " + out.trim());
        }
    }

    public static Double recurs(Long B) {
        if (B <= 0) {
            return 0.0;
        }
        return Math.pow(2, B - 1);
//        if (B == 0) {
//            return 1;
//        }
//        int sum = 0;
//        for (int i = 0; i < B; i++) {
//            sum += recurs(i);
//        }
//        return sum;
    }
}
