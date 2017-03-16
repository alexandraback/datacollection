import java.util.HashMap;
import java.util.Scanner;

public class C {
    private void solve(int[] a) {

        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
        for (int len = 0; len <= a.length; len++) {
            for (int i = 0; i < 1 << a.length; i++) {
                if (Integer.bitCount(i) != len) {
                    int sum = 0;
                    for (int p = 0; p < a.length; p++) {
                        if ((i & (1 << p)) > 0) {
                            sum += a[p];
                        }
                    }
                    if (hm.containsKey(sum)) {
                        int j = hm.get(sum);
                        if ((i & j)!= 0) {
                            throw new AssertionError();
                        }
                        for (int p = 0; p < a.length; p++) {
                            if ((i & (1 << p)) > 0) {
                                System.out.print(a[p] + " ");
                            }
                        }
                        System.out.println();
                        for (int p = 0; p < a.length; p++) {
                            if ((j & (1 << p)) > 0) {
                                System.out.print(a[p] + " ");
                            }
                        }
                        System.out.println();
                        return;
                    }
                    hm.put(sum, i);
                }
            }
        }
        System.out.println("Impossible");
    }


    public void run() {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = in.nextInt();
            }
            System.out.println("Case #" + (i + 1) + ":");
            solve(a);
        }
    }


    public static void main(String[] args) {
        new C().run();
    }
}
