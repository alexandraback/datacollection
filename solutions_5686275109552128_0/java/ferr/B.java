import java.io.PrintWriter;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Scanner;

public class B {

    private static Scanner sc;
    private static PrintWriter pw;

    int[][] dp;

    int split(int val, int level) {
        if (val <= level) return 0;
        if (dp[val][level] != -1) return dp[val][level];
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < val; ++i) {
            ans = Math.min(ans, split(i, level) + split(val - i, level) + 1);
        }
        return dp[val][level] = ans;
    }

    int appr2(int[] a) {
        int mval = a[a.length - 1];
        int ans = Integer.MAX_VALUE;
        dp = new int[mval + 1][mval + 1];
        for (int[] aa: dp) {
            Arrays.fill(aa, -1);
        }
        for (int i = 1; i <= mval; ++i) {
            int cur = i;
            for (int aa: a) {
                cur += split(aa, i);
            }
            ans = Math.min(ans, cur);
        }
        return ans;
    }

//    int appr1(int[] a) {
//        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
//        int ans = Integer.MAX_VALUE;
//        for (int i = 0; i < a.length; ++i) {
//            pq.add(a[i]);
//        }
//        int add = 0;
//        while (true) {
//            ans = Math.min(ans, pq.peek() + add);
//            add++;
//            int from_top = pq.poll();
//            pq.add(from_top / 2);
//            pq.add(from_top / 2 + from_top % 2);
//            if (pq.peek() <= 1) break;
//        }
//        return ans;
//    }

    private String run_case() {
        int D = sc.nextInt();
        int[] a = new int[D];
        for (int i = 0; i < D; ++i) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
//        int a1 = appr1(a);
        int a2 = appr2(a);
        return  "" + a2;
    }


    private void run() {
        int n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            String res = run_case();
            pw.println("Case #" + (i + 1) + ": " + res);
        }
        pw.flush();
    }

    public static void main(String[] args) throws Exception {
        if (args.length == 2) {
            sc = new Scanner(Paths.get(args[0]));
            pw = new PrintWriter(args[1]);
        } else {
            sc = new Scanner(System.in);
            pw = new PrintWriter(System.out);
        }
        new B().run();
    }
}
