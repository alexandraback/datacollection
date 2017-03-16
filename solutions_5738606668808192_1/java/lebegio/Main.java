import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.util.BitSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lebegio
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "C-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("c.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        MyReader in = new MyReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, MyReader in, PrintWriter out) {
            List<Integer> primes = NT.getPrimes(5000);
            int N = in.nextInt();
            int J = in.nextInt();
            out.println("Case #1:");
            BigInteger rad = BigInteger.ONE.shiftLeft(N - 1).add(BigInteger.ONE);
            while (J > 0) {
                int[] pr = new int[9];
                int k = 2;
                while (k <= 10) {
                    BigInteger val = new BigInteger(rad.toString(2), k);
                    for (int p : primes) {
                        if (val.remainder(BigInteger.valueOf(p)).equals(BigInteger.ZERO)) {
                            pr[k - 2] = p;
                            break;
                        }
                    }
                    if (pr[k - 2] == 0) {
                        pr = null;
                        break;
                    }
                    k++;
                }

                if (pr != null) {
                    J--;
                    out.print(rad.toString(2) + " ");
                    for (int p : pr)
                        out.print(p + " ");
                    out.println();
                }
                rad = rad.add(BigInteger.valueOf(2));
            }
        }

    }

    static class MyReader {
        private BufferedReader buffReader;
        private StringTokenizer strTokenizer;
        private static final int SIZE = 32768;

        public MyReader(InputStream inputStream) {
            buffReader = new BufferedReader(new InputStreamReader(inputStream), SIZE);
        }

        public String next() {
            if (strTokenizer == null || !strTokenizer.hasMoreTokens()) {
                try {
                    strTokenizer = new StringTokenizer(buffReader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return strTokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }

    static class NT {
        public static List<Integer> getPrimes(int N) {
            BitSet isPrimes = new BitSet(N);//107374
            ArrayList<Integer> primes = new ArrayList<>();
            primes.add(2);
            for (int i = 3; i < N; i += 2) {
                if (!isPrimes.get(i)) {
                    primes.add(i);
                    for (int k = 2 * i; k < N; k += i) {
                        isPrimes.set(k);
                    }
                }
            }
            return primes;
        }

    }
}

