import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CoinJam {
    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());

        for (int i = 1; i <= t; i++) {
            String[] inputs = bi.readLine().split("\\s");
            int n = Integer.parseInt(inputs[0]);
            int j = Integer.parseInt(inputs[1]);
            out.println("Case #" + i + ":");

            for (int count = n / 6; count >= 1; count--) {
                for (List<Integer> combination: combinations(count * 6 - 2, n - 2)) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(1);
                    for (int index = 0; index < n - 2; index++) {
                        sb.append(combination.contains(index) ? 1 : 0);
                    }
                    String original = sb.append(1).toString();
                    int base2Divisor = getLowestDivisorInt(Long.parseLong(original, 2));
                    if (base2Divisor >= 0) {
                        long base6Divisor = count % 5 == 0 ? 5 : getLowestDivisor(new BigInteger(original, 6));
                        if (base6Divisor >= 0) {
                            long base8Divisor = getLowestDivisor(new BigInteger(original, 8));
                            if (base8Divisor >= 0) {
                                j -= 1;
                                out.println(original + " " + base2Divisor + " 2 3 2 " + base6Divisor + " 2 " + base8Divisor + " 2 3");
                                if (j == 0) {
                                    break;
                                }
                            }
                        }
                    }
                }
                if (j == 0) {
                    break;
                }
            }

            if (j > 0) {
                throw new IllegalArgumentException();
            }
        }
        out.close();
    }

    static final BigInteger INITIAL_DIVISOR = BigInteger.valueOf(3);
    static final BigInteger INTERVAL = BigInteger.valueOf(2);
    static final int MAX_ITERATION = 1000000;

    static long getLowestDivisor(BigInteger num) {
        BigInteger divisor = INITIAL_DIVISOR;
        int ite = 0;
        while (ite++ < MAX_ITERATION) {
            BigInteger[] divideAndRemainder = num.divideAndRemainder(divisor);
            if (divideAndRemainder[1] == BigInteger.ZERO) {
                return divisor.longValue();
            }
            divisor = divisor.add(INTERVAL);
            if (divisor.compareTo(divideAndRemainder[0]) >= 0) {
                break;
            }
        }
        return -1;
    }

    static int getLowestDivisorInt(long num) {
        int i = 3;
        while (num / i >= i) {
            if (num % i == 0) {
                return i;
            }
            i = i + 2;
        }
        return -1;
    }

    static List<List<Integer>> combinations(int selectCount, int length) {
        List<List<Integer>> result = new ArrayList<>();
        selectR(-1, new Integer[selectCount], selectCount, 0, length, result);
        return result;
    }

    static void selectR(int lastIndex, Integer[] acc, int selectCount, int currentlySelected, int length, List<List<Integer>> result) {
        if (selectCount == currentlySelected) {
            result.add(new ArrayList<>(Arrays.asList(acc)));
            return;
        }
        int end = length - (selectCount - currentlySelected);
        for (int i = lastIndex + 1; i <= end; i ++) {
            acc[currentlySelected] = i;
            selectR(i, acc, selectCount, currentlySelected + 1, length, result);
        }
    }
}
