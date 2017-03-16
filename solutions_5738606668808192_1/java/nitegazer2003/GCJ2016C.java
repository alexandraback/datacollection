import java.awt.geom.AffineTransform;
import java.awt.geom.Point2D;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class GCJ2016C
{

private static StringTokenizer st;
    
    public static void nextLine(BufferedReader br) throws IOException
    {
        st = new StringTokenizer(br.readLine());
    }
    
    public static int nextInt()
    {
        return Integer.parseInt(st.nextToken());
    }
    
    public static String next()
    {
        return st.nextToken();
    }
    
    public static long nextLong()
    {
        return Long.parseLong(st.nextToken());
    }

    public static double nextDouble()
    {
        return Double.parseDouble(st.nextToken());
    }
    
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new File("C-small.out"));
        nextLine(br);
        int T = nextInt();
        Random rng = new Random();
        nextLine(br);
        int N = nextInt();
        int J = nextInt();
        pw.println("Case #1:");
        BigInteger[][] pows = new BigInteger[11][33];
        for (int i = 2; i <= 10; i++)
        {
            BigInteger base = BigInteger.valueOf(i);
            BigInteger val = BigInteger.ONE;
            for (int j = 0; j < 32; j++)
            {
                pows[i][j] = val;
                val = val.multiply(base);
            }
        }
        int total = 0;
        for (long i = 0; i < (1L << (N-2)); i++)
        {
            boolean good = true;
            BigInteger[] res = new BigInteger[11];
            long bits = (i << 1) + (1L << (N-1)) + 1;
            System.out.println("Trying bits " + bits);
            for (int j = 2; j <= 10; j++)
            {
                BigInteger val = BigInteger.ZERO;
                for (int k = 0; k < N; k++)
                {
                    if (((bits >> k) & 1) == 1)
                    {
                        val = val.add(pows[j][k]);
                    }
                }
                //System.out.println("In base " + j + " is " + val);
                boolean found = false;
                for (int k = 0; k < 200; k++)
                {
                    BigInteger div = BigInteger.probablePrime(32, rng);
                    if (!div.modPow(val.subtract(BigInteger.ONE), val).equals(BigInteger.ONE))
                    {
                        res[j] = prho(val);
                        //System.out.println("Found counter " + div + " with gcd " + res[j]);
                        if (res[j] != null)
                        {
                            found = true;
                            break;
                        }
                    }
                }
                
                if (!found)
                {
                    good = false;
                    break;
                }
            }
            if (good)
            {
                pw.print(binstr(bits) + " ");
                for (int j = 2; j <= 10; j++)
                {
                    pw.print(res[j].toString());
                    if (j != 10)
                    {
                        pw.print(" ");
                    }
                }
                pw.println();
                total++;
                System.out.println("Found " + total);
                if (total == J) break;
            }
        }
        pw.close();
    }
    
    static BigInteger prho (BigInteger n)
    {
        BigInteger x = BigInteger.valueOf(2);
        BigInteger y = BigInteger.valueOf(2);
        BigInteger d = BigInteger.valueOf(1);
        while (d.equals(BigInteger.ONE))
        {
            x = g(x, n);
            y = g(g(y, n), n);
            d = x.subtract(y).abs().gcd(n);
        }
        if (d.equals(n))
        {
            return null;
        }
        return d;
    }
    
    static BigInteger g(BigInteger x, BigInteger n)
    {
        x = x.multiply(x);
        x = x.add(BigInteger.ONE);
        return x.mod(n);
    }
    
    private static String binstr(long val)
    {
        StringBuffer sb = new StringBuffer();
        while (val > 0)
        {
            if (val % 2 == 0)
            {
                sb.append("0");
            }
            else
            {
                sb.append("1");
            }
            val /= 2;
        }
        sb.reverse();
        return sb.toString();
    }
    
    private static long modexp(long a, long b, long m)
    {
        long k = 1;
        while (b > 0)
        {
            if ((b & 1) == 1)
            {
                k = modm(a, k, m);
            }
            b = b >> 1;
            a = modm(a, a, m);
        }
        return k;
    }
    
    private static long modinv(long a, long m)
    {
        return modexp(a, m-2, m);
    }
    
    private static long moda(long a, long b, long m)
    {
        return (a+b) % m;
    }
    
    private static long modm(long a, long b, long m)
    {
        return ((a%m)*(b%m)) % m;
    }
    
}