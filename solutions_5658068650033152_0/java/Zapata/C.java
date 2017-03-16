import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Max Loewenthal
 */
public class C {
    public void solve(Scanner input, StringBuilder buffer) {
        cache = new HashMap<Object, Integer>();

        int n = input.nextInt();
        int m = input.nextInt();
        int k = input.nextInt();

        buffer.append(Integer.toString(solve(n, m, k)));
    }

    private Map<Object, Integer> cache = new HashMap<Object, Integer>();

    private Integer solve(int N, int M, int K) {
        if (K == 0) {
            return 0;
        }

        if (N * M < K) {
            return null;
        }

        if (N < M) {
            int t = N;
            N = M;
            M = t;
        }
        List key = new ArrayList();

        key.add(Math.max(M, N));
        key.add(Math.min(M, N));

        if (cache.containsKey(key)) {
            return cache.get(key);
        }

        int t1 = Math.min(M, (int) Math.sqrt(K + 4));
        int t2 = Math.min(M, 1+ (int) Math.sqrt(K + 4));

        int bonus1 = 0;
        int bonus2 = 0;

        if (t1 > 2) {
            bonus1 = 4;
        }
        if (t2 > 2) {
            bonus2 = 4;
        }

        int otherSideMin = Math.min(N,(K + bonus1) / t1);
        int otherSideMax = Math.min(N, ((K  + bonus1 + t1 - 1) / t1));
        int otherSideMin2 = Math.min(N,(K+bonus2) / t2);
        int otherSideMax2 = Math.min(N, ((K + bonus2 + t1 - 1) / t2));

        tryIt(key, otherSideMin, t1, N, M, K);
        tryIt(key, otherSideMax, t1, N, M, K);
        tryIt(key, otherSideMin2, t2, N, M, K);
        tryIt(key, otherSideMax2, t2, N, M, K);

        if (!cache.containsKey(key)) {
            cache.put(key, K);
        }

        // todo: 4 away
        return cache.get(key);
    }

    void tryIt(Object key, int a, int b, int n, int m, int k) {
        int remaining = Math.max(0, a*b - 4 - k);
        Integer extraCost;
        int cost = Math.max(a,b);
        if (Math.min(a,b) >=2 ) {
            cost = cost  + cost;
        }
        if (b >=3 && a>=3 ) {
            cost = 2*(a+b)-8;
        }


        if (remaining <= 4) {
            cost = cost + remaining;
            extraCost = 0;
        }
        else {
            extraCost = solve(n - a, m, remaining);
        }

        if (extraCost != null) {
            if (!cache.containsKey(key) || cache.get(key) > cost + extraCost) {
                cache.put(key, cost + extraCost);
            }
        }
    }

    public static void main(String[] args) {
        try {
            InputStream input = System.in;
            OutputStream output = System.out;

            if (args.length > 0) {
                input = new FileInputStream(new File(args[0]));
            }

            if (args.length > 1) {
                File outputFile = new File(args[1]);

                if (outputFile.exists()) {
                    throw new Exception("Output file already exists");
                }

                output = new FileOutputStream(new File(args[1]));
            }

            Scanner scanner = new Scanner(input);
            PrintWriter writer = new PrintWriter(output);

            C a = new C();

            int count = scanner.nextInt();
            scanner.nextLine();

            for (int i = 0; i < count; i++) {
                StringBuilder result = new StringBuilder();
                a.solve(scanner, result);


                writer.println("Case #" + (i + 1) + ": " + result.toString());
            }

            writer.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

}
