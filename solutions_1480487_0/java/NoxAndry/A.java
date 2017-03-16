import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.Comparator;

public class A {


	private static void solve(String s) {
		String[] ss = s.split(" ");
		int n = Integer.parseInt(ss[0]);
		int[][] mas = new int[n][];
		for(int i = 0; i<n; i++) {
			mas[i] = new int[] {Integer.parseInt(ss[1+i]), i};
		}
		Arrays.sort(mas, new Comparator<int[]>() {
			public int compare(int[] mas1, int[] mas2) {
				return mas1[0] - mas2[0];
			}
		});
		
		
		int x = 0;
		for(int i = 0; i<n; i++) {
			x += mas[i][0];
		}
		
		double[] ansMas = new double[n];
		
		
		double high = mas[0][0];
		double left = x;
			
		for(int up = 0; up<n; up++) {
			
			if(left - ((mas[up][0] - high)*up) > 0) {
				left -= ((mas[up][0] - high)*up);
				high = mas[up][0];
			} else {
				high += left/(double)up;
				left = 0;
			}
				
		}
			
		if(left > 0) {
			high += left/(double)n;
		}
		
		
		for(int i = 0; i<n; i++) {
				
			double ans = (high - mas[i][0])/(double)x;
			
			ansMas[mas[i][1]] = ans > 0 ? ans : 0;
		}
		
		for(int i = 0; i<n; i++) {
			out.print(ansMas[i]*100);
			if(i != n-1)out.print(" ");
		}
		out.println();
		
	}
	
	public static void main(String[] args) throws Exception {
		int t = Integer.parseInt(inB.readLine());
		for(int _ = 0; _<t; _++) {
			out.print("Case #" + (_+1) + ": ");
			solve(inB.readLine());
		}
		out.flush();
	}

	// ///////////////////////////////////////////////////////////////
	// IO
	// ///////////////////////////////////////////////////////////////
	private static StreamTokenizer in;
	private static PrintWriter out;
	private static BufferedReader inB;

	private static boolean FILE = true;

	private static int nextInt() throws Exception {
		in.nextToken();
		return (int) in.nval;
	}

	private static String nextString() throws Exception {
		in.nextToken();
		return in.sval;
	}

	static {
		try {
			out = new PrintWriter(FILE ? (new FileOutputStream("output.txt"))
					: System.out);
			inB = new BufferedReader(new InputStreamReader(
					FILE ? new FileInputStream("A-small-attempt0.in") : System.in));
		} catch (Exception e) {
			e.printStackTrace();
		}
		in = new StreamTokenizer(inB);
	}

	// ///////////////////////////////////////////////////////////////

	// ///////////////////////////////////////////////////////////////
	// pre - written
	// ///////////////////////////////////////////////////////////////
	private static void println(Object o) throws Exception {
		out.println(o);
		out.flush();
	}

	private static void exit(Object o) throws Exception {
		println(o);
		exit();
	}

	private static void exit() {
		System.exit(0);
	}

	private static final int INF = Integer.MAX_VALUE;
	private static final int MINF = Integer.MIN_VALUE;
	// ////////////////////////////////////////////////////////////////
}
