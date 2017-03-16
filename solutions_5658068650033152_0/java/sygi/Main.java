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
 * @author Jakub Sygnowski
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
    boolean board[][];
    boolean free[][];
    int n,m,k;
    int howMany(){
        free = new boolean[n][m];

        for(int i = 0; i < n; i++){
            if (board[i][0])
                free[i][0] = false;
            else {
                free[i][0] = true;
            }
            if (board[i][m-1])
                free[i][m-1] = false;
            else
                free[i][m-1] = true;
        }

        for(int j = 0; j < m; j++){
            if (board[0][j])
                free[0][j] = false;
            else
                free[0][j] = true;
            if (board[n-1][j])
                free[n-1][j] = false;
            else
                free[n-1][j] = true;
        }

        //w dol
        for(int i = 1; i < n-1; i++){
            for(int j = 1; j < m-1; j++){
                if (board[i][j]){
                    free[i][j] = false;
                    continue;
                }
                if (free[i-1][j] || free[i][j-1])
                    free[i][j] = true;
            }
        }
        //w gore
        for(int i = n - 2; i >=1 ;i--){
            for(int j = m-2; j > 0 ; j--){
                if (board[i][j]){
                    free[i][j] = false;
                    continue;
                }
                if (free[i+1][j] || free[i][j+1])
                    free[i][j] = true;
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (!free[i][j])
                    res++;
            }
        return res;
    }
    int act, best;
    void backtrack(int posx, int posy){
        if (act > best)
            return;
        if(posx >= n){
            if (howMany() >= k){
                best = Math.min(best, act);
            }
            return;
        }
        if (posy >= m){
            backtrack(posx+1, 0);
            return;
        }
        //nie stawiam
        board[posx][posy] = false;
        backtrack(posx, posy+1);
        act++;
        board[posx][posy] = true;
        backtrack(posx, posy+1);
        act--;
    }
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        best = 1000000000;
        n = in.readInt();
        m = in.readInt();
        board = new boolean[n][m];
        k = in.readInt();
        backtrack(0, 0);
        out.printLine("Case #" + testNumber + ": " + best);
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

    public int readInt() {
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
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String readString() {
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
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public String next() {
        return readString();
    }

    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object...objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine(Object...objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}

