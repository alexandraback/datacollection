import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class A12013C {

	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;

	public static void main(String[] args) throws IOException {
		// Initializing ...
		new A12013C();
		// -------------------------------------------------------------------------
		int testCases = nextInt();
		int counter = 0;
		while (testCases-- > 0) {
			counter++;
			// Here put the code..:)
			long r = nextLong();
			long t = nextLong();
			BigInteger rr = new BigInteger("" + r);
			BigInteger tt = new BigInteger("" + t);
			BigInteger one = new BigInteger("1");
			BigInteger two = new BigInteger("2");
			long low = 0l;
			long high = 707106781l;
			int itr = 100;
			while (itr-- > 0) {
				long med = (low + high) / 2;
				BigInteger mm = new BigInteger("" + med);
//				long need = 2l * med * (med + 1l) + med + 1l + 2 * (med + 1)
//						* r;
				BigInteger nn = (two.multiply(mm.multiply(mm.add(one))))
						.add(mm).add(one)
						.add(two.multiply(mm.add(one)).multiply(rr));
				if (nn.compareTo(tt)>0)
					high = med;
				else
					low = med;
			}

			writeln("Case #" + counter + ": " + (low + 1));
		}
		// -------------------------------------------------------------------------
		// closing up
		end();
		// --------------------------------------------------------------------------

	}

	public A12013C() throws IOException {
		// Input Output for Console to be used for trying the test samples of
		// the problem
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		// -------------------------------------------------------------------------
		// Input Output for File to be used for solving the small and large test
		// files
		// in = new BufferedReader(new FileReader("Template.in"));
		 out = new PrintWriter("A12013A.out");
		// -------------------------------------------------------------------------
		// Initalize Stringtokenizer input
		input = new StringTokenizer(in.readLine());
	}

	private static int nextInt() throws IOException {
		if (!input.hasMoreTokens())
			input = new StringTokenizer(in.readLine());
		return Integer.parseInt(input.nextToken());
	}

	private static long nextLong() throws IOException {
		if (!input.hasMoreTokens())
			input = new StringTokenizer(in.readLine());
		return Long.parseLong(input.nextToken());
	}

	private static double nextDouble() throws IOException {
		if (!input.hasMoreTokens())
			input = new StringTokenizer(in.readLine());
		return Double.parseDouble(input.nextToken());
	}

	private static String nextString() throws IOException {
		if (!input.hasMoreTokens())
			input = new StringTokenizer(in.readLine());
		return input.nextToken();
	}

	private static void write(String output) {
		out.write(output);
		out.flush();
	}

	private static void writeln(String output) {
		out.write(output + "\n");
		out.flush();
	}

	private static void end() throws IOException {
		in.close();
		out.close();
		System.exit(0);
	}

}
