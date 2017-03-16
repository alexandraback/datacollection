import java.io.*;
import java.util.*;
import java.lang.*;

public class Pancake {

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

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int cases = Integer.parseInt(br.readLine());
        for (int i = 1; i <= cases; i++) {
            int d = Integer.parseInt(br.readLine());
            int[] plates = new int[d];
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < d; j++) {
                plates[j] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(plates);
            int best = Integer.MAX_VALUE;
            for (int currm = plates[d-1]; currm >= 1; currm--) {
                int c = 0;
                for (int p : plates) {
                    if (p % currm == 0) {
                        c += p / currm - 1;
                    } else {
                        c += p / currm;
                    }
                }
                best = Math.min(best, currm + c);
            }
            print(String.format("Case #%d: %d", i, best));
        }
    }
}
