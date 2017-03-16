import java.io.*;
import java.util.*;

public class D {

    private void solve() throws IOException {
        int tests = nextInt();
        for (int t = 1; t <= tests; t++) {
            String s1 = nextToken();
            String s2 = nextToken();

            String t1 = "";
            String t2 = "";
            long min = Long.MAX_VALUE;
            long min1 = Long.MAX_VALUE;
            long min2 = Long.MAX_VALUE;
            String res1 = "";
            String res2 = "";
            for (int i = 0; i < s1.length(); i++) {
                if (s1.charAt(i) == '?' && s2.charAt(i) == '?') {
                    {
                        String p1 = t1 + '0' + s1.substring(i + 1).replace('?', '9');
                        String p2 = t2 + '1' + s2.substring(i + 1).replace('?', '0');

                        Long P1 = Long.parseLong(p1);
                        Long P2 = Long.parseLong(p2);
                        if (Math.abs(P1 - P2) < min || (Math.abs(P1 - P2) == min &&
                                (P1 < min1 || P1.equals(min1) && P2 < min2))) {
                            min = Math.abs(P1 - P2);
                            min1 = P1;
                            min2 = P2;
                            res1 = p1;
                            res2 = p2;
                        }
                    }

                    {
                        String p1 = t1 + '1' + s1.substring(i + 1).replace('?', '0');
                        String p2 = t2 + '0' + s2.substring(i + 1).replace('?', '9');

                        Long P1 = Long.parseLong(p1);
                        Long P2 = Long.parseLong(p2);
                        if (Math.abs(P1 - P2) < min || (Math.abs(P1 - P2) == min &&
                                (P1 < min1 || P1.equals(min1) && P2 < min2))) {
                            min = Math.abs(P1 - P2);
                            min1 = P1;
                            min2 = P2;
                            res1 = p1;
                            res2 = p2;
                        }
                    }

                    t1 += '0';
                    t2 += '0';
                } else if (s1.charAt(i) == '?') {
                    if (s2.charAt(i) > '0') {
                        String p1 = t1 + sub(s2.charAt(i)) + s1.substring(i + 1).replace('?', '9');
                        String p2 = t2 + s2.substring(i).replace('?', '0');

                        Long P1 = Long.parseLong(p1);
                        Long P2 = Long.parseLong(p2);
                        if (Math.abs(P1 - P2) < min || (Math.abs(P1 - P2) == min &&
                                (P1 < min1 || P1.equals(min1) && P2 < min2))) {
                            min = Math.abs(P1 - P2);
                            min1 = P1;
                            min2 = P2;
                            res1 = p1;
                            res2 = p2;
                        }
                    }

                    if (s2.charAt(i) < '9') {
                        String p1 = t1 + add(s2.charAt(i)) + s1.substring(i + 1).replace('?', '0');
                        String p2 = t2 + s2.substring(i).replace('?', '9');

                        Long P1 = Long.parseLong(p1);
                        Long P2 = Long.parseLong(p2);
                        if (Math.abs(P1 - P2) < min || (Math.abs(P1 - P2) == min &&
                                (P1 < min1 || P1.equals(min1) && P2 < min2))) {
                            min = Math.abs(P1 - P2);
                            min1 = P1;
                            min2 = P2;
                            res1 = p1;
                            res2 = p2;
                        }
                    }

                    t1 += s2.charAt(i);
                    t2 += s2.charAt(i);
                } else if (s2.charAt(i) == '?') {
                    if (s1.charAt(i) > '0') {
                        String p1 = t1 + s1.substring(i).replace('?', '0');
                        String p2 = t2 + sub(s1.charAt(i)) + s2.substring(i + 1).replace('?', '9');

                        Long P1 = Long.parseLong(p1);
                        Long P2 = Long.parseLong(p2);
                        if (Math.abs(P1 - P2) < min || (Math.abs(P1 - P2) == min &&
                                (P1 < min1 || P1.equals(min1) && P2 < min2))) {
                            min = Math.abs(P1 - P2);
                            min1 = P1;
                            min2 = P2;
                            res1 = p1;
                            res2 = p2;
                        }
                    }

                    if (s1.charAt(i) < '9') {
                        String p1 = t1 + s1.substring(i).replace('?', '9');
                        String p2 = t2 + add(s1.charAt(i)) + s2.substring(i + 1).replace('?', '0');

                        Long P1 = Long.parseLong(p1);
                        Long P2 = Long.parseLong(p2);
                        if (Math.abs(P1 - P2) < min || (Math.abs(P1 - P2) == min &&
                                (P1 < min1 || P1.equals(min1) && P2 < min2))) {
                            min = Math.abs(P1 - P2);
                            min1 = P1;
                            min2 = P2;
                            res1 = p1;
                            res2 = p2;
                        }
                    }

                    t1 += s1.charAt(i);
                    t2 += s1.charAt(i);
                } else if (s1.charAt(i) == s2.charAt(i)) {
                    t1 += s1.charAt(i);
                    t2 += s1.charAt(i);
                } else {
                    if (s1.charAt(i) < s2.charAt(i)) {
                        String p1 = t1 + s1.substring(i).replace('?', '9');
                        String p2 = t2 + s2.substring(i).replace('?', '0');

                        Long P1 = Long.parseLong(p1);
                        Long P2 = Long.parseLong(p2);
                        if (Math.abs(P1 - P2) < min || (Math.abs(P1 - P2) == min &&
                                (P1 < min1 || P1.equals(min1) && P2 < min2))) {
                            min = Math.abs(P1 - P2);
                            min1 = P1;
                            min2 = P2;
                            res1 = p1;
                            res2 = p2;
                        }
                    } else {
                        String p1 = t1 + s1.substring(i).replace('?', '0');
                        String p2 = t2 + s2.substring(i).replace('?', '9');

                        Long P1 = Long.parseLong(p1);
                        Long P2 = Long.parseLong(p2);
                        if (Math.abs(P1 - P2) < min || (Math.abs(P1 - P2) == min &&
                                (P1 < min1 || P1.equals(min1) && P2 < min2))) {
                            min = Math.abs(P1 - P2);
                            min1 = P1;
                            min2 = P2;
                            res1 = p1;
                            res2 = p2;
                        }
                    }
                    break;
                }
            }

            if (t1.length() == s1.length()) {
                Long P1 = Long.parseLong(t1);
                Long P2 = Long.parseLong(t2);
                if (Math.abs(P1 - P2) < min || (Math.abs(P1 - P2) == min &&
                        (P1 < min1 || P1.equals(min1) && P2 < min2))) {
                    min = Math.abs(P1 - P2);
                    min1 = P1;
                    min2 = P2;
                    res1 = t1;
                    res2 = t2;
                }
            }

            println("Case #" + t + ": " + res1 + " " + res2);
        }
    }

    private char add(char c) {
        return (char) (c + 1);
    }

    private char sub(char c) {
        return (char) (c - 1);
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
        new D().run();
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