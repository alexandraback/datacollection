import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class Luck {
    public static final String NAME = "Luck";

    class IntCount {
        final int i, n;

        IntCount(int i, int n) { this.i = i; this.n = n; }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            IntCount that = (IntCount) o;
            return i == that.i && n == that.n;
        }

        @Override public int hashCode() { return 61 * i + 31 * n; }
    }

    List<Long> products = new ArrayList<>();
    int n, max;
    public Luck(int numbers, int max, int k, Scanner in) {
        for (int i = 0; i < k; ++i)
            products.add(in.nextLong());
        this.max = max;
        this.n = numbers;
    }

    private List<Integer> better() {
        Map<IntCount, Integer> prob = new HashMap<>();

        // idea: do several times in random log-weighted order: chance of coming first is related to your log
        // prob to n
        Map<Double, Integer> weighted = new HashMap<>();
        double sum = 0;
        for (int i = 2; i < max; ++i) {
            double log = i; // Math.log(i);
            sum += log;
            weighted.put(log, i);
        }
        for (int trial = 0; trial < max * max; ++trial) {
            for (long p : products) {
                Map<Integer, Integer> count = new HashMap<>();
                {
                    while (p > 1) {
                        // pick a candidate number at random
                        double r = Math.random() * sum;
                        double soFar = 0;
                        int pick = 0;
                        for (double log : weighted.keySet()) {
                            soFar += log;
                            pick = weighted.get(log);
                            if (soFar > r) break;
                        }
                        if (p % pick == 0) {
                            p /= pick;
                            int x = count.containsKey(pick) ? count.get(pick) : 0;
                            count.put(pick, x + 1);
                        }
                    }
                }

                // accumulate IntCount counts
                for (int i : count.keySet()) {
                    IntCount a = new IntCount(i, count.get(i));
                    int x = prob.containsKey(a) ? prob.get(a) : 0;
                    prob.put(a, x + 1);
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        while (prob.size() > 0 && result.size() < n) {
            int maxProb = -1;
            IntCount max = null;
            for (IntCount a : prob.keySet()) {
                if (prob.get(a) > maxProb) {
                    maxProb = prob.get(a);
                    max = a;
                }
            }
            prob.remove(max);
            for (int i = 0; i < max.n && result.size() < n; ++i)
                result.add(max.i);
        }
        while (result.size() < n)
            result.add(2);
        return result;
    }
    private List<Integer> stupid() {
        Map<IntCount, Integer> prob = new HashMap<>();

        // idea: do several times in random log-weighted order: chance of coming first is related to your log
        for (long p : products) {
            Map<Integer, Integer> count = new HashMap<>();
            {
                int i = max;
                while (p > 1) {
                    // how many i's are in p?
                    while (p % i == 0) {
                        p /= i;
                        int x = count.containsKey(i) ? count.get(i) : 0;
                        count.put(i, x + 1);
                    }
                    --i;
                }
            }
            // accumulate IntCount counts
            for (int i : count.keySet()) {
                IntCount a = new IntCount(i, count.get(i));
                int x = prob.containsKey(a) ? prob.get(a) : 0;
                prob.put(a, x + 1);
            }
        }

        List<Integer> result = new ArrayList<>();
        while (prob.size() > 0 && result.size() < n) {
            int maxProb = -1;
            IntCount max = null;
            for (IntCount a : prob.keySet()) {
                if (prob.get(a) > maxProb) {
                    maxProb = prob.get(a);
                    max = a;
                }
            }
            prob.remove(max);
            for (int i = 0; i < max.n && result.size() < n; ++i)
                result.add(max.i);
        }
        while (result.size() < n)
            result.add(2);
        return result;
    }

    public String report() {
        List<Integer> x = stupid();
        String result = "";
        for (int i : x) result += i;
        return result;
    }

    public static void main(String[] args) throws IOException {
        String name = new Scanner(System.in).next();
        Scanner in = new Scanner(Luck.class.getResourceAsStream(name));

        in.nextInt(); // discard 1
        int n = in.nextInt(), numbers = in.nextInt(), max = in.nextInt(), k = in.nextInt();

        long start = System.currentTimeMillis();
        int fileI = 1;
        File outFile;
        do {
            outFile = new File(NAME + "_" + fileI + ".out");
            ++fileI;
        } while(outFile.exists());

        FileOutputStream fout = new FileOutputStream(outFile);
        PrintWriter print = new PrintWriter(fout);
        print.println("Case #1:");
        for (int i = 1; i <= n; ++i) {
            String report = new Luck(numbers, max, k, in).report();
            print.println(report);
            System.out.println(report);
        }
        print.flush();
        fout.close();
        System.out.println("Elapsed: " + (System.currentTimeMillis() - start));
    }

}
