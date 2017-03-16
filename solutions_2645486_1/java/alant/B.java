import java.util.Arrays;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1 ; i <= T; ++i) {
            int e = sc.nextInt();
            int r = sc.nextInt();
            int n = sc.nextInt();
            int[] ar = new int[n];
            for (int j = 0; j < n; ++j) {
                ar[j] = sc.nextInt();
            }
            long x = foo(ar, 0, n, e, r, 0, e);
            System.out.println("Case #" + i + ": " + x);
        }
    }
    
    static long foo(int[] ar, int begin, int end, int power, int regain, int last, int maxP) {
        if (end - begin == 0) {
            return 0;
        }
        if (end - begin == 1) {
            int p = power - last + regain;
            if (p > maxP) p = maxP;
            if (p > power) p = power;
            return ((long)ar[begin]) * p;
        }
        int max = begin;
        for (int i = begin; i < end; ++i) {
            if (ar[i] > ar[max]) {
                max = i;
            }
        }
        return foo(ar, begin, max, power, regain, power, maxP) + ((long)ar[max]) * power +
               foo(ar, max + 1, end, regain, regain, last, maxP);
    }
    
}
