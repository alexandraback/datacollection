import java.io.IOException;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.HashSet;
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
		C_Recycled_Numbers solver = new C_Recycled_Numbers();
		solver.solve(1, in, out);
		out.close();
	}
}

class C_Recycled_Numbers {

	public void solve(int testNumber, MyInputReader in, MyOutputWriter out) {
        int test = in.nextInt() ;
        for (int tc = 0; tc < test; tc++) {
            int A = in.nextInt() ;
            int B = in.nextInt() ;
            HashSet<Pair<Integer,Integer>> myset = new HashSet<Pair<Integer, Integer>>();
            int len = Integer.toString( A ).length() , d = power( len ) ;
            //out.printLine( d , len );
            for( int n = A ; n <= B-1 ; n ++ ){
               if( Integer.toString(n).length() > len ){ len ++ ; d *= 10 ;}
                int nn = n ;
                for( int i = 1 ; i < len ; i ++ ){
                    int last = nn % 10 ;
                    nn = nn / 10 + last * d ;
                    if( last == 0) continue;
                    if(  nn > n && nn <= B ){
                        myset.add( Pair.makePair( n ,nn) );
                    }

                }
            }
            //if( tc < 2 )out.printLine( myset.toString());
            out.printLine("Case #" + (tc+1) + ": " + myset.size() );
        }
	}

    private int power(int d) {
        int ret = 1 ;
        for( int i = 1 ; i < d ; i ++ )
            ret *= 10 ;
        return ret;
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

    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }

    public static <U, V> Pair<U, V> makePair(U first, V second) {
        return new Pair<U, V>(first, second);
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass())
            return false;
        Pair pair = (Pair) o;
        return !(first != null ? !first.equals(pair.first) : pair.first != null) &&
                !(second != null ? !second.equals(pair.second) : pair.second != null);
    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        return 31 * result + (second != null ? second.hashCode() : 0);
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

