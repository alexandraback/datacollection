import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Created by helfper on 08/05/16.
 */
public class FashionPolice {
    private final static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = sc.nextInt();

        for (int i = 1; i <= t; i++) {
            solve(i);
        }
    }

    private static void solve(int tc) {
        int j = sc.nextInt();
        int p = sc.nextInt();
        int s = sc.nextInt();
        int k = sc.nextInt();

        List<List<Integer>> outfits = new ArrayList<>();
        Map<String, AtomicInteger> jp = new HashMap<>();
        Map<String, AtomicInteger> js = new HashMap<>();
        Map<String, AtomicInteger> ps = new HashMap<>();
        for (int ji = 0; ji < j; ji++) {
            for (int pi = 0; pi < p; pi++) {
                for (int si = 0; si < s; si++) {
                    String jpi = Arrays.asList(ji, pi).toString();
                    String jsi = Arrays.asList(ji, si).toString();
                    String psi = Arrays.asList(pi, si).toString();
                    if (!jp.containsKey(jpi)) {
                        jp.put(jpi, new AtomicInteger());
                    }
                    if (!js.containsKey(jsi)) {
                        js.put(jsi, new AtomicInteger());
                    }
                    if (!ps.containsKey(psi)) {
                        ps.put(psi, new AtomicInteger());
                    }
                    if (jp.get(jpi).get() < k && js.get(jsi).get() < k && ps.get(psi).get() < k) {
                        outfits.add(Arrays.asList(ji + 1, pi + 1, si + 1));
                        jp.get(jpi).getAndIncrement();
                        js.get(jsi).getAndIncrement();
                        ps.get(psi).getAndIncrement();
                    }
                }
            }
        }
        System.out.printf("Case #%d: %d\n", tc, outfits.size());
        for (List<Integer> outfit : outfits) {
            System.out.println(outfit.toString().replaceAll("[^0-9 ]+", ""));
        }
    }
}
