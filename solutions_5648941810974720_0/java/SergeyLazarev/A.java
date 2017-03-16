import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class A {

    private void solve() throws IOException {
        int tests = nextInt();
        for (int t = 1; t <= tests; t++) {
            String s = nextToken();
            int[] c = new int[256];
            for (int i = 0; i < s.length(); i++) {
                c[s.charAt(i)]++;
            }

            List<Integer> result = new ArrayList<>();
            while (c['Z'] != 0) {
                c['Z']--;
                c['E']--;
                c['R']--;
                c['O']--;
                result.add(0);
            }
            while (c['W'] != 0) {
                c['T']--;
                c['W']--;
                c['O']--;
                result.add(2);
            }
            while (c['X'] != 0) {
                c['S']--;
                c['I']--;
                c['X']--;
                result.add(6);
            }
            while (c['S'] != 0) {
                c['S']--;
                c['E']--;
                c['V']--;
                c['E']--;
                c['N']--;
                result.add(7);
            }
            while (c['V'] != 0) {
                c['F']--;
                c['I']--;
                c['V']--;
                c['E']--;
                result.add(5);
            }
            while (c['F'] != 0) {
                c['F']--;
                c['O']--;
                c['U']--;
                c['R']--;
                result.add(4);
            }
            while (c['G'] != 0) {
                c['E']--;
                c['I']--;
                c['G']--;
                c['H']--;
                c['T']--;
                result.add(8);
            }
            while (c['I'] != 0) {
                c['N']--;
                c['I']--;
                c['N']--;
                c['E']--;
                result.add(9);
            }
            while (c['T'] != 0) {
                c['T']--;
                c['H']--;
                c['R']--;
                c['E']--;
                c['E']--;
                result.add(3);
            }
            while (c['O'] != 0) {
                c['O']--;
                c['N']--;
                c['E']--;
                result.add(1);
            }

            Collections.sort(result);
            println("Case #" + t + ": " + result.stream().map(String::valueOf).collect(Collectors.joining()));
        }
    }

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    private int nextInt() throws NumberFormatException, IOException {
        return Integer.parseInt(nextToken());
    }

    private double nextDouble() throws NumberFormatException, IOException {
        return Double.parseDouble(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private void print(Object o) {
        writer.print(o);
    }

    private void println(Object o) {
        writer.println(o);
    }

    private void printf(String format, Object... o) {
        writer.printf(format, o);
    }

    public static void main(String[] args) {
        long time = System.currentTimeMillis();
        Locale.setDefault(Locale.US);
        new A().run();
        System.err.printf("%.3f\n", 1e-3 * (System.currentTimeMillis() - time));
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    private void run() {
        try {
            reader = new BufferedReader(new FileReader("input.txt"));
            writer = new PrintWriter(new File("output.txt"));
            solve();
            reader.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(13);
        }
    }
}