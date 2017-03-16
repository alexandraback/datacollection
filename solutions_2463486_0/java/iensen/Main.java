import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskCGCJ2013 solver = new TaskCGCJ2013();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskCGCJ2013 {
    boolean isPolynomial(long number) {
        String s=Long.toString(number);
        boolean is=true;
        for(int i=0;i<s.length()/2;i++) {
            int countra=s.length()-1-i;
            if(s.charAt(i)!=s.charAt(countra)) {
                is=false;
                break;
            }
        }
        return is;
    }

    int lower_bound(long goodPol[],long A,int lastIndex) {
        //find the least p suc that  p*p>=A;
        int L=1;
        int R=lastIndex;
        while(L!=R-1) {
            int C=(L+R)/2;
            long p=goodPol[C];
            if(p*p>=A) {
                R=C;
            }
            else {
                L=C;
            }
        }
        if(R>0) {
            long p=goodPol[L];
            if(p*p>=A) {
                R=L;
            }
        }
        return R;
    }


    int upper_bound(long goodPol[],long B, int lastIndex) {
        //find the max index p suc that  p*p<=B;
        int L=1;
        int R=lastIndex;
        while(L!=R-1) {
            int C=(L+R)/2;
            long p=goodPol[C];
            if(p*p<=B) {
                L=C;
            }
            else {
                R=C;
            }
        }
        return L;
    }



	public void solve(int testNumber, InputReader in, PrintWriter out) {
        long goodPol[]=new long[1000000];
        int countgoodPol=0;
        for(long i=0;i<1000000000;i++) {
            if(isPolynomial(i) && isPolynomial(i*i)) {
                goodPol[countgoodPol++]=i;
                if(i>10000000)
                    break;
            }
        }

        int T=in.nextInt();
        for(int i=0;i<T;i++)  {
            long A=in.nextInt();
            long B=in.nextInt();
            int i1=lower_bound(goodPol,A,countgoodPol-1);
            int i2=upper_bound(goodPol,B,countgoodPol-1);
            out.println("Case #"+(i+1)+": "+((i2-i1)+1));
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

    }

