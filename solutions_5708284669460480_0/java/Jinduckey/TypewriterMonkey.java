package codejam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class TypewriterMonkey {

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {

        Scanner in = new Scanner(new FileReader("B-small-attempt3.in"));
        PrintWriter out = new PrintWriter("output.txt", "UTF-8");

        int T = in.nextInt();

        for (int t = 1; t <= T; t++) {
            int K = in.nextInt();
            int L = in.nextInt();
            int S = in.nextInt();
            String keyboard = in.next();
            String target = in.next();
            double ans = answer(K, L, S, keyboard, target);
            out.println("Case #" + t + ": " + ans);
            System.out.println(keyboard + " " + target + " " + S);
            System.out.println(ans);
        }
        in.close();
        out.close();
    }

    public static HashMap<Tuple, Double> memoize = new HashMap<Tuple, Double>();
    public static double answer(int K, int L, int S, String keyboard, String target) {
        Map<String, Double> freq = new HashMap<String, Double>();
        for (int i = 0; i < keyboard.length(); i++) {
            String c = keyboard.substring(i,  i+1);
            if (!freq.containsKey(c))
                freq.put(c, 0.0);
            freq.put(c, freq.get(c) + 1);
        }
        // Check if target is attainable
        for (int i = 0; i < target.length(); i++)
            if (!freq.containsKey(target.substring(i, i+1))) {
                return 0;                                                          //CHANGEEEEEE
            }
        // Target is attainable. Check max amount
        int firstRepeat = L;
        for (int i = 1; i < L; i++) {
            boolean allEqual = true;
            for (int j = i; j < L; j++) {
                if (!target.substring(j-i, j-i+1).equals(target.substring(j, j+1)))
                    allEqual = false;
            }
            if (allEqual) {
                firstRepeat = i;
                break;
            }
        }
        double max = 1 + (S - L) / firstRepeat;
        memoize = new HashMap<Tuple, Double>();
        double exp = expected(S, K, firstRepeat, target, 0, freq);
        if (exp < 0.00000001)
            exp = 0.0;
        return max - exp;
    }

    public static double expected(int S, int K, int firstRepeat, String target, int first, Map<String, Double> freq) {
        Tuple t = new Tuple(S, first);
        if (memoize.containsKey(t))
            return memoize.get(t);
        if (first == target.length())
            return expected(S, K, firstRepeat, target, target.length() - firstRepeat, freq) + 1.0;
        if (S == 0)
            return 0;

        String firstTarget = target.substring(0, 1);
        String firstFirst = target.substring(first, first+1);
        double ans = 0;
        if (!firstTarget.equals(firstFirst)) {
            ans += freq.get(firstTarget) / K *                              expected(S-1, K, firstRepeat, target, 1, freq);
            ans += freq.get(firstFirst) / K *                               expected(S-1, K, firstRepeat, target, first+1, freq);
            ans += (K - freq.get(firstTarget) - freq.get(firstFirst)) / K * expected(S-1, K, firstRepeat, target, 0, freq);
        }
        else {
            ans += freq.get(firstFirst) / K *       expected(S-1, K, firstRepeat, target, first+1, freq);
            ans += (K - freq.get(firstFirst)) / K * expected(S-1, K, firstRepeat, target, 0, freq);
        }
        memoize.put(t, ans);
        //        System.out.println(S + " " + first + " " + ans);

        return ans;
    }
    public static class Tuple {
        public int x;
        public int y;
        public Tuple(int x, int y) {
            this.x = x;
            this.y = y;
        }
        @Override
        public boolean equals(Object other) {
            if (!(other instanceof Tuple)) return false;
            Tuple otherTuple = (Tuple)other;
            return otherTuple.x == this.x && otherTuple.y == this.y;
        }
        @Override
        public int hashCode() {
            return 31*x+7*y;
        }

    }  
}
