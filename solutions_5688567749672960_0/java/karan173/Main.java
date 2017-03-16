import java.io.*;
import java.util.*;

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
    public void solve(int testNumber, FastReader in, PrintWriter out)
    {
        long n = in.nl ();
        out.print ("Case #" + testNumber + ": ");
        Queue<Integer> queue = new ArrayDeque<Integer> ();
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer> ();
        queue.add (1);
        map.put (1, 1);
        while (!queue.isEmpty ())
        {
            int x = queue.poll ();
            int val = map.get (x);
            if (x == n)
            {
                out.println (val);
                return;
            }
            int new1 = getReverse (x);
            int new2 = x + 1;
            if (!map.containsKey (new1))
            {
                map.put (new1, val + 1);
                queue.add (new1);
            }
            if (!map.containsKey (new2))
            {
                map.put (new2, val + 1);
                queue.add (new2);
            }
        }

//        long cnt = 0;
//        while (true)
//        {
//            if (n < 10)
//            {
//                cnt += n;
//                break;
//            }
//            if (n % 10 == 0)
//            {
//                cnt++;
//                n--;
//                continue;
//            }
//            String s = Long.toString (n);
//            String srev = new StringBuilder (s).reverse ().toString ();
//            long nrev = Long.parseLong (srev, 10);
//            if (nrev <= n - 1)
//            {
//                cnt++;
//                n = nrev;
//            }
//            n = n-1;
//            cnt++;
//        }
//        out.println (cnt);
    }

    private int getReverse(int x)
    {
        String s = Integer.toString (x);
        String srev = new StringBuilder (s).reverse ().toString ();
        int nrev = Integer.parseInt (srev, 10);
        return nrev;
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

