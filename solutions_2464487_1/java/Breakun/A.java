import java.io.*;
import java.util.*;
import java.math.*;

public class A {
    public static BigInteger TWO = BigInteger.valueOf(2);

    public static void main(String[] args) throws FileNotFoundException {
        InputReader reader = new InputReader(new FileInputStream("A.in"));
        PrintWriter writer = new PrintWriter(new FileOutputStream("A.out"));

        int T = reader.nextInt();
        for(int i = 1; i <= T; i++) {
            BigInteger r = reader.nextBigInteger();
            BigInteger t = reader.nextBigInteger();
            BigInteger lc = BigInteger.ONE;
            BigInteger uc = BigInteger.valueOf(10).pow(20);
            while(lc.compareTo(uc) == -1) {
                BigInteger c = uc.subtract(uc.subtract(lc).divide(TWO));
                BigInteger v = TWO.multiply(r).add(TWO.multiply(c)).subtract(BigInteger.ONE).multiply(c);
                if(v.compareTo(t) == 1) {
                    uc = c.subtract(BigInteger.ONE);
                } else {
                    lc = c;
                }
            }
            assert lc.equals(uc);
            writer.print("Case #");
            writer.print(i);
            writer.print(": ");
            writer.println(lc.toString(10));
            writer.flush();
        }
    }
}


class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = new StringTokenizer("");
    }

    public String next() {
        try {
            while(!tokenizer.hasMoreTokens())
                tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public BigInteger nextBigInteger() {
        return new BigInteger(next());
    }
}
