import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.Pattern;

public class C {
    static int[] primes = new int[1<<16];
    public static void main(String[] args) throws Exception {
        generatePrimes();
//        InputStream in = System.in;
        InputStream in = new FileInputStream("/home/floris/Downloads/C-small-attempt0.in");
        System.setOut(new PrintStream("/home/floris/dev/java/Codejam2016/src/C.out"));
        Scanner sc = new Scanner(in);
        sc.useDelimiter(Pattern.compile("[\n /]"));

        int[] dividers = new int[11];

        for (int c = 1, cases = sc.nextInt(); c <= cases; c++) {
            System.out.printf("Case #%d:%n", c);
            int coinlength = sc.nextInt();
            int coincount = sc.nextInt();

c:          for (int i = 0; i < (1<<(coinlength - 2)); i++) {
                String coin = Integer.toBinaryString((i<<1) + 1 + (1<<coinlength-1));
                for (int j = 2; j <= 10; j++) {
                    BigInteger cv = new BigInteger(coin, j);
//                    System.out.println(cv + " " + (int)cv);
                    dividers[j] = divider(cv);
                    if (dividers[j] == 0) continue c;
                }
                System.out.print(coin);
                for (int j = 2; j <= 10; j++) System.out.print(" " + dividers[j]);
                System.out.println();
                coincount--;
                if (coincount == 0) break;
            }
        }
    }

    private static void generatePrimes() {
        int primecount = 0;
x:      for (int i = 2; primecount < primes.length; i++) {
            for (int dii = 0; primes[dii] != 0 &&  primes[dii] * primes[dii] <= i; dii++) {
                if (i % primes[dii] == 0 ) continue x;
            }
            primes[primecount] = i;
//            if (primecount%10000 ==0) System.out.println(primecount+ " " + i);
            primecount++;
        }
//        System.out.println(primecount + " " + primes[primecount - 1]);
    }

    private static int divider(BigInteger v) {
        for (int i = 0; i < primes.length; i++) {
            BigInteger p = BigInteger.valueOf(primes[i]);
            if (!v.equals(p) && v.mod(p).equals(BigInteger.ZERO)) return primes[i];
        }
        return 0;
    }
}
