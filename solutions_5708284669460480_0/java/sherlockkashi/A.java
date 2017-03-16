import java.io.PrintStream;
import java.util.Scanner;

public class A {

    Scanner             sc       = new Scanner(getClass().getResourceAsStream(IN));
    static final String FILENAME = "A-small";
    static final String IN       = FILENAME + ".in";
    static final String OUT      = FILENAME + ".out";
    PrintStream         out      = System.out;
    int[] letters = new int[26];

    private void solve() {
        double ans = 0;
        int K = sc.nextInt();
        int L = sc.nextInt();
        int S = sc.nextInt();
        String keyboard = sc.next();
        String target = sc.next();

        for (int i = 0; i < letters.length; i++){
            letters[i] = 0;
        }

        for (int i = 0; i < keyboard.length(); i++){
            int c = keyboard.charAt(i) - 'A';
            letters[c]++;
        }

        int overlap = getOverlap(target);
        if (S < target.length()) ans = 0;
        else {
            int maxFreq = 1 + (S-target.length())/(target.length() - overlap);
            double freq = 1;
            for (int i = 0; i < target.length(); i++){
                int index = target.charAt(i) - 'A';
                freq *= (1.0*letters[index])/K;
            }

            if (freq == 0){
                ans = 0;
            } else {
                ans = round((maxFreq - freq * (S-target.length()+1)), 7);
            }
        }
        out.println(ans);
    }

    public static double round(double value, int places) {
        if (places < 0) throw new IllegalArgumentException();

        long factor = (long) Math.pow(10, places);
        value = value * factor;
        long tmp = Math.round(value);
        return (double) tmp / factor;
    }

    public int getOverlap(String t) {
        for (int i = 1; i < t.length(); i++){
            if (t.startsWith(t.substring(i))) return t.length() - i;
        }

        return 0;
    }

    private void run() throws Exception {
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            out.print("Case #" + i + ": ");
            solve();
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new A().run();
    }
}