import java.util.*;

public class CB {
    public static Double links = 0.0;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Integer T = in.nextInt();
        for (Integer _i = 0; _i < T; _i++) {
            Integer B = in.nextInt();
            Integer M = in.nextInt();
            Double max_ways = recurs(B - 1);
            Boolean possible = max_ways >= M;
            if (!possible) {
                System.out.println("Case #" + String.valueOf(_i + 1) + ": IMPOSSIBLE");
                continue;
            }
            int test = B - 2;
            while (test >= 0 && recurs(test) > M) {
//                System.out.println(1 + recurs(test));
                test--;
            }
//            System.out.println(test);

            List<List<Integer>> adj = new ArrayList<>();

            for (int k = 0; k < B; k++) {
                List<Integer> tmp = new ArrayList<>(Collections.nCopies(B, 0));
                adj.add(tmp);
            }
            for (int k = 0; k < test; k++) {
                for (int j = k + 1; j < test; j++) {
                    adj.get(k).set(j, 1);
                }
                adj.get(k).set(B - 1, 1);
            }
//            System.out.println(adj);
            // Links we still need to make
//            System.out.println(test);
            links = M - recurs(test);
//            System.out.println(links);
            if (links > 0.0) {
                adj.get(test).set(B - 1, 1);
                if (test != 0) {
                    adj.get(0).set(test, 1);
                }
                links--;
            }
            int start = test - 1;

//            System.out.println(adj);
//            System.out.println(links);
            while (links > 0.0) {
//                System.out.println(links);
                if (links - Math.pow(2, start - 1) >= 0.0) {
                    adj.get(start).set(test, 1);
                    links -= Math.pow(2, start - 1);
                }
                start--;
//                System.out.println(adj);
//                System.out.println(links);
            }
//            System.out.println(links);
            System.out.println("Case #" + String.valueOf(_i + 1) + ": POSSIBLE");
            for (List<Integer> adjRow : adj) {
                String out = "";
                for (Integer k : adjRow) {
                    out += String.valueOf(k);
                }
                System.out.println(out);
            }
//            System.out.println(adj);
//            System.out.println("Case #" + String.valueOf(_i + 1) + ": " + out.trim());
        }
    }

    public static Double recurs(Integer B) {
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
