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
    long cur;
    long cnt;
    long n;
    public void solve(int testNumber, FastReader in, PrintWriter out)
    {
        n = in.nl ();
        int dig = numDigits (n);
        cnt = 1;
        cur = 1;
        while (true)
        {
            if (numDigits (cur) != dig)
            {
                increaseDig ();
            }
            else
            {
                break;
            }
        }
        out.print("Case #"+testNumber+": ");
        if (n == 1)
        {
            out.println (1);
            return;
        }
        //now it is 1000000 something
        matchToN ();
        cnt--;
        out.println (cnt);
    }

    private void matchToN()
    {

        int firstDigN = getFirstDig (n);
//        System.out.println ("--" + firstDigN + " " + n);
        if (1 == firstDigN)
        {
            cnt += n - cur;
            return;
        }

        while (cur % 10 != firstDigN)
        {
            cur++;
            cnt++;
        }
        cnt++;
        long revN = getReverse (cur);
        cnt += n - revN;
        return;
    }

    private long getReverse(long cur)
    {
        String s = Long.toString (cur);
        String srev = new StringBuilder (s).reverse ().toString ();
        long nrev = Long.parseLong (srev, 10);
        return nrev;
    }

    private int getFirstDig(long cur)
    {
        String s = Long.toString (cur);
        return s.charAt (0) - '0';
    }

    private void increaseDig()
    {
        if (cur == 1)
        {
            cnt += 10;
            cur = 10;
            return;
        }
        if (cur % 10 != 0)
        {
            throw new RuntimeException ();
        }
        cur *= 10;
        cnt += 19;
    }

    private int numDigits(long n)
    {
        return String.valueOf (n).length ();
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

