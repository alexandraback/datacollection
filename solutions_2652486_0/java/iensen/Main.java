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
			inputStream = new FileInputStream("task3.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("task3.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task3 solver = new Task3();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task3 {
    public int generated[][];
    int currentGIndex;
    public void generate( int []ar,int curIndex,int maxIndex,int M,int N) {

        if(curIndex==maxIndex) {

           for(int i=0;i<N;i++) {

               generated[currentGIndex][i]=ar[i];

           }
            currentGIndex++;
           return;
        }
        for(int i=2;i<=M;i++) {
            int []ar2=new int[N];
            System.arraycopy(ar,0,ar2, 0, N);
            ar2[curIndex]=i;
            generate(ar2,curIndex+1,maxIndex,M,N);
        }

    }
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t=in.nextInt();
        int R=in.nextInt();
        int N=in.nextInt();
        int M=in.nextInt();
        int K=in.nextInt();
        int []ar=new int[N];
        generated=new int[(int)Math.pow((M-1),N)][N];
        currentGIndex=0;

        generate(ar,0,N,M,N);

        out.println("Case #1:");
        for(int i=0;i<R;i++) {
             int []products=new int[K];
             for(int j=0;j<K;j++)  {
                products[j]=in.nextInt();
             }


             for(int j=0;j<Math.pow((M-1),N);j++) {
                 boolean []was =new boolean[127];
                 for(int k=0;k<(1<<N);k++) {
                    //construct a subset
                    int sk=k;
                    int prod=1;
                    int curIndex=0;
                    while(sk>0) {
                        if((sk&1)>0) {
                            prod*=generated[j][curIndex];
                        }
                        ++curIndex;
                        sk>>=1;
                    }
                    was[prod]=true;
                 }
                 boolean good=true;
                 for(int kk=0;kk<K;kk++) {
                     if(!was[products[kk]]) {
                         good=false;
                     }
                 }
                 if(good) {
                     for(int kk=0;kk<N;kk++) {
                         out.print(generated[j][kk]);
                     }
                     out.println();
                     break;
                 }

             }

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

