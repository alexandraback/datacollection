import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CloseMatch {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("close_match_in.txt"));
        PrintStream out = new PrintStream(new File("close_match_out_optimal.txt"));

        CloseMatch program = new CloseMatch();

        int tests = in.nextInt();
        for (int test = 1; test <= tests; test++) {
            String a = in.next();
            String b = in.next();

            Pair p = program.solve(a, b, a.length());

            String rowSolution = "Case #" + test + ": " + p.a + " " + p.b;

            System.out.println(rowSolution);
            out.println(rowSolution);
        }

        in.close();
        out.close();
    }
    
    private Pair solve(String a, String b, int n) {
        if (n == 0) {
            return new Pair(a, b);
        }
        
        char aa = a.charAt(0);
        char bb = b.charAt(0);

        if (a.charAt(0) != '?' && b.charAt(0) != '?') {
            if (a.charAt(0) == b.charAt(0)) {
                Pair subPair = solve(a.substring(1), b.substring(1), n-1);
                return new Pair(aa + subPair.a, bb + subPair.b);
            } else if (a.charAt(0) < b.charAt(0)){
                return new Pair(a.replace('?', '9'), b.replace('?', '0'));
            } else {
                return new Pair(a.replace('?', '0'), b.replace('?', '9'));
            }
        } else if (aa == '?' && bb == '?') {
            // 0, 0
            Pair zzSubPair = solve(a.substring(1), b.substring(1), n-1);
            Pair zzPair = new Pair("0" + zzSubPair.a, "0" + zzSubPair.b);

            // 0, 1
            String newA = "0" + a.substring(1);
            String newB = "1" + b.substring(1);
            Pair zoPair = solve(newA, newB, n);

            // 1, 0
            newA = "1" + a.substring(1);
            newB = "0" + b.substring(1);
            Pair ozPair = solve(newA, newB, n);

            BigInteger min = zzPair.getDiff().min(zoPair.getDiff()).min(ozPair.getDiff());
            if (min.equals(zzPair.getDiff())) {
                return zzPair;
            }
            if (min.equals(zoPair.getDiff())) {
                return zoPair;
            }
            return ozPair;

        }

        Pair firstPair, secondPair, thirdPair;
        if (aa != '?') {
            // bb == '?'

            if (aa != '0') {
                String newA = a;
                String newB = b.replaceFirst("\\?", Character.toString((char) (aa - 1)));
                firstPair = solve(newA, newB, n);
            } else {
                firstPair = Pair.NOT_INIT;
            }

            Pair subPair = solve(a.substring(1), b.substring(1), n - 1);
            secondPair = new Pair(aa + subPair.a, aa + subPair.b);

            if (aa != '9') {
                String newA = a;
                String newB = b.replaceFirst("\\?", Character.toString((char) (aa + 1)));
                thirdPair = solve(newA, newB, n);
            } else {
                thirdPair = Pair.NOT_INIT;
            }
        } else {
            // aa == '?'
            if (bb != '0') {
                String newA = a.replaceFirst("\\?", Character.toString((char) (bb - 1)));
                String newB = b;
                firstPair = solve(newA, newB, n);
            } else {
                firstPair = Pair.NOT_INIT;
            }

            Pair subPair = solve(a.substring(1), b.substring(1), n - 1);
            secondPair = new Pair(bb + subPair.a, bb + subPair.b);

            if (bb != '9') {
                String newA = a.replaceFirst("\\?", Character.toString((char) (bb + 1)));
                String newB = b;
                thirdPair = solve(newA, newB, n);
            } else {
                thirdPair = Pair.NOT_INIT;
            }
        }

        BigInteger min = firstPair.getDiff().min(secondPair.getDiff()).min(thirdPair.getDiff());
        if (min.equals(firstPair.getDiff())) {
            return firstPair;
        }
        if (min.equals(secondPair.getDiff())) {
            return secondPair;
        }
        return thirdPair;
    }

    static class Pair {
        public static final Pair NOT_INIT = new Pair(null, null) {
            @Override
            public BigInteger getDiff() {
                return new BigInteger("99999999999999999999");
            }
        };
        String a;
        String b;

        public Pair(String a, String b) {
            this.a = a;
            this.b = b;
        }

        public BigInteger getDiff() {
            BigInteger x = new BigInteger(a);
            BigInteger y = new BigInteger(b);
            return x.subtract(y).abs();
        }
    }
}