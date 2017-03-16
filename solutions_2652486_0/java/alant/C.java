import java.util.*;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        Random random = new Random();
        for (int i = 1 ; i <= T; ++i) {
            int r, n, m, k;
            r = sc.nextInt();
            n = sc.nextInt();
            m = sc.nextInt();
            k = sc.nextInt();

            System.out.println("Case #" + i + ":");
            for (; r > 0; --r) {
                int[] ar = new int[k];
                for (int j = 0; j < k; ++j) {
                    ar[j] = sc.nextInt();
                }

                while (true) {
                    int[] nr = new int[n];
                    for (int j = 0; j < n; ++j) {
                        nr[j] = random.nextInt(m - 1) + 2;
                    }
                    Set<Integer> set = new HashSet<Integer>();
                    addAll(nr, 0, set);
                    /*
                    for (int x : nr) {
                        System.err.print(x + " ");
                    }
                    System.err.println();
                    for (int x : set) {
                        System.err.print(x + " ");
                    }
                    System.err.println();
                    while (nr.length < 10);
                    */
                    boolean ok = true;
                    for (int x : ar) {
                        if (!set.contains(x)) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
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

    public static void addAll(int[] ar, int begin, Set<Integer> set) {
        if (begin == ar.length - 1) {
            set.add(1);
            set.add(ar[begin]);
            return;
        }
        addAll(ar, begin + 1, set);
        Set<Integer> temp = new HashSet<Integer>();
        for (int x : set) {
            temp.add(x * ar[begin]);
        }
        set.addAll(temp);
    }

}
