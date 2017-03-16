package gcj2013.round1a;

import java.util.Scanner;

public class A {

    private static int getAns(long r, long t) {
        int min = 1, mid, max = 1000000000;
        while (min <= max) {
            mid = (min + max) / 2;
            long v = 2 * mid - 1 + 2 * r;
            if (t / mid > v) {
                min = mid + 1;
            } else if (t / mid + 1 < v) {
                max = mid - 1;
            } else {
                v *= mid;
                if (v == t) {
                    return mid;
                } else if (v > t) {
                    max = mid - 1;
                } else {
                    min = mid + 1;
                }
            }
        }
        return max;
    }
    
    public static void solve(Scanner scan) {
        long r = scan.nextLong();
        long t = scan.nextLong();
        System.out.println(getAns(r, t));
    }
    
    public static final void main(final String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 1; i <= t; i++ ) {
            System.out.print("Case #" + i + ": ");
            solve(scan);
        }

    }

}
