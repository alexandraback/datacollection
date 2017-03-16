import java.io.*;
import java.util.*;
import java.lang.*;

public class Rank {

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

    public static int nextInt(StringTokenizer st) {
        return Integer.parseInt(st.nextToken());
    }

    public static long nextLong(StringTokenizer st) {
        return Long.parseLong(st.nextToken());
    }

    public static int[] nextInts(BufferedReader br, int n) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        return arr;
    }

    public static long[] nextLongs(BufferedReader br, int n) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
        return arr;
    }

    public static void doCase(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] counts = new int[3000];
        for (int i = 0; i < 2*n - 1; i++) {
            int[] line = nextInts(br, n);
            for (int sol : line) {
                counts[sol]++;
            }
        }
        int[] out = new int[n];
        int j = 0;
        for (int i = 0; i < 3000; i++) {
            if (counts[i] % 2 == 1) {
                out[j++] = i;
            }
        }
        for (int q : out) {
            System.out.print(" " + q);
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
            doCase(br);
        }
    }
}
