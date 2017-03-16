import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.TreeSet;

public class C {


	private static void printMas(int a, int[] mas) {
		int n = mas.length;
		for(int i = 0; i<n; i++) {
			if(((a>>i)&1) == 1) {
				out.print(mas[i] + " ");
			}
		}
		out.println();
	}
	
	private static void solve(String s) {
		String[] ss = s.split(" ");
		int n = Integer.parseInt(ss[0]);
		int[] mas = new int[n];
		for(int i = 0; i<n; i++) {
			mas[i] = Integer.parseInt(ss[1+i]);
		}
		Arrays.sort(mas);
		
		TreeSet<Integer> ts = new TreeSet<Integer>();
		
		int found = -1;
		
		int a = 0;
		for(; a < 1 << n; a++) {
			int sum = 0;
			for(int i = 0; i<n; i++) {
				if(((a >> i)&1) == 1) {
					sum += mas[i];
				}
			}
			if(ts.contains(sum)) {
				found = sum;
				break;
			}
			ts.add(sum);
		}
		
		if(found == -1) {
			out.println("Impossible");
		} else {
			for(int b = 0; ; b++) {
				int sum = 0;
				for(int i = 0; i<n; i++) {
					if(((b >> i)&1) == 1) {
						sum += mas[i];
					}
				}
				if(sum == found) {
					printMas(a, mas);
					printMas(b, mas);
					break;
				}
			}
		}
		
	}
	
	public static void main(String[] args) throws Exception {
		int t = Integer.parseInt(inB.readLine());
		for(int _ = 0; _<t; _++) {
			out.print("Case #" + (_+1) + ": ");
			out.println();
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
					FILE ? new FileInputStream("C-small-attempt0.in") : System.in));
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
