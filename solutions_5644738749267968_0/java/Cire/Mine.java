import java.io.*;
import java.util.*;

public class Mine {
	//private DataInputStream in;
	private PrintWriter out;
	private Scanner in;
	
	Mine() throws IOException {
		out = new PrintWriter(new FileWriter("output.txt"), true);		
	
		in = new Scanner(new File("input.txt"));
	}
	
	int OptimalWar(double[] a, double[] b) {
		/*int n = 0;
		for(int i = 0; i < a.length; i++) {
			if (a[i]>b[i])
				n++;
		}*/
		return b.length - OptimalDec(b, a);
	}
	
	int OptimalDec(double[] a, double[] b) {
		int n = a.length;
		int[] c = new int[n];
		int now = 0;
		for(int i = 0; i< n; i++) {
			while (now<n && a[now]<b[i]) {
				c[now] = i;
				now++;
			}
		}
		while (now<n) {
			c[now] = n;
			now++;
		}
		for(int i = 0; i< n; i++) {
			c[i] += n - i - 1;
		}
		int low = c[n-1];
		int best = 0;
		for(int i = n-1; i>=0; i--) {
			low = Math.min(c[i], low);
			best = Math.max(best, Math.min(low, n-i));
		}
		return best;
	}
		
	
	
	
	public void run() throws IOException {
		int n = in.nextInt();
		double[] a = new double[n];
		double[] b = new double[n];
		for(int i = 0; i<n;i++) {
			a[i] = in.nextDouble();
		}
		for(int i = 0; i<n;i++) {
			b[i]= in.nextDouble();
		}
		Arrays.sort(a);
		Arrays.sort(b);
		
		out.print(OptimalDec(a, b));
		out.print(" ");
		out.println(OptimalWar(a, b));
	}
	
	public static void main(String[] args) throws IOException {

		Mine m = new Mine();
		/*char[][] a = new char[1][2];
		a[0][0] = 'a';
		a[0][1] = 'b';
		m.Output(a);
		m.Output(m.Transpose(a, true));
		*/
		int T = m.in.nextInt();
		for(int i=1; i<=T; i++) {
			m.out.print("Case #" + i + ": ");
			m.run();
		}
		return;
	}
}
