import java.io.*;
import java.util.*;
import java.lang.*;

public class Digits {

    static class FastScan {
        BufferedReader br;
        StringTokenizer st;

        FastScan(InputStream source) throws IOException {
            br = new BufferedReader(new InputStreamReader(source));
            st = new StringTokenizer(br.readLine());
        }

        String next() throws IOException {
            if (!st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

    }

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

    public static String doCase(FastScan sc) throws IOException {
        char[] phone = sc.next().toCharArray();
        int[] counts = new int[10];
        int[] let = new int[256];
        for (char c : phone) {
            let[c]++;
        }
        // 0
        counts[0] = let['Z'];
        let['E'] -= let['Z'];
        let['R'] -= let['Z'];
        let['O'] -= let['Z'];
        let['Z'] = 0;
        // 2
        counts[2] = let['W'];
        let['T'] -= let['W'];
        let['O'] -= let['W'];
        let['W'] = 0;
        // 4
        counts[4] = let['U'];
        let['F'] -= let['U'];
        let['O'] -= let['U'];
        let['R'] -= let['U'];
        let['U'] = 0;
        // 6
        counts[6] = let['X'];
        let['S'] -= let['X'];
        let['I'] -= let['X'];
        let['X'] = 0;
        // now 7
        counts[7] = let['S'];
        let['E'] -= 2*let['S'];
        let['V'] -= let['S'];
        let['N'] -= let['S'];
        let['S'] = 0;
        // 8
        counts[8] = let['G'];
        let['E'] -= let['G'];
        let['I'] -= let['G'];
        let['H'] -= let['G'];
        let['T'] -= let['G'];
        let['G'] = 0;
        // 5
        counts[5] = let['V'];
        let['F'] -= let['V'];
        let['I'] -= let['V'];
        let['E'] -= let['V'];
        let['V'] = 0;
        // 9
        counts[9] = let['I'];
        let['N'] -= 2*let['I'];
        let['E'] -= let['I'];
        let['I'] = 0;
        // 3
        counts[3] = let['T'];
        let['H'] -= let['T'];
        let['R'] -= let['T'];
        let['E'] -= 2*let['T'];
        let['T'] = 0;
        // 1
        counts[1] = let['N'];

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < counts[i]; j++) {
                sb.append(i);
            }
        }
        return sb.toString();
    }

    public static void main(String args[]) throws IOException {
        FastScan sc = new FastScan(System.in);
        int cases = sc.nextInt();
        for (int i = 1; i <= cases; i++) {
            print(String.format("Case #%d: %s", i, doCase(sc)));
        }
    }
}
