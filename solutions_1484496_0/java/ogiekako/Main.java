import java.io.IOException;
import java.util.HashMap;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.NoSuchElementException;
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
		MyScanner in = new MyScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, MyScanner in, PrintWriter out) {
                out.printf("Case #%d:\n", testNumber);
        int n = in.nextInt();
        long[] S = new long[n];
        HashMap<Long, Integer> map = new HashMap<Long, Integer>();
        for (int i = 0; i < n; i++) {
            S[i] = in.nextInt();
        }
        for (int i = 0; i < 1 << n; i++){
            long T = 0;
            for (int j = 0; j < n; j++)if((i>>j&1)==1){
                T += S[j];
            }
            if(map.containsKey(T)){
                int ni  =map.get(T);
                int and = i&ni;
                int A = i^and;
                int B = ni^and;
                output(out,A,S);
                output(out,B,S);
                return;
            }else{
                map.put(T,i);
            }
        }
        out.println("Impossible");
    }

    private void output(PrintWriter out, int A, long[] S) {
        for (int i = 0; i < 20; i++){
            if((A>>i&1)==1){
                out.printf("%d ",S[i]);
            }
        }
        out.println();
    }
}

class MyScanner {
    private final InputStream in;
    public MyScanner(InputStream in){
        this.in = in;
    }

    char[] buf = new char[2000000];
    int strLen;
	public String next() {
		try {
            strLen = 0;
            int c;
			do{
				c = in.read();
				if(c==-1)throw new NoSuchElementException();
			}while(Character.isWhitespace(c));
			do {
                buf[strLen++] = (char)c;
                c = in.read();
			} while (c!=-1 && !Character.isWhitespace(c));
            return new String(buf,0,strLen);
		} catch (IOException e) {
            throw new NoSuchElementException();
		}
	}

	public int nextInt(){
		try{
			int c=in.read();
			if(c==-1) return c;
			while(c!='-'&&(c<'0'||'9'<c)){
				c=in.read();
				if(c==-1) return c;
			}
			if(c=='-') return -nextInt();
			int res=0;
			do{
				res*=10;
				res+=c-'0';
				c=in.read();
			}while('0'<=c&&c<='9');
			return res;
		}catch(Exception e){
			return -1;
		}
	}


    }

