import java.io.*;
import java.util.*;
import java.lang.*;

public class Sheep {

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

    public static long doCase(long l) {
        HashSet<Character> seen = new HashSet<>();
        long a = l;
        String s = Long.toString(a);
        for (char c : s.toCharArray()) {
            seen.add(c);
        }
        while (seen.size() < 10) {
            if (a < 0) {
                System.err.println("NO");
            }
            a += l;
            s = Long.toString(a);
            for (char c : s.toCharArray()) {
                seen.add(c);
            }
        }
        return a;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        Scanner sc;
        int cases = Integer.parseInt(br.readLine());
        for (int i = 1; i <= cases; i++) {
            long ca = Long.parseLong(br.readLine());
            if (ca == 0) {
                print(String.format("Case #%d: INSOMNIA", i));
                continue;
            }
            print(String.format("Case #%d: %d", i, doCase(ca)));
        }
    }
}
