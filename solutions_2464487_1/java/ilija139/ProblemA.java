package my.codejam.y13.round1a;

import java.io.*;
import java.math.*;
import java.util.*;

public class ProblemA {

    static void runIt() throws IOException {

//        String inFName = "resource/cj13/A-small-attempt0.in";
         String inFName = "resource/cj13/A-large.in";
//        String outFName = "resource/cj13/A-small.out";
         String outFName = "resource/cj13/A-large.out";

        PrintWriter out = new PrintWriter(new File(outFName));
        Scanner sc = new Scanner(new File(inFName));

        int testCases = Integer.parseInt(sc.nextLine());

        for (int T = 0; T < testCases; ++T) {

            long r = sc.nextLong();
            long t = sc.nextLong();

            long k = find(r, t);

            StringBuilder output = new StringBuilder();
            output.append("Case #" + (T + 1) + ": ");
            output.append(k);
            System.out.println(output);
            out.println(output.toString().trim());
        }
        sc.close();

        out.flush();
        out.close();
    }

    private static long find(long r, long t) {
        long low = 0, high = t;

        long k = 0;

        while (low <= high) {

            long mid = (low + high) / 2;

            if (check(r, mid, t)) {
                high = mid - 1;
                k = mid;
            } else {
                low = mid + 1;
            }
        }

        return k;
    }

    private static boolean check(long r, long mid, long t) {

        BigInteger d = new BigInteger(String.valueOf(mid + 1));
        BigInteger s = new BigInteger(String.valueOf(2 * r));
        BigInteger e = new BigInteger(String.valueOf(2 * mid));
        BigInteger f = new BigInteger("1");
        f = f.add(s);
        f = f.add(e);
        d = d.multiply(f);

        return d.compareTo(new BigInteger(String.valueOf(t))) > 0;

    }

    public static void main(String[] args) {

        try {
            ProblemA.runIt();
        } catch (IOException e) {

            System.out.println(e.getMessage());
            e.printStackTrace();

        } catch (Exception e) {

            System.out.println(e.getMessage());
            e.printStackTrace();

        }
    }
}
