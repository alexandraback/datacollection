
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;

public class C {

    private static final long SEED = 142464575786945324L;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        n = in.nextInt();
        a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextLong();
        }
        z = new boolean[n];
        random = new Random(SEED);
        Set<Long> set = new HashSet<Long>();
        while (true) {
            long sum = next();
            if (sum == 0) continue;
            if (set.contains(sum)) {
                Random oldRandom = random;
                boolean[] zz = z.clone();
                random = new Random();
                while (next() != sum) {
                }
                boolean ok = false;
                for (int i = 0; i < n; i++) {
                    if (zz[i] != z[i]) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    for (int i = 0; i < n; i++) {
                        if (z[i] && zz[i]) {
                            z[i] = false;
                            zz[i] = false;
                        }
                    }
                    String res = "\n";
                    for (int i = 0; i < n; i++) {
                        if (z[i]) res += a[i] + " ";
                    }
                    res += "\n";
                    for (int i = 0; i < n; i++) {
                        if (zz[i]) res += a[i] + " ";
                    }
                    return res;
                } else {
                    random = oldRandom;
                }
            } else {
                set.add(sum);
            }
        }
    }

    int n;
    boolean[] z;
    long[] a;
    Random random;
    private long next() {
        long res = 0;
        for (int i = 0; i < n; i++) {
            z[i] = random.nextBoolean();
            if (z[i]) res += a[i];
        }
        return res;
    }
}