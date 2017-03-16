import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class B12014A {

	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;

	public static void main(String[] args) throws IOException {
		// Initializing ...
		new B12014A();
		// -------------------------------------------------------------------------
		int testCases = nextInt();
		int counter = 0;
		while (testCases-- > 0) {
			counter++;
			// Here put the code..:)
			
			long a = nextLong();
			long b = nextLong();
			long k = nextLong();
			
			long ret = a*k - k*k + b*k;
			
			for (long i = k; i < a; i++) {
				for (long j = k; j < b; j++) {
					if((i&j) < k)
						 ret ++;
				}
			}
			
			writeln("Case #"+counter+": "+ret);
		}
		// -------------------------------------------------------------------------
		// closing up
		end();
		// --------------------------------------------------------------------------

	}


	public B12014A() throws IOException {
		// Input Output for Console to be used for trying the test samples of
		// the problem
		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(System.out);
		// -------------------------------------------------------------------------
		// Input Output for File to be used for solving the small and large test
		// files
		// in = new BufferedReader(new FileReader("Template.in"));
		 out = new PrintWriter("B12014A.out");
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
