import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Q1 {
	private static void run(int CASE) throws Exception {
		StringTokenizer st = new StringTokenizer(readLine());
		int A = parseInt(st.nextToken());
		int B = parseInt(st.nextToken());
		double[] p = new double[A];
		st = new StringTokenizer(readLine());
		double allCorrectP = 1;
		double[] tmp = new double[A];
		for(int i=0; i<A; i++) {
			p[i] = Double.parseDouble(st.nextToken());
			allCorrectP *= p[i];
			tmp[i] = allCorrectP;
		}
		double[] allCorrectExceptIth = new double[A];
		allCorrectExceptIth[0] = tmp[tmp.length-1];
		int ti = tmp.length-2;
		for (int i = 1; i < p.length; i++, ti--) {
			allCorrectExceptIth[i] = allCorrectExceptIth[i-1] + tmp[ti]*(1-p[ti+1]);
		}
		
		double minExp = B+2;
		double[] expected = new double[A];
		for (int i = 0; i < expected.length; i++) {
			int numTypeOnce = 2*i+B-A+1;
			expected[i] = allCorrectExceptIth[i]*numTypeOnce + (1-allCorrectExceptIth[i])*(numTypeOnce+B+1);
//			printf("Debug %.2f\n", expected[i]);
			if(expected[i]<minExp)
				minExp = expected[i];
		}
		printf("Case #%d: %.6f\n", CASE, minExp);
	}

	//-- Supporting --//
	static BufferedReader in;
	static PrintWriter out;
	static {
		try {
			in = new BufferedReader(new FileReader("A-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("out.txt"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) throws Exception {
		int N = Integer.parseInt(readLine());
		for (int c = 1; c <= N; c++) {
			run(c);
		}
		in.close();
		out.close();
	}

	private static String readLine() throws IOException {
		return in.readLine();
	}

	private static void printf(String str, Object... o) {
		System.out.printf(str, o);
		out.printf(str, o);
	}

	private static int parseInt(String t) {
		return Integer.parseInt(t);
	}
}
