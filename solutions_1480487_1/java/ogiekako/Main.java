import java.io.IOException;
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
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, MyScanner in, PrintWriter out) {
        int n = in.nextInt();
        out.printf("Case #%d:", testNumber);
        double[] xs = new double[n];
        for (int i = 0; i < n; i++) xs[i] = in.nextDouble();
        double sum = 0;
        for(double x:xs)sum += x;
        for (int i = 0; i < n; i++) {
            double lb=0, ub=1;
            for (int j = 0; j < 100; j++){
                double md = (lb+ub)/2;
                double myScore = xs[i] + sum * md;
                double Y = md;
                for (int k = 0; k < n; k++)if(i!=k){
                    double y = Math.max((myScore-xs[k])/sum, 0);
                    Y += y;
                }
                if(Y <= 1){ // lose
                    lb = md;
                }else{
                    ub = md;
                }
            }
            out.printf(" %.12f",ub*100);
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

	public double nextDouble() {
        return Double.parseDouble(next());
    }


    }

