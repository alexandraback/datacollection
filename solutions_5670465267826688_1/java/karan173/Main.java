import java.io.*;
import java.util.InputMismatchException;
import java.util.Locale;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author karan173
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
		FastReader in = new FastReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC
{

    int n;
    long X;
    //1 = 0, i = 1, j = 2, k = 3
    //-1 = 4, -i = 5, -j = 6, -k = 7
    int val1 = 0, vali = 1, valk = 3;
    int map[][] = {
            {0, 1, 2, 3},
            {1, 4, 3, 6},
            {2, 7, 4, 1},
            {3, 2, 5, 4}
    };
    int getMap(int x, int y)
    {
        if (x >= 4)
        {
            return minus (getMap (x - 4, y));
        }
        if (y >= 4)
        {
            return minus (getMap (x, y - 4));
        }
        return map[x][y];
    }

    private int minus(int x)
    {
        return (x + 4) % 8;
    }

    int a[];

    public void solve(int testNumber, FastReader in, PrintWriter out)
    {
        n = in.ni ();
        X = in.nl ();
        a = new int[n];
        String s = in.ns ();
        int product = val1;
        for (int i = 0; i < n; i++)
        {
            a[i] = getVal (s.charAt (i));
            product = getMap (product, a[i]);
        }
        boolean yes = false;
        if (power (product, X) == minus (val1))
        {
            yes = true;
        }
        long smallestI = getSmallestI ();
        long smallestK = getSmallestK ();
        long total = n;
        total *= X;
        out.print ("Case #" + testNumber + ": ");
        out.println ((yes && (smallestI + smallestK < total)) ? "YES" : "NO");
    }

    private int power(int a, long n)
    {
        if (n == 0)
        {
            return val1;
        }
        int val = power (a, n >> 1);
        int sqr = getMap (val, val);
        if (n % 2 == 0)
        {
            return sqr;
        }
        return getMap (sqr, a);
    }

    private long getSmallestK()
    {
        //find smallest suffix which is equal to k
        //repetition starts after 4 copies
        int productTillNow = val1;
        int charsTillNow = 0;
        for (int copies = 0; copies < 4; copies++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                productTillNow = getMap (a[i], productTillNow);
                charsTillNow++;
                if (productTillNow == valk)
                {
                    return charsTillNow;
                }
            }
        }
        return INF;
    }

    long INF = Long.MAX_VALUE / 4;
    private long getSmallestI()
    {
        //repetition starts after 4 copies
        int productTillNow = val1;
        int charsTillNow = 0;
        for (int copies = 0; copies < 4; copies++)
        {
            for (int i = 0; i < n; i++)
            {
                productTillNow = getMap (productTillNow, a[i]);
                charsTillNow++;
                if (productTillNow == vali)
                {
                    return charsTillNow;
                }
            }
        }
        return INF;
    }


    private int getVal(char c)
    {
        return c - 'i' + 1;
    }


}

class FastReader
{

    public InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

    public FastReader(InputStream stream)
    {
        this.stream = stream;
    }

    public int read()
    {
        if (numChars == -1)
        {
            throw new InputMismatchException ();
        }
        if (curChar >= numChars)
        {
            curChar = 0;
            try
            {
                numChars = stream.read (buf);
            } catch (IOException e)
            {
                throw new InputMismatchException ();
            }
            if (numChars <= 0)
            {
                return -1;
            }
        }
        return buf[curChar++];
    }

    public int ni()
    {
        int c = read ();
        while (isSpaceChar (c))
            c = read ();
        int sgn = 1;
        if (c == '-')
        {
            sgn = -1;
            c = read ();
        }
        int res = 0;
        do
        {
            if (c < '0' || c > '9')
            {
                throw new InputMismatchException ();
            }
            res *= 10;
            res += c - '0';
            c = read ();
        } while (!isSpaceChar (c));
        return res * sgn;
    }

    public long nl()
    {
        int c = read ();
        while (isSpaceChar (c))
            c = read ();
        int sgn = 1;
        if (c == '-')
        {
            sgn = -1;
            c = read ();
        }
        long res = 0;
        do
        {
            if (c < '0' || c > '9')
            {
                throw new InputMismatchException ();
            }
            res *= 10;
            res += c - '0';
            c = read ();
        } while (!isSpaceChar (c));
        return res * sgn;
    }

    public String ns()
    {
        int c = read ();
        while (isSpaceChar (c))
            c = read ();
        StringBuilder res = new StringBuilder ();
        do
        {
            res.appendCodePoint (c);
            c = read ();
        } while (!isSpaceChar (c));
        return res.toString ();
    }

    public boolean isSpaceChar(int c)
    {
        if (filter != null)
        {
            return filter.isSpaceChar (c);
        }
        return isWhitespace (c);
    }

    public static boolean isWhitespace(int c)
    {
        return c==' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public String next()
    {
        return ns ();
    }

    public interface SpaceCharFilter
    {
        public boolean isSpaceChar(int ch);
    }
}

