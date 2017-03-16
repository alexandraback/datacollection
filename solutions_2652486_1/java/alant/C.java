import java.util.*;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        Random random = new Random();
        int ch = 0;
        for (int i = 1 ; i <= T; ++i) {
            int r, n, m, k;
            r = sc.nextInt();
            n = sc.nextInt();
            m = sc.nextInt();
            k = sc.nextInt();

            System.out.println("Case #" + i + ":");
            long ct = System.currentTimeMillis();
            boolean calc = true;
            for (; r > 0; --r) {
                boolean rem3 = false, rem5 = false, rem7 = false;
                long[] ar = new long[k];
                Set<Long> sl = new HashSet<Long>();
                for (int j = 0; j < k; ++j) {
                    ar[j] = sc.nextLong();
                    sl.add(ar[j]);
                    rem3 |= ar[j] % 3 == 0;
                    rem5 |= ar[j] % 5 == 0;
                    rem7 |= ar[j] % 7 == 0;
                }

                int[] nr = new int[n];
                int begin = 0;
                if (rem3) nr[begin++] = 3;
                if (rem5) nr[begin++] = 5;
                if (rem7) nr[begin++] = 7;
                while (true) {
                    /*
                    if (System.currentTimeMillis() - ct > 10 * (8000 - r - 1)) {
                        printRandomAnswer(random, n, m);
                        ++ch;
                        break;
                    }
                    */
                    for (int j = begin; j < n; ++j) {
                        nr[j] = random.nextInt(m - 1) + 2;
                    }
                    if (possible(ar, nr)) {
                        for (int x : nr) {
                            System.out.print(x);
                        }
                        System.out.println();
                        break;
                    }
                }
            }
        }
    }

    public static boolean possible(long[] pr, int[] ar) {
        boolean changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < pr.length; ++i) {
                for (int j = 0; j < ar.length; ++j) {
                    while (pr[i] % ar[j] == 0) {
                        pr[i] /= ar[j];
                        changed = true;
                    }
                }
            }
        }
        for (long x : pr) {
            if (x != 1) {
                return false;
            }
        }
        return true;
    }
    
    public static void printRandomAnswer(Random random, int n, int m) {
        for (int i = 0; i < n; ++i) {
            System.out.print(random.nextInt(m - 1) + 2);
        }
        System.out.println();
    }
    
    public static long genP(int[] ar, int n, Random r) {
        long p = 1;
        for (int i = 0; i < n; ++i) {
            int ind = r.nextInt(ar.length);
            p *= ar[ind];
        }
        return p;
    }
    
    public static void addAll(int[] ar, int begin, Set<Long> set) {
        if (begin == ar.length - 1) {
            set.add(1L);
            set.add((long) ar[begin]);
            return;
        }
        addAll(ar, begin + 1, set);
        Set<Long> temp = new HashSet<Long>();
        for (long x : set) {
            temp.add(x * ar[begin]);
        }
        set.addAll(temp);
    }

}
