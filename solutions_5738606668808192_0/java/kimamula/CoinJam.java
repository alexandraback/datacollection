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

            for (int count = 1; count * 6 <= n; count++) {
                for (List<Integer> combination: combinations(count * 6 - 2, n - 2)) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(1);
                    for (int index = 0; index < n - 2; index++) {
                        sb.append(combination.contains(index) ? 1 : 0);
                    }
                    String original = sb.append(1).toString();
                    long base2Divisor = getLowestDivisor(new BigInteger(original, 2));
                    long base6Divisor = getLowestDivisor(new BigInteger(original, 6));
                    long base8Divisor = getLowestDivisor(new BigInteger(original, 8));
                    if (base2Divisor >= 0 && base6Divisor >= 0 && base8Divisor >= 0) {
                        j -= 1;
                        out.println(original + " " + base2Divisor + " 2 3 2 " + base6Divisor + " 2 " + base8Divisor + " 2 3");
                        if (j == 0) {
                            break;
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

    static long getLowestDivisor(BigInteger num) {
        long i = 2;
        while (true) {
            BigInteger divisor = new BigInteger(i + "");
            BigInteger[] divideAndRemainder = num.divideAndRemainder(divisor);
            if (divideAndRemainder[1].equals(BigInteger.ZERO)) {
                return i;
            }
            if (divisor.compareTo(divideAndRemainder[0]) >= 0) {
                break;
            }
            i++;
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
