import java.io.*;
import java.util.Locale;
import java.util.Scanner;

public class Main {
    private static StreamTokenizer in;
    private static Scanner ins;
    private static PrintWriter out;

    public static void main(String[] args) {

        try {
            in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
            ins = new Scanner(System.in);
            out = new PrintWriter(System.out);
            try {
                if (System.getProperty("xDx") != null) {
                    in = new StreamTokenizer(new BufferedReader(new FileReader("input.txt")));
                    ins = new Scanner(new FileReader("input.txt"));
                    out = new PrintWriter(new FileWriter("output.txt"));
                }
            } catch (Exception e) {
                in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
                ins = new Scanner(System.in);
                out = new PrintWriter(System.out);
            }
            new Main().run(args);
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }

    int k, l, s;
    String keyboard;
    String target;
    double max = 0;
    int sum = 0;

    private void run(String[] args) throws Exception {
        int T = nextInt();
        for (int t = 0; t < T; t++) {
            k = nextInt();
            l = nextInt();
            s = nextInt();
            keyboard = nextString();
            target = nextString();
            max = 0;
            sum = 0;
            rec(0, new StringBuilder(s));

            double answ = (max - ((double) sum) / Math.pow(k, s));
            answ = Math.max(answ, 0);
            out.printf(Locale.ENGLISH, "Case #%d: %.7f\n", t + 1, answ);
//            out.println(answ);
        }
    }

    private void rec(int pos, StringBuilder sb) {
        if (pos == s) {
            int ban = numBanana(sb.toString());
            max = Math.max(max, ban);
            sum += ban;
            return;
        }

        if (sb.length() == pos) {
            sb.append(' ');
        }
        for (int i = 0; i < keyboard.length(); i++) {
            sb.setCharAt(pos, keyboard.charAt(i));
            rec(pos + 1, sb);
        }
    }

    private int numBanana(String s) {
        String sb = new StringBuilder(target).append('#').append(s).toString();
        int[] pi = prefixFunction(sb);
        int res = 0;
        for (int i = 0; i < pi.length; i++) {
            if (pi[i] == target.length()) {
                ++res;
            }
        }
        return res;
    }

    private int[] prefixFunction(String s) {
        int n = s.length();
        int[] pi = new int[n];
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s.charAt(i) != s.charAt(j)) {
                j = pi[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                ++j;
            }
            pi[i] = j;
        }
        return pi;
    }

    private int nextInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }

    private long nextLong() throws IOException {
        in.nextToken();
        return (long) in.nval;
    }

    private double nextDouble() throws IOException {
        in.nextToken();
        return in.nval;
    }

    private String nextString() throws IOException {
        in.nextToken();
        return in.sval;
    }

}
