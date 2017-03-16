import java.io.IOException;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.io.BufferedWriter;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Writer;
import java.math.BigInteger;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Jacob Jiang
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
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    private static String [][] multiplyTable =
            {{"1", "i", "j", "k"},
            {"i", "-1", "k", "-j"},
            {"j", "-k", "-1", "i"},
            {"k", "j", "-i", "-1"}};
    private static String charTable = "1ijk";
    private int getSign(String s) {
        return s.charAt(0) == '-' ? -1 : 1;
    }

    private char getChar(String s) {
        return s.charAt(s.length() - 1);
    }

    private String multiply(String a, String b) {
        int aSign = getSign(a);
        int bSign = getSign(b);
        char aChar = getChar(a);
        char bChar = getChar(b);
        int aIndex = charTable.indexOf(aChar);
        int bIndex = charTable.indexOf(bChar);
        String rawAnswer = multiplyTable[aIndex][bIndex];
        int answerSign = getSign(rawAnswer) * aSign * bSign;
        char answerChar = getChar(rawAnswer);
        if (answerSign == -1) {
            return "-" + answerChar;
        } else {
            return String.valueOf(answerChar);
        }
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int l = in.nextInt();
        long x = in.nextLong();
//        x %= 16;
        String s0 = in.next();
        StringBuilder builder = new StringBuilder(" ");
        for (int i = 0; i < x; i++) {
            builder.append(s0);
        }
        char[] s = builder.toString().toCharArray();
        l = s.length - 1;
        String[] product = new String[l + 1];
        product[0] = "1";
        for (int i = 1; i <= l; i++) {
            product[i] = multiply(product[i - 1], String.valueOf(s[i]));
        }
        if (!product[l].equals("-1")) {
            out.println("Case #" + testNumber + ": " + "NO");
            return;
        }
        int i0 = -1;
        for (int i = 1; i <= l; i++) {
            if (product[i].equals("i")) {
                i0 = i;
                break;
            }
        }
        if (i0 == -1) {
            out.println("Case #" + testNumber + ": " + "NO");
            return;
        }
        int j0 = -1;
        for (int j = i0 + 1; j <= l; j++) {
            if (product[j].equals("k")) {
                j0 = j;
                break;
            }
        }
        if (j0 == -1) {
            out.println("Case #" + testNumber + ": " + "NO");
            return;
        }
        out.println("Case #" + testNumber + ": " + "YES");
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1 << 16];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
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

    public int nextInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c & 15;
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String next() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public long nextLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c & 15;
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

}

class OutputWriter {
    private PrintWriter writer;

    public OutputWriter(OutputStream stream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream)));
    }

    public void println(String x) {
        writer.println(x);
    }

    public void close() {
        writer.close();
    }

}

