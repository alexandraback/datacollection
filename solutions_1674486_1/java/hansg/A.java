import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class A {
    public static void main(String[] args) throws IOException {
        if (args.length < 1) {
            System.err.println("Missing input filename as argument.");
            System.exit(1);
        }
        final BufferedReader in = new BufferedReader(new FileReader(args[0]));
        final PrintWriter out =
            new PrintWriter(new BufferedOutputStream(System.out));

        final int nbrTestCases = Integer.parseInt(in.readLine());
        for (int testCase = 1; testCase <= nbrTestCases; testCase++) {
            final int n = Integer.parseInt(in.readLine());
            final int[][] classes = new int[n + 1][];
            for (int i = 1; i <= n; i++) {
                final StringTokenizer st1 = new StringTokenizer(in.readLine());
                final int m = Integer.parseInt(st1.nextToken());
                final int[] superClasses = new int[m];
                for (int j = 0; j < m; j++) {
                    superClasses[j] = Integer.parseInt(st1.nextToken());
                }
                classes[i] = superClasses;
            }

            final boolean diamond = f(n, classes);
            out.printf("Case #%d: ", testCase);
            if (diamond) {
                out.println("Yes");
            } else {
                out.println("No");
            }
        }

        out.flush();
    }

    private static final int DWIB = 5;
    private static final int MWIB = Integer.SIZE - 1;

    private static boolean f(final int n, final int[][] classes) {
        final int nInts = (n + Integer.SIZE) / Integer.SIZE;
        final int[][] subClasses = new int[n + 1][nInts];
        final int[] inheritedFrom = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            final int[] superClasses = classes[i];
            for (int j = 0; j < superClasses.length; j++) {
                inheritedFrom[ superClasses[j] ]++;
            }
        }

        final ArrayDeque<Integer> queue = new ArrayDeque<Integer>(n);
        for (int i = 1; i <= n; i++) {
            if (inheritedFrom[i] == 0) {
                queue.add(i);
            }
        }

        while (!queue.isEmpty()) {
            final int subClass = queue.removeFirst();
            final int[] superClasses = classes[subClass];
            final int subClassIndex = subClass >>> DWIB;
            final int bitNbr = subClass & MWIB;
            final int subClassBit = 1 << bitNbr;
            for (int i = 0; i < superClasses.length; i++) {
                final int superClass = superClasses[i];
                if ((subClasses[superClass][subClassIndex] & subClassBit) != 0) {
                    return true;
                }
                subClasses[superClass][subClassIndex] |= subClassBit;

                for (int j = 0; j < nInts; j++) {
                    final int s = subClasses[subClass][j];
                    if ((subClasses[superClass][j] & s) != 0) {
                        return true;
                    }
                    subClasses[superClass][j] |= s;
                }

                assert inheritedFrom[superClass] > 0;
                inheritedFrom[superClass]--;
                if (inheritedFrom[superClass] == 0) {
                    queue.add(superClass);
                }
            }
        }

        return false;
    }
}
