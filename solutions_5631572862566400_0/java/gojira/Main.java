import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for(int t = 1; t <= T; t++) {
            int n = in.nextInt();
            int[] bff = new int[n];
            for(int i = 0; i < n; i++) {
                bff[i] = in.nextInt() - 1;
            }
            System.out.println("Case #" + t + ": " + solve(bff));
        }
    }

    static int solve(int[] bff) {
        int n = bff.length;
        boolean[] used = new boolean[n];
        List<Integer> list = new ArrayList<Integer>();
        return rec(bff, list, used);
    }

    static int rec(int[] bff, List<Integer> list, boolean[] used) {
        int ret = check(list, bff) ? list.size() : 0;
        for(int i = 0; i < bff.length; i++) {
            if (used[i]) continue;
            used[i] = true;
            list.add(i);
            ret = Math.max(ret, rec(bff, list, used));
            list.remove(list.size() - 1);
            used[i] = false;
        }
        return ret;
    }

    static boolean check(List<Integer> list, int[] bff) {
        for(int i = 0; i < list.size(); i++) {
            int prev = i - 1;
            if (prev < 0) prev = list.size() - 1;
            int next = i + 1;
            if (next == list.size()) next = 0;
            int cur = list.get(i);
            if (bff[cur] != list.get(prev) && bff[cur] != list.get(next)) return false;
        }
        return true;
    }
}