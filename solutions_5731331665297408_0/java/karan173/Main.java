import java.io.*;
import java.util.Arrays;
import java.util.InputMismatchException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author karan173
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("c.in");
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
		c solver = new c();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class c {

    public static boolean nextPermutation(int[] p)
    {
        for (int a = p.length - 2; a >= 0; --a)if (p[a] < p[a + 1]) for (int b = p.length - 1;; --b) if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        return false;
    }
    boolean flight[][];
    public void solve(int testNumber, FastReader in, PrintWriter out)
    {
        int n = in.ni ();
        int m = in.ni ();
        int zips[] = new int[n];
        for (int i = 0; i < n; i++)
        {
            zips[i] = in.ni ();
        }
        flight = new boolean[n][n];
        for (int i = 0; i < m; i++)
        {
            int a = in.ni ();
            int b = in.ni ();
            flight[a - 1][b - 1] = flight[b - 1][a - 1] = true;
        }
        out.print ("Case #" + testNumber + ": ");
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = i;
        }
        int back[] = new int[n];

        StringBuilder inf = new StringBuilder ("");
        for (int i = 0; i < 40; i++)
        {
            inf.append ('9');
        }
        String zip = inf.toString ();
        do
        {
//            out.println ("-- " + Arrays.toString (arr));
            Arrays.fill (back, -1);
            int curnode = arr[0];
            int i;
            for ( i = 0; i < n - 1; i++)
            {
                //go direct or back
                int t = curnode;
                while (t != -1 && !flight[t][arr[i + 1]])
                {
                    int z = t;
                    t = back[t];
                    back[z] = -1;
                }
                if (t == -1)
                {
                    break;
                }
                curnode = arr[i + 1];
                back[curnode] = t;
            }
            if (i == n - 1)
            {

                //possible
                String z = "";
                for (int j = 0; j < n; j++)
                {
                    z = z + Integer.toString (zips[arr[j]]);
                }
//                out.println ("--" + Arrays.toString (arr) + " " + z);
                int cmp = z.compareTo (zip);
                if (cmp < 0)
                {
                    zip = z;
                }
            }
        } while (nextPermutation (arr));
        out.println (zip);
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

