import java.io.*;
import java.util.*;
import java.lang.*;

public class Last {

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

    public static void doCase(int cas, BufferedReader br) throws IOException {
        System.out.print(String.format("Case #%d: ", cas));
        String s = br.readLine();
        char[] cs = s.toCharArray();
        ArrayList<Character> out = new ArrayList<Character>();
        out.add(cs[0]);
        for (int i = 1; i < cs.length; i++) {
            if (cs[i] >= out.get(0)) {
                out.add(0, cs[i]);
            } else {
                out.add(cs[i]);
            }
        }
        for (char c : out) {
            System.out.print(c);
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        Scanner sc;
        int cases = Integer.parseInt(br.readLine());
        for (int i = 1; i <= cases; i++) {
            doCase(i, br);
        }
    }
}
