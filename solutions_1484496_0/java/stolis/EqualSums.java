package round1;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class EqualSums {
    static int T;
    static int N;
    static long[] S;
    static long sum;
    static LongPlus[] results;

    public static void main(String[] args) throws IOException {
        read();
        write();
    }

    static void read() throws IOException {
        File input = new File("input.txt");
        Scanner scanner = new Scanner(input);
        T = scanner.nextInt();
        results = new LongPlus[T];
        for (int t=0; t<T; t++) {
            N = scanner.nextInt();
            S = new long[N];
            sum = 0;
            for (int n=0; n<N; n++) {
                S[n] = scanner.nextLong();
                sum += S[n];
            }
            process(t);
        }
    }

    static void process(int t) {
        Arrays.sort(S);
        Set<LongPlus> set = new HashSet<LongPlus>();
        double rest = sum;
        LongPlus zero = new LongPlus();
        set.add(zero);
        outer: for (int n=N-1; n>=0; n--) {
            long y = S[n];
            rest -= y;
            Set<LongPlus> old = set;
            set = new HashSet<LongPlus>();
            for (LongPlus x : old) {
                long value = x.value;
                if (rest >= value && value >= -rest) {
                    set.add(x);
                }
                long z = value+y;
                if (rest >= z && z >= -rest) {
                    LongPlus newVal = new LongPlus();
                    newVal.value = z;
                    newVal.delta = y;
                    newVal.previous = x;
                    set.add(newVal);
                    if (z == 0) {
                        results[t] = newVal;
                        break outer;
                    }
                }
                z = value-y;
                if (rest >= z && z >= -rest) {
                    LongPlus newVal = new LongPlus();
                    newVal.value = z;
                    newVal.delta = -y;
                    newVal.previous = x;
                    set.add(newVal);
                    if (z == 0) {
                        results[t] = newVal;
                        break outer;
                    }
                }
            }
        }

    }

    static class LongPlus {
        long value;
        long delta;
        LongPlus previous;

        @Override
        public boolean equals(Object obj) {
            return ((LongPlus)obj).value == value;
        }

        @Override
        public int hashCode() {
            return Long.valueOf(value).hashCode();
        }

    }

    static void write() throws IOException {
        File output = new File("output.txt");
        PrintWriter pw = new PrintWriter(output);

        for (int t=0; t<T; t++) {
            pw.println("Case #"+(t+1)+":");
            LongPlus value = results[t];
            if (value == null) {
                pw.println("Impossible");
            } else {
                List<Long> plus = new LinkedList<Long>();
                List<Long> minus = new LinkedList<Long>();
                while (value.previous != null) {
                    if (value.delta > 0) {
                        plus.add(value.delta);
                    } else {
                        minus.add(-value.delta);
                    }
                    value = value.previous;
                }
                for (long x : plus) {
                    pw.print(x+" ");
                }
                pw.println();
                for (long x : minus) {
                    pw.print(x+" ");
                }
                pw.println();
            }
        }

        pw.close();
    }

}
