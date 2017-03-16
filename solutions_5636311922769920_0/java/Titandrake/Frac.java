import java.io.*;
import java.util.*;
import java.lang.*;

public class Frac {

    public static void print(Object o) {
        System.out.println(o);
    }

    // debugging
    public static void printArray(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static long convert(int[] digits, int base) {
        long t = 0;
        for (int i = 0; i < digits.length; i++) {
            t *= base;
            t += digits[i];
        }
        return t;
    }

    public static int nextInt(StringTokenizer st) {
        return Integer.parseInt(st.nextToken());
    }

    public static long nextLong(StringTokenizer st) {
        return Long.parseLong(st.nextToken());
    }

    public static void doCase(int k, int c, int s) {
        if (c * s < k) {
            print(" IMPOSSIBLE");
            return;
        }
        int offset = 0;
        while (offset < k) {
            int[] digits = new int[c];
            for (int i = 0; i < c; i++) {
                digits[i] = (offset + i) % k;
            }
            System.out.print(" " + (convert(digits, k) + 1));
            offset += c;
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        Scanner sc;
        int cases = Integer.parseInt(br.readLine());
        for (int i = 1; i <= cases; i++) {
            System.out.print(String.format("Case #%d:", i));
            st = new StringTokenizer(br.readLine());
            int k = nextInt(st);
            int c = nextInt(st);
            int s = nextInt(st);
            doCase(k, c, s);
        }
    }
}
