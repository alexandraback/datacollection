import java.math.BigInteger;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class JamB1 {
    public static void main(String[] args) {
        BigInteger _40 = BigInteger.valueOf(2).pow(40);
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        Pattern compile = Pattern.compile("/");
        BigInteger _2 = BigInteger.valueOf(2);
        for (int i = 1; i <= T; i++) {
            String next = in.next();
            String[] split = compile.split(next);
            BigInteger Q = BigInteger.valueOf(Long.parseLong(split[1]));
            BigInteger P = BigInteger.valueOf(Long.parseLong(split[0]));
            String result = "impossible";
            if ((_40.multiply(P).mod(Q).equals(BigInteger.ZERO))) {
                int count = 0;
                BigInteger acc = BigInteger.ONE;
                while (Q.compareTo(P.multiply(acc))> 0) {
                    acc = acc.multiply(_2);
                    count++;
                }
                result = String.valueOf(count);
            }
            System.out.println("Case #" + i + ": " + result);
        }
        in.close();
    }
}
