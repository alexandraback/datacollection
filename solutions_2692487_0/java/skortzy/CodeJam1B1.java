import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;

public class CodeJam1B1 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("A-small.in")));
            PrintWriter pw = new PrintWriter(new FileOutputStream("A-small.out"));
            String line = br.readLine();
            int T = Integer.parseInt(line);
            for (int i = 0; i < T; i++) {
                System.out.println((i + 1) + " / " + T + "...");

                line = br.readLine();
                String[] values = line.split(" ");
                long A = Long.parseLong(values[0]);
                long N = Long.parseLong(values[1]);

                values = br.readLine().split(" ");
                long[] m = new long[(int)N];
                for (int j = 0; j < N ; j++) {
                    m[j] = Long.parseLong(values[j]);
                }
                Arrays.sort(m);


                System.out.print(A + " - ");
                for (int j = 0; j < N; j++) {
                    System.out.print("\t" + m[j]);
                }
                System.out.print("\n" + A);
                long result = solve(A, N, m);
                System.out.println();

                long sum = 0;
                for (int j = (int)N - 1; j >= 0; j--) {
                    sum += total[j];
                    if (sum > (N - j)) {
                        //System.out.println("*******************");
                        result-= (sum - N + j);
                        sum = N - j;
                        break;
                    }
                }

                pw.println("Case #" + (i + 1) + ": " + result);
            }
            pw.close();
            System.out.println("DONE");
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static long[] total;

    private static long solve(long A, long N, long[] m) {
        long current = A;
        long result = 0;
        total = new long[(int)N];
        for (int i = 0; i < N; i++) {
            if (current > m[i]) {
                current += m[i];
                System.out.print("\t" + current);
                total[i] = 0;
            }
            else {
                long value = needed(current, m[i]);
                if (value > N - i) {
                    System.out.print(" # +" + (N - i));
                    total[i] = N - i;
                    return result + N - i;
                } else {
                    result += value;
                    for (int j = 0; j < value; j++) {
                        current = 2 * current - 1;
                        System.out.print("\t*" + current);
                    }
                    current += m[i];
                    System.out.print("\t" + current);
                    total[i] = value;
                }
            }
        }
        return result;
    }

    private static long needed(long current, long total) {
        if (current <= 1) {
            return Long.MAX_VALUE;
        }
        long needed = 0;
        while (current <= total) {
            current = 2 * current - 1;
            needed++;
        }
        return needed;
    }

    static BigInteger sqrt(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while (b.compareTo(a) >= 0) {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if (mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
            else a = mid.add(BigInteger.ONE);
        }
        return a.subtract(BigInteger.ONE);
    }


}
