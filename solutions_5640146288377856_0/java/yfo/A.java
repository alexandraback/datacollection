import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class A {
	static BufferedReader in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader(new File(
				"/Users/yfo/Downloads/a1.in")));
		out = new PrintWriter(new FileWriter(new File(
				"/Users/yfo/Downloads/a1_out.in")));

		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; t++) {
			System.out.print((t + 1) + ": ");
			
			String[] tok = rst();
			int R = Integer.parseInt(tok[0]);
			int C = Integer.parseInt(tok[1]);
			int W = Integer.parseInt(tok[2]);
			
			int x = (C/W)*R;
			int m = C%W;
			
			x+=(W-1);
			if (m>0) x++;
			
			
			out.println("Case #" + (t + 1) + ": "+x);
			System.out.println(x);
		}

		in.close();
		out.close();
	}

	static int ri() throws IOException {
		return Integer.parseInt(in.readLine());
	}

	static long rl() throws IOException {
		return Long.parseLong(in.readLine());
	}

	static String[] rst() throws IOException {
		return in.readLine().split(" ");
	}

	public static int[] rit() throws IOException {
		String[] tok = in.readLine().split(" ");
		int[] res = new int[tok.length];
		for (int i = 0; i < tok.length; i++) {
			res[i] = Integer.parseInt(tok[i]);
		}
		return res;
	}

	public static long[] rlt() throws IOException {
		String[] tok = in.readLine().split(" ");
		long[] res = new long[tok.length];
		for (int i = 0; i < tok.length; i++) {
			res[i] = Long.parseLong(tok[i]);
		}
		return res;
	}
}
