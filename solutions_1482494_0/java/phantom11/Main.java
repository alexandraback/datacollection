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
			inputStream = new FileInputStream("B-small-attempt0.in");
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, Scanner in, PrintWriter out) {
        int t,test=in.nextInt(),i,j;

        for(t=1;t<=test;t++)
        {
             int n=in.nextInt();
            stars a[]=new stars[n];
            for(i=0;i<n;i++)
                a[i]=new stars(in.nextInt(),in.nextInt());
            Arrays.sort(a);
            int s=0,k=0;
            int status[]=new int[n];
            boolean st=true;
            for(i=0;i<n;i++)
            {
                if(a[i].two<=s)
                {
                    s+=2-status[i];
                    status[i]=2;
                    k++;
                }
                else
                {
                    j=n-1;

                    while (j>=i&&s<a[i].two)
                    {
                        if(status[j]<1&&a[j].one<=s)
                        {
                            s+=1;
                            status[j]=1;
                            k++;
                        }
                        j--;

                    }
                    if(a[i].two>s)
                    {
                        st=false;
                        break;
                    }
                    else
                    {
                        s+=2-status[i];
                        status[i]=2;
                        k++;
                    }
                }
            }
            if(!st)
            out.println("Case #"+t+": "+"Too Bad");
            else out.println("Case #"+t+": "+k);
        }
	}
    class stars implements Comparable<stars>
    {
        int one,two;
        public stars(int one,int two)
        {
            this.one=one;
            this.two=two;
        }
        public int compareTo(stars a)
        {
            int k=0;
            if(this.two>a.two)
                k=1;
            else if(this.two<a.two)
            k=-1 ;
            else if(this.two==a.two)
            {
                if(this.one>a.one)
                    k=-1;
                else
                    k=1;

            }
            return k;
        }
    }
}

