import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.floor;
import static java.lang.Math.pow;

public class Main {
    static int n = 0;
    static int m = 0;
    public static void main(String[] args) throws FileNotFoundException {
//        Scanner s = new Scanner("/home/cone/Downloads/C-small.in");
        Scanner s = new Scanner(new File("/home/cone/Downloads/C-small-1-attempt0.in"));
        s.nextLine();
        System.out.println("Case #1:");
        int r = s.nextInt();
        n = s.nextInt();
        m = s.nextInt();
        int k = s.nextInt();
        int[] counts = new int[(int)floor(pow(m, n) + 1.0)];
        for (int i = 0; i < r; i++) {
            int[] ns = new int[k];
            for (int j = 0; j < k; j++) {
                ns[j] = s.nextInt();
            }
//            System.out.println(Arrays.toString(ns));
            Thing t = new Thing(2, m);
            int[] best = new int[n];
            int bestVal = 0;
            int[] buf = new int[n];
            int[] buf2 = new int[n];
            while (t.next()) {
                Arrays.fill(counts, 0);
                t.get(buf);
//                System.out.println("Trying: " + Arrays.toString(buf));
                Thing bt = new Thing(0, 1);
                int product;
                while (bt.next()) {
                    product = 1;
                    bt.get(buf2);
//                    System.out.print("Trying: ");
                    for (int j = 0; j < n; j++) {
                        if (buf2[j] == 1) {
                            product *= buf[j];
//                            System.out.print(buf[j]);
                        }
                    }
//                    System.out.println();
                    counts[product]++;
                }
                int count = 1;
                for (int v : ns) {
                    count *= counts[v];
                }
                if (count > bestVal) {
//                    System.out.println("NEW BEST! : "+Arrays.toString(buf) +", count = "+count);
                    System.arraycopy(buf, 0, best, 0, n);
                    bestVal = count;
                }
            }
            for (int n : best) {
                System.out.print(Integer.toString(n));
            }
            System.out.println();
        }
    }

    static class Thing {
        boolean started = false;
        final int[] current;
        final int min;
        final int max;
        Thing(int min, int max) {
            this.min = min;
            this.max = max;
            current = new int[n];
            Arrays.fill(current, min);
        }
        void get(int[] buf) {
            for (int i = 0; i < current.length; i++) {
                buf[i] = current[i];
            }
        }
        boolean next() {
            if (!started) {
                started = true;
                return true;
            }
            current[0]++;
            for (int i = 0; i < current.length; i++) {
                if (current[i] != max + 1) break;
                current[i] = min;
                if (i == current.length - 1) return false;
                current[i+1]++;
            }
            return true;
        }
    }
}
