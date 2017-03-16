import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.util.Arrays;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author codeKNIGHT
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("A-large.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    boolean status;
    int mark;
	public void solve(int testNumber, Scanner in, PrintWriter out) {
        int i,j,test=in.nextInt(),t;
        for(t=1;t<=test;t++)
        {
            int n=in.nextInt(),m;
            boolean a[][]=new boolean[n][n];
            for(i=0;i<n;i++)
            {
                m=in.nextInt();
                for(j=0;j<m;j++)
                {
                    a[i][in.nextInt()-1]=true;
                }
            }
            int visited[]=new int[n];
            status=false;
            for(i=0;i<n;i++)
            {
                mark=i;
                Arrays.fill(visited,-1);
                dfs(a,visited,i);
            }
            String res="No";
            if(status)
                res="Yes";
            out.println("Case #"+t+": "+res);
        }

	}
    public void dfs(boolean a[][],int visited[],int p)
    {
        int i;
        for(i=0;i<a.length;i++)
        {
            if(a[p][i])
            {
                if(visited[i]==mark)
                    status=true;
                else 
                {
                    visited[i]=mark;
                    dfs(a,visited,i);
                }
            }
        }
    }
}

