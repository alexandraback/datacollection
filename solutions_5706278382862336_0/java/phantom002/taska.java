import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Nitesh Agarwal
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		task1 solver = new task1();
		solver.solve(1, in, out);
		out.close();
	}
}

class task1 {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int t=in.nextInt();
        for(int z=1;z<=t;z++){
            String s=in.nextString();
            long p=Long.parseLong(s.substring(0,s.indexOf('/'))),q=Long.parseLong(s.substring(s.indexOf('/')+1,s.length()));
            long g=gcd(p,q);

            p=p/g;
            q=q/g;
            double pw=(Math.log(q)/Math.log(2));
            long pw1=(long)pw;

            if(p%2==1&&((pw1-pw)==0.0)&&pw1<=40){
                long cou=0;
                while (q>p){
                    q=q/2;
                    cou++;
                }
                out.printLine("Case #"+z+": "+cou);
            }
            else
                out.printLine("Case #"+z+": "+"impossible");
        }

    }
    public long gcd(long a,long b){
        while(b != 0){
            long t=b;
        b  =a % b;
            a=t;
        }
        return a;
    }
}

class InputReader {
    BufferedReader in;
    StringTokenizer tokenizer=null;

    public InputReader(InputStream inputStream)
    {
        in=new BufferedReader(new InputStreamReader(inputStream));
    }
    public String next()
    {
        try{
            while (tokenizer==null||!tokenizer.hasMoreTokens())
            {
                tokenizer=new StringTokenizer(in.readLine());
            }
            return tokenizer.nextToken();
        }
        catch (IOException e)
        {
            return null;
        }
    }
    public int nextInt()
    {
        return Integer.parseInt(next());
    }

    public String nextString()
    {
        try {
            return in.readLine();
        }
        catch (Exception e)
        {
            return null;
        }

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

