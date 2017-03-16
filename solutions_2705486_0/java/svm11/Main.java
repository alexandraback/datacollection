import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Vaibhav Mittal
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("C-small-attempt0.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		GarbledEmail solver = new GarbledEmail();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++) {
			solver.solve(i, in, out);
            System.out.println(i);
        }
		out.close();
	}
}

class GarbledEmail {
    String[] dictionary = new String[521196];

    public GarbledEmail() {
        InputReader inDictionary;
        try {
            inDictionary = new InputReader(new FileInputStream("garbled_email_dictionary.txt"));
        } catch (FileNotFoundException e) {
            throw new RuntimeException();
        }
        for (int i = 0; i < dictionary.length; ++i)
            dictionary[i] = inDictionary.readString();
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.readString();
        int n = s.length();
        int[] min = new int[n + 1];
        Arrays.fill(min, Integer.MAX_VALUE);
        int[] last = new int[n + 1];
        Arrays.fill(last, Integer.MAX_VALUE);
        boolean[] mark = new boolean[n + 1];
        min[0] = 0;
        last[0] = -10;
        mark[0] = true;
        for (int i = 0; i < n; ++i) {
            if (!mark[i]) continue;
            for (String word : dictionary) {
                int m = word.length();
                if (n - i < m) continue;
                ArrayList<Integer> errors = new ArrayList<Integer>();
                for (int j = 0; j < m; ++j)
                    if (s.charAt(i + j) != word.charAt(j))
                        errors.add(i + j);
                if (errors.size() == 0) {
                    if (min[i] < min[i + m]) {
                        min[i + m] = min[i];
                        last[i + m] = last[i];
                    }
                    else if (min[i] == min[i + m]) {
                        last[i + m] = Math.min(last[i + m], last[i]);
                    }
                    mark[i + m] = true;
                }
                else {
                    boolean ok = true;
                    if (errors.get(0) - last[i] < 5) ok = false;
                    for (int j = 1; j < errors.size(); ++j)
                        if (errors.get(j) - errors.get(j - 1) < 5)
                            ok = false;
                    if (ok) {
                        if (min[i] + errors.size() < min[i + m]) {
                            min[i + m] = min[i] + errors.size();
                            last[i + m] = errors.get(errors.size() - 1);
                        }
                        else if (min[i] + errors.size() == min[i + m]) {
                            last[i + m] = Math.min(last[i + m], errors.get(errors.size() - 1));
                        }
                        mark[i + m] = true;
                    }
                }
            }
        }
        out.println("Case #" + testNumber + ": " + min[n]);
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    private int read() {
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

    public String readString() {
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

    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public String next() {
        return readString();
    }

    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}

