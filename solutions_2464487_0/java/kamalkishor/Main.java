import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int T=in.nextInt();
        for(int i=0;i<T;i++){
            out.print("Case #"+(i+1)+": ");
            in.readLine();
            long r=in.nextLong();
            long t=in.nextLong();
            for(int j=1;j<=1000;j++){
                if(calc(j,r).compareTo(new BigInteger(""+t))>0){
                    out.println(j-1);
                    break;
                }
            }

        }
    }

    public BigInteger calc(long n,long r){
        BigInteger ret=BigInteger.ZERO;
        ret=ret.add(new BigInteger(""+(2*r-1)));
        ret=ret.multiply(new BigInteger(""+n));
        BigInteger s=new BigInteger(""+n);
        s=s.multiply(s);
        s=s.multiply(new BigInteger(""+2));
        return ret.add(s);

    }
}

class InputReader {
    private BufferedReader br;
    private StringTokenizer st;
    public InputReader(InputStream in) {
        br=new BufferedReader(new InputStreamReader(in));
        try {
            st=new StringTokenizer(br.readLine());
        } catch (IOException ignored) {

        }
    }

    public InputReader(String file)  {
        try {
            br=new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        } catch (FileNotFoundException e) {

        }
        try {
            st=new StringTokenizer(br.readLine());
        } catch (IOException ignored) {

        }
    }

    public boolean readLine() {
        try {
            st=new StringTokenizer(br.readLine());

        } catch (IOException e) {
            return false;
        }
        catch (NullPointerException e){
            return false;
        }
        return true;
    }
    public int nextInt(){
        return Integer.parseInt(st.nextToken());
    }

    public long nextLong(){
        return Long.parseLong(st.nextToken());
    }


}

