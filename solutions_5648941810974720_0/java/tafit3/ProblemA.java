import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.InterruptedIOException;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

public class ProblemA {
    BufferedReader rd;
    int[][] digits;

    ProblemA() throws IOException {
        rd = new BufferedReader(new InputStreamReader(System.in));
        compute();
    }

    private void compute() throws IOException {
        digits = new int[10][26];
        String[] dg = new String[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
        for(int i=0;i<10;i++) {
            for(char x: dg[i].toCharArray()) {
                digits[i][x-'A']++;
            }
        }

        int n = pint();
        for(int i=0;i<n;i++) {
            out("Case #" + (i + 1) + ": " + solve());
        }
    }

    private String solve() throws IOException {
        char[] c = rd.readLine().toCharArray();
        int[] y = new int[26];
        for(char x: c) {
            y[x-'A']++;
        }
        int[] res = new int[10];

        Map<Character, Integer> w = new LinkedHashMap<>();
        w.put('Z', 0);
        w.put('W', 2);
        w.put('U', 4);
        w.put('X', 6);
        w.put('G', 8);
        w.put('F', 5);
        w.put('S', 7);
        w.put('I', 9);
        w.put('T', 3);
        w.put('O', 1);

        for(Map.Entry<Character, Integer> e: w.entrySet()) {
            int count = y[e.getKey() - 'A'];
            if (count > 0) {
                res[e.getValue()] += count;
                for (int i = 0; i < 26; i++) {
                    y[i] -= count*digits[e.getValue()][i];
                }
            }
        }
        StringBuilder buf = new StringBuilder();
        for(int i=0;i<res.length;i++) {
            for(int j=0;j<res[i];j++) {
                buf.append((char) (i + '0'));
            }
        }
        return buf.toString();
    }

    private int pint() throws IOException {
        return pint(rd.readLine());
    }

    private int pint(String s) {
        return Integer.parseInt(s);
    }

    private static void out(Object x) {
        System.out.println(x);
    }

    public static void main(String[] args) throws IOException {
        new ProblemA();
    }
}
