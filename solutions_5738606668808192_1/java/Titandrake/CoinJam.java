import java.io.*;
import java.util.*;
import java.lang.*;

public class CoinJam {

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

    public static void doCase(int n, int j) {
        int outp = 0;
        int places = n / 2;
        int m = 1 << (places - 1);
        m++;
        while (outp < j) {
            char[] bits = new char[n];
            for (int i = 0; i < places; i++) {
                if (((m >> i) & 1) == 1) {
                    bits[n - 1 - 2*i] = '1';
                    bits[n - 1 - (2*i+1)] = '1';
                } else {
                    bits[n - 1 - 2*i] = '0';
                    bits[n - 1 - (2*i+1)] = '0';
                }
            }
            for (char c : bits) {
                System.out.print(c);
            }
            for (int i = 2; i <= 10; i++) {
                System.out.print(" " + (i + 1));
            }
            System.out.println();
            outp++;
            m += 2;
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        Scanner sc;
        int cases = Integer.parseInt(br.readLine());
        for (int i = 1; i <= cases; i++) {
            st = new StringTokenizer(br.readLine());
            print("Case #1:");
            doCase(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
    }
}
