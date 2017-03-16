import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Writer;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Andrey Rechitsky (arechitsky@gmail.com)
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
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    private long[] two = new long[41];
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        init();
        String[] s = in.next().split("/");
        long a = Long.parseLong(s[0]);
        long b = Long.parseLong(s[1]);
        int ans = getAns(a,b);
        out.printLine(String.format("Case #%d: %s", testNumber, ans==-1?"impossible":String.valueOf(ans)));
    }

    private int getAns(long a, long b){
        if (a==0) return -1;
        long e = euclid(a,b);
        a/=e;
        b/=e;
        int bi = -1;
        for (int i = 0; i < two.length; i++) {
            if (two[i]==b){
                bi = i;
                break;
            }
        }
        if (bi==-1) return -1;
        int ai=-1;
        for (int i = 0; i < two.length; i++) {
            if (a>=two[i]) ai=i;
        }
        return bi-ai;
    }

    private void init()
    {
        long x = 1;
        for (int i = 0; i < two.length; i++) {
            two[i] = x;
            x<<=1;
        }
    }
    private long euclid(long a, long b){
        if (a<b) return euclid(b,a);
        if (b==0) return a;
        return euclid(b, a%b);
    }
}

class FastScanner {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

    public FastScanner(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public String next() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            if (Character.isValidCodePoint(c))
                res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\t' || isEOL(c);
    }

    public static boolean isEOL(int c) {
        return c == '\n' || c == '\r' || c == -1;
    }

    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}

class FastPrinter {
    private final PrintWriter writer;

    public FastPrinter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public FastPrinter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void close() {
        writer.close();
    }

    public void printLine(String s) {
        writer.println(s);
    }

    }

