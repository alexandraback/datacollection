import sun.awt.image.BufferedImageGraphicsConfig;

import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.concurrent.atomic.*;
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main
{
    public static void main(String[] args)
    {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Scanner sc = new Scanner(inputStream);
        Task solver = new Task(sc, out);
        solver.solve();
        out.close();
    }
}

class Task
{
    int N, A, B;
    private Scanner in;
    private PrintWriter out;
    private String line;
    Task(Scanner _in, PrintWriter _out)
    {
        in = _in;
        out =_out;
    }

    BigInteger sqrt(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while(b.compareTo(a) >= 0) {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
            else a = mid.add(BigInteger.ONE);
        }
        return a.subtract(BigInteger.ONE);
    }

    public void solve()
    {
        int T = in.nextInt();
        for (int testNumber = 1; testNumber <= T; ++testNumber)
        {
            long r = in.nextLong();
            long t = in.nextLong();

            BigInteger R = BigInteger.valueOf(r);
            BigInteger S = BigInteger.valueOf(4).multiply(R.multiply(R).subtract(R))
                            .add(BigInteger.ONE).add(BigInteger.valueOf(8).multiply(BigInteger.valueOf(t)));
            BigInteger ans = sqrt(S).subtract(BigInteger.valueOf(2 * r - 1)).divide(BigInteger.valueOf(4));
//            ans = (sqrt(4 * (sqr(r) - r) + 1.0 + 8 * t) - 2 * r + 1) / 4;
            out.println("Case #" + testNumber + ": " + ans);
        }
//        out.print(sqrt(BigInteger.valueOf(123)));
    }
}

class InputReader
{
    private BufferedReader reader;
    private StringTokenizer tokenizer;
    public InputReader(InputStream stream)
    {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }
    public String next()
    {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
    public int nextInt()
    {
        return Integer.parseInt(next());
    }
    public long nextLong()
    {
        return Long.parseLong(next());
    }
}
