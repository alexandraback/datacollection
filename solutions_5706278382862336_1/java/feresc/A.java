package round1c;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;

public class A {

    private static String input = "A-large";
    private static boolean testing = false;    
    private static String FAIL_MSG = "impossible";
    
    public static int[] parseInts(String line) {
        String[] nums = line.split(" ");
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            res[i] = Integer.parseInt(nums[i]);
        }
        return res;
    }

    public static void main(String[] args) throws Exception {
        PrintWriter out = null;
        if (!testing) {
            System.setIn(new FileInputStream(input + ".in"));
            out = new PrintWriter(new FileWriter(input + ".out"));
        }
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int cases = Integer.parseInt(in.readLine());
        for (int i = 0; i < cases; i++) {
            ACase ac = read(in);
            if (testing)
                System.out.printf("Case #%d: %s\n", i+1, solve(ac));
            else
                out.printf("Case #%d: %s\n", i+1, solve(ac));
        }
        if (out != null)  out.close();
    }
    
    static class ACase {
        ACase(BigInteger p, BigInteger q) {
            BigInteger div = p.gcd(q);
            P = p.divide(div);
            Q = q.divide(div);
            
        }
        BigInteger P;
        BigInteger Q;
    }
    
    private static ACase read(BufferedReader in) throws IOException {
        String[] ss = in.readLine().split("/");
        BigInteger P = new BigInteger(ss[0]);
        BigInteger Q = new BigInteger(ss[1]);
        ACase c = new ACase(P, Q);        
        return c;
    }
    
    private static String solve(ACase c) {
        int gen = c.Q.getLowestSetBit();
        if (gen > 41) return FAIL_MSG;
        BigInteger test = new BigInteger("0").setBit(gen);
        if (c.Q.compareTo(test) != 0) return FAIL_MSG;
        
        for (int i = 1; i <= gen; i++) {
            BigInteger b = new BigInteger("0").setBit(i);
            BigInteger bb = c.Q.divide(b);
            if ( c.P.compareTo(bb) >= 0) {
                return Integer.toString(i);
            }
        }
                        
        return FAIL_MSG;
    }
        
}
