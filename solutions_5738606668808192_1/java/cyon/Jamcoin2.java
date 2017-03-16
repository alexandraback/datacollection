package qualif;

/**
 * Created by Martin on 4/9/2016.
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.io.PrintWriter;
import java.util.stream.Collectors;

public class Jamcoin2 {

    private static final BigInteger TWO = BigInteger.valueOf(2);
    private static final BigInteger THREE = BigInteger.valueOf(3);
    private static final BigInteger FIVE = BigInteger.valueOf(5);
    private static final BigInteger SEVEN = BigInteger.valueOf(7);

    public static void main(String[]args) throws IOException {
        //debug(String.format("1%14s1", "10000001").replace(' ', '0'));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        for(int i=1;i<=T;i++) {
            pw.println("Case #" + i + ": " + solve(br));
        }
        pw.flush();
    }

    private static String solve(BufferedReader br) throws IOException {

        StringBuilder bob = new StringBuilder("\n");

        int N = 32;
        int J = 500;
        int MAX = 1 << (N-2);

        for (int i=0;i<MAX;i++) {
            boolean ok = true;
            List<Long> divs = new ArrayList<>();
            String num = String.format("1%" + (N-2) + "s1", Integer.toBinaryString(i)).replace(' ', '0');
            //debug(num);
            for (int rad=2;rad<=10;rad++) {
                BigInteger val = new BigInteger(num, rad);
                long div = findDiv2(val, rad);
                if (div == 1) {
                    ok=false;
                    break;
                }
                else {
                    divs.add(div);
                }
            }
            if (ok) {
                if(!check(num, divs)) {
                    debug("ERROR", num, divs);
                }
                bob.append(num).append(" ").append(divs.stream().map(l -> l.toString()).collect(Collectors.joining(" ")));
                J--;
                if (J != 0) bob.append("\n");
            }
            if (J == 0) break;
        }

        return bob.toString();
    }

    private static boolean check(String num, List<Long> divs) {
        if (num.length() != 32) return false;
        if (!num.startsWith("1")) return false;
        if (!num.endsWith("1")) return false;
        for (int rad = 2; rad <= 10; rad++) {
            BigInteger val = new BigInteger(num, rad);
            BigInteger div = BigInteger.valueOf(divs.get(rad - 2));
            if (!val.mod(div).equals(BigInteger.ZERO)) return false;
        }
        return true;
    }

    private static long findDiv2(BigInteger val, int rad) {
        if (val.mod(TWO).equals(BigInteger.ZERO)) return 2;
        if (val.mod(THREE).equals(BigInteger.ZERO)) return 3;
        if (val.mod(FIVE).equals(BigInteger.ZERO)) return 5;
        if (val.mod(SEVEN).equals(BigInteger.ZERO)) return 7;
        return 1;
    }

    private static long findDiv(long val) {
        long root = (long)Math.ceil(Math.sqrt(val));
        for (long i=2;i<root;i++) {
            if (val%i==0) return i;
        }
        return 1;
    }

    public static void debug(Object...args) {
        System.out.println(Arrays.deepToString(args));
    }
}
