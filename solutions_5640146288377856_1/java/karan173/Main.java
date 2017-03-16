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
			final String regex = "A-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastReader in = new FastReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA

{

    int r,c, w;
    public void solve(int testNumber, FastReader in, PrintWriter out)
    {
            r = in.ni ();
            c = in.ni ();
            w = in.ni ();
        int y = getNumTries (c, w);
        int x = getMinTries (c, w);
        int z = minTries (c, w);
        int ans1 = z * r + w - 1;
        int ans2 = y * r + w - 1;
            out.print ("Case #" + testNumber + ": ");
            out.println (Math.min (ans1, ans2));
    }

    private int getNumTries(int c, int w)
    {
        if (c == w)
        {
            return 1;
        }
        if (c >= 2 * w)
        {
            int ans = getNumTries (c - w, w) + 1;
            return ans;
        }
        return 2;
    }

    private int getMinTries(int c, int w)
    {
        if (c == w)
        {
            return w;
        }
        if (c >= 2 * w)
        {
            return getMinTries (c - w, w) + 1;
        }
        return 2 + w - 1;
    }

    private int minTries(int r, int w)
    {
        int minTries = Integer.MAX_VALUE / 2;
        int actualTries = Integer.MAX_VALUE / 2;
        for (int i = 0; i < 1 << r; i++)
        {
            boolean ok = true;
            for (int j = 0; j < r; j++)
            {
                int covered = 0;
                int right = j + w - 1;
                if (right >= r)
                {
                    break;
                }
                for (int x = j; x <= right; x++)
                {
                    if (!BitUtils.isIthOff (i, x))
                    {
                        covered++;
                    }
                }
                if (covered == 0)
                {
                    ok = false;
                    break;
                }
            }
            if (ok && Integer.bitCount (i) < minTries)
            {
                minTries = Integer.bitCount (i);
            }
        }
        return minTries;
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

class BitUtils
{

    public static boolean isIthOff(long n, int i)
    {
        return ((n & (1 << i)) == 0);
    }
}

