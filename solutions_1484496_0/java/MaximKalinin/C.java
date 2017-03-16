import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            System.out.print("Case #");
            System.out.print(t);
            System.out.println(":");
            int N = in.nextInt();
            int[] s = new int[N];
            for (int i = 0; i < N; ++i) {
                s[i] = in.nextInt();
            }
            Map<Integer, Integer> map = new HashMap<Integer, Integer>();
            boolean found = false;
            for (int mask = 1; mask < (1 << N); ++mask) {
                int sum = 0;
                for (int i = 0; i < N; ++i) {
                    if ((mask & (1 << i)) != 0) {
                        sum += s[i];
                    }
                }
                if (map.containsKey(sum)) {
                    found = true;
                    int mask1 = map.get(sum);
                    for (int i = 0; i < N; ++i) {
                        if ((mask & (1 << i)) != 0) {
                            System.out.print(s[i]);
                            System.out.print(" ");
                        }
                    }
                    System.out.println();
                    for (int i = 0; i < N; ++i) {
                        if ((mask1 & (1 << i)) != 0) {
                            System.out.print(s[i]);
                            System.out.print(" ");
                        }
                    }
                    System.out.println();
                    break;
                }
                map.put(sum, mask);
            }
            if (!found) {
                System.out.println("Impossible");
            }
        }
    }
}
