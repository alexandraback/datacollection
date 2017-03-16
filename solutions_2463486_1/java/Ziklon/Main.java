import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author @Ziklon
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("fairandsquare.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("fairandsquare.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		FairAndSquare solver = new FairAndSquare();
		solver.solve(1, in, out);
		out.close();
	}
}

class FairAndSquare {
    final long MAXN = 100000000000000L;
    ArrayList<Long> squares;
    boolean isPal(String n) {
        String rev = new StringBuffer(n).reverse().toString();
        return rev.equals(n);
    }

    int find(long a){//fin 0 - to a
        int ans=0;
        BigInteger ba=BigInteger.valueOf(a);
        if(a==0)return 0;
        boolean oka=false;
        for(long n :squares){
            BigInteger bi=BigInteger.valueOf(n);
            bi=bi.pow(2);
            if(ba.compareTo(bi)==-1)break;
            if(isPal(bi.toString()))ans++;
        }

        return ans;
    }
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        squares = new ArrayList<Long>();
        squares.add(1L);
        squares.add(2L);
        squares.add(3L);
        for (long i = 4; i * i <= MAXN; i++)if(isPal(i+"")){
            boolean ok=true;
            for(char c='3';c<='9';c++)if((i+"").indexOf(c)!=-1)ok=false;
            if(ok)squares.add(i);
        }
        int T=in.nextInt();
        for(int t=0;t<T;t++){
            long a=in.nextLong();
            long b=in.nextLong();
            int ans=find(b)-find(a-1);
            out.printFormat("Case #%d: %d\n",t+1,ans);
        }
    }
}

class InputReader {
    InputStream stream;
    byte[] buf = new byte[1024];
    int curChar, numChars;

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
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
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
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    private boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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

    public void printFormat(String format, Object...objects) {
        writer.printf(format, objects);
    }

    public void close() {
        writer.close();
    }

    }

