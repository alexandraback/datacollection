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
		Task2 solver = new Task2();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task2 {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int T=in.nextInt();
        for(int tcase=1;tcase<=T;tcase++) {
            int N=in.nextInt();
            int M=in.nextInt();
            int[][]a=new int[N][M];
            int count[]=new int[101];
            for(int i=0;i<N;i++) {
                for(int j=0;j<M;j++) {
                    a[i][j]=in.nextInt();
                    count[a[i][j]]++;
                }
            }
                 boolean good=true;
                for(int i=0;i<N;i++) {
                    if(!good)break;
                    for(int j=0;j<M;j++) {
                      int curNum=a[i][j];
                      //try to explain horiz:
                      boolean explained=true;
                      for(int jj=0;jj<M;jj++) {
                          if(a[i][jj]>curNum) {
                             explained=false;
                              break;
                          }
                    }
                      if(!explained) {
                          explained=true;
                          for(int jj=0;jj<N;jj++) {
                              if(a[jj][j]>curNum) {
                                  explained=false;
                                  break;
                              }
                          }
                      }
                      if(!explained){
                          good=false;
                          break;
                      }
                }
            }

            out.println("Case #"+tcase+": "+((good)?"YES":"NO"));


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

