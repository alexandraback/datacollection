import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by kamil on 09.04.2016.
 */
public class CoinMinerOpt {


    public static void main(String[] args) throws IOException {

        int n = 32;
        int j = 500;

        Writer writer = new OutputStreamWriter(new FileOutputStream("c:\\codejam\\coin.out"));

        BigInteger two = BigInteger.valueOf(2);
        BigInteger base2 = BigInteger.valueOf(1);
        BigInteger max = BigInteger.valueOf(10).pow(8).multiply(two);
        BigInteger[] dividers = new BigInteger[11];

        List<BigInteger> primes = calculatePrimes(max);

        for (int i = 1; i < n; i++) {
            base2 = base2.multiply(two);
        }

        base2 = base2.add(BigInteger.ONE);

        String base2String = base2.toString(2);

        while (j > 0) {
            base2 = base2.add(two);
            base2String = base2.toString(2);

            dividers[2] = findDivider(base2, primes);
            boolean good = dividers[2] != null;

            for (int i = 3; good && i < 11; i++) {
                BigInteger interpretation = new BigInteger(base2String, i);

                dividers[i] = findDivider(interpretation, primes);
                good = dividers[i] != null;
            }

            if (good) {
                System.out.print(base2String + " ");
                writer.write(base2String + " ");
                for (int i = 2; i < 11; i++) {
                    System.out.print(dividers[i] + " ");
                    writer.write(dividers[i] + " ");
                }
                System.out.println();
                writer.write("\n");
                j--;
            }


        }

        writer.close();
    }

    private static BigInteger findDivider(BigInteger candidate, List<BigInteger> primes) {
        for (BigInteger divider : primes) {
            if (divider.multiply(divider).compareTo(candidate) > 0) {
                break;
            }

            if (candidate.mod(divider).equals(BigInteger.ZERO)) {
                return divider;
            }
        }
        return null;
    }

    private static Long findDivider(Long candidate, List<Long> primes) {
        for (Long divider : primes) {
            if (divider * divider > candidate) {
                break;
            }

            if (candidate % divider == 0) {
                return divider;
            }
        }
        return null;
    }

    private static List<BigInteger> calculatePrimes(BigInteger max) {
        long[] list = new long[(int) (max.longValueExact() / 9L)];

        int last = 0;
        list[last++] = 2;
        list[last++] = 3;
        list[last++] = 5;
        list[last++] = 7;
        list[last++] = 11;
        list[last++] = 13;
        list[last++] = 17;
        list[last++] = 19;

        Long candidate;
        long i = 4;
        int j = 0;
        long maxLong = max.longValueExact();
        boolean good;
        do {
            candidate = i * 6 - 1;

            good = true;
            for (j = 0; j < last; j++) {
                if (list[j] * list[j] > candidate) {
                    break;
                }

                if (candidate % list[j] == 0) {
                    good = false;
                    break;
                }
            }

            if (good) {
                list[last++] = candidate;
            }

            candidate = i * 6 - 1;

            good = true;
            for (j = 0; j < last; j++) {
                if (list[j] * list[j] > candidate) {
                    break;
                }

                if (candidate % list[j] == 0) {
                    good = false;
                    break;
                }
            }

            if (good) {
                list[last++] = candidate;
            }

            if (i % 100000 == 0) {
                System.out.println("Prime prog" + candidate + "/" + max + " " + ((candidate * 1000l) / maxLong) + "%% size:" + last);
            }

            i++;
        } while (candidate < maxLong);

        LinkedList<BigInteger> big = new LinkedList<>();
        for (j = 0; j < last; j++) {
            big.add(BigInteger.valueOf(list[j]));
        }
        return big;
    }

}
