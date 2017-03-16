import java.io.IOException;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.TreeSet;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    int index=0;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int T=in.readInt();
        for (int i=0;i<T;i++){
            Mote A=new Mote(in.readInt(),1000);
            int N=in.readInt();
            TreeSet<Mote> ts=new TreeSet<Mote>();
            for (int j=0;j<N;j++){
                ts.add(new Mote(in.readInt(),j));
                index++;
            }
            int ans=min(A,ts);
            out.println("Case #"+(i+1)+": "+ans);


        }
    }
    int min(Mote A,TreeSet<Mote> motes){
       // System.out.println(A);
        boolean ok=true;
        int ans=0;
        while (!motes.isEmpty()){
            Mote a=motes.pollFirst();
            if(a.val<A.val)
                A.val+=a.val;
            else{
                motes.add(a);
                ok=false;
                break;
            }
        }
        if(ok) return ans;
        ans=motes.size();
        motes.add(new Mote(A.val-1,A.index+1));
        if(A.val!=1)
            ans=Math.min(ans,min(A,motes)+1);
        return ans;
    }
}

class Mote implements Comparable<Mote>{
    int val,index;
    public Mote(int v,int m){
        val=v;
        index=m;
    }
    public int compareTo(Mote t){
        if(t.val!=val)
            return val-t.val;
        return index-t.index;
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

        public boolean isSpaceChar(int c) {
                if (filter != null)
                        return filter.isSpaceChar(c);
                return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
                return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
                public boolean isSpaceChar(int ch);
        }
}

