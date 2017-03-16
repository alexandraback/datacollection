import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.StringTokenizer;

public class CoinJam {
    private static final String CASE = "Case #";
    private static final int MAX = (int) 1e7;
    private static boolean[] sieve;
    private static ArrayList<BigInteger> primes;

    private static void init() {
        sieve = new boolean[MAX];
        primes = new ArrayList<BigInteger>();
    }

    private static void genSieve() {

        for (int i = 2; i * i < MAX; ++i) {
            if (!sieve[i]) {
                primes.add(new BigInteger(i + ""));
                for (int j = 2 * i; j < MAX; j += i) {
                    sieve[j] = true;
                }
            }
        }
    }

    private static String getRandomJamCoin(int len) {
        StringBuilder sb = new StringBuilder();
        sb.append("1");
        for (int i = 0; i < (len - 2); ++i) {
            int randomVal = (int) Math.round(Math.random());
            sb.append(String.valueOf(randomVal));
        }
        sb.append("1");
        return sb.toString();
    }

    private static int checkFactorInBase(String jamCoin, int base) {
        BigInteger currentBase = new BigInteger(jamCoin, base);
        for (int i = 0, iLen = primes.size(); i < iLen; ++i) {
            if (currentBase.mod(primes.get(i)).compareTo(BigInteger.ZERO) == 0) {
                // found a factor for base 2
                return primes.get(i).intValue();
            }
        }
        return 0;
    }

    public static void main(String[] args) throws Exception {
        // initialize
        init();
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        // generating all prime numbers
        genSieve();

        int tcs = Integer.parseInt(in.readLine());
        for (int t = 1; t <= tcs; ++t) {
            String opFormat = CASE + t + ":";

            StringTokenizer st = new StringTokenizer(in.readLine());
            int jamCoinLen = Integer.parseInt(st.nextToken()), requiredNumberOfJamCoins = Integer.parseInt(st.nextToken());

            HashMap<String, int[]> jamCoins = new HashMap<String, int[]>();

            while (jamCoins.size() < requiredNumberOfJamCoins) {
                String newJamCoin = getRandomJamCoin(jamCoinLen);
                while (jamCoins.containsKey(newJamCoin)) {
                    newJamCoin = getRandomJamCoin(jamCoinLen);
                }

                // factors array for all 10 bases
                int[] factors = new int[11];
                boolean possiblePrime = false;

                for (int i = 2; i <= 10; ++i) {
                    int factor = checkFactorInBase(newJamCoin, i);
                    if (factor == 0) {
                        possiblePrime = true;
                        break;
                    }
                    factors[i] = factor;
                }

                if (!possiblePrime) {
                    jamCoins.put(newJamCoin, factors);
                }
            }
            // starting to print output
            out.println(opFormat);
            Iterator<String> jamCoinIterator = jamCoins.keySet().iterator();
            while (jamCoinIterator.hasNext()) {
                String currentJamCoin = jamCoinIterator.next();
                int[] factors = jamCoins.get(currentJamCoin);

                out.print(currentJamCoin);
                for (int i = 2; i <= 10; ++i) {
                    out.print(" " + factors[i]);
                }
                out.println();
            }
        }

        in.close();
        out.flush();
        out.close();

    }
}

