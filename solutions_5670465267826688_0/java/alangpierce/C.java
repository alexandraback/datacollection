package qual;

import com.google.common.collect.FluentIterable;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.Ordering;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class C {
    private static final String PROBLEM = "qual/C-small-attempt0";
    private final Scanner in;
    public C(Scanner in) {
        this.in = in;
    }

    List<List<Integer>> mulTable = ImmutableList.of(
            ImmutableList.of(),
            ImmutableList.of(-999, 1, 2, 3, 4),
            ImmutableList.of(-999, 2, -1, 4, -3),
            ImmutableList.of(-999, 3, -4, -1, 2),
            ImmutableList.of(-999, 4, 3, -2, -1)
    );

    int mul(int a, int b) {
        boolean neg = (a < 0) != (b < 0);
        a = Math.abs(a);
        b = Math.abs(b);
        int result = mulTable.get(a).get(b);
        if (neg) {
            result = -result;
        }
        return result;
    }

    int mulList(List<Integer> list) {
        int result = 1;
        for (int val : list) {
            result = mul(result, val);
        }
        return result;
    }

    int pow(int val, long exp) {
        int result = 1;
        int power = val;
        while (exp > 0) {
            if (exp % 2 > 0) {
                result = mul(result, power);
            }
            power = mul(power, power);
            exp /= 2;
        }
        return result;
    }

    private String runCase() {
        in.nextInt();
        long numCopies = in.nextLong();
        String str = in.next();
        ImmutableList<Integer> vals =
                ImmutableList.copyOf(str.chars().map(c -> c - 'i' + 2).iterator());

        int valsProd = mulList(vals);
        int fullProd = pow(valsProd, numCopies);
        if (fullProd != -1) {
            return "NO";
        }
        ImmutableList.Builder<Integer> builder = ImmutableList.builder();
        for (int i = 0; i < numCopies && i < 20; i++) {
            builder.addAll(vals);
        }
        ImmutableList<Integer> lotsOfVals = builder.build();
        int firstVal = 1;
        int secondVal = 1;
        for (int val : lotsOfVals) {
            if (firstVal != 2) {
                firstVal = mul(firstVal, val);
            } else if (secondVal != 3) {
                secondVal = mul(secondVal, val);
            } else {
                return "YES";
            }
        }
        return "NO";
    }

    private List<Integer> nextIntList(int n) {
        ImmutableList.Builder<Integer> builder = ImmutableList.builder();
        for (int i = 0; i < n; i++) {
            builder.add(in.nextInt());
        }
        return builder.build();
    }

    private void runCases() throws FileNotFoundException {
        int numCases = in.nextInt();
        PrintWriter writer = new PrintWriter(PROBLEM + ".out");
        for (int casenum = 1; casenum <= numCases; casenum++) {
            String result = runCase();
            System.out.printf("Case #%d: %s%n", casenum, result);
            writer.printf("Case #%d: %s%n", casenum, result);
            writer.flush();
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(PROBLEM + ".in"));
        new C(in).runCases();
    }
}
