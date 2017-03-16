import java.io.*;
import java.util.Arrays;
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
			final String regex = "B-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastReader in = new FastReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB
{
    int dp[][] = new int[1001][1001];
    public void solve(int testNumber, FastReader in, PrintWriter out)
    {
        for (int i = 0; i < 1001; i++)
        {
            Arrays.fill (dp[i], -1);
        }
        int t = in.ni ();
        for (int i = 1; i <= t; i++)
        {
            int n = in.ni ();
            int a[] = in.iArr (n);
            int best = Integer.MAX_VALUE / 4;
            int bestNormal = -1;
            for (int normal = 1; normal <= 1000; normal++)
            {
                int moves = normal;
                for (int j = 0; j < n; j++)
                {
                    moves += getMinSpecialMoves (a[j], normal);
                }
                if (moves < best)
                {
                    best = moves;
                    bestNormal = normal;
                }
            }
            out.print ("Case #" + i + ": ");
            out.println (best);
        }
    }

    private int getMinSpecialMoves(int n, int normal)
    {
        if (n <= normal)
        {
            return 0;
        }
        if (normal == 0)
        {
            return Integer.MAX_VALUE / 4;
        }
        if (dp[n][normal] != -1)
        {
            return dp[n][normal];
        }
        dp[n][normal] = Integer.MAX_VALUE/4;
        for (int k = 1; k <= n / 2; k++)
        {
            dp[n][normal] = Math.min (dp[n][normal], 1 + getMinSpecialMoves (k, normal) + getMinSpecialMoves (n - k, normal));
        }
        if (n % 2 != 0)
        {
            dp[n][normal] = Math.min (dp[n][normal], 2 * getMinSpecialMoves (n / 2, normal - 1) + 1);
        }
        return dp[n][normal];
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

    public int[] iArr(int n)
    {
        int a[] = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = ni ();
        }
        return a;
    }

    public interface SpaceCharFilter
    {
        public boolean isSpaceChar(int ch);
    }
}

