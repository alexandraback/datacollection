
import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

public class J12R2A implements Runnable {
	Scanner in;
	PrintWriter out;
	static String taskname = ".\\src\\A-small-attempt1";
	int test, testn, i, j, k;
	int n;

	public static void main(String[] args) {
		new Thread(new J12R2A()).start();
	}

	public void solve() throws Exception {
		testn = in.nextInt();

		for (test = 0; test < testn; test++) {
			out.print("Case #" + (test + 1) + ": ");
			n = in.nextInt();
			double a[] = new double[n], total=0, cc, x=0;
			double b[] = new double[n];
			for (i = 0; i < n; i++) {
				a[i]=in.nextInt();
				total+=a[i];
				b[i]=0;
			}
			double c1=total*2;
			cc=total*2/n;
			for (i = 0; i < n; i++) {
				if(cc < a[i]) {
					x++;
					c1-=a[i];
				}
			}
			c1/=(n-x);
			for (i = 0; i < n; i++) {
				if(c1 < a[i]) b[i]=0;
				else b[i]= ((double)c1-a[i])/total*100;
			}
			
			
			for (i = 0; i < n; i++) {
				out.print(b[i]+" ");
			}
			out.print("\n");
		}
	}

	@Override
	public void run() {
		try {
			in = new Scanner(new File(taskname + ".in"));
			out = new PrintWriter(taskname+".out");
			//out = new PrintWriter(System.out, true);
			//			in = new BufferedReader( new InputStreamReader(System.in));
			//			out = new BufferedWriter( new OutputStreamWriter(System.out));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
