import java.io.*;
import java.util.ArrayList;
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
    int c, d, v;
    boolean taken[];
    ArrayList<Integer> dens;
    boolean possible[];
    ArrayList<Integer> options;
    public void solve(int testNumber, FastReader in, PrintWriter out)
    {
        out.print("Case #"+testNumber+": ");
        c = in.ni ();
        d = in.ni ();
        v = in.ni ();
        options = new ArrayList<> ();
        taken = new boolean[v + 1];
        dens = new ArrayList<> ();
        for (int i = 0; i < d; i++)
        {
            dens.add (in.ni ());
        }
        for (int x : dens)
        {
            taken[x] = true;
        }
        possible = getPossible (dens);
        for (int i = 1; i <= v; i++)
        {
            if (!taken[i])
            {
                options.add (i);
            }
        }
        int opLen = options.size ();
        for (int x = 0; x < (1 << opLen); x++)
        {
            ArrayList<Integer> take = new ArrayList<> ();
            for (int j = 0; j < opLen; j++)
            {
                if (!BitUtils.isIthOff (x, j))
                {
                    take.add (options.get (j));
                }
            }
            boolean z[] = getPossible (take);
            if (makeAll (z, possible))
            {
                out.println (Integer.bitCount (x));
                return;
            }
        }
    }

    private boolean makeAll(boolean[] z, boolean[] y)
    {
        boolean yes = true;
        for (int i = 1; i <= v; i++)
        {
            boolean ok = false;
            for (int k = 0; k <= i; k++)
            {
                boolean t = (y[k] && z[i - k]);
                ok |= t;
            }
            yes &= ok;
        }
        return yes;
    }

    private boolean[] getPossible(ArrayList<Integer> dens)
    {
        int len = dens.size ();
        boolean poss[] = new boolean[v + 1];
        for (int i = 0; i < (1 << len); i++)
        {
            int sum = 0;
            for (int j = 0; j < len; j++)
            {
                if (!BitUtils.isIthOff (i, j))
                {
                    sum += dens.get (j);
                }
            }
            if (sum <= v)
            {
                poss[sum] = true;
            }
        }
        return poss;
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

