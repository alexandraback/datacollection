import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
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
	public void solve(int testNumber, Scanner in, PrintWriter out) {
        int t,test=in.nextInt(),i,j;
        int a,b;
        for(t=1;t<=test;t++)
        {
            a=in.nextInt();
            b=in.nextInt();
             double array[]=new double[a];
            double sum=0,pro=1;
            double a1[]=new double[a];
            for(i=0;i<a;i++)
            {
                array[i]=in.nextDouble();
                sum+=array[i];
                pro*=array[i];
                a1[i]=pro;
            }
            double min=Double.MAX_VALUE;
            min=b+2;
            min=Math.min(min,pro*(b-a+1)+(1-pro)*(2*b-a+2));
            for(int k=1;k<a;k++)
            {
                min=Math.min(min,a1[a-1-k]*(2*k+b-a+1)+(1-a1[a-1-k])*(2*k+b-a+1+b+1));
            }
            min=Math.min(min,(a+b+1));
            //NumberFormat nf=new DecimalFormat("")
            out.println("Case #"+t+": "+min);
        }
	}
}

