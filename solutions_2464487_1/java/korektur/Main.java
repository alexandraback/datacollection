
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

    public static BigInteger sqrt(BigInteger N) {
        BigInteger rootN = N;
        int bitLength = 1; // There is a bug in finding bit length hence we start with 1 not 0
        while (rootN.remainder(BigInteger.valueOf(2)) != BigInteger.ZERO) {
            rootN = rootN.divide(BigInteger.valueOf(2));
            bitLength++;
        }
        bitLength = (bitLength + 1) / 2;
        rootN = N.shiftRight(bitLength);

        BigInteger lastRoot = BigInteger.ZERO;
        do {
            lastRoot = rootN;
            rootN = ((N.divide(rootN)).add(rootN)).shiftRight(1);
        } while (!((rootN.xor(lastRoot)).toString() == "0"));
        return rootN;
    } // SqRtN

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int t = in.nextInt();
        for (int tt = 0; tt < t; tt++) {
            long r = in.nextLong();
            long m = in.nextLong();
            long r1 = r;
            long r2 = r1 + 1;
            BigInteger rr = BigInteger.valueOf(r);
            BigInteger a1 = BigInteger.valueOf(r + 1);
            a1 = a1.pow(2);
            rr = rr.pow(2);
            a1 = a1.subtract(rr);
            BigInteger x = new BigInteger("2");
            x = x.multiply(a1);
            x = x.subtract(BigInteger.valueOf(4));
            BigInteger d = x;
            d = d.multiply(d);
           // out.println(d);
            BigInteger s = new BigInteger("32");
            s = s.multiply(BigInteger.valueOf(m));
            d = d.add(s);
           // d = d.divide(BigInteger.valueOf(64));
           // out.println(s);
           // out.println(d);
            d = sqrt(d);
           // if (d.compareTo(x) >= 1)
           //     out.println("YES");
           // else out.println("NO");
            d = d.subtract(x);
            d = d.divide(BigInteger.valueOf(8));

            out.print("Case #" + (tt + 1) + ": ");
            out.println(d.toString());
        }
        out.close();
    }
}