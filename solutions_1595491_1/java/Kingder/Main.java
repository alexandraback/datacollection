import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author lwc626
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyInputReader in = new MyInputReader(inputStream);
		MyOutputWriter out = new MyOutputWriter(outputStream);
		B_Dancing_With_the_Googlers solver = new B_Dancing_With_the_Googlers();
		solver.solve(1, in, out);
		out.close();
	}
}

class B_Dancing_With_the_Googlers {
	public void solve(int testNumber, MyInputReader in, MyOutputWriter out) {
        int test = in.nextInt() ;
        for (int tc = 0; tc < test; tc++) {
            int n = in.nextInt() ;
            int s = in.nextInt() ;
            int p = in.nextInt() ;
            int[] A = new int[ n ];
            ArrayList<Pair<Integer,Integer>> ap = new ArrayList<Pair<Integer, Integer>>();

            for( int i = 0 ; i < n ; i ++ ){
                A[i] = in.nextInt() ;
                if( A[i] % 3 == 0 ){
                    ap.add( Pair.makePair( A[i] / 3 , A[i] >= 3 ? A[i] / 3 + 1 : -1 ));
                }
                else if( A[i] % 3 == 1 ){
                    ap.add( Pair.makePair( (A[i] + 2)/ 3 , A[i] >= 4 ? (A[i]+2) / 3 : -1 )  );
                }else{
                    ap.add( Pair.makePair( (A[i] + 1)/ 3 , A[i] >= 2 ? (A[i] + 4)/3 : -1 ) );
                }
            }
            //out.printLine( ap.toString());
            int [][] dp = new int[ n+1 ][ s+1 ];
            for( int[] o : dp ) Arrays.fill( o , -1 );
            dp[0][0] = 0 ;
            for( int i = 0 ; i < n ; i ++ ){
                for( int j = 0 ; j <= s ; j ++ ) if( dp[i][j] != -1 ){
                    update( dp , i+1 , j , dp[i][j] + (ap.get(i).first >= p ? 1 : 0) );
                    if(j+1<=s && ap.get(i).second != -1)
                        update( dp , i+1 , j+1 , dp[i][j] + (ap.get(i).second >= p ? 1 : 0 ) );
                }
            }
            //for( int[] o : dp ) IOUtils.printIntArrays( out, o );
            out.printLine( "Case #" + (tc+1) +": "+ dp[n][s] );
        }
	}

    private void update(int[][] dp, int i, int j, int v) {
        if( dp[i][j] == -1 || dp[i][j] < v ) dp[i][j] = v ;
    }
}

class MyInputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public MyInputReader(InputStream stream) {
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
    public int nextInt(){
        return readInt() ;
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    }

class MyOutputWriter {
    private final PrintWriter writer;

    public MyOutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(outputStream);
    }

    public MyOutputWriter(Writer writer) {
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

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

	}

	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	public String toString() {
		return "(" + first + "," + second + ")";
	}

	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>)first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>)second).compareTo(o.second);
	}
}

