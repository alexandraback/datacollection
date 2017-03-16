import java.io.InputStreamReader;
import java.io.IOException;
import java.math.BigDecimal;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("task.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("task.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int T=in.nextInt();
      for(int i=0;i<T;i++) {
          long r=in.nextLong();
          long t=in.nextLong();
          long L=0;
          long R=t;
          while(L!=R-1) {
              long C=(L+R)/2;
              BigDecimal n=BigDecimal.valueOf(r);
              n=n.multiply(BigDecimal.valueOf(4));
              BigDecimal n2=BigDecimal.valueOf(C);
              n2=n2.multiply(BigDecimal.valueOf(4));
              n2=n2.subtract(BigDecimal.valueOf(2));
              n=n.add(n2);
              n=n.multiply(BigDecimal.valueOf(C));

              BigDecimal bd=BigDecimal.valueOf(2*t);
            //  bd=bd.divide(BigDecimal.valueOf(Math.PI), RoundingMode.DOWN);

              if(bd.compareTo(n)>=0) {
                  L=C;

              }
              else {
                  R=C;
              }

          }
          out.println("Case #"+(i+1)+": "+L);
      }
    }
}

class InputReader {
    StringTokenizer st;
    BufferedReader in;
    public InputReader(InputStream ins)
    {
        in = new BufferedReader(new InputStreamReader(ins));
    }

    public String nextToken()
    {
        while(st==null || !st.hasMoreTokens())
        {
            try {
                st=new StringTokenizer(in.readLine());
            } catch (IOException e) {
                e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
            }
        }
        return st.nextToken();
    }
    public int nextInt()
    {

        return Integer.parseInt(nextToken());
    }

    public long nextLong()
    {
       return  Long.parseLong(nextToken());
    }

}

